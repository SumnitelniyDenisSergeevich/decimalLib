#include "s21_decimal.h"

#include <limits.h>
#include <math.h>

#define EXP 0x00ff0000
#define SIGN (1 << 31)
#define BITS_SIZE 32

int GetExp(const s21_decimal* dcml) { return (dcml->bits[3] & EXP) >> 16; }

void SetExp(s21_decimal* dcml, const int exp) {
  dcml->bits[3] &= (~EXP);
  dcml->bits[3] |= exp << 16;
}

int GetSign(const s21_decimal* dcml) { return dcml->bits[3] & SIGN ? 1 : 0; }

void SetSign(s21_decimal* dcml, const int sign) {
  dcml->bits[3] &= (~SIGN);
  if (sign) dcml->bits[3] |= SIGN;
}

void ResetDecimal(s21_decimal* dcml) {
  for (int i = 0; i < SIZE; ++i) dcml->bits[i] = 0;
}

int decimal_is_null(s21_decimal* dcml) {
  int result = 1;
  for (int i = 0; i < SIZE - 1; ++i)
    if (dcml->bits[i]) {
      result = 0;
      break;
    }
  return result;
}

int ModTen(s21_decimal* dcml) {
  int remainder = 0;
  int i = 2, j = 31;
  while (!(dcml->bits[i] & (1 << j)) && (i >= 0)) {
    --j;
    if (j == -1) {
      --i;
      j = 31;
    }
  }
  for (; i >= 0; --i) {
    for (; j >= 0; --j) {
      remainder <<= 1;
      if (dcml->bits[i] & (1 << j)) remainder += 1;
      remainder -= remainder >= 10 ? 10 : 0;
    }
    j = 31;
  }
  return remainder;
}

void left_shift(s21_decimal* dcml, int count) {
  while (count > 31) {
    left_shift(dcml, 31);
    count -= 31;
  }
  dcml->bits[2] <<= count;
  for (int i = 1; i >= 0; --i) {
    for (int j = 0; j < count; ++j)
      if (dcml->bits[i] & (1 << (BITS_SIZE - j - 1)))
        dcml->bits[i + 1] |= (1 << (count - 1 - j));
    dcml->bits[i] <<= count;
  }
}

void right_shift(s21_decimal* dcml, int count) {
  while (count > 31) {
    right_shift(dcml, 31);
    count -= 31;
  }
  dcml->bits[0] >>= count;
  for (int i = 0; i < count; ++i)
    dcml->bits[0] &= (~(1 << (BITS_SIZE - 1 - i)));
  for (int i = 1; i < SIZE - 1; ++i) {
    for (int j = 0; j < count; ++j)
      if (dcml->bits[i] & (1 << j))
        dcml->bits[i - 1] |= (1 << (BITS_SIZE - count + j));
    dcml->bits[i] >>= count;
    for (int j = 0; j < count; ++j)
      dcml->bits[i] &= (~(1 << (BITS_SIZE - 1 - j)));
  }
}

void shift(s21_decimal* dcml, int count) {
  count >= 0 ? right_shift(dcml, count) : left_shift(dcml, -count);
}

void DivTen(s21_decimal* dcml) {
  s21_decimal result;
  ResetDecimal(&result);
  int i = 2, j = 31;
  while (!(dcml->bits[i] & (1 << j)) && (i >= 0)) {
    --j;
    if (j == -1) {
      --i;
      j = 31;
    }
  }
  if (i >= 0) {
    int remainder = 0;
    for (; i >= 0; --i) {
      for (; j >= 0; --j) {
        remainder <<= 1;
        if (dcml->bits[i] & (1 << j)) remainder += 1;
        shift(&result, -1);
        if (remainder >= 10) {
          result.bits[0] |= 1;
          remainder -= 10;
        }
      }
      j = 31;
    }
    SetSign(&result, GetSign(dcml));
    SetExp(&result, GetExp(dcml));
    *dcml = result;
  }
}

void RemoveExtraZeros(s21_decimal* dcml) {
  while (GetExp(dcml) && !ModTen(dcml)) {
    DivTen(dcml);
    SetExp(dcml, GetExp(dcml) - 1);
  }
}

void DecimalSwap(s21_decimal* val1, s21_decimal* val2) {
  s21_decimal temp = *val1;
  *val1 = *val2;
  *val2 = temp;
}

int add_decimal_values(s21_decimal val1, s21_decimal val2,
                       s21_decimal* result) {
  ResetDecimal(result);
  int overflow = 0;
  for (int i = 0; i < SIZE - 1; ++i)
    for (int j = 0; j < BITS_SIZE; ++j)
      if (val1.bits[i] & (1 << j) && val2.bits[i] & (1 << j)) {
        if (overflow) result->bits[i] |= (1 << j);
        overflow = 1;
      } else if (val1.bits[i] & (1 << j) || val2.bits[i] & (1 << j)) {
        if (!overflow) result->bits[i] |= (1 << j);
      } else if (overflow) {
        result->bits[i] |= (1 << j);
        overflow = 0;
      }
  return overflow;
}

void sub_bits(int i, int j, s21_decimal* val1, s21_decimal* result) {
  if (!(val1->bits[i] & (1 << j))) {
    int k = 0;
    while (!(val1->bits[i] & (1 << j))) {
      shift(val1, 1);
      ++k;
    }
    val1->bits[i] &= ~(1 << j);
    for (int z = 0; z < k; ++z) {
      shift(val1, -1);
      val1->bits[i] |= (1 << j);
    }
    result->bits[i] |= (1 << j);
  }
}

int sub_decimal_values(s21_decimal val1, s21_decimal val2,
                       s21_decimal* result) {
  ResetDecimal(result);
  for (int i = 0; i < SIZE - 1; ++i)
    for (int j = 0; j < BITS_SIZE; ++j)
      if (val2.bits[i] & (1 << j)) {
        sub_bits(i, j, &val1, result);
      } else if (val1.bits[i] & (1 << j)) {
        result->bits[i] |= (1 << j);
      }
  return 0;
}

int CheckOverflow(s21_decimal val1, int bit_count, s21_decimal* result) {
  int err = 0;
  s21_decimal v1_shifted = val1;
  for (int i = 0; i < bit_count; ++i)
    if (v1_shifted.bits[2] & (1 << 31)) {
      err = 1;
      break;
    } else
      shift(&v1_shifted, -1);
  if (!err) err = add_decimal_values(v1_shifted, *result, result);
  return err;
}

int mult_decimal_values(s21_decimal val1, s21_decimal val2,
                        s21_decimal* result) {
  int err = 0;
  ResetDecimal(result);
  int bit_count = 0;
  for (int i = 0; i < SIZE - 1; ++i) {
    for (int j = 0; j < BITS_SIZE; ++j) {
      if (val2.bits[i] & (1 << j)) {
        err = CheckOverflow(val1, bit_count, result);
      }
      if (err) break;
      ++bit_count;
    }
    if (err) break;
  }
  return err;
}

int MultTen(s21_decimal* dcml) {
  int err = 0;
  s21_decimal temp_dcml_s_1 = *dcml;
  s21_decimal temp_dcml_s_3 = *dcml;
  if (dcml->bits[2] & 7 << (BITS_SIZE - 1 - 2))
    err = 1;
  else
    shift(&temp_dcml_s_3, -3);
  if (!err) {
    shift(&temp_dcml_s_1, -1);
    s21_decimal result;
    err = add_decimal_values(temp_dcml_s_1, temp_dcml_s_3, &result);
    if (!err) {
      SetExp(&result, GetExp(dcml));
      SetSign(&result, GetSign(dcml));
      *dcml = result;
    }
  }
  return err;
}

void BringSamePowNotChange(s21_decimal* val1, s21_decimal* val2) {
  RemoveExtraZeros(val1);
  RemoveExtraZeros(val2);
  int err = 0;
  if (GetExp(val1) > GetExp(val2))
    while ((GetExp(val1) != GetExp(val2)) && !err) {
      err = MultTen(val2);
      if (!err) SetExp(val2, GetExp(val2) + 1);
    }
  else if (GetExp(val1) < GetExp(val2))
    while ((GetExp(val1) != GetExp(val2)) && !err) {
      err = MultTen(val1);
      if (!err) SetExp(val1, GetExp(val1) + 1);
    }
}

s21_decimal div_int(int i, int j, s21_decimal val1, s21_decimal val2,
                    s21_decimal* result) {
  s21_decimal tmp_dec;
  ResetDecimal(&tmp_dec);
  for (; i >= 0; --i) {
    for (; j >= 0; --j) {
      shift(&tmp_dec, -1);
      if (val1.bits[i] & (1 << j)) tmp_dec.bits[0] |= 1;
      shift(result, -1);
      if (s21_is_greater_or_equal(tmp_dec, val2)) {
        result->bits[0] |= 1;
        s21_sub(tmp_dec, val2, &tmp_dec);
      }
      if (result->bits[2] & (1 << 31)) break;
    }
    if (result->bits[2] & (1 << 31)) break;
    j = 31;
  }
  return tmp_dec;
}

int div_remainder(int* exp, s21_decimal* tmp_dec, s21_decimal val2,
                  s21_decimal* result) {
  int err = MultTen(tmp_dec);
  if (!err) {
    int count = 0;
    while (s21_is_greater_or_equal(*tmp_dec, val2)) {
      sub_decimal_values(*tmp_dec, val2, tmp_dec);
      ++count;
    }
    err = MultTen(result);
    if (!err) {
      s21_decimal dec_count;
      s21_from_int_to_decimal(count, &dec_count);
      err = add_decimal_values(*result, dec_count, result);
      SetExp(result, GetExp(result) + 1);
      if (err) {
        if (count > 5 || (count == 5 && ModTen(result) % 2)) {
          s21_decimal dec_one;
          s21_from_int_to_decimal(1, &dec_one);
          add_decimal_values(*result, dec_one, result);
        }
      } else {
        ++(*exp);
      }
    } else {
      if (count > 5 || (count == 5 && ModTen(result) % 2)) {
        s21_decimal dec_one;
        s21_from_int_to_decimal(1, &dec_one);
        add_decimal_values(*result, dec_one, result);
      }
    }
  }
  return err;
}

int div_decimal_values(s21_decimal val1, s21_decimal val2,
                       s21_decimal* result) {
  int err = 0;
  val1.bits[3] = 0;
  val2.bits[3] = 0;
  ResetDecimal(result);
  int i = 2, j = 31;
  while (!(val1.bits[i] & (1 << j)) && (i >= 0)) {
    --j;
    if (j == -1) {
      --i;
      j = 31;
    }
  }
  if (i >= 0) {
    s21_decimal tmp_dec = div_int(i, j, val1, val2, result);
    int exp = 0;
    while (!decimal_is_null(&tmp_dec) && !err) {
      err = div_remainder(&exp, &tmp_dec, val2, result);
    }
    SetExp(result, exp);
  }
  return 0;
}

void RoundLastDigit(s21_decimal* dcml) {
  int remainder = ModTen(dcml);
  DivTen(dcml);
  SetExp(dcml, GetExp(dcml) - 1);
  if ((remainder == 5 && (ModTen(dcml) % 2)) || remainder > 5) {
    s21_decimal result;
    s21_decimal one;
    s21_from_int_to_decimal(1, &one);
    int err = add_decimal_values(*dcml, one, &result);
    if (!err) {
      SetSign(&result, GetSign(dcml));
      SetExp(&result, GetExp(dcml));
      *dcml = result;
    }
  }
}

void BringSamePow(s21_decimal* val1, s21_decimal* val2) {
  BringSamePowNotChange(val1, val2);
  while (GetExp(val1) > GetExp(val2)) RoundLastDigit(val1);
  while (GetExp(val1) < GetExp(val2)) RoundLastDigit(val2);
}

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  int err = 0;
  if (!GetSign(&value_1) && GetSign(&value_2)) {
    SetSign(&value_2, 0);
    err = s21_sub(value_1, value_2, result);
  } else if (GetSign(&value_1) && !GetSign(&value_2)) {
    SetSign(&value_1, 0);
    err = s21_sub(value_2, value_1, result);
  } else if (GetExp(&value_1) == GetExp(&value_2)) {
    err = add_decimal_values(value_1, value_2, result);
    while (err && GetExp(&value_1)) {
      RoundLastDigit(&value_1);
      RoundLastDigit(&value_2);
      err = add_decimal_values(value_1, value_2, result);
    }
    if (!err) {
      SetSign(result, GetSign(&value_1));
      SetExp(result, GetExp(&value_1));
      RemoveExtraZeros(result);
    } else {
      err = GetSign(&value_1) ? 2 : err;
      ResetDecimal(result);
    }
  } else {
    BringSamePow(&value_1, &value_2);
    s21_add(value_1, value_2, result);
  }
  return err;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  int err = 0;
  if (!GetSign(&value_1) && GetSign(&value_2)) {
    SetSign(&value_2, 0);
    err = s21_add(value_1, value_2, result);
  } else if (GetSign(&value_1) && !GetSign(&value_2)) {
    SetSign(&value_1, 0);
    err = s21_add(value_2, value_1, result);
    SetSign(result, 1);
    if (err == 1) err = 2;
  } else if (GetExp(&value_1) == GetExp(&value_2)) {
    int neg = 0;
    if (s21_is_greater(value_2, value_1)) {
      neg = 1;
      DecimalSwap(&value_1, &value_2);
    }
    sub_decimal_values(value_1, value_2, result);
    SetExp(result, GetExp(&value_1));
    if (neg) SetSign(result, 1);
    RemoveExtraZeros(result);
  } else {
    BringSamePow(&value_1, &value_2);
    s21_sub(value_1, value_2, result);
  }
  return err;
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  int err = 0;
  s21_decimal one;
  s21_from_int_to_decimal(1, &one);
  int minus = GetSign(&value_2);
  SetSign(&value_2, 0);
  if (s21_is_less(value_2, one) && !decimal_is_null(&value_2)) {
    SetSign(&value_2, minus);
    s21_decimal temp;
    s21_from_int_to_decimal(1, &temp);
    while (GetExp(&value_2)) {
      MultTen(&temp);
      SetExp(&value_2, GetExp(&value_2) - 1);
    }
    s21_decimal divider;
    s21_div(temp, value_2, &divider);
    err = s21_div(value_1, divider, result);
  } else if (GetExp(&value_1) == GetExp(&value_2)) {
    SetSign(&value_2, minus);
    minus = 0;
    if ((GetSign(&value_1) || GetSign(&value_2)) &&
        (!GetSign(&value_1) || !GetSign(&value_2)))
      minus = 1;
    SetSign(&value_1, 0);
    SetSign(&value_2, 0);
    if (s21_is_less(value_1, value_2)) DecimalSwap(&value_1, &value_2);
    err = mult_decimal_values(value_1, value_2, result);
    while (err && GetExp(&value_1)) {
      RoundLastDigit(&value_1);
      RoundLastDigit(&value_2);
      err = mult_decimal_values(value_1, value_2, result);
    }
    if (!err) {
      SetExp(result, GetExp(&value_1) + GetExp(&value_2));
      SetSign(result, minus);
      RemoveExtraZeros(result);
    } else
      err = minus ? 2 : err;
  } else {
    SetSign(&value_2, minus);
    BringSamePow(&value_1, &value_2);
    s21_mul(value_1, value_2, result);
  }
  return err;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  int err = 0;
  s21_decimal one;
  s21_from_int_to_decimal(1, &one);
  int minus = GetSign(&value_2);
  SetSign(&value_2, 0);
  if (decimal_is_null(&value_2))
    err = 3;
  else if (decimal_is_null(&value_1))
    ResetDecimal(result);
  else if (s21_is_less(value_2, one) && !decimal_is_null(&value_2)) {
    SetSign(&value_2, minus);
    s21_decimal temp;
    s21_from_int_to_decimal(1, &temp);
    while (GetExp(&value_2)) {
      MultTen(&temp);
      SetExp(&value_2, GetExp(&value_2) - 1);
    }
    s21_decimal factor;
    s21_div(temp, value_2, &factor);
    err = s21_mul(value_1, factor, result);
  } else if (GetExp(&value_1) == GetExp(&value_2)) {
    SetSign(&value_2, minus);
    int neg = 0;
    if (GetSign(&value_1) != GetSign(&value_2)) neg = 1;
    div_decimal_values(value_1, value_2, result);
    if (decimal_is_null(result)) {
      err = 2;
    } else {
      SetSign(result, neg);
      RemoveExtraZeros(result);
    }
  } else {
    SetSign(&value_2, minus);
    BringSamePow(&value_1, &value_2);
    if (decimal_is_null(&value_1))
      err = 2;
    else
      err = s21_div(value_1, value_2, result);
  }
  return err;
}

int s21_is_less(s21_decimal val1, s21_decimal val2) {
  int result = -1;
  if (decimal_is_null(&val1) && decimal_is_null(&val2)) {
    result = 0;
  } else if (GetSign(&val1) != GetSign(&val2)) {
    result = GetSign(&val1) ? 1 : 0;
  } else if (GetExp(&val1) == GetExp(&val2)) {
    for (int i = SIZE - 2; i >= 0; --i) {
      for (int j = BITS_SIZE - 1; j >= 0; --j)
        if ((val1.bits[i] & (1 << j)) && !(val2.bits[i] & (1 << j))) {
          result = GetSign(&val1) ? 1 : 0;
          break;
        } else if (!(val1.bits[i] & (1 << j)) && (val2.bits[i] & (1 << j))) {
          result = GetSign(&val1) ? 0 : 1;
          break;
        }
      if (result == 0 || result == 1) break;
    }
  } else {
    BringSamePowNotChange(&val1, &val2);
    if (GetExp(&val1) == GetExp(&val2)) {
      result = s21_is_less(val1, val2);
    } else {
      if (GetExp(&val1) > GetExp(&val2))
        result = GetSign(&val1) ? 0 : 1;
      else
        result = GetSign(&val1) ? 1 : 0;
    }
  }
  return result == -1 ? 0 : result;
}

int s21_is_less_or_equal(s21_decimal val1, s21_decimal val2) {
  return s21_is_less(val1, val2) || s21_is_equal(val1, val2);
}

int s21_is_greater(s21_decimal val1, s21_decimal val2) {
  return !s21_is_less_or_equal(val1, val2);
}

int s21_is_greater_or_equal(s21_decimal val1, s21_decimal val2) {
  return !s21_is_less(val1, val2);
}

int s21_is_equal(s21_decimal val1, s21_decimal val2) {
  int result = 1;
  RemoveExtraZeros(&val1);
  RemoveExtraZeros(&val2);
  if (decimal_is_null(&val1) && decimal_is_null(&val2)) {
    result = 1;
  } else if (GetSign(&val1) != GetSign(&val2)) {
    result = 0;
  } else if (GetExp(&val1) == GetExp(&val2)) {
    for (int i = 0; i < SIZE - 1; ++i) {
      if (val1.bits[i] != val2.bits[i]) {
        result = 0;
        break;
      }
    }
  } else {
    result = 0;
  }
  return result;
}

int s21_is_not_equal(s21_decimal val1, s21_decimal val2) {
  return !s21_is_equal(val1, val2);
}

int s21_from_int_to_decimal(int src, s21_decimal* dst) {
  int is_neg = src < 0;
  src = is_neg ? -src : src;
  ResetDecimal(dst);
  dst->bits[0] = src;
  SetSign(dst, is_neg);
  return 0;
}

int s21_from_float_to_decimal(float src, s21_decimal* dst) {
  ResetDecimal(dst);
  if (fabs(src) < 1e-28f || fabs(src) > 79228162514264337593543950335.f ||
      isinf(src) || isnan(src))
    return 1;
  int neg = src < 0 ? 1 : 0;
  double temp = fabs(src);
  int degree = 0;
  while (temp > 10. || fabs(temp - 10.) < 1e-6) {
    temp /= 10.;
    ++degree;
  }
  while (temp < 1.) {
    temp *= 10.;
    --degree;
  }
  double pow_deg = 1.;
  int temp_degree = degree;
  while (temp_degree) {
    pow_deg *= temp_degree > 0 ? 10. : 0.1;
    temp_degree += temp_degree > 0 ? -1 : 1;
  }
  temp = fabs(src);
  temp_degree = degree;
  for (int i = 0; i < 7 && temp_degree > -29; ++i) {
    --temp_degree;
    dst->bits[0] *= 10;
    dst->bits[0] += (int)(temp / pow_deg);
    temp -= (int)(temp / pow_deg) * pow_deg;
    pow_deg /= 10.;
  }
  int remainder = (int)(temp / pow_deg);
  if ((remainder == 5 && ((dst->bits[0] % 10) % 2)) || remainder > 5)
    dst->bits[0] += 1;
  if (degree >= 7) {
    for (int i = 7; i <= degree; ++i) MultTen(dst);
  } else if (degree > 0) {
    SetExp(dst, 6 - degree);
  } else {
    SetExp(dst, -degree + 6 > 28 ? 28 : -degree + 6);
  }
  SetSign(dst, neg);
  return 0;
}

int s21_from_decimal_to_int(s21_decimal src, int* dst) {
  s21_decimal dec_int;
  s21_truncate(src, &dec_int);
  int err = 0;
  if (GetSign(&src)) {
    s21_decimal dec_int_min;
    s21_from_int_to_decimal(INT_MIN, &dec_int_min);
    if (s21_is_less(src, dec_int_min)) err = 1;
  } else {
    s21_decimal dec_int_max;
    s21_from_int_to_decimal(INT_MAX, &dec_int_max);
    if (s21_is_greater(src, dec_int_max)) err = 1;
  }
  if (!err) {
    *dst = 0;
    int pow = 1;
    while (!decimal_is_null(&dec_int)) {
      if (GetSign(&src))
        *dst -= pow * ModTen(&dec_int);
      else
        *dst += pow * ModTen(&dec_int);
      pow *= 10;
      DivTen(&dec_int);
    }
  }
  return err;
}

int s21_from_decimal_to_float(s21_decimal src, float* dst) {
  *dst = 0;
  double temp = 0;
  double degree = 1.;
  while (!decimal_is_null(&src)) {
    temp += ModTen(&src) * degree;
    DivTen(&src);
    degree *= 10.;
  }
  for (int i = 0; i < GetExp(&src); ++i) temp /= 10.;
  temp *= GetSign(&src) ? -1.0 : 1.0;
  *dst = temp;
  return 0;
}

int s21_floor(s21_decimal value, s21_decimal* result) {
  int err = 0;
  RemoveExtraZeros(&value);
  if (GetExp(&value)) {
    s21_truncate(value, &value);
    int neg = 0;
    if (GetSign(&value)) {
      neg = 1;
      s21_decimal one;
      s21_from_int_to_decimal(1, &one);
      add_decimal_values(value, one, &value);
    }
    *result = value;
    SetSign(result, neg);
  } else {
    *result = value;
  }
  return err;
}

int s21_round(s21_decimal value, s21_decimal* result) {
  *result = value;
  while (GetExp(result)) RoundLastDigit(result);
  return 0;
}

int s21_truncate(s21_decimal value, s21_decimal* result) {
  *result = value;
  while (GetExp(result)) {
    DivTen(result);
    SetExp(result, GetExp(result) - 1);
  }
  return 0;
}

int s21_negate(s21_decimal value, s21_decimal* result) {
  *result = value;
  SetSign(result, GetSign(result) ? 0 : 1);
  return 0;
}
