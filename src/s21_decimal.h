#ifndef S21_DECIMAL  // S21_DECIMAL
#define S21_DECIMAL  // S21_DECIMAL

#define SIZE 4

typedef struct {
  int bits[SIZE];
} s21_decimal;

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);

int s21_is_less(s21_decimal, s21_decimal);
int s21_is_less_or_equal(s21_decimal, s21_decimal);
int s21_is_greater(s21_decimal, s21_decimal);
int s21_is_greater_or_equal(s21_decimal, s21_decimal);
int s21_is_equal(s21_decimal, s21_decimal);
int s21_is_not_equal(s21_decimal, s21_decimal);

int s21_from_int_to_decimal(int src, s21_decimal* dst);
int s21_from_float_to_decimal(float src, s21_decimal* dst);
int s21_from_decimal_to_int(s21_decimal src, int* dst);
int s21_from_decimal_to_float(s21_decimal src, float* dst);

int s21_floor(s21_decimal value, s21_decimal* result);
int s21_round(s21_decimal value, s21_decimal* result);
int s21_truncate(s21_decimal value, s21_decimal* result);
int s21_negate(s21_decimal value, s21_decimal* result);

// void SetExp(s21_decimal* dcml, const int exp);//delete
// void ResetDecimal(s21_decimal* dcml);//delete
void PrintDecimalBinary(s21_decimal* dcml);  // delete
void PrintDecimalDec(s21_decimal dcml);      // delete
// void shift(s21_decimal* dcml, int count);//delete
// void left_shift(s21_decimal* dcml, int count);//delete
// void right_shift(s21_decimal* dcml, int count);//delete
// void DivTen(s21_decimal* dcml);//delete
// int ModTen(s21_decimal* dcml);//delete
// int MultTen(s21_decimal* dcml);//delete
// int GetExp(const s21_decimal* dcml);//delete
// int GetSign(const s21_decimal* dcml);//delete

#endif  // S21_DECIMAL
