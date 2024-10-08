#include <check.h>
#include <ctype.h>
#include <stdio.h>

#include "s21_decimal.h"

#define MAX_DEC powf(2.0f, 96.0f) - 1.0
#define MIN_DEC -powf(2.0f, 96.0f) + 1.0

/////////////---------int_to_dec---------///////////////

START_TEST(int_to_dec_1) {
  s21_decimal result, origin;
  int src = 1;
  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_2) {
  s21_decimal result, origin;
  int src = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_3) {
  s21_decimal result, origin;
  int src = -1;
  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_4) {
  s21_decimal result, origin;
  int src = 2147483647;
  origin.bits[0] = 0b01111111111111111111111111111111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_5) {
  s21_decimal result, origin;
  int src = -2147483647;
  origin.bits[0] = 0b01111111111111111111111111111111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_6) {
  s21_decimal result, origin;
  int src = -12345;
  origin.bits[0] = 0b00000000000000000011000000111001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_7) {
  s21_decimal result, origin;
  int src = -12345;
  origin.bits[0] = 0b00000000000000000011000000111001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_8) {
  s21_decimal result, origin;
  int src = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_9) {
  s21_decimal result, origin;
  int src = 45678;
  origin.bits[0] = 0b00000000000000001011001001101110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_10) {
  s21_decimal result, origin;
  int src = -45678;
  origin.bits[0] = 0b00000000000000001011001001101110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_11) {
  s21_decimal result, origin;
  int src = 5555555;
  origin.bits[0] = 0b00000000010101001100010101100011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_12) {
  s21_decimal result, origin;
  int src = -5555555;
  origin.bits[0] = 0b00000000010101001100010101100011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_13) {
  s21_decimal result, origin;
  int src = 127;
  origin.bits[0] = 0b00000000000000000000000001111111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_14) {
  s21_decimal result, origin;
  int src = -127;
  origin.bits[0] = 0b00000000000000000000000001111111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_15) {
  s21_decimal result, origin;
  int src = 34567898;
  origin.bits[0] = 0b00000010000011110111011011011010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_16) {
  s21_decimal result, origin;
  int src = -34567898;
  origin.bits[0] = 0b00000010000011110111011011011010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_17) {
  s21_decimal result, origin;
  int src = 999;
  origin.bits[0] = 0b00000000000000000000001111100111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_18) {
  s21_decimal result, origin;
  int src = -999;
  origin.bits[0] = 0b00000000000000000000001111100111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_19) {
  s21_decimal result, origin;
  int src = -3254754;
  origin.bits[0] = 0b00000000001100011010100111100010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_20) {
  s21_decimal result, origin;
  int src = 3436425;
  origin.bits[0] = 0b00000000001101000110111110001001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_21) {
  s21_decimal result, origin;
  int src = 222222222;
  origin.bits[0] = 0b00001101001111101101011110001110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

/////////////---------dec_to_int---------///////////////

START_TEST(dec_to_int_1) {
  s21_decimal src;
  src.bits[0] = 0b00000000000000000000000000110010;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  int result = 0;
  int origin = 5;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_2) {
  s21_decimal src;
  src.bits[0] = 0b00000000000000000000000000100010;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  int result = 0;
  int origin = 3;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_3) {
  s21_decimal src;
  src.bits[0] = 0b00000000000000000000000000000000;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  int result = 0;
  int origin = 0;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_4) {
  s21_decimal src;
  src.bits[0] = 0b00000001011100111100000111000111;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000001110000000000000000;
  int result = 0;
  int origin = -2;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_5) {
  s21_decimal src;
  src.bits[0] = 0b00000000000000000000000000000000;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000000010000000000000000;
  int result = 0;
  int origin = 0;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_7) {
  s21_decimal src;
  src.bits[0] = 0b00000011111000110110011011000111;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000001010000000000000000;
  int result = 0;
  int origin = 652;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_8) {
  s21_decimal src;
  src.bits[0] = 0b00011101101010010010000100011011;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000010000000000000000000;
  int result = 0;
  int origin = 4;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_9) {
  s21_decimal src;
  src.bits[0] = 0b10000111010110110010011111110011;
  src.bits[1] = 0b00000000000000000000000000000001;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000100000000000000000;
  int result = 0;
  int origin = 65658654;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_10) {
  s21_decimal src;
  src.bits[0] = 0b00010101101111011001110101001110;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000000110000000000000000;
  int result = 0;
  int origin = -364748;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_11) {
  s21_decimal src;
  src.bits[0] = 0b01101000011010011010001100101111;
  src.bits[1] = 0b00000000000000000001001000010011;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000011010000000000000000;
  int result = 0;
  int origin = 1;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_12) {
  s21_decimal src;
  src.bits[0] = 0b00010110010010101110101011000000;
  src.bits[1] = 0b00000000000000000000100011111100;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000010110000000000000000;
  int result = 0;
  int origin = -98;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_13) {
  s21_decimal src;
  src.bits[0] = 0b00111011100110101100100111111001;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  int result = 0;
  int origin = 99999999;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_14) {
  s21_decimal src;
  src.bits[0] = 0b11001010011010010001110011000010;
  src.bits[1] = 0b10011001110101001010110100100110;
  src.bits[2] = 0b10110000001111100010111010011101;
  src.bits[3] = 0b10000000000101110000000000000000;
  int result = 0;
  int origin = -545445;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_15) {
  s21_decimal src;
  src.bits[0] = 0b11101010011100001110100101000111;
  src.bits[1] = 0b10100010011001110000111100001010;
  src.bits[2] = 0b10110000001111101111000100010000;
  src.bits[3] = 0b00000000000101100000000000000000;
  int result = 0;
  int origin = 5454545;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_16) {
  s21_decimal src;
  src.bits[0] = 0b11101010001011100110110001010100;
  src.bits[1] = 0b00100111000110111110101011111001;
  src.bits[2] = 0b00011001101111000001110101101001;
  src.bits[3] = 0b00000000000101000000000000000000;
  int result = 0;
  int origin = 79645421;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_17) {
  s21_decimal src;
  src.bits[0] = 0b10010001000010101111010011001010;
  src.bits[1] = 0b11000000010001011101010111110010;
  src.bits[2] = 0b00100111111001000001101100000000;
  src.bits[3] = 0b00000000000101010000000000000000;
  int result = 0;
  int origin = 12345677;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_18) {
  s21_decimal src;
  src.bits[0] = 0b10010001000010101111010011001010;
  src.bits[1] = 0b11000000010001011101010111110010;
  src.bits[2] = 0b00100111111001000001101100000000;
  src.bits[3] = 0b10000000000101010000000000000000;
  int result = 0;
  int origin = -12345677;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_19) {
  s21_decimal src;
  src.bits[0] = 0b10011100101100011101000110000101;
  src.bits[1] = 0b01100001100101011101011101110110;
  src.bits[2] = 0b00000000000000000000000011101010;
  src.bits[3] = 0b00000000000100000000000000000000;
  int result = 0;
  int origin = 432356;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_20) {
  s21_decimal src;
  src.bits[0] = 0b01100001011111010111001111001001;
  src.bits[1] = 0b00000000100111100100000111010001;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000010010000000000000000;
  int result = 0;
  int origin = 44545413;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_21) {
  s21_decimal src;
  src.bits[0] = 0b01011100000110001011011001101010;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000000000000000000000000;
  int result = 0;
  int origin = -1545123434;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_23) {
  s21_decimal src;
  src.bits[0] = 0b10101001101110110110011111111111;
  src.bits[1] = 0b00001010111111101100000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000011000000000000000000;
  int result = 0;
  int origin = 792281;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_24) {
  s21_decimal src;
  src.bits[0] = 0b11111110100100001101100101011111;
  src.bits[1] = 0b10000100011001000010000111101000;
  src.bits[2] = 0b00000000000000000000000000000001;
  src.bits[3] = 0b00000000000100110000000000000000;
  int result = 0;
  int origin = 2;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

/////////////---------add---------///////////////

START_TEST(s21_add_1) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 3;
  // src2 = 3;
  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_2) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 10;
  // src2 = 21;
  src1.bits[0] = 0b00000000000000000000000000001010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000010101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000011111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_3) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 5;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_4) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 0;
  src1.bits[0] = 0b0000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_6) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -2;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_7) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 6521;
  // src2 = 74120;
  src1.bits[0] = 0b00000000000000000001100101111001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000010010000110001000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000010011101100000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_8) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 4;
  // src2 = 97623323;
  src1.bits[0] = 0b00000000000000000000000000000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000101110100011001110100011011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000101110100011001110100011111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_9) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 65658654;
  // src2 = 5;
  src1.bits[0] = 0b00000011111010011101111100011110;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000011111010011101111100100011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_10) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -364748;
  // src2 = 1;
  src1.bits[0] = 0b00000000000001011001000011001100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000001011001000011001011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_11) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 1;
  // src2 = 98745654321;
  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111101101100110001110000110001;
  src2.bits[1] = 0b00000000000000000000000000010110;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11111101101100110001110000110010;
  origin.bits[1] = 0b00000000000000000000000000010110;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_12) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -9878798789;
  // src2 = -3;
  src1.bits[0] = 0b01001100110100101000000111000101;
  src1.bits[1] = 0b00000000000000000000000000000010;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b01001100110100101000000111001000;
  origin.bits[1] = 0b00000000000000000000000000000010;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_13) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 9999999999999999999;
  // src2 = 1;
  src1.bits[0] = 0b10001001111001111111111111111111;
  src1.bits[1] = 0b10001010110001110010001100000100;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b10001001111010000000000000000000;
  origin.bits[1] = 0b10001010110001110010001100000100;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_14) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 18446744073709551615;
  // src2 = 1;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000001;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_15) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 18446744073709551615.0;
  // src2 = 965453154;
  src1.bits[0] = 0b11111111111111111111111111110110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000001001;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b00111001100010111010010101100010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00111001100010111010010101100001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000001;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_16) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -545454512454545.35265454545645;
  // src2 = 54564654;
  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;
  src2.bits[0] = 0b00000011010000001001011100101110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b01110001001010101101101011101101;
  origin.bits[1] = 0b00101110001111001110000111111000;
  origin.bits[2] = 0b10110000001111101110111101101101;
  origin.bits[3] = 0b10000000000011100000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_18) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 7961327845421.879754123131254;
  // src2 = 0;
  src1.bits[0] = 0b01001110111001000011100101110110;
  src1.bits[1] = 0b01001011001101011010000111011001;
  src1.bits[2] = 0b00011001101110010111010010111111;
  src1.bits[3] = 0b00000000000011110000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b01001110111001000011100101110110;
  origin.bits[1] = 0b01001011001101011010000111011001;
  origin.bits[2] = 0b00011001101110010111010010111111;
  origin.bits[3] = 0b00000000000011110000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_23) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_24) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_25) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_27) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 7922816251427554395;
  // src2 = 65645646;
  src1.bits[0] = 0b01011111000010000000010001011011;
  src1.bits[1] = 0b01101101111100110111111101100111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000011111010011010110001001110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b01100010111100011011000010101001;
  origin.bits[1] = 0b01101101111100110111111101100111;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_28) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 665464545;
  // src2 = 8798232189789785;
  src1.bits[0] = 0b00100111101010100010111011100001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00010000010100101110011001011001;
  src2.bits[1] = 0b00000000000111110100000111110010;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00110111111111010001010100111010;
  origin.bits[1] = 0b00000000000111110100000111110010;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_29) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 2.7986531268974139743;
  // src2 = 9.979623121254565121244554;
  src1.bits[0] = 0b11111110100100001101100101011111;
  src1.bits[1] = 0b10000100011001000010000111101000;
  src1.bits[2] = 0b00000000000000000000000000000001;
  src1.bits[3] = 0b00000000000100110000000000000000;
  src2.bits[0] = 0b11010100101011100011110110001010;
  src2.bits[1] = 0b01110100000101000010011110100011;
  src2.bits[2] = 0b00000000000010000100000101000100;
  src2.bits[3] = 0b00000000000110000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b10011010010111001101001011101010;
  origin.bits[1] = 0b10111110010100100100110100010011;
  origin.bits[2] = 0b00000000000010101001000111100111;
  origin.bits[3] = 0b00000000000110000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_30) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -9798956154578676.797564534156;
  // src2 = -2156878451.854764;
  src1.bits[0] = 0b01010100010000000011110110001100;
  src1.bits[1] = 0b10001011010100100000010101011001;
  src1.bits[2] = 0b00011111101010011000000110101101;
  src1.bits[3] = 0b10000000000011000000000000000000;
  src2.bits[0] = 0b01100101111100100100110110101100;
  src2.bits[1] = 0b00000000000001111010100110101011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001100000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11010101111011100000000010001100;
  origin.bits[1] = 0b01111000000001011001100110101101;
  origin.bits[2] = 0b00011111101010011000001000100010;
  origin.bits[3] = 0b10000000000011000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_31) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0.5456465465486476846545465485;
  // src2 = 0.68985125146545154;
  src1.bits[0] = 0b00001011000011110111000010001101;
  src1.bits[1] = 0b10010110101100000101100101010001;
  src1.bits[2] = 0b00010001101000010111101110000001;
  src1.bits[3] = 0b00000000000111000000000000000000;
  src2.bits[0] = 0b00010111001001010100110000000010;
  src2.bits[1] = 0b00000000111101010001010110011011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000100010000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b01110000110111010100000010001101;
  origin.bits[1] = 0b01011010100111011110001100001010;
  origin.bits[2] = 0b00100111111010111100110001011010;
  origin.bits[3] = 0b00000000000111000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_36) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = -37986322154988653.784354545765;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b01001111101101000110000001100101;
  src2.bits[1] = 0b01000010001101101011011001100001;
  src2.bits[2] = 0b01111010101111011000110010011010;
  src2.bits[3] = 0b10000000000011000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b01001111101101000110000001100101;
  origin.bits[1] = 0b01000010001101101011011001100001;
  origin.bits[2] = 0b01111010101111011000110010011010;
  origin.bits[3] = 0b10000000000011000000000000000000;
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_37) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -2;
  // src2 = 5;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_40) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -79228162514264337593543950335;
  // src2 = 79228162514264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_41) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -2;
  // src2 = 2;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_44) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 546378;
  // src2 = 0;
  src1.bits[0] = 0b00000000000010000101011001001010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000010000101011001001010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_45) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 8976545415646545.5746845454;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11011101111000010000101100001110;
  src2.bits[1] = 0b00000101010000010110101000000010;
  src2.bits[2] = 0b00000000010010100100000010010011;
  src2.bits[3] = 0b00000000000010100000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11011101111000010000101100001110;
  origin.bits[1] = 0b00000101010000010110101000000010;
  origin.bits[2] = 0b00000000010010100100000010010011;
  origin.bits[3] = 0b00000000000010100000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_51) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 1;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_52) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_53) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 20;
  // src2 = -2;
  src1.bits[0] = 0b00000000000000000000000000010100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000010100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000010000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000010010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_54) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 1;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_add_55) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  src1.bits[0] = 1;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0;

  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b00000000000000010000000000000000;
  value_type_result = s21_add(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b10011001100110011001100110011011;
  origin.bits[1] = 0b10011001100110011001100110011001;
  origin.bits[2] = 0b00011001100110011001100110011001;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(add_test_1) {
  int num1 = 42;
  int num2 = 30;
  int sum_int = 72;
  s21_decimal a, b;
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);
  ck_assert_int_eq(s21_add(a, b, &res_dec), 0);
}
END_TEST

START_TEST(add_test_2) {
  int num1 = 1000;
  int num2 = 2000;
  int sum_int = 3000;
  s21_decimal a, b;
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);
}
END_TEST

START_TEST(add_test_3) {
  int num1 = 0;
  int num2 = 0;
  int sum_int = 0;
  s21_decimal a, b;
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);
}
END_TEST

START_TEST(add_test_4) {
  int num1 = -15;
  int num2 = 5;
  int sum_int = -10;
  s21_decimal a, b;
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);
}
END_TEST

START_TEST(add_test_5) {
  int num1 = 11115;
  int num2 = 5;
  int sum_int = 11120;
  s21_decimal a, b;
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);
}
END_TEST

START_TEST(add_test_6) {
  int num1 = -1;
  int num2 = -10;
  int sum_int = -11;
  s21_decimal a, b;
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);
}
END_TEST

START_TEST(add_test_7) {
  s21_decimal src1, src2;
  int a = -1234;
  int b = 234;
  int res_origin = -1000;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(add_test_8) {
  s21_decimal src1, src2;
  int a = -9403;
  int b = 234;
  int res_origin = -9169;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(add_test_9) {
  s21_decimal src1, src2;
  int a = 9403;
  int b = 202;
  int res_origin = 9605;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(add_test_10) {
  s21_decimal src1, src2;
  int a = 450;
  int b = -50;
  int res_origin = 400;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(add_test_11) {
  s21_decimal src1, src2;
  float num1 = 7.25;
  float num2 = 9.5;
  float res_origin = 16.75;
  s21_from_float_to_decimal(num1, &src1);
  s21_from_float_to_decimal(num2, &src2);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(add_test_12) {
  s21_decimal src1, src2;
  int num1 = -1234;
  float num2 = 1.234;
  float res_origin = -1232.766;
  s21_from_int_to_decimal(num1, &src1);
  s21_from_float_to_decimal(num2, &src2);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(add_test_13) {
  s21_decimal src1, src2;
  int num1 = -1234;
  float num2 = -1.234;
  float res_origin = -1235.234;
  s21_from_int_to_decimal(num1, &src1);
  s21_from_float_to_decimal(num2, &src2);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(add_test_14) {
  s21_decimal src1, src2;
  float num1 = -94;
  float num2 = 0.00234;
  float res_origin = num1 + num2;
  s21_from_float_to_decimal(num1, &src1);
  s21_from_float_to_decimal(num2, &src2);
  s21_decimal res_dec = {0};
  float res_float;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(add_test_15) {
  s21_decimal src1, src2;
  float num1 = -940.3;
  float num2 = 0.000234;
  float res_origin = -940.299766;
  s21_from_float_to_decimal(num1, &src1);
  s21_from_float_to_decimal(num2, &src2);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(add_test_16) {
  s21_decimal src1, src2;
  float num1 = -0.9403;
  float num2 = 0.000234;
  float res_origin = -0.940066;
  s21_from_float_to_decimal(num1, &src1);
  s21_from_float_to_decimal(num2, &src2);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(add_test_17) {
  s21_decimal src1, src2;
  float num1 = -0.9403;
  float num2 = 2.0234;
  float res_origin = num1 + num2;
  s21_from_float_to_decimal(num1, &src1);
  s21_from_float_to_decimal(num2, &src2);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq_tol(res_float, res_origin, 1e3);
}
END_TEST

START_TEST(add_test_18) {
  s21_decimal src1, src2;
  float num1 = -0.9403;
  float num2 = -112.0234;
  float res_origin = -112.9637;
  s21_from_float_to_decimal(num1, &src1);
  s21_from_float_to_decimal(num2, &src2);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(add_test_19) {
  s21_decimal src1, src2;
  float num1 = -0.94e03;
  float num2 = -112.0234;
  float res_origin = -1052.0234;
  s21_from_float_to_decimal(num1, &src1);
  s21_from_float_to_decimal(num2, &src2);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(add_test_20) {
  s21_decimal src1, src2;
  float num1 = -0.94e03;
  float num2 = -112.0e2;
  float res_origin = -12140;
  s21_from_float_to_decimal(num1, &src1);
  s21_from_float_to_decimal(num2, &src2);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(add_test_21) {
  s21_decimal dec1, dec2;
  int tmp1 = 100;
  int tmp2 = 99999;
  int res_s21 = 0;
  int res = 100099;
  s21_decimal res1;
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_int_to_decimal(tmp2, &dec2);
  s21_add(dec1, dec2, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(add_test_22) {
  s21_decimal dec1, dec2;
  int tmp1 = -100;
  int tmp2 = -99999;
  int res_s21 = 0;
  int res = -100099;
  s21_decimal res1;
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_int_to_decimal(tmp2, &dec2);
  s21_add(dec1, dec2, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(add_test_23) {
  s21_decimal dec1, dec2;
  int tmp1 = 2147483647;
  int tmp2 = -2147483647;
  int res_s21 = 0;
  int res = 0;
  s21_decimal res1;
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_int_to_decimal(tmp2, &dec2);
  s21_add(dec1, dec2, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(add_test_25) {
  s21_decimal dec1, dec2;
  int tmp1 = -2147483647;
  int tmp2 = 2147483647;
  int res_s21 = 0;
  int res = 0;
  s21_decimal res1;
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_int_to_decimal(tmp2, &dec2);
  s21_add(dec1, dec2, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(add_test_26) {
  long int tmp1 = 4294967295;
  s21_decimal dec1 = {{tmp1, tmp1, tmp1, 0}};
  s21_decimal dec2 = {{1, 0, 0, 0}};
  s21_decimal res1;
  int ret_s21 = s21_add(dec1, dec2, &res1);
  ck_assert_int_eq(1, ret_s21);
}
END_TEST

START_TEST(add_test_27) {
  long int tmp1 = 4294967295;
  int tmp2 = (1 << 31);
  s21_decimal dec1 = {{tmp1, tmp1, tmp1, tmp2}};
  s21_decimal dec2 = {{1, 0, 0, tmp2}};
  s21_decimal res1;
  int ret_s21 = s21_add(dec1, dec2, &res1);
  ck_assert_int_eq(2, ret_s21);
}
END_TEST

/////////////---------sub---------///////////////

START_TEST(s21_sub_1) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 5;
  // src2 = 3;
  src1.bits[0] = 0b00000000000000000000000000000101;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_2) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 3;
  // src2 = 6;
  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_3) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 8;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000001000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000001000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_4) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 7;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000111;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_6) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 3;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_7) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 787891;
  // src2 = 238471;
  src1.bits[0] = 0b00000000000011000000010110110011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000111010001110000111;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000010000110001000101100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_8) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 9;
  // src2 = 18571145;
  src1.bits[0] = 0b00000000000000000000000000001001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000001000110110101111110001001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000001000110110101111110000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_9) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 1849687;
  // src2 = 6;
  src1.bits[0] = 0b00000000000111000011100101010111;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000111000011100101010001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_10) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -3187878;
  // src2 = 1;
  src1.bits[0] = 0b00000000001100001010010010100110;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000001100001010010010100111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_11) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 1;
  // src2 = 18768768;
  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000001000111100110001110000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000001000111100110001101111111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_15) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 18446744073709551615.0;
  // src2 = 3556877454;
  src1.bits[0] = 0b11111111111111111111111111110110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000001001;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b11010100000000011010010010001110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00101011111111100101101101110001;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_16) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -54896651557845.352654545456455;
  // src2 = 21465;
  src1.bits[0] = 0b01110001100100011000110101000111;
  src1.bits[1] = 0b00001111010011100000001101011111;
  src1.bits[2] = 0b10110001011000010111001000100100;
  src1.bits[3] = 0b10000000000011110000000000000000;
  src2.bits[0] = 0b00000000000000000101001111011001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b01111001010101000000110101000111;
  origin.bits[1] = 0b00111001001100010000001100100101;
  origin.bits[2] = 0b10110001011000010111001000100101;
  origin.bits[3] = 0b10000000000011110000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_17) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 7961327845421.879754123131254;
  // src2 = 0;
  src1.bits[0] = 0b01001110111001000011100101110110;
  src1.bits[1] = 0b01001011001101011010000111011001;
  src1.bits[2] = 0b00011001101110010111010010111111;
  src1.bits[3] = 0b00000000000011110000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b01001110111001000011100101110110;
  origin.bits[1] = 0b01001011001101011010000111011001;
  origin.bits[2] = 0b00011001101110010111010010111111;
  origin.bits[3] = 0b00000000000011110000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_22) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_23) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_24) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_26) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 7922816251427554395;
  // src2 = 65645646;
  src1.bits[0] = 0b01011111000010000000010001011011;
  src1.bits[1] = 0b01101101111100110111111101100111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000011111010011010110001001110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b01011011000111100101100000001101;
  origin.bits[1] = 0b01101101111100110111111101100111;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_28) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 2.7986531268974139743;
  // src2 = 9.979623121254565121244554;
  src1.bits[0] = 0b11111110100100001101100101011111;
  src1.bits[1] = 0b10000100011001000010000111101000;
  src1.bits[2] = 0b00000000000000000000000000000001;
  src1.bits[3] = 0b00000000000100110000000000000000;
  src2.bits[0] = 0b11010100101011100011110110001010;
  src2.bits[1] = 0b01110100000101000010011110100011;
  src2.bits[2] = 0b00000000000010000100000101000100;
  src2.bits[3] = 0b00000000000110000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00001110111111111010100000101010;
  origin.bits[1] = 0b00101001110101100000001000110100;
  origin.bits[2] = 0b00000000000001011111000010100001;
  origin.bits[3] = 0b10000000000110000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_30) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0.5456465465486476846545465485;
  // src2 = 0.68985125146545154;
  src1.bits[0] = 0b00001011000011110111000010001101;
  src1.bits[1] = 0b10010110101100000101100101010001;
  src1.bits[2] = 0b00010001101000010111101110000001;
  src1.bits[3] = 0b00000000000111000000000000000000;
  src2.bits[0] = 0b00010111001001010100110000000010;
  src2.bits[1] = 0b00000000111101010001010110011011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000100010000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b01011010101111100101111101110011;
  origin.bits[1] = 0b00101101001111010011000001101000;
  origin.bits[2] = 0b00000100101010001101010101010111;
  origin.bits[3] = 0b10000000000111000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_35) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = -37986322154988653.784354545765;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b01001111101101000110000001100101;
  src2.bits[1] = 0b01000010001101101011011001100001;
  src2.bits[2] = 0b01111010101111011000110010011010;
  src2.bits[3] = 0b10000000000011000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b01001111101101000110000001100101;
  origin.bits[1] = 0b01000010001101101011011001100001;
  origin.bits[2] = 0b01111010101111011000110010011010;
  origin.bits[3] = 0b00000000000011000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_36) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 79228162513351883030198514100;
  // src2 = -912454563345436235;
  src1.bits[0] = 0b10110110000111000111000110110100;
  src1.bits[1] = 0b11110011010101100100111101101000;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b01001001111000111000111001001011;
  src2.bits[1] = 0b00001100101010011011000010010111;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11111111111111111111111111111111;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b11111111111111111111111111111111;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_39) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 79228162514264337593543950335;
  // src2 = 79228162514264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_51) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 1;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_52) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 1;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_53) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

/////////////---------is_less---------///////////////

START_TEST(s21_less_1) {
  s21_decimal first = {{4412, 5675, 1254, 0b10000000000000000000000000000000}};
  s21_decimal second = {{4412, 5675, 1254, 0b00000000000000000000000000000000}};
  ck_assert_int_eq(s21_is_less(first, second), 1);
}
END_TEST

START_TEST(s21_less_2) {
  s21_decimal first = {{4412, 5675, 1254, 0b00000000000000000000000000000000}};
  s21_decimal second = {{4412, 5675, 1254, 0b10000000000000000000000000000000}};
  ck_assert_int_eq(s21_is_less(first, second), 0);
}
END_TEST

START_TEST(s21_less_3_zero) {
  s21_decimal first = {{0, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal second = {{0, 0, 0, 0b10000000000000000000000000000000}};
  ck_assert_int_eq(s21_is_less(first, second), 0);
}
END_TEST

START_TEST(s21_less_4_zero) {
  s21_decimal first = {{0, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal second = {{0, 0, 0, 0b00000000000000000000000000000000}};
  ck_assert_int_eq(s21_is_less(first, second), 0);
}
END_TEST

START_TEST(s21_less_5_len_int_part) {
  s21_decimal first = {{0, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal second = {{0, 0, 0, 0b00000000000000000000000000000000}};
  ck_assert_int_eq(s21_is_less(first, second), 0);
}
END_TEST

START_TEST(s21_less_6_len_int_part_positive) {
  s21_decimal first = {{4412, 5675, 1254, 0b00000011000000000000000000000000}};
  s21_decimal second = {{4412, 5675, 1254, 0b00000101000000000000000000000000}};
  ck_assert_int_eq(s21_is_less(first, second), 0);
}
END_TEST

START_TEST(s21_less_7_len_int_part_negative) {
  s21_decimal first = {{4422, 5515, 9254, 0b10000000000000110000000000000000}};
  s21_decimal second = {{6312, 5616, 1844, 0b10000000000001010000000000000000}};
  ck_assert_int_eq(s21_is_less(first, second), 1);
}
END_TEST

START_TEST(s21_less_8_value_int_part_positive) {
  s21_decimal first = {{4412, 5775, 1254, 0b00000000000001110000000000000000}};
  s21_decimal second = {{4412, 5675, 1254, 0b00000000000001110000000000000000}};
  ck_assert_int_eq(s21_is_less(first, second), 0);
}
END_TEST

START_TEST(s21_less_9_value_fract_part_positive) {
  s21_decimal first = {{4412, 5775, 1254, 0b00000000000010000000000000000000}};
  s21_decimal second = {{4412, 5775, 1254, 0b00000000000001110000000000000000}};
  ck_assert_int_eq(s21_is_less(first, second), 1);
}
END_TEST

START_TEST(s21_less_10_max_int_positive) {
  s21_decimal first = {
      {2147483646, 2147483647, 2147483647, 0b00000000000001110000000000000000}};
  s21_decimal second = {
      {2147483647, 2147483647, 2147483647, 0b00000000000001110000000000000000}};
  ck_assert_int_eq(s21_is_less(first, second), 1);
}
END_TEST

START_TEST(s21_less_11_max_int_negative) {
  s21_decimal first = {
      {2147483647, 2147483647, 2147483647, 0b10000000000001110000000000000000}};
  s21_decimal second = {
      {2147483646, 2147483647, 2147483647, 0b10000000000001110000000000000000}};
  ck_assert_int_eq(s21_is_less(first, second), 1);
}
END_TEST

START_TEST(s21_less_12) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2;
  // src2 = 2;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_13) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2;
  // src2 = 2.00;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000011001000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_14) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2;
  // src2 = 3;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_15) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 0.000000000000000000000000000;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000110110000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_16) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -3;
  // src2 = 3;
  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_17) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.222212;
  // src2 = 2.222212;
  src1.bits[0] = 0b00000000001000011110100010000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  src2.bits[0] = 0b00000000001000011110100010000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_18) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.22221200000001000;
  // src2 = 2.222212;
  src1.bits[0] = 0b00000111100011111010001111101000;
  src1.bits[1] = 0b00000011000101010111110100000001;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000100010000000000000000;
  src2.bits[0] = 0b00000000001000011110100010000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_19) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 3.2222121;
  // src2 = 3.222212;
  src1.bits[0] = 0b00000001111010111010101110101001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001110000000000000000;
  src2.bits[0] = 0b00000000001100010010101011000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_20) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.222212;
  // src2 = -2.2222120002;
  src1.bits[0] = 0b00000000001000011110100010000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  src2.bits[0] = 0b00101100100010101010010001000010;
  src2.bits[1] = 0b00000000000000000000000000000101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000010100000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_21) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -364748;
  // src2 = 1;
  src1.bits[0] = 0b00000000000001011001000011001100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_22) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 987456543210.0;
  // src2 = 98745654321.0;
  src1.bits[0] = 0b00011001111101110000001100100100;
  src1.bits[1] = 0b00000000000000000000100011111011;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b11101000111111110001100111101010;
  src2.bits[1] = 0b00000000000000000000000011100101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000010000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_23) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -9878798789.5867800;
  // src2 = -9878798789.58678;
  src1.bits[0] = 0b11001110100110111101100110011000;
  src1.bits[1] = 0b00000001010111101111011100100110;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001110000000000000000;
  src2.bits[0] = 0b10110101010001000001111001010110;
  src2.bits[1] = 0b00000000000000111000001001111000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001010000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_24) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 9999999999999999999;
  // src2 = 1;
  src1.bits[0] = 0b10001001111001111111111111111111;
  src1.bits[1] = 0b10001010110001110010001100000100;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_25) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 18446744073709551615;
  // src2 = 18446744073709551615.000000000;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11000100011001010011011000000000;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b00111011100110101100100111111111;
  src2.bits[3] = 0b00000000000010010000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_26) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 18446744073709551615.0;
  // src2 = 965453154;
  src1.bits[0] = 0b11111111111111111111111111110110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000001001;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b00111001100010111010010101100010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_27) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -545454512454545.35265454545645;
  // src2 = -545454512454545.35265454545645;
  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;
  src2.bits[0] = 0b10000010111000100101101011101101;
  src2.bits[1] = 0b11111001111010000010010110101101;
  src2.bits[2] = 0b10110000001111101111000010010100;
  src2.bits[3] = 0b10000000000011100000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_28) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -545454512454545.35265454545645;
  // src2 = -5.352654545456454545645464;
  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;
  src2.bits[0] = 0b01001000000110110001111110011000;
  src2.bits[1] = 0b11111011111111011000100101101101;
  src2.bits[2] = 0b00000000000001000110110101110111;
  src2.bits[3] = 0b10000000000110000000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_29) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 7961327845421.879754123131254;
  // src2 = 7961327.845421879754123131254;
  src1.bits[0] = 0b01001110111001000011100101110110;
  src1.bits[1] = 0b01001011001101011010000111011001;
  src1.bits[2] = 0b00011001101110010111010010111111;
  src1.bits[3] = 0b00000000000011110000000000000000;
  src2.bits[0] = 0b01001110111001000011100101110110;
  src2.bits[1] = 0b01001011001101011010000111011001;
  src2.bits[2] = 0b00011001101110010111010010111111;
  src2.bits[3] = 0b00000000000101010000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_30) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 12345677.987654345678987654346;
  // src2 = 12345677.987654000000000000000;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;
  src2.bits[0] = 0b11100111110001110000000000000000;
  src2.bits[1] = 0b11000000010001001001101110001101;
  src2.bits[2] = 0b00100111111001000001101100000000;
  src2.bits[3] = 0b00000000000101010000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_31) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -12345677.987654345678987654346;
  // src2 = 87654323456.9876545678987653;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b10000000000101010000000000000000;
  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b00000000000100000000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_32) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -87654323456.98765456789876530;
  // src2 = -87654323456.98765456789876531;
  src1.bits[0] = 0b10110010000010100010111100110010;
  src1.bits[1] = 0b10011001010111000101110110000000;
  src1.bits[2] = 0b00011100010100101001100001111111;
  src1.bits[3] = 0b10000000000100010000000000000000;
  src2.bits[0] = 0b10110010000010100010111100110011;
  src2.bits[1] = 0b10011001010111000101110110000000;
  src2.bits[2] = 0b00011100010100101001100001111111;
  src2.bits[3] = 0b10000000000100010000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_33) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -87654323456.98765456789876530;
  // src2 = -87654323456.98765456789876530;
  src1.bits[0] = 0b10110010000010100010111100110010;
  src1.bits[1] = 0b10011001010111000101110110000000;
  src1.bits[2] = 0b00011100010100101001100001111111;
  src1.bits[3] = 0b10000000000100010000000000000000;
  src2.bits[0] = 0b10110010000010100010111100110010;
  src2.bits[1] = 0b10011001010111000101110110000000;
  src2.bits[2] = 0b00011100010100101001100001111111;
  src2.bits[3] = 0b10000000000100010000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_34) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 0.0;
  // src2 = 0.69;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b00000000000000000000000001000101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_35) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -69.1234567;
  // src2 = -69.12345670000000;
  src1.bits[0] = 0b00101001001100110110011100000111;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001110000000000000000;
  src2.bits[0] = 0b11100100001110011001110110000000;
  src2.bits[1] = 0b00000000000110001000111010111101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000011100000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_36) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 13436577854.000000000000;
  // src2 = 13436577854;
  src1.bits[0] = 0b00100110011110011110000000000000;
  src1.bits[1] = 0b01100101111110011111000000101100;
  src1.bits[2] = 0b00000000000000000000001011011000;
  src1.bits[3] = 0b00000000000011000000000000000000;
  src2.bits[0] = 0b00100000111000011110100000111110;
  src2.bits[1] = 0b00000000000000000000000000000011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_37) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 79228162514264337593543950335;
  // src2 = 79228162514264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_38) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 79228162514264337593543950335;
  // src2 = -79228162514264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b10000000000000000000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_39) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 665464545;
  // src2 = 8798232189789785;
  src1.bits[0] = 0b00100111101010100010111011100001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00010000010100101110011001011001;
  src2.bits[1] = 0b00000000000111110100000111110010;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_40) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.7986531268974139743;
  // src2 = 2.7986531268974139743;
  src1.bits[0] = 0b11111110100100001101100101011111;
  src1.bits[1] = 0b10000100011001000010000111101000;
  src1.bits[2] = 0b00000000000000000000000000000001;
  src1.bits[3] = 0b00000000000100110000000000000000;
  src2.bits[0] = 0b11111110100100001101100101011111;
  src2.bits[1] = 0b10000100011001000010000111101000;
  src2.bits[2] = 0b00000000000000000000000000000001;
  src2.bits[3] = 0b00000000000100110000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_41) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -2156878451.8547640000000000;
  // src2 = -2156878451.854764;
  src1.bits[0] = 0b10010011100100010011000000000000;
  src1.bits[1] = 0b00100110110100100010010100001001;
  src1.bits[2] = 0b00000000000100011101011101011110;
  src1.bits[3] = 0b10000000000100000000000000000000;
  src2.bits[0] = 0b01100101111100100100110110101100;
  src2.bits[1] = 0b00000000000001111010100110101011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001100000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_42) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 0.5456465465486476846545465485;
  // src2 = 5.4564654654864768465454654846;
  src1.bits[0] = 0b00001011000011110111000010001101;
  src1.bits[1] = 0b10010110101100000101100101010001;
  src1.bits[2] = 0b00010001101000010111101110000001;
  src1.bits[3] = 0b00000000000111000000000000000000;
  src2.bits[0] = 0b01101110100110100110010101111110;
  src2.bits[1] = 0b11100010111000110111110100101010;
  src2.bits[2] = 0b10110000010011101101001100001111;
  src2.bits[3] = 0b00000000000111000000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_43) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -7.7545545454546589781677545545;
  // src2 = -7.7545545454546589781677545545;
  src1.bits[0] = 0b00000101101101111001100001001001;
  src1.bits[1] = 0b01101011011011011010110110010010;
  src1.bits[2] = 0b11111010100100000010101111111010;
  src1.bits[3] = 0b10000000000111000000000000000000;
  src2.bits[0] = 0b00000101101101111001100001001001;
  src2.bits[1] = 0b01101011011011011010110110010010;
  src2.bits[2] = 0b11111010100100000010101111111010;
  src2.bits[3] = 0b10000000000111000000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_44) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -79228162514264337593543950335;
  // src2 = -792281625.14264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b10000000000101000000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_45) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 675432788976.5424354657687;
  // src2 = 67543278.89765424354657687;
  src1.bits[0] = 0b10111110000100011000010110010111;
  src1.bits[1] = 0b11011001001111010001001011000110;
  src1.bits[2] = 0b00000000000001011001011001001000;
  src1.bits[3] = 0b00000000000011010000000000000000;
  src2.bits[0] = 0b10111110000100011000010110010111;
  src2.bits[1] = 0b11011001001111010001001011000110;
  src2.bits[2] = 0b00000000000001011001011001001000;
  src2.bits[3] = 0b00000000000100010000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_46) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -579895323215489956.67897455465;
  // src2 = -579895323215489956.67897455465;
  src1.bits[0] = 0b11100110001001011001001101101001;
  src1.bits[1] = 0b00111000110110101110001010110100;
  src1.bits[2] = 0b10111011010111111101000100011110;
  src1.bits[3] = 0b10000000000010110000000000000000;
  src2.bits[0] = 0b11100110001001011001001101101001;
  src2.bits[1] = 0b00111000110110101110001010110100;
  src2.bits[2] = 0b10111011010111111101000100011110;
  src2.bits[3] = 0b10000000000010110000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_47) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 18446744073709551615.0;
  // src2 = 1844674407370955161.50;
  src1.bits[0] = 0b11111111111111111111111111110110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000001001;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b11111111111111111111111111110110;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b00000000000000000000000000001001;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_48) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 44073709551615.0;
  // src2 = 44073709551615.00000000;
  src1.bits[0] = 0b00011010000001000111111111110110;
  src1.bits[1] = 0b00000000000000011001000011011001;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b10011111010010100001111100000000;
  src2.bits[1] = 0b11101100100011110001010001110111;
  src2.bits[2] = 0b00000000000000000000000011101110;
  src2.bits[3] = 0b00000000000010000000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_49) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 228162514264337.5935439503;
  // src2 = 228162514264337.59354395030000;
  src1.bits[0] = 0b01010010111101011100001010001111;
  src1.bits[1] = 0b00100101100101100010101000001101;
  src1.bits[2] = 0b00000000000000011110001100100111;
  src1.bits[3] = 0b00000000000010100000000000000000;
  src2.bits[0] = 0b10011111111111111111000111110000;
  src2.bits[1] = 0b00111001110010101010100001111000;
  src2.bits[2] = 0b01001001101110010010100100101100;
  src2.bits[3] = 0b00000000000011100000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_50) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -754554545454658.97816770;
  // src2 = -754554545454658.9781677;
  src1.bits[0] = 0b00100000101101101001001011000010;
  src1.bits[1] = 0b01110010110010011000000011111000;
  src1.bits[2] = 0b00000000000000000000111111111010;
  src1.bits[3] = 0b10000000000010000000000000000000;
  src2.bits[0] = 0b10011100110111110000111010101101;
  src2.bits[1] = 0b00001011011110101000110011100101;
  src2.bits[2] = 0b00000000000000000000000110011001;
  src2.bits[3] = 0b10000000000001110000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_51) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -2.514264337593543;
  // src2 = -2.514264337593542;
  src1.bits[0] = 0b11001000101101101011010011000111;
  src1.bits[1] = 0b00000000000010001110111010110101;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000011110000000000000000;
  src2.bits[0] = 0b11001000101101101011010011000110;
  src2.bits[1] = 0b00000000000010001110111010110101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000011110000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_52) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -79228162514264337593543950335;
  // src2 = 0;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

/////////////---------is_greater---------///////////////

START_TEST(s21_greater_1) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2;
  // src2 = 2;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_2) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 457;
  // src2 = 2.00;
  src1.bits[0] = 0b00000000000000000000000111001001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000011001000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_3) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2;
  // src2 = 54;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000110110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_4) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 0.000000000000000000000000000;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000110110000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_5) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -3;
  // src2 = 3;
  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_6) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.222212;
  // src2 = 2.222212;
  src1.bits[0] = 0b00000000001000011110100010000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  src2.bits[0] = 0b00000000001000011110100010000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_7) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.22221200000001000;
  // src2 = 2.222212;
  src1.bits[0] = 0b00000111100011111010001111101000;
  src1.bits[1] = 0b00000011000101010111110100000001;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000100010000000000000000;
  src2.bits[0] = 0b00000000001000011110100010000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_8) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 3.745754741;
  // src2 = 3.222212;
  src1.bits[0] = 0b11011111010000111010111001110101;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000010010000000000000000;
  src2.bits[0] = 0b00000000001100010010101011000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_9) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.222212;
  // src2 = -2.2222120002;
  src1.bits[0] = 0b00000000001000011110100010000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  src2.bits[0] = 0b00101100100010101010010001000010;
  src2.bits[1] = 0b00000000000000000000000000000101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000010100000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_10) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -364748;
  // src2 = 1;
  src1.bits[0] = 0b00000000000001011001000011001100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_11) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 987456543210.0;
  // src2 = 98745654321.0;
  src1.bits[0] = 0b00011001111101110000001100100100;
  src1.bits[1] = 0b00000000000000000000100011111011;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b11101000111111110001100111101010;
  src2.bits[1] = 0b00000000000000000000000011100101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000010000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_12) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -9878798789.5867800;
  // src2 = -9878798789.58678;
  src1.bits[0] = 0b11001110100110111101100110011000;
  src1.bits[1] = 0b00000001010111101111011100100110;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001110000000000000000;
  src2.bits[0] = 0b10110101010001000001111001010110;
  src2.bits[1] = 0b00000000000000111000001001111000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001010000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_13) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 9999999999999999999;
  // src2 = 1;
  src1.bits[0] = 0b10001001111001111111111111111111;
  src1.bits[1] = 0b10001010110001110010001100000100;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_14) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 18446744073709551615;
  // src2 = 434345343551615.00000000000;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b01000110001111010001100000000000;
  src2.bits[1] = 0b11010011010011111110100110011101;
  src2.bits[2] = 0b00000000001000111110110110011110;
  src2.bits[3] = 0b00000000000010110000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_15) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 18446744073709551615.0;
  // src2 = 965453154;
  src1.bits[0] = 0b11111111111111111111111111110110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000001001;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b00111001100010111010010101100010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_16) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -796214545.3526545454564545456;
  // src2 = -545454512454545.35265454545645;
  src1.bits[0] = 0b10111111111111101001001110110000;
  src1.bits[1] = 0b11101010111111101111100111101000;
  src1.bits[2] = 0b00011001101110100010000111100001;
  src1.bits[3] = 0b10000000000100110000000000000000;
  src2.bits[0] = 0b10000010111000100101101011101101;
  src2.bits[1] = 0b11111001111010000010010110101101;
  src2.bits[2] = 0b10110000001111101111000010010100;
  src2.bits[3] = 0b10000000000011100000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_17) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -545454512454545.35265454545645;
  // src2 = -5.352654545456454545645464;
  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;
  src2.bits[0] = 0b01001000000110110001111110011000;
  src2.bits[1] = 0b11111011111111011000100101101101;
  src2.bits[2] = 0b00000000000001000110110101110111;
  src2.bits[3] = 0b10000000000110000000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_18) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -7961327845421.843434341378545;
  // src2 = 7961327.845421879754123131254;
  src1.bits[0] = 0b11110011001100111010100111110001;
  src1.bits[1] = 0b01001011001101011000000011010000;
  src1.bits[2] = 0b00011001101110010111010010111111;
  src1.bits[3] = 0b10000000000011110000000000000000;
  src2.bits[0] = 0b01001110111001000011100101110110;
  src2.bits[1] = 0b01001011001101011010000111011001;
  src2.bits[2] = 0b00011001101110010111010010111111;
  src2.bits[3] = 0b00000000000101010000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_19) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 12345677.987654345678987654346;
  // src2 = 12345677.987654000000000000000;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;
  src2.bits[0] = 0b11100111110001110000000000000000;
  src2.bits[1] = 0b11000000010001001001101110001101;
  src2.bits[2] = 0b00100111111001000001101100000000;
  src2.bits[3] = 0b00000000000101010000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_20) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 12345677.987654345678987654346;
  // src2 = 145752736456.9876545678987653;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;
  src2.bits[0] = 0b10001101100101011101000110000101;
  src2.bits[1] = 0b11000001100101010111000111101011;
  src2.bits[2] = 0b00000100101101011010001101101100;
  src2.bits[3] = 0b00000000000100000000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_21) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 87654323456.98765456789876530;
  // src2 = -87654323456.98765456789876531;
  src1.bits[0] = 0b10110010000010100010111100110010;
  src1.bits[1] = 0b10011001010111000101110110000000;
  src1.bits[2] = 0b00011100010100101001100001111111;
  src1.bits[3] = 0b00000000000100010000000000000000;
  src2.bits[0] = 0b10110010000010100010111100110011;
  src2.bits[1] = 0b10011001010111000101110110000000;
  src2.bits[2] = 0b00011100010100101001100001111111;
  src2.bits[3] = 0b10000000000100010000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_22) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -854764561465456456.9876545679;
  // src2 = -87654323456.98765456789876530;
  src1.bits[0] = 0b11000100000001000100000010001111;
  src1.bits[1] = 0b01000000100100100110001100010101;
  src1.bits[2] = 0b00011011100111100111001001011101;
  src1.bits[3] = 0b10000000000010100000000000000000;
  src2.bits[0] = 0b10110010000010100010111100110010;
  src2.bits[1] = 0b10011001010111000101110110000000;
  src2.bits[2] = 0b00011100010100101001100001111111;
  src2.bits[3] = 0b10000000000100010000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_23) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 0.0;
  // src2 = 0.69;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b00000000000000000000000001000101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_24) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -69.1234567;
  // src2 = -69.12345670000000;
  src1.bits[0] = 0b00101001001100110110011100000111;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001110000000000000000;
  src2.bits[0] = 0b11100100001110011001110110000000;
  src2.bits[1] = 0b00000000000110001000111010111101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000011100000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_25) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 13436577854.000000000000;
  // src2 = 13436577854;
  src1.bits[0] = 0b00100110011110011110000000000000;
  src1.bits[1] = 0b01100101111110011111000000101100;
  src1.bits[2] = 0b00000000000000000000001011011000;
  src1.bits[3] = 0b00000000000011000000000000000000;
  src2.bits[0] = 0b00100000111000011110100000111110;
  src2.bits[1] = 0b00000000000000000000000000000011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_26) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 79228162514264337593543950335;
  // src2 = 79228162514264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_27) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 79228162514264337593543950335;
  // src2 = -79228162514264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b10000000000000000000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_28) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 665464545;
  // src2 = 8798232189789785;
  src1.bits[0] = 0b00100111101010100010111011100001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00010000010100101110011001011001;
  src2.bits[1] = 0b00000000000111110100000111110010;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_29) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.7986531268974139743;
  // src2 = 2.7986531268974139743;
  src1.bits[0] = 0b11111110100100001101100101011111;
  src1.bits[1] = 0b10000100011001000010000111101000;
  src1.bits[2] = 0b00000000000000000000000000000001;
  src1.bits[3] = 0b00000000000100110000000000000000;
  src2.bits[0] = 0b11111110100100001101100101011111;
  src2.bits[1] = 0b10000100011001000010000111101000;
  src2.bits[2] = 0b00000000000000000000000000000001;
  src2.bits[3] = 0b00000000000100110000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_30) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -2156878451.8547640000000000;
  // src2 = -2156878451.854764;
  src1.bits[0] = 0b10010011100100010011000000000000;
  src1.bits[1] = 0b00100110110100100010010100001001;
  src1.bits[2] = 0b00000000000100011101011101011110;
  src1.bits[3] = 0b10000000000100000000000000000000;
  src2.bits[0] = 0b01100101111100100100110110101100;
  src2.bits[1] = 0b00000000000001111010100110101011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001100000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_31) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 0.5456465465486476846545465485;
  // src2 = 45645405.456456345684654546548;
  src1.bits[0] = 0b00001011000011110111000010001101;
  src1.bits[1] = 0b10010110101100000101100101010001;
  src1.bits[2] = 0b00010001101000010111101110000001;
  src1.bits[3] = 0b00000000000111000000000000000000;
  src2.bits[0] = 0b01000110110111011101111001110100;
  src2.bits[1] = 0b11111110010110110111101101110010;
  src2.bits[2] = 0b10010011011111001111111010010011;
  src2.bits[3] = 0b00000000000101010000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_32) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -776890.75455454213415678965898;
  // src2 = -7.7545545454546589781677545545;
  src1.bits[0] = 0b11000010010111101111100010001010;
  src1.bits[1] = 0b01011100000101000111000011011000;
  src1.bits[2] = 0b11111011000001101110010110100011;
  src1.bits[3] = 0b10000000000101110000000000000000;
  src2.bits[0] = 0b00000101101101111001100001001001;
  src2.bits[1] = 0b01101011011011011010110110010010;
  src2.bits[2] = 0b11111010100100000010101111111010;
  src2.bits[3] = 0b10000000000111000000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_33) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -732123534337593543950335.12;
  // src2 = -792281625.14264337593543950335;
  src1.bits[0] = 0b11000011000110111111111110101000;
  src1.bits[1] = 0b10100001110111010100101100101110;
  src1.bits[2] = 0b00000000001111001000111101010001;
  src1.bits[3] = 0b10000000000000100000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b10000000000101000000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_34) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 675432788976.5424354657687;
  // src2 = 67543278.89765424354657687;
  src1.bits[0] = 0b10111110000100011000010110010111;
  src1.bits[1] = 0b11011001001111010001001011000110;
  src1.bits[2] = 0b00000000000001011001011001001000;
  src1.bits[3] = 0b00000000000011010000000000000000;
  src2.bits[0] = 0b10111110000100011000010110010111;
  src2.bits[1] = 0b11011001001111010001001011000110;
  src2.bits[2] = 0b00000000000001011001011001001000;
  src2.bits[3] = 0b00000000000100010000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_35) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -579895323215489956.67897455465;
  // src2 = -579895323215489956.67897455465;
  src1.bits[0] = 0b11100110001001011001001101101001;
  src1.bits[1] = 0b00111000110110101110001010110100;
  src1.bits[2] = 0b10111011010111111101000100011110;
  src1.bits[3] = 0b10000000000010110000000000000000;
  src2.bits[0] = 0b11100110001001011001001101101001;
  src2.bits[1] = 0b00111000110110101110001010110100;
  src2.bits[2] = 0b10111011010111111101000100011110;
  src2.bits[3] = 0b10000000000010110000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_36) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 123523543453453453.0;
  // src2 = 1844674407370955161.50;
  src1.bits[0] = 0b01001001011001111111110110000010;
  src1.bits[1] = 0b00010001001001000111000000010101;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b11111111111111111111111111110110;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b00000000000000000000000000001001;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_37) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 31231232456315.0;
  // src2 = 44073709551615.00000000;
  src1.bits[0] = 0b11100001001010100010000011001110;
  src1.bits[1] = 0b00000000000000010001110000001011;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b10011111010010100001111100000000;
  src2.bits[1] = 0b11101100100011110001010001110111;
  src2.bits[2] = 0b00000000000000000000000011101110;
  src2.bits[3] = 0b00000000000010000000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_38) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 78987543557678337.5935439503;
  // src2 = 228162514264337.59354395030000;
  src1.bits[0] = 0b00111011110001111000001010001111;
  src1.bits[1] = 0b00101001100010100010010001100011;
  src1.bits[2] = 0b00000010100011010101111010100001;
  src1.bits[3] = 0b00000000000010100000000000000000;
  src2.bits[0] = 0b10011111111111111111000111110000;
  src2.bits[1] = 0b00111001110010101010100001111000;
  src2.bits[2] = 0b01001001101110010010100100101100;
  src2.bits[3] = 0b00000000000011100000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_39) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -754567488438.97816770;
  // src2 = -754554545454658.9781677;
  src1.bits[0] = 0b01011010011001011000011011000010;
  src1.bits[1] = 0b00010111001011000011100101001001;
  src1.bits[2] = 0b00000000000000000000000000000100;
  src1.bits[3] = 0b10000000000010000000000000000000;
  src2.bits[0] = 0b10011100110111110000111010101101;
  src2.bits[1] = 0b00001011011110101000110011100101;
  src2.bits[2] = 0b00000000000000000000000110011001;
  src2.bits[3] = 0b10000000000001110000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_40) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -2.514475768684753643;
  // src2 = -2.514264337593542;
  src1.bits[0] = 0b10101100110010000011001011101011;
  src1.bits[1] = 0b00100010111001010011011001100011;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000100100000000000000000;
  src2.bits[0] = 0b11001000101101101011010011000110;
  src2.bits[1] = 0b00000000000010001110111010110101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000011110000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

/////////////---------is_equal---------///////////////

START_TEST(s21_is_equalal_1) {
  s21_decimal first = {{4412, 5675, 1254, 0b00000100000000000010000000000000}};
  s21_decimal second = {{4412, 5675, 1254, 0b00000100000000000010000000000000}};
  ck_assert_int_eq(s21_is_equal(first, second), 1);
}
END_TEST

START_TEST(s21_is_equalal_2) {
  s21_decimal first = {{4412, 5675, 1254, 0b10000100000000000010000000000000}};
  s21_decimal second = {{4412, 5675, 1254, 0b10000100000000000010000000000000}};
  ck_assert_int_eq(s21_is_equal(first, second), 1);
}
END_TEST

START_TEST(s21_is_equalal_3_fraction) {
  s21_decimal first = {{4412, 5675, 1254, 0b10110010000000001110000111000011}};
  s21_decimal second = {{4412, 5675, 1254, 0b11001001000000000010000111111110}};
  ck_assert_int_eq(s21_is_equal(first, second), 1);
}
END_TEST

START_TEST(s21_is_equalal_4_sign) {
  s21_decimal first = {{4412, 5675, 1254, 0b10110100111111110010000000000011}};
  s21_decimal second = {{4412, 5675, 1254, 0b01110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_equal(first, second), 0);
}
END_TEST

START_TEST(s21_is_equalal_5_sign) {
  s21_decimal first = {{4412, 5675, 1254, 0b00110100111111110010000000000011}};
  s21_decimal second = {{4412, 5675, 1254, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_equal(first, second), 0);
}
END_TEST

START_TEST(s21_is_equalal_6) {
  s21_decimal first = {{4412, 5675, 1154, 0b10110100111111110010000000000011}};
  s21_decimal second = {{4412, 5675, 1254, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_equal(first, second), 0);
}
END_TEST

START_TEST(s21_is_equalal_7) {
  s21_decimal first = {{4412, 5675, 1254, 0b10110100111111110010000000000011}};
  s21_decimal second = {{4412, 5675, 1244, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_equal(first, second), 0);
}
END_TEST

START_TEST(s21_is_equalal_8) {
  s21_decimal first = {{4412, 5675, 1254, 0b10110100111111110010000000000011}};
  s21_decimal second = {
      {4412, 5675, 12541, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_equal(first, second), 0);
}
END_TEST

START_TEST(s21_is_equalal_9_ss) {
  s21_decimal first = {
      {0x4A1D, 05675, 1254, 0b10110100111111110010000000000011}};
  s21_decimal second = {
      {0x4A1D, 05675, 1254, 0b10110100111111110010000000000011}};
  ck_assert_int_eq(s21_is_equal(first, second), 1);
}
END_TEST

START_TEST(s21_is_equalal_10) {
  s21_decimal first = {{412, 5675, 1254, 0b10110100111111110010000000000011}};
  s21_decimal second = {{4412, 5675, 1254, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_equal(first, second), 0);
}
END_TEST

START_TEST(s21_is_equalal_12_value) {
  s21_decimal first = {
      {1564, 31452, 6109410, 0b11110100000000000010000111111110}};
  s21_decimal second = {
      {1564, 31452, 610941, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_equal(first, second), 0);
}
END_TEST

START_TEST(s21_is_equalal_13_value) {
  s21_decimal first = {
      {1564, 31452, 610941, 0b11110100000000000010000111111110}};
  s21_decimal second = {
      {1564, 3142, 610941, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_equal(first, second), 0);
}
END_TEST

START_TEST(s21_is_equalal_14_value) {
  s21_decimal first = {
      {15614, 31452, 610941, 0b11110100000000000010000111111110}};
  s21_decimal second = {
      {1564, 31452, 610941, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_equal(first, second), 0);
}
END_TEST

START_TEST(s21_is_equalal_15) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2;
  // src2 = 2;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_17) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2;
  // src2 = 3;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_18) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 0.000000000000000000000000000;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000110110000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_19) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -3;
  // src2 = 3;
  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_20) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.222212;
  // src2 = 2.222212;
  src1.bits[0] = 0b00000000001000011110100010000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  src2.bits[0] = 0b00000000001000011110100010000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_21) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.22221200000000000;
  // src2 = 2.222212;
  src1.bits[0] = 0b00000111100011111010000000000000;
  src1.bits[1] = 0b00000011000101010111110100000001;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000100010000000000000000;
  src2.bits[0] = 0b00000000001000011110100010000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_22) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 3.2222121;
  // src2 = 3.222212;
  src1.bits[0] = 0b00000001111010111010101110101001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001110000000000000000;
  src2.bits[0] = 0b00000000001100010010101011000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_23) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.222212;
  // src2 = -2.222212;
  src1.bits[0] = 0b00000000001000011110100010000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  src2.bits[0] = 0b00000000001000011110100010000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001100000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_24) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -364748;
  // src2 = 1;
  src1.bits[0] = 0b00000000000001011001000011001100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_25) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 987456543210.0;
  // src2 = 98745654321.0;
  src1.bits[0] = 0b00011001111101110000001100100100;
  src1.bits[1] = 0b00000000000000000000100011111011;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b11101000111111110001100111101010;
  src2.bits[1] = 0b00000000000000000000000011100101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000010000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_26) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -9878798789.5867800;
  // src2 = -9878798789.58678;
  src1.bits[0] = 0b11001110100110111101100110011000;
  src1.bits[1] = 0b00000001010111101111011100100110;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001110000000000000000;
  src2.bits[0] = 0b10110101010001000001111001010110;
  src2.bits[1] = 0b00000000000000111000001001111000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001010000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_27) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 9999999999999999999;
  // src2 = 1;
  src1.bits[0] = 0b10001001111001111111111111111111;
  src1.bits[1] = 0b10001010110001110010001100000100;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_28) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 18446744073709551615;
  // src2 = 18446744073709551615.000000000;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11000100011001010011011000000000;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b00111011100110101100100111111111;
  src2.bits[3] = 0b00000000000010010000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_29) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 18446744073709551615.0;
  // src2 = 965453154;
  src1.bits[0] = 0b11111111111111111111111111110110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000001001;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b00111001100010111010010101100010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_30) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -545454512454545.35265454545645;
  // src2 = -545454512454545.35265454545645;
  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;
  src2.bits[0] = 0b10000010111000100101101011101101;
  src2.bits[1] = 0b11111001111010000010010110101101;
  src2.bits[2] = 0b10110000001111101111000010010100;
  src2.bits[3] = 0b10000000000011100000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_31) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -545454512454545.35265454545645;
  // src2 = -5.352654545456454545645464;
  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;
  src2.bits[0] = 0b01001000000110110001111110011000;
  src2.bits[1] = 0b11111011111111011000100101101101;
  src2.bits[2] = 0b00000000000001000110110101110111;
  src2.bits[3] = 0b10000000000110000000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_32) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 7961327845421.879754123131254;
  // src2 = 7961327.845421879754123131254;
  src1.bits[0] = 0b01001110111001000011100101110110;
  src1.bits[1] = 0b01001011001101011010000111011001;
  src1.bits[2] = 0b00011001101110010111010010111111;
  src1.bits[3] = 0b00000000000011110000000000000000;
  src2.bits[0] = 0b01001110111001000011100101110110;
  src2.bits[1] = 0b01001011001101011010000111011001;
  src2.bits[2] = 0b00011001101110010111010010111111;
  src2.bits[3] = 0b00000000000101010000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_33) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 12345677.987654345678987654346;
  // src2 = 12345677.987654000000000000000;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;
  src2.bits[0] = 0b11100111110001110000000000000000;
  src2.bits[1] = 0b11000000010001001001101110001101;
  src2.bits[2] = 0b00100111111001000001101100000000;
  src2.bits[3] = 0b00000000000101010000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_34) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -12345677.987654345678987654346;
  // src2 = 87654323456.9876545678987653;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b10000000000101010000000000000000;
  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b00000000000100000000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_35) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -87654323456.98765456789876530;
  // src2 = -87654323456.98765456789876531;
  src1.bits[0] = 0b10110010000010100010111100110010;
  src1.bits[1] = 0b10011001010111000101110110000000;
  src1.bits[2] = 0b00011100010100101001100001111111;
  src1.bits[3] = 0b10000000000100010000000000000000;
  src2.bits[0] = 0b10110010000010100010111100110011;
  src2.bits[1] = 0b10011001010111000101110110000000;
  src2.bits[2] = 0b00011100010100101001100001111111;
  src2.bits[3] = 0b10000000000100010000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_36) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -87654323456.98765456789876530;
  // src2 = -87654323456.98765456789876530;
  src1.bits[0] = 0b10110010000010100010111100110010;
  src1.bits[1] = 0b10011001010111000101110110000000;
  src1.bits[2] = 0b00011100010100101001100001111111;
  src1.bits[3] = 0b10000000000100010000000000000000;
  src2.bits[0] = 0b10110010000010100010111100110010;
  src2.bits[1] = 0b10011001010111000101110110000000;
  src2.bits[2] = 0b00011100010100101001100001111111;
  src2.bits[3] = 0b10000000000100010000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_37) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 0.0;
  // src2 = 0.69;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b00000000000000000000000001000101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_38) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -69.1234567;
  // src2 = -69.12345670000000;
  src1.bits[0] = 0b00101001001100110110011100000111;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001110000000000000000;
  src2.bits[0] = 0b11100100001110011001110110000000;
  src2.bits[1] = 0b00000000000110001000111010111101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000011100000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_39) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 13436577854.000000000000;
  // src2 = 13436577854;
  src1.bits[0] = 0b00100110011110011110000000000000;
  src1.bits[1] = 0b01100101111110011111000000101100;
  src1.bits[2] = 0b00000000000000000000001011011000;
  src1.bits[3] = 0b00000000000011000000000000000000;
  src2.bits[0] = 0b00100000111000011110100000111110;
  src2.bits[1] = 0b00000000000000000000000000000011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_40) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 79228162514264337593543950335;
  // src2 = 79228162514264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_41) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 79228162514264337593543950335;
  // src2 = -79228162514264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b10000000000000000000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_42) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 665464545;
  // src2 = 8798232189789785;
  src1.bits[0] = 0b00100111101010100010111011100001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00010000010100101110011001011001;
  src2.bits[1] = 0b00000000000111110100000111110010;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_43) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.7986531268974139743;
  // src2 = 2.7986531268974139743;
  src1.bits[0] = 0b11111110100100001101100101011111;
  src1.bits[1] = 0b10000100011001000010000111101000;
  src1.bits[2] = 0b00000000000000000000000000000001;
  src1.bits[3] = 0b00000000000100110000000000000000;
  src2.bits[0] = 0b11111110100100001101100101011111;
  src2.bits[1] = 0b10000100011001000010000111101000;
  src2.bits[2] = 0b00000000000000000000000000000001;
  src2.bits[3] = 0b00000000000100110000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_44) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -2156878451.8547640000000000;
  // src2 = -2156878451.854764;
  src1.bits[0] = 0b10010011100100010011000000000000;
  src1.bits[1] = 0b00100110110100100010010100001001;
  src1.bits[2] = 0b00000000000100011101011101011110;
  src1.bits[3] = 0b10000000000100000000000000000000;
  src2.bits[0] = 0b01100101111100100100110110101100;
  src2.bits[1] = 0b00000000000001111010100110101011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001100000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_45) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 0.5456465465486476846545465485;
  // src2 = 5.4564654654864768465454654846;
  src1.bits[0] = 0b00001011000011110111000010001101;
  src1.bits[1] = 0b10010110101100000101100101010001;
  src1.bits[2] = 0b00010001101000010111101110000001;
  src1.bits[3] = 0b00000000000111000000000000000000;
  src2.bits[0] = 0b01101110100110100110010101111110;
  src2.bits[1] = 0b11100010111000110111110100101010;
  src2.bits[2] = 0b10110000010011101101001100001111;
  src2.bits[3] = 0b00000000000111000000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_46) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -7.7545545454546589781677545545;
  // src2 = -7.7545545454546589781677545545;
  src1.bits[0] = 0b00000101101101111001100001001001;
  src1.bits[1] = 0b01101011011011011010110110010010;
  src1.bits[2] = 0b11111010100100000010101111111010;
  src1.bits[3] = 0b10000000000111000000000000000000;
  src2.bits[0] = 0b00000101101101111001100001001001;
  src2.bits[1] = 0b01101011011011011010110110010010;
  src2.bits[2] = 0b11111010100100000010101111111010;
  src2.bits[3] = 0b10000000000111000000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_47) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -79228162514264337593543950335;
  // src2 = -792281625.14264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b10000000000101000000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_48) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 675432788976.5424354657687;
  // src2 = 67543278.89765424354657687;
  src1.bits[0] = 0b10111110000100011000010110010111;
  src1.bits[1] = 0b11011001001111010001001011000110;
  src1.bits[2] = 0b00000000000001011001011001001000;
  src1.bits[3] = 0b00000000000011010000000000000000;
  src2.bits[0] = 0b10111110000100011000010110010111;
  src2.bits[1] = 0b11011001001111010001001011000110;
  src2.bits[2] = 0b00000000000001011001011001001000;
  src2.bits[3] = 0b00000000000100010000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_49) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -579895323215489956.67897455465;
  // src2 = -579895323215489956.67897455465;
  src1.bits[0] = 0b11100110001001011001001101101001;
  src1.bits[1] = 0b00111000110110101110001010110100;
  src1.bits[2] = 0b10111011010111111101000100011110;
  src1.bits[3] = 0b10000000000010110000000000000000;
  src2.bits[0] = 0b11100110001001011001001101101001;
  src2.bits[1] = 0b00111000110110101110001010110100;
  src2.bits[2] = 0b10111011010111111101000100011110;
  src2.bits[3] = 0b10000000000010110000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_50) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 18446744073709551615.0;
  // src2 = 1844674407370955161.50;
  src1.bits[0] = 0b11111111111111111111111111110110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000001001;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b11111111111111111111111111110110;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b00000000000000000000000000001001;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_51) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 44073709551615.0;
  // src2 = 44073709551615.00000000;
  src1.bits[0] = 0b00011010000001000111111111110110;
  src1.bits[1] = 0b00000000000000011001000011011001;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b10011111010010100001111100000000;
  src2.bits[1] = 0b11101100100011110001010001110111;
  src2.bits[2] = 0b00000000000000000000000011101110;
  src2.bits[3] = 0b00000000000010000000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_52) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 228162514264337.5935439503;
  // src2 = 228162514264337.59354395030000;
  src1.bits[0] = 0b01010010111101011100001010001111;
  src1.bits[1] = 0b00100101100101100010101000001101;
  src1.bits[2] = 0b00000000000000011110001100100111;
  src1.bits[3] = 0b00000000000010100000000000000000;
  src2.bits[0] = 0b10011111111111111111000111110000;
  src2.bits[1] = 0b00111001110010101010100001111000;
  src2.bits[2] = 0b01001001101110010010100100101100;
  src2.bits[3] = 0b00000000000011100000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_53) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -754554545454658.97816770;
  // src2 = -754554545454658.9781677;
  src1.bits[0] = 0b00100000101101101001001011000010;
  src1.bits[1] = 0b01110010110010011000000011111000;
  src1.bits[2] = 0b00000000000000000000111111111010;
  src1.bits[3] = 0b10000000000010000000000000000000;
  src2.bits[0] = 0b10011100110111110000111010101101;
  src2.bits[1] = 0b00001011011110101000110011100101;
  src2.bits[2] = 0b00000000000000000000000110011001;
  src2.bits[3] = 0b10000000000001110000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_is_equalal_54) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -2.514264337593543;
  // src2 = -2.5142643375935430000000000000;
  src1.bits[0] = 0b11001000101101101011010011000111;
  src1.bits[1] = 0b00000000000010001110111010110101;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000011110000000000000000;
  src2.bits[0] = 0b01010011100110100110000000000000;
  src2.bits[1] = 0b10000010110010001001101110001011;
  src2.bits[2] = 0b01010001001111011000000111010100;
  src2.bits[3] = 0b10000000000111000000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

///////////////// ---is less or equal--- /////////////

START_TEST(s21_less_or_equal_1) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2;
  // src2 = 2;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_2) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2;
  // src2 = 2.00;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000011001000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_3) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2;
  // src2 = 3;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_4) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 0.000000000000000000000000000;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000110110000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_5) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -3;
  // src2 = 3;
  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_6) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.222212;
  // src2 = 2.222212;
  src1.bits[0] = 0b00000000001000011110100010000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  src2.bits[0] = 0b00000000001000011110100010000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_7) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.22221200000001000;
  // src2 = 2.222212;
  src1.bits[0] = 0b00000111100011111010001111101000;
  src1.bits[1] = 0b00000011000101010111110100000001;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000100010000000000000000;
  src2.bits[0] = 0b00000000001000011110100010000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_8) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 3.2222121;
  // src2 = 3.222212;
  src1.bits[0] = 0b00000001111010111010101110101001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001110000000000000000;
  src2.bits[0] = 0b00000000001100010010101011000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_9) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.222212;
  // src2 = -2.2222120002;
  src1.bits[0] = 0b00000000001000011110100010000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  src2.bits[0] = 0b00101100100010101010010001000010;
  src2.bits[1] = 0b00000000000000000000000000000101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000010100000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_10) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -364748;
  // src2 = 1;
  src1.bits[0] = 0b00000000000001011001000011001100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_11) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 987456543210.0;
  // src2 = 98745654321.0;
  src1.bits[0] = 0b00011001111101110000001100100100;
  src1.bits[1] = 0b00000000000000000000100011111011;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b11101000111111110001100111101010;
  src2.bits[1] = 0b00000000000000000000000011100101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000010000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_12) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -9878798789.5867800;
  // src2 = -9878798789.58678;
  src1.bits[0] = 0b11001110100110111101100110011000;
  src1.bits[1] = 0b00000001010111101111011100100110;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001110000000000000000;
  src2.bits[0] = 0b10110101010001000001111001010110;
  src2.bits[1] = 0b00000000000000111000001001111000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001010000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_13) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 9999999999999999999;
  // src2 = 1;
  src1.bits[0] = 0b10001001111001111111111111111111;
  src1.bits[1] = 0b10001010110001110010001100000100;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_14) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 18446744073709551615;
  // src2 = 18446744073709551615.000000000;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11000100011001010011011000000000;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b00111011100110101100100111111111;
  src2.bits[3] = 0b00000000000010010000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_15) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 18446744073709551615.0;
  // src2 = 965453154;
  src1.bits[0] = 0b11111111111111111111111111110110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000001001;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b00111001100010111010010101100010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_16) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -545454512454545.35265454545645;
  // src2 = -545454512454545.35265454545645;
  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;
  src2.bits[0] = 0b10000010111000100101101011101101;
  src2.bits[1] = 0b11111001111010000010010110101101;
  src2.bits[2] = 0b10110000001111101111000010010100;
  src2.bits[3] = 0b10000000000011100000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_17) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -545454512454545.35265454545645;
  // src2 = -5.352654545456454545645464;
  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;
  src2.bits[0] = 0b01001000000110110001111110011000;
  src2.bits[1] = 0b11111011111111011000100101101101;
  src2.bits[2] = 0b00000000000001000110110101110111;
  src2.bits[3] = 0b10000000000110000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_18) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 7961327845421.879754123131254;
  // src2 = 7961327.845421879754123131254;
  src1.bits[0] = 0b01001110111001000011100101110110;
  src1.bits[1] = 0b01001011001101011010000111011001;
  src1.bits[2] = 0b00011001101110010111010010111111;
  src1.bits[3] = 0b00000000000011110000000000000000;
  src2.bits[0] = 0b01001110111001000011100101110110;
  src2.bits[1] = 0b01001011001101011010000111011001;
  src2.bits[2] = 0b00011001101110010111010010111111;
  src2.bits[3] = 0b00000000000101010000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_19) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 12345677.987654345678987654346;
  // src2 = 12345677.987654000000000000000;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;
  src2.bits[0] = 0b11100111110001110000000000000000;
  src2.bits[1] = 0b11000000010001001001101110001101;
  src2.bits[2] = 0b00100111111001000001101100000000;
  src2.bits[3] = 0b00000000000101010000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_20) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -12345677.987654345678987654346;
  // src2 = 87654323456.9876545678987653;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b10000000000101010000000000000000;
  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b00000000000100000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_21) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -87654323456.98765456789876530;
  // src2 = -87654323456.98765456789876531;
  src1.bits[0] = 0b10110010000010100010111100110010;
  src1.bits[1] = 0b10011001010111000101110110000000;
  src1.bits[2] = 0b00011100010100101001100001111111;
  src1.bits[3] = 0b10000000000100010000000000000000;
  src2.bits[0] = 0b10110010000010100010111100110011;
  src2.bits[1] = 0b10011001010111000101110110000000;
  src2.bits[2] = 0b00011100010100101001100001111111;
  src2.bits[3] = 0b10000000000100010000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_22) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -87654323456.98765456789876530;
  // src2 = -87654323456.98765456789876530;
  src1.bits[0] = 0b10110010000010100010111100110010;
  src1.bits[1] = 0b10011001010111000101110110000000;
  src1.bits[2] = 0b00011100010100101001100001111111;
  src1.bits[3] = 0b10000000000100010000000000000000;
  src2.bits[0] = 0b10110010000010100010111100110010;
  src2.bits[1] = 0b10011001010111000101110110000000;
  src2.bits[2] = 0b00011100010100101001100001111111;
  src2.bits[3] = 0b10000000000100010000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_23) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 0.0;
  // src2 = 0.69;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b00000000000000000000000001000101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_24) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -69.1234567;
  // src2 = -69.12345670000000;
  src1.bits[0] = 0b00101001001100110110011100000111;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001110000000000000000;
  src2.bits[0] = 0b11100100001110011001110110000000;
  src2.bits[1] = 0b00000000000110001000111010111101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000011100000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_25) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 13436577854.000000000000;
  // src2 = 13436577854;
  src1.bits[0] = 0b00100110011110011110000000000000;
  src1.bits[1] = 0b01100101111110011111000000101100;
  src1.bits[2] = 0b00000000000000000000001011011000;
  src1.bits[3] = 0b00000000000011000000000000000000;
  src2.bits[0] = 0b00100000111000011110100000111110;
  src2.bits[1] = 0b00000000000000000000000000000011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_26) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 79228162514264337593543950335;
  // src2 = 79228162514264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_27) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 79228162514264337593543950335;
  // src2 = -79228162514264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b10000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_28) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 665464545;
  // src2 = 8798232189789785;
  src1.bits[0] = 0b00100111101010100010111011100001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00010000010100101110011001011001;
  src2.bits[1] = 0b00000000000111110100000111110010;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_29) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.7986531268974139743;
  // src2 = 2.7986531268974139743;
  src1.bits[0] = 0b11111110100100001101100101011111;
  src1.bits[1] = 0b10000100011001000010000111101000;
  src1.bits[2] = 0b00000000000000000000000000000001;
  src1.bits[3] = 0b00000000000100110000000000000000;
  src2.bits[0] = 0b11111110100100001101100101011111;
  src2.bits[1] = 0b10000100011001000010000111101000;
  src2.bits[2] = 0b00000000000000000000000000000001;
  src2.bits[3] = 0b00000000000100110000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_30) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -2156878451.8547640000000000;
  // src2 = -2156878451.854764;
  src1.bits[0] = 0b10010011100100010011000000000000;
  src1.bits[1] = 0b00100110110100100010010100001001;
  src1.bits[2] = 0b00000000000100011101011101011110;
  src1.bits[3] = 0b10000000000100000000000000000000;
  src2.bits[0] = 0b01100101111100100100110110101100;
  src2.bits[1] = 0b00000000000001111010100110101011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001100000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_31) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 0.5456465465486476846545465485;
  // src2 = 5.4564654654864768465454654846;
  src1.bits[0] = 0b00001011000011110111000010001101;
  src1.bits[1] = 0b10010110101100000101100101010001;
  src1.bits[2] = 0b00010001101000010111101110000001;
  src1.bits[3] = 0b00000000000111000000000000000000;
  src2.bits[0] = 0b01101110100110100110010101111110;
  src2.bits[1] = 0b11100010111000110111110100101010;
  src2.bits[2] = 0b10110000010011101101001100001111;
  src2.bits[3] = 0b00000000000111000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_32) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -7.7545545454546589781677545545;
  // src2 = -7.7545545454546589781677545545;
  src1.bits[0] = 0b00000101101101111001100001001001;
  src1.bits[1] = 0b01101011011011011010110110010010;
  src1.bits[2] = 0b11111010100100000010101111111010;
  src1.bits[3] = 0b10000000000111000000000000000000;
  src2.bits[0] = 0b00000101101101111001100001001001;
  src2.bits[1] = 0b01101011011011011010110110010010;
  src2.bits[2] = 0b11111010100100000010101111111010;
  src2.bits[3] = 0b10000000000111000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_33) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -79228162514264337593543950335;
  // src2 = -792281625.14264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b10000000000101000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_34) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 675432788976.5424354657687;
  // src2 = 67543278.89765424354657687;
  src1.bits[0] = 0b10111110000100011000010110010111;
  src1.bits[1] = 0b11011001001111010001001011000110;
  src1.bits[2] = 0b00000000000001011001011001001000;
  src1.bits[3] = 0b00000000000011010000000000000000;
  src2.bits[0] = 0b10111110000100011000010110010111;
  src2.bits[1] = 0b11011001001111010001001011000110;
  src2.bits[2] = 0b00000000000001011001011001001000;
  src2.bits[3] = 0b00000000000100010000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_35) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -579895323215489956.67897455465;
  // src2 = -579895323215489956.67897455465;
  src1.bits[0] = 0b11100110001001011001001101101001;
  src1.bits[1] = 0b00111000110110101110001010110100;
  src1.bits[2] = 0b10111011010111111101000100011110;
  src1.bits[3] = 0b10000000000010110000000000000000;
  src2.bits[0] = 0b11100110001001011001001101101001;
  src2.bits[1] = 0b00111000110110101110001010110100;
  src2.bits[2] = 0b10111011010111111101000100011110;
  src2.bits[3] = 0b10000000000010110000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_36) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 18446744073709551615.0;
  // src2 = 1844674407370955161.50;
  src1.bits[0] = 0b11111111111111111111111111110110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000001001;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b11111111111111111111111111110110;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b00000000000000000000000000001001;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_37) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 44073709551615.0;
  // src2 = 44073709551615.00000000;
  src1.bits[0] = 0b00011010000001000111111111110110;
  src1.bits[1] = 0b00000000000000011001000011011001;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b10011111010010100001111100000000;
  src2.bits[1] = 0b11101100100011110001010001110111;
  src2.bits[2] = 0b00000000000000000000000011101110;
  src2.bits[3] = 0b00000000000010000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_38) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 228162514264337.5935439503;
  // src2 = 228162514264337.59354395030000;
  src1.bits[0] = 0b01010010111101011100001010001111;
  src1.bits[1] = 0b00100101100101100010101000001101;
  src1.bits[2] = 0b00000000000000011110001100100111;
  src1.bits[3] = 0b00000000000010100000000000000000;
  src2.bits[0] = 0b10011111111111111111000111110000;
  src2.bits[1] = 0b00111001110010101010100001111000;
  src2.bits[2] = 0b01001001101110010010100100101100;
  src2.bits[3] = 0b00000000000011100000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_39) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -754554545454658.97816770;
  // src2 = -754554545454658.9781677;
  src1.bits[0] = 0b00100000101101101001001011000010;
  src1.bits[1] = 0b01110010110010011000000011111000;
  src1.bits[2] = 0b00000000000000000000111111111010;
  src1.bits[3] = 0b10000000000010000000000000000000;
  src2.bits[0] = 0b10011100110111110000111010101101;
  src2.bits[1] = 0b00001011011110101000110011100101;
  src2.bits[2] = 0b00000000000000000000000110011001;
  src2.bits[3] = 0b10000000000001110000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_40) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -2.514264337593543;
  // src2 = -2.514264337593542;
  src1.bits[0] = 0b11001000101101101011010011000111;
  src1.bits[1] = 0b00000000000010001110111010110101;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000011110000000000000000;
  src2.bits[0] = 0b11001000101101101011010011000110;
  src2.bits[1] = 0b00000000000010001110111010110101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000011110000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

///////////////---is_greater_or_equal---///////////

START_TEST(s21_greater_or_equal_1) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2;
  // src2 = 2;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_2) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 457;
  // src2 = 2.00;
  src1.bits[0] = 0b00000000000000000000000111001001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000011001000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_3) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2;
  // src2 = 54;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000110110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_4) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 0.000000000000000000000000000;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000110110000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_5) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -3;
  // src2 = 3;
  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_6) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.222212;
  // src2 = 2.222212;
  src1.bits[0] = 0b00000000001000011110100010000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  src2.bits[0] = 0b00000000001000011110100010000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_7) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.22221200000001000;
  // src2 = 2.222212;
  src1.bits[0] = 0b00000111100011111010001111101000;
  src1.bits[1] = 0b00000011000101010111110100000001;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000100010000000000000000;
  src2.bits[0] = 0b00000000001000011110100010000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_8) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 3.745754741;
  // src2 = 3.222212;
  src1.bits[0] = 0b11011111010000111010111001110101;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000010010000000000000000;
  src2.bits[0] = 0b00000000001100010010101011000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_9) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.222212;
  // src2 = -2.2222120002;
  src1.bits[0] = 0b00000000001000011110100010000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  src2.bits[0] = 0b00101100100010101010010001000010;
  src2.bits[1] = 0b00000000000000000000000000000101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000010100000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_10) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -364748;
  // src2 = 1;
  src1.bits[0] = 0b00000000000001011001000011001100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_11) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 987456543210.0;
  // src2 = 98745654321.0;
  src1.bits[0] = 0b00011001111101110000001100100100;
  src1.bits[1] = 0b00000000000000000000100011111011;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b11101000111111110001100111101010;
  src2.bits[1] = 0b00000000000000000000000011100101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000010000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_12) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -9878798789.5867800;
  // src2 = -9878798789.58678;
  src1.bits[0] = 0b11001110100110111101100110011000;
  src1.bits[1] = 0b00000001010111101111011100100110;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001110000000000000000;
  src2.bits[0] = 0b10110101010001000001111001010110;
  src2.bits[1] = 0b00000000000000111000001001111000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001010000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_13) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 9999999999999999999;
  // src2 = 1;
  src1.bits[0] = 0b10001001111001111111111111111111;
  src1.bits[1] = 0b10001010110001110010001100000100;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_14) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 18446744073709551615;
  // src2 = 434345343551615.00000000000;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b01000110001111010001100000000000;
  src2.bits[1] = 0b11010011010011111110100110011101;
  src2.bits[2] = 0b00000000001000111110110110011110;
  src2.bits[3] = 0b00000000000010110000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_15) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 18446744073709551615.0;
  // src2 = 965453154;
  src1.bits[0] = 0b11111111111111111111111111110110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000001001;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b00111001100010111010010101100010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_16) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -796214545.3526545454564545456;
  // src2 = -545454512454545.35265454545645;
  src1.bits[0] = 0b10111111111111101001001110110000;
  src1.bits[1] = 0b11101010111111101111100111101000;
  src1.bits[2] = 0b00011001101110100010000111100001;
  src1.bits[3] = 0b10000000000100110000000000000000;
  src2.bits[0] = 0b10000010111000100101101011101101;
  src2.bits[1] = 0b11111001111010000010010110101101;
  src2.bits[2] = 0b10110000001111101111000010010100;
  src2.bits[3] = 0b10000000000011100000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_17) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -545454512454545.35265454545645;
  // src2 = -5.352654545456454545645464;
  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;
  src2.bits[0] = 0b01001000000110110001111110011000;
  src2.bits[1] = 0b11111011111111011000100101101101;
  src2.bits[2] = 0b00000000000001000110110101110111;
  src2.bits[3] = 0b10000000000110000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_18) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -7961327845421.843434341378545;
  // src2 = 7961327.845421879754123131254;
  src1.bits[0] = 0b11110011001100111010100111110001;
  src1.bits[1] = 0b01001011001101011000000011010000;
  src1.bits[2] = 0b00011001101110010111010010111111;
  src1.bits[3] = 0b10000000000011110000000000000000;
  src2.bits[0] = 0b01001110111001000011100101110110;
  src2.bits[1] = 0b01001011001101011010000111011001;
  src2.bits[2] = 0b00011001101110010111010010111111;
  src2.bits[3] = 0b00000000000101010000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_19) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 12345677.987654345678987654346;
  // src2 = 12345677.987654000000000000000;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;
  src2.bits[0] = 0b11100111110001110000000000000000;
  src2.bits[1] = 0b11000000010001001001101110001101;
  src2.bits[2] = 0b00100111111001000001101100000000;
  src2.bits[3] = 0b00000000000101010000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_20) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 12345677.987654345678987654346;
  // src2 = 145752736456.9876545678987653;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;
  src2.bits[0] = 0b10001101100101011101000110000101;
  src2.bits[1] = 0b11000001100101010111000111101011;
  src2.bits[2] = 0b00000100101101011010001101101100;
  src2.bits[3] = 0b00000000000100000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_21) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 87654323456.98765456789876530;
  // src2 = -87654323456.98765456789876531;
  src1.bits[0] = 0b10110010000010100010111100110010;
  src1.bits[1] = 0b10011001010111000101110110000000;
  src1.bits[2] = 0b00011100010100101001100001111111;
  src1.bits[3] = 0b00000000000100010000000000000000;
  src2.bits[0] = 0b10110010000010100010111100110011;
  src2.bits[1] = 0b10011001010111000101110110000000;
  src2.bits[2] = 0b00011100010100101001100001111111;
  src2.bits[3] = 0b10000000000100010000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_22) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -854764561465456456.9876545679;
  // src2 = -87654323456.98765456789876530;
  src1.bits[0] = 0b11000100000001000100000010001111;
  src1.bits[1] = 0b01000000100100100110001100010101;
  src1.bits[2] = 0b00011011100111100111001001011101;
  src1.bits[3] = 0b10000000000010100000000000000000;
  src2.bits[0] = 0b10110010000010100010111100110010;
  src2.bits[1] = 0b10011001010111000101110110000000;
  src2.bits[2] = 0b00011100010100101001100001111111;
  src2.bits[3] = 0b10000000000100010000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_23) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 0.0;
  // src2 = 0.69;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b00000000000000000000000001000101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_24) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -69.1234567;
  // src2 = -69.12345670000000;
  src1.bits[0] = 0b00101001001100110110011100000111;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001110000000000000000;
  src2.bits[0] = 0b11100100001110011001110110000000;
  src2.bits[1] = 0b00000000000110001000111010111101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000011100000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_25) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 13436577854.000000000000;
  // src2 = 13436577854;
  src1.bits[0] = 0b00100110011110011110000000000000;
  src1.bits[1] = 0b01100101111110011111000000101100;
  src1.bits[2] = 0b00000000000000000000001011011000;
  src1.bits[3] = 0b00000000000011000000000000000000;
  src2.bits[0] = 0b00100000111000011110100000111110;
  src2.bits[1] = 0b00000000000000000000000000000011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_26) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 79228162514264337593543950335;
  // src2 = 79228162514264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_27) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 79228162514264337593543950335;
  // src2 = -79228162514264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b10000000000000000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_28) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 665464545;
  // src2 = 8798232189789785;
  src1.bits[0] = 0b00100111101010100010111011100001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00010000010100101110011001011001;
  src2.bits[1] = 0b00000000000111110100000111110010;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_29) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.7986531268974139743;
  // src2 = 2.7986531268974139743;
  src1.bits[0] = 0b11111110100100001101100101011111;
  src1.bits[1] = 0b10000100011001000010000111101000;
  src1.bits[2] = 0b00000000000000000000000000000001;
  src1.bits[3] = 0b00000000000100110000000000000000;
  src2.bits[0] = 0b11111110100100001101100101011111;
  src2.bits[1] = 0b10000100011001000010000111101000;
  src2.bits[2] = 0b00000000000000000000000000000001;
  src2.bits[3] = 0b00000000000100110000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_30) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -2156878451.8547640000000000;
  // src2 = -2156878451.854764;
  src1.bits[0] = 0b10010011100100010011000000000000;
  src1.bits[1] = 0b00100110110100100010010100001001;
  src1.bits[2] = 0b00000000000100011101011101011110;
  src1.bits[3] = 0b10000000000100000000000000000000;
  src2.bits[0] = 0b01100101111100100100110110101100;
  src2.bits[1] = 0b00000000000001111010100110101011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001100000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_31) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 0.5456465465486476846545465485;
  // src2 = 45645405.456456345684654546548;
  src1.bits[0] = 0b00001011000011110111000010001101;
  src1.bits[1] = 0b10010110101100000101100101010001;
  src1.bits[2] = 0b00010001101000010111101110000001;
  src1.bits[3] = 0b00000000000111000000000000000000;
  src2.bits[0] = 0b01000110110111011101111001110100;
  src2.bits[1] = 0b11111110010110110111101101110010;
  src2.bits[2] = 0b10010011011111001111111010010011;
  src2.bits[3] = 0b00000000000101010000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_32) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -776890.75455454213415678965898;
  // src2 = -7.7545545454546589781677545545;
  src1.bits[0] = 0b11000010010111101111100010001010;
  src1.bits[1] = 0b01011100000101000111000011011000;
  src1.bits[2] = 0b11111011000001101110010110100011;
  src1.bits[3] = 0b10000000000101110000000000000000;
  src2.bits[0] = 0b00000101101101111001100001001001;
  src2.bits[1] = 0b01101011011011011010110110010010;
  src2.bits[2] = 0b11111010100100000010101111111010;
  src2.bits[3] = 0b10000000000111000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_33) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -732123534337593543950335.12;
  // src2 = -792281625.14264337593543950335;
  src1.bits[0] = 0b11000011000110111111111110101000;
  src1.bits[1] = 0b10100001110111010100101100101110;
  src1.bits[2] = 0b00000000001111001000111101010001;
  src1.bits[3] = 0b10000000000000100000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b10000000000101000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_34) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 675432788976.5424354657687;
  // src2 = 67543278.89765424354657687;
  src1.bits[0] = 0b10111110000100011000010110010111;
  src1.bits[1] = 0b11011001001111010001001011000110;
  src1.bits[2] = 0b00000000000001011001011001001000;
  src1.bits[3] = 0b00000000000011010000000000000000;
  src2.bits[0] = 0b10111110000100011000010110010111;
  src2.bits[1] = 0b11011001001111010001001011000110;
  src2.bits[2] = 0b00000000000001011001011001001000;
  src2.bits[3] = 0b00000000000100010000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_35) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -579895323215489956.67897455465;
  // src2 = -579895323215489956.67897455465;
  src1.bits[0] = 0b11100110001001011001001101101001;
  src1.bits[1] = 0b00111000110110101110001010110100;
  src1.bits[2] = 0b10111011010111111101000100011110;
  src1.bits[3] = 0b10000000000010110000000000000000;
  src2.bits[0] = 0b11100110001001011001001101101001;
  src2.bits[1] = 0b00111000110110101110001010110100;
  src2.bits[2] = 0b10111011010111111101000100011110;
  src2.bits[3] = 0b10000000000010110000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_36) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 123523543453453453.0;
  // src2 = 1844674407370955161.50;
  src1.bits[0] = 0b01001001011001111111110110000010;
  src1.bits[1] = 0b00010001001001000111000000010101;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b11111111111111111111111111110110;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b00000000000000000000000000001001;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_37) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 31231232456315.0;
  // src2 = 44073709551615.00000000;
  src1.bits[0] = 0b11100001001010100010000011001110;
  src1.bits[1] = 0b00000000000000010001110000001011;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b10011111010010100001111100000000;
  src2.bits[1] = 0b11101100100011110001010001110111;
  src2.bits[2] = 0b00000000000000000000000011101110;
  src2.bits[3] = 0b00000000000010000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_38) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 78987543557678337.5935439503;
  // src2 = 228162514264337.59354395030000;
  src1.bits[0] = 0b00111011110001111000001010001111;
  src1.bits[1] = 0b00101001100010100010010001100011;
  src1.bits[2] = 0b00000010100011010101111010100001;
  src1.bits[3] = 0b00000000000010100000000000000000;
  src2.bits[0] = 0b10011111111111111111000111110000;
  src2.bits[1] = 0b00111001110010101010100001111000;
  src2.bits[2] = 0b01001001101110010010100100101100;
  src2.bits[3] = 0b00000000000011100000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_39) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -754567488438.97816770;
  // src2 = -754554545454658.9781677;
  src1.bits[0] = 0b01011010011001011000011011000010;
  src1.bits[1] = 0b00010111001011000011100101001001;
  src1.bits[2] = 0b00000000000000000000000000000100;
  src1.bits[3] = 0b10000000000010000000000000000000;
  src2.bits[0] = 0b10011100110111110000111010101101;
  src2.bits[1] = 0b00001011011110101000110011100101;
  src2.bits[2] = 0b00000000000000000000000110011001;
  src2.bits[3] = 0b10000000000001110000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_40) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -2.514475768684753643;
  // src2 = -2.514264337593542;
  src1.bits[0] = 0b10101100110010000011001011101011;
  src1.bits[1] = 0b00100010111001010011011001100011;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000100100000000000000000;
  src2.bits[0] = 0b11001000101101101011010011000110;
  src2.bits[1] = 0b00000000000010001110111010110101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000011110000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

//////////////---not_equal---///////////

START_TEST(s21_not_equal_1_1) {
  s21_decimal first = {{4412, 5675, 1254, 0b00000100000000000010000000000000}};
  s21_decimal second = {{4412, 5675, 1254, 0b00000100000000000010000000000000}};
  ck_assert_int_eq(s21_is_not_equal(first, second), 0);
}
END_TEST

START_TEST(s21_not_equal_2_1) {
  s21_decimal first = {{4412, 5675, 1254, 0b10000100000000000010000000000000}};
  s21_decimal second = {{4412, 5675, 1254, 0b10000100000000000010000000000000}};
  ck_assert_int_eq(s21_is_not_equal(first, second), 0);
}
END_TEST

START_TEST(s21_not_equal_3_fraction_1) {
  s21_decimal first = {{4412, 5675, 1254, 0b10110010000000001110000111000011}};
  s21_decimal second = {{4412, 5675, 1254, 0b11001001000000000010000111111110}};
  ck_assert_int_eq(s21_is_not_equal(first, second), 0);
}
END_TEST

START_TEST(s21_not_equal_4_sign_1) {
  s21_decimal first = {{4412, 5675, 1254, 0b10110100111111110010000000000011}};
  s21_decimal second = {{4412, 5675, 1254, 0b01110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_not_equal(first, second), 1);
}
END_TEST

START_TEST(s21_not_equal_5_sign_1) {
  s21_decimal first = {{4412, 5675, 1254, 0b00110100111111110010000000000011}};
  s21_decimal second = {{4412, 5675, 1254, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_not_equal(first, second), 1);
}
END_TEST

START_TEST(s21_not_equal_6_1) {
  s21_decimal first = {{4412, 5675, 1154, 0b10110100111111110010000000000011}};
  s21_decimal second = {{4412, 5675, 1254, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_not_equal(first, second), 1);
}
END_TEST

START_TEST(s21_not_equal_7_1) {
  s21_decimal first = {{4412, 5675, 1254, 0b10110100111111110010000000000011}};
  s21_decimal second = {{4412, 5675, 1244, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_not_equal(first, second), 1);
}
END_TEST

START_TEST(s21_not_equal_8_1) {
  s21_decimal first = {{4412, 5675, 1254, 0b10110100111111110010000000000011}};
  s21_decimal second = {
      {4412, 5675, 12541, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_not_equal(first, second), 1);
}
END_TEST

START_TEST(s21_not_equal_9_ss_1) {
  s21_decimal first = {
      {0x4A1D, 05675, 1254, 0b10110100111111110010000000000011}};
  s21_decimal second = {
      {0x4A1D, 05675, 1254, 0b10110100111111110010000000000011}};
  ck_assert_int_eq(s21_is_not_equal(first, second), 0);
}
END_TEST

START_TEST(s21_not_equal_10_1) {
  s21_decimal first = {{412, 5675, 1254, 0b10110100111111110010000000000011}};
  s21_decimal second = {{4412, 5675, 1254, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_not_equal(first, second), 1);
}
END_TEST

START_TEST(s21_not_equal_11_zero_1) {
  s21_decimal first = {{0, 0, 0, 0b11110100000000000010000111111110}};
  s21_decimal second = {{0, 0, 0, 0b01110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_not_equal(first, second), 0);
}
END_TEST

START_TEST(s21_not_equal_12_value_1) {
  s21_decimal first = {
      {1564, 31452, 6109410, 0b11110100000000000010000111111110}};
  s21_decimal second = {
      {1564, 31452, 610941, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_not_equal(first, second), 1);
}
END_TEST

START_TEST(s21_not_equal_13_value_1) {
  s21_decimal first = {
      {1564, 31452, 610941, 0b11110100000000000010000111111110}};
  s21_decimal second = {
      {1564, 3142, 610941, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_not_equal(first, second), 1);
}
END_TEST

START_TEST(s21_not_equal_14_value_1) {
  s21_decimal first = {
      {15614, 31452, 610941, 0b11110100000000000010000111111110}};
  s21_decimal second = {
      {1564, 31452, 610941, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_not_equal(first, second), 1);
}
END_TEST

START_TEST(s21_not_equal_1) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2;
  // src2 = 2;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_2) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2;
  // src2 = 2.00;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000011001000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_3) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2;
  // src2 = 3;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_4) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 0.000000000000000000000000000;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000110110000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_5) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -3;
  // src2 = 3;
  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_6) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.222212;
  // src2 = 2.222212;
  src1.bits[0] = 0b00000000001000011110100010000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  src2.bits[0] = 0b00000000001000011110100010000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_7) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.22221200000000000;
  // src2 = 2.222212;
  src1.bits[0] = 0b00000111100011111010000000000000;
  src1.bits[1] = 0b00000011000101010111110100000001;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000100010000000000000000;
  src2.bits[0] = 0b00000000001000011110100010000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_8) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 3.2222121;
  // src2 = 3.222212;
  src1.bits[0] = 0b00000001111010111010101110101001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001110000000000000000;
  src2.bits[0] = 0b00000000001100010010101011000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_9) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.222212;
  // src2 = -2.222212;
  src1.bits[0] = 0b00000000001000011110100010000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  src2.bits[0] = 0b00000000001000011110100010000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001100000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_10) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -364748;
  // src2 = 1;
  src1.bits[0] = 0b00000000000001011001000011001100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_11) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 987456543210.0;
  // src2 = 98745654321.0;
  src1.bits[0] = 0b00011001111101110000001100100100;
  src1.bits[1] = 0b00000000000000000000100011111011;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b11101000111111110001100111101010;
  src2.bits[1] = 0b00000000000000000000000011100101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000010000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_12) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -9878798789.5867800;
  // src2 = -9878798789.58678;
  src1.bits[0] = 0b11001110100110111101100110011000;
  src1.bits[1] = 0b00000001010111101111011100100110;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001110000000000000000;
  src2.bits[0] = 0b10110101010001000001111001010110;
  src2.bits[1] = 0b00000000000000111000001001111000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001010000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_13) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 9999999999999999999;
  // src2 = 1;
  src1.bits[0] = 0b10001001111001111111111111111111;
  src1.bits[1] = 0b10001010110001110010001100000100;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_14) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 18446744073709551615;
  // src2 = 18446744073709551615.000000000;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11000100011001010011011000000000;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b00111011100110101100100111111111;
  src2.bits[3] = 0b00000000000010010000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_15) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 18446744073709551615.0;
  // src2 = 965453154;
  src1.bits[0] = 0b11111111111111111111111111110110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000001001;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b00111001100010111010010101100010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_16) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -545454512454545.35265454545645;
  // src2 = -545454512454545.35265454545645;
  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;
  src2.bits[0] = 0b10000010111000100101101011101101;
  src2.bits[1] = 0b11111001111010000010010110101101;
  src2.bits[2] = 0b10110000001111101111000010010100;
  src2.bits[3] = 0b10000000000011100000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_17) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -545454512454545.35265454545645;
  // src2 = -5.352654545456454545645464;
  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;
  src2.bits[0] = 0b01001000000110110001111110011000;
  src2.bits[1] = 0b11111011111111011000100101101101;
  src2.bits[2] = 0b00000000000001000110110101110111;
  src2.bits[3] = 0b10000000000110000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_18) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 7961327845421.879754123131254;
  // src2 = 7961327.845421879754123131254;
  src1.bits[0] = 0b01001110111001000011100101110110;
  src1.bits[1] = 0b01001011001101011010000111011001;
  src1.bits[2] = 0b00011001101110010111010010111111;
  src1.bits[3] = 0b00000000000011110000000000000000;
  src2.bits[0] = 0b01001110111001000011100101110110;
  src2.bits[1] = 0b01001011001101011010000111011001;
  src2.bits[2] = 0b00011001101110010111010010111111;
  src2.bits[3] = 0b00000000000101010000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_19) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 12345677.987654345678987654346;
  // src2 = 12345677.987654000000000000000;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;
  src2.bits[0] = 0b11100111110001110000000000000000;
  src2.bits[1] = 0b11000000010001001001101110001101;
  src2.bits[2] = 0b00100111111001000001101100000000;
  src2.bits[3] = 0b00000000000101010000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_20) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -12345677.987654345678987654346;
  // src2 = 87654323456.9876545678987653;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b10000000000101010000000000000000;
  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b00000000000100000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_21) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -87654323456.98765456789876530;
  // src2 = -87654323456.98765456789876531;
  src1.bits[0] = 0b10110010000010100010111100110010;
  src1.bits[1] = 0b10011001010111000101110110000000;
  src1.bits[2] = 0b00011100010100101001100001111111;
  src1.bits[3] = 0b10000000000100010000000000000000;
  src2.bits[0] = 0b10110010000010100010111100110011;
  src2.bits[1] = 0b10011001010111000101110110000000;
  src2.bits[2] = 0b00011100010100101001100001111111;
  src2.bits[3] = 0b10000000000100010000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_22) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -87654323456.98765456789876530;
  // src2 = -87654323456.98765456789876530;
  src1.bits[0] = 0b10110010000010100010111100110010;
  src1.bits[1] = 0b10011001010111000101110110000000;
  src1.bits[2] = 0b00011100010100101001100001111111;
  src1.bits[3] = 0b10000000000100010000000000000000;
  src2.bits[0] = 0b10110010000010100010111100110010;
  src2.bits[1] = 0b10011001010111000101110110000000;
  src2.bits[2] = 0b00011100010100101001100001111111;
  src2.bits[3] = 0b10000000000100010000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_23) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 0.0;
  // src2 = 0.69;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b00000000000000000000000001000101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_24) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -69.1234567;
  // src2 = -69.12345670000000;
  src1.bits[0] = 0b00101001001100110110011100000111;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001110000000000000000;
  src2.bits[0] = 0b11100100001110011001110110000000;
  src2.bits[1] = 0b00000000000110001000111010111101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000011100000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_25) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 13436577854.000000000000;
  // src2 = 13436577854;
  src1.bits[0] = 0b00100110011110011110000000000000;
  src1.bits[1] = 0b01100101111110011111000000101100;
  src1.bits[2] = 0b00000000000000000000001011011000;
  src1.bits[3] = 0b00000000000011000000000000000000;
  src2.bits[0] = 0b00100000111000011110100000111110;
  src2.bits[1] = 0b00000000000000000000000000000011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_26) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 79228162514264337593543950335;
  // src2 = 79228162514264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_27) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 79228162514264337593543950335;
  // src2 = -79228162514264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b10000000000000000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_28) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 665464545;
  // src2 = 8798232189789785;
  src1.bits[0] = 0b00100111101010100010111011100001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00010000010100101110011001011001;
  src2.bits[1] = 0b00000000000111110100000111110010;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_29) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.7986531268974139743;
  // src2 = 2.7986531268974139743;
  src1.bits[0] = 0b11111110100100001101100101011111;
  src1.bits[1] = 0b10000100011001000010000111101000;
  src1.bits[2] = 0b00000000000000000000000000000001;
  src1.bits[3] = 0b00000000000100110000000000000000;
  src2.bits[0] = 0b11111110100100001101100101011111;
  src2.bits[1] = 0b10000100011001000010000111101000;
  src2.bits[2] = 0b00000000000000000000000000000001;
  src2.bits[3] = 0b00000000000100110000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_30) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -2156878451.8547640000000000;
  // src2 = -2156878451.854764;
  src1.bits[0] = 0b10010011100100010011000000000000;
  src1.bits[1] = 0b00100110110100100010010100001001;
  src1.bits[2] = 0b00000000000100011101011101011110;
  src1.bits[3] = 0b10000000000100000000000000000000;
  src2.bits[0] = 0b01100101111100100100110110101100;
  src2.bits[1] = 0b00000000000001111010100110101011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001100000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_31) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 0.5456465465486476846545465485;
  // src2 = 5.4564654654864768465454654846;
  src1.bits[0] = 0b00001011000011110111000010001101;
  src1.bits[1] = 0b10010110101100000101100101010001;
  src1.bits[2] = 0b00010001101000010111101110000001;
  src1.bits[3] = 0b00000000000111000000000000000000;
  src2.bits[0] = 0b01101110100110100110010101111110;
  src2.bits[1] = 0b11100010111000110111110100101010;
  src2.bits[2] = 0b10110000010011101101001100001111;
  src2.bits[3] = 0b00000000000111000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_32) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -7.7545545454546589781677545545;
  // src2 = -7.7545545454546589781677545545;
  src1.bits[0] = 0b00000101101101111001100001001001;
  src1.bits[1] = 0b01101011011011011010110110010010;
  src1.bits[2] = 0b11111010100100000010101111111010;
  src1.bits[3] = 0b10000000000111000000000000000000;
  src2.bits[0] = 0b00000101101101111001100001001001;
  src2.bits[1] = 0b01101011011011011010110110010010;
  src2.bits[2] = 0b11111010100100000010101111111010;
  src2.bits[3] = 0b10000000000111000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_33) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -79228162514264337593543950335;
  // src2 = -792281625.14264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b10000000000101000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_34) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 675432788976.5424354657687;
  // src2 = 67543278.89765424354657687;
  src1.bits[0] = 0b10111110000100011000010110010111;
  src1.bits[1] = 0b11011001001111010001001011000110;
  src1.bits[2] = 0b00000000000001011001011001001000;
  src1.bits[3] = 0b00000000000011010000000000000000;
  src2.bits[0] = 0b10111110000100011000010110010111;
  src2.bits[1] = 0b11011001001111010001001011000110;
  src2.bits[2] = 0b00000000000001011001011001001000;
  src2.bits[3] = 0b00000000000100010000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_35) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -579895323215489956.67897455465;
  // src2 = -579895323215489956.67897455465;
  src1.bits[0] = 0b11100110001001011001001101101001;
  src1.bits[1] = 0b00111000110110101110001010110100;
  src1.bits[2] = 0b10111011010111111101000100011110;
  src1.bits[3] = 0b10000000000010110000000000000000;
  src2.bits[0] = 0b11100110001001011001001101101001;
  src2.bits[1] = 0b00111000110110101110001010110100;
  src2.bits[2] = 0b10111011010111111101000100011110;
  src2.bits[3] = 0b10000000000010110000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_36) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 18446744073709551615.0;
  // src2 = 1844674407370955161.50;
  src1.bits[0] = 0b11111111111111111111111111110110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000001001;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b11111111111111111111111111110110;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b00000000000000000000000000001001;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_37) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 44073709551615.0;
  // src2 = 44073709551615.00000000;
  src1.bits[0] = 0b00011010000001000111111111110110;
  src1.bits[1] = 0b00000000000000011001000011011001;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b10011111010010100001111100000000;
  src2.bits[1] = 0b11101100100011110001010001110111;
  src2.bits[2] = 0b00000000000000000000000011101110;
  src2.bits[3] = 0b00000000000010000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_38) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 228162514264337.5935439503;
  // src2 = 228162514264337.59354395030000;
  src1.bits[0] = 0b01010010111101011100001010001111;
  src1.bits[1] = 0b00100101100101100010101000001101;
  src1.bits[2] = 0b00000000000000011110001100100111;
  src1.bits[3] = 0b00000000000010100000000000000000;
  src2.bits[0] = 0b10011111111111111111000111110000;
  src2.bits[1] = 0b00111001110010101010100001111000;
  src2.bits[2] = 0b01001001101110010010100100101100;
  src2.bits[3] = 0b00000000000011100000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_39) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -754554545454658.97816770;
  // src2 = -754554545454658.9781677;
  src1.bits[0] = 0b00100000101101101001001011000010;
  src1.bits[1] = 0b01110010110010011000000011111000;
  src1.bits[2] = 0b00000000000000000000111111111010;
  src1.bits[3] = 0b10000000000010000000000000000000;
  src2.bits[0] = 0b10011100110111110000111010101101;
  src2.bits[1] = 0b00001011011110101000110011100101;
  src2.bits[2] = 0b00000000000000000000000110011001;
  src2.bits[3] = 0b10000000000001110000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_not_equal_40) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -2.514264337593543;
  // src2 = -2.5142643375935430000000000000;
  src1.bits[0] = 0b11001000101101101011010011000111;
  src1.bits[1] = 0b00000000000010001110111010110101;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000011110000000000000000;
  src2.bits[0] = 0b01010011100110100110000000000000;
  src2.bits[1] = 0b10000010110010001001101110001011;
  src2.bits[2] = 0b01010001001111011000000111010100;
  src2.bits[3] = 0b10000000000111000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

////////////////----------s21_negate----------/////////////////

START_TEST(s21_negate_1) {
  s21_decimal src1, origin, result;
  // src1 = 2.1234;
  src1.bits[0] = 0b00000000000000000101001011110010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001000000000000000000;
  // origin = -2.1234;
  origin.bits[0] = 0b00000000000000000101001011110010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000001000000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_negate_2) {
  s21_decimal src1, origin, result;
  // src1 = 457.000001;
  src1.bits[0] = 0b00011011001111010100010001000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  // origin = -457.000001;
  origin.bits[0] = 0b00011011001111010100010001000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000001100000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_negate_3) {
  s21_decimal src1, origin, result;
  // src1 = 2.000;
  src1.bits[0] = 0b00000000000000000000011111010000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000110000000000000000;
  // origin = -2.000;
  origin.bits[0] = 0b00000000000000000000011111010000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000110000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_negate_4) {
  s21_decimal src1, origin, result;
  // src1 = 0.000000000000000000000000000;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000110110000000000000000;
  // origin = 0.000000000000000000000000000;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000110110000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_negate_5) {
  s21_decimal src1, origin, result;
  // src1 = -3;
  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  // origin = 3;
  origin.bits[0] = 0b00000000000000000000000000000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_negate_6) {
  s21_decimal src1, origin, result;
  // src1 = 2.222212;
  src1.bits[0] = 0b00000000001000011110100010000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  // origin = -2.222212;
  origin.bits[0] = 0b00000000001000011110100010000100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000001100000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_negate_7) {
  s21_decimal src1, origin, result;
  // src1 = 2.22221200000001000;
  src1.bits[0] = 0b00000111100011111010001111101000;
  src1.bits[1] = 0b00000011000101010111110100000001;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000100010000000000000000;
  // origin = -2.22221200000001000;
  origin.bits[0] = 0b00000111100011111010001111101000;
  origin.bits[1] = 0b00000011000101010111110100000001;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000100010000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_negate_8) {
  s21_decimal src1, origin, result;
  // src1 = 3.745754741;
  src1.bits[0] = 0b11011111010000111010111001110101;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000010010000000000000000;
  // origin = -3.745754741;
  origin.bits[0] = 0b11011111010000111010111001110101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000010010000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_negate_9) {
  s21_decimal src1, origin, result;
  // src1 = 2.222212;
  src1.bits[0] = 0b00000000001000011110100010000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  // origin = -2.222212;
  origin.bits[0] = 0b00000000001000011110100010000100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000001100000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_negate_10) {
  s21_decimal src1, origin, result;
  // src1 = -364748;
  src1.bits[0] = 0b00000000000001011001000011001100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  // origin = 364748;
  origin.bits[0] = 0b00000000000001011001000011001100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_negate_11) {
  s21_decimal src1, origin, result;
  // src1 = 987456543210.0;
  src1.bits[0] = 0b00011001111101110000001100100100;
  src1.bits[1] = 0b00000000000000000000100011111011;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  // origin = -987456543210.0;
  origin.bits[0] = 0b00011001111101110000001100100100;
  origin.bits[1] = 0b00000000000000000000100011111011;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000010000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_negate_12) {
  s21_decimal src1, origin, result;
  // src1 = -9878798789.5867800;
  src1.bits[0] = 0b11001110100110111101100110011000;
  src1.bits[1] = 0b00000001010111101111011100100110;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001110000000000000000;
  // origin = 9878798789.5867800;
  origin.bits[0] = 0b11001110100110111101100110011000;
  origin.bits[1] = 0b00000001010111101111011100100110;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000001110000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_negate_13) {
  s21_decimal src1, origin, result;
  // src1 = 9999999999999999999;
  src1.bits[0] = 0b10001001111001111111111111111111;
  src1.bits[1] = 0b10001010110001110010001100000100;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  // origin = -9999999999999999999;
  origin.bits[0] = 0b10001001111001111111111111111111;
  origin.bits[1] = 0b10001010110001110010001100000100;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_negate_14) {
  s21_decimal src1, origin, result;
  // src1 = 18446744073709551615;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  // origin = -18446744073709551615;
  origin.bits[0] = 0b11111111111111111111111111111111;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_negate_15) {
  s21_decimal src1, origin, result;
  // src1 = 18446744073709551615.0;
  src1.bits[0] = 0b11111111111111111111111111110110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000001001;
  src1.bits[3] = 0b00000000000000010000000000000000;
  // origin = -18446744073709551615.0;
  origin.bits[0] = 0b11111111111111111111111111110110;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b00000000000000000000000000001001;
  origin.bits[3] = 0b10000000000000010000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_negate_16) {
  s21_decimal src1, origin, result;
  // src1 = -796214545.3526545454564545456;
  src1.bits[0] = 0b10111111111111101001001110110000;
  src1.bits[1] = 0b11101010111111101111100111101000;
  src1.bits[2] = 0b00011001101110100010000111100001;
  src1.bits[3] = 0b10000000000100110000000000000000;
  // origin = 796214545.3526545454564545456;
  origin.bits[0] = 0b10111111111111101001001110110000;
  origin.bits[1] = 0b11101010111111101111100111101000;
  origin.bits[2] = 0b00011001101110100010000111100001;
  origin.bits[3] = 0b00000000000100110000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_negate_17) {
  s21_decimal src1, origin, result;
  // src1 = -545454512454545.35265454545645;
  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;
  // origin = 545454512454545.35265454545645;
  origin.bits[0] = 0b10000010111000100101101011101101;
  origin.bits[1] = 0b11111001111010000010010110101101;
  origin.bits[2] = 0b10110000001111101111000010010100;
  origin.bits[3] = 0b00000000000011100000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_negate_18) {
  s21_decimal src1, origin, result;
  // src1 = -7961327845421.843434341378545;
  src1.bits[0] = 0b11110011001100111010100111110001;
  src1.bits[1] = 0b01001011001101011000000011010000;
  src1.bits[2] = 0b00011001101110010111010010111111;
  src1.bits[3] = 0b10000000000011110000000000000000;
  // origin = 7961327845421.843434341378545;
  origin.bits[0] = 0b11110011001100111010100111110001;
  origin.bits[1] = 0b01001011001101011000000011010000;
  origin.bits[2] = 0b00011001101110010111010010111111;
  origin.bits[3] = 0b00000000000011110000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_negate_19) {
  s21_decimal src1, origin, result;
  // src1 = 12345677.987654345678987654346;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;
  // origin = -12345677.987654345678987654346;
  origin.bits[0] = 0b10010001000010101111010011001010;
  origin.bits[1] = 0b11000000010001011101010111110010;
  origin.bits[2] = 0b00100111111001000001101100000000;
  origin.bits[3] = 0b10000000000101010000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_negate_20) {
  s21_decimal src1, origin, result;
  // src1 = 12345677.987654345678987654346;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;
  // origin = -12345677.987654345678987654346;
  origin.bits[0] = 0b10010001000010101111010011001010;
  origin.bits[1] = 0b11000000010001011101010111110010;
  origin.bits[2] = 0b00100111111001000001101100000000;
  origin.bits[3] = 0b10000000000101010000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_negate_21) {
  s21_decimal src1, origin, result;
  // src1 = 87654323456.98765456789876530;
  src1.bits[0] = 0b10110010000010100010111100110010;
  src1.bits[1] = 0b10011001010111000101110110000000;
  src1.bits[2] = 0b00011100010100101001100001111111;
  src1.bits[3] = 0b00000000000100010000000000000000;
  // origin = -87654323456.98765456789876530;
  origin.bits[0] = 0b10110010000010100010111100110010;
  origin.bits[1] = 0b10011001010111000101110110000000;
  origin.bits[2] = 0b00011100010100101001100001111111;
  origin.bits[3] = 0b10000000000100010000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_negate_22) {
  s21_decimal src1, origin, result;
  // src1 = -854764561465456456.9876545679;
  src1.bits[0] = 0b11000100000001000100000010001111;
  src1.bits[1] = 0b01000000100100100110001100010101;
  src1.bits[2] = 0b00011011100111100111001001011101;
  src1.bits[3] = 0b10000000000010100000000000000000;
  // origin = 854764561465456456.9876545679;
  origin.bits[0] = 0b11000100000001000100000010001111;
  origin.bits[1] = 0b01000000100100100110001100010101;
  origin.bits[2] = 0b00011011100111100111001001011101;
  origin.bits[3] = 0b00000000000010100000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_negate_23) {
  s21_decimal src1, origin, result;
  // src1 = 79228162514264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  // origin = -79228162514264337593543950335;
  origin.bits[0] = 0b11111111111111111111111111111111;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b11111111111111111111111111111111;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_negate_24) {
  s21_decimal src1, origin, result;
  // src1 = -69.1234567;
  src1.bits[0] = 0b00101001001100110110011100000111;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001110000000000000000;
  // origin = 69.1234567;
  origin.bits[0] = 0b00101001001100110110011100000111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000001110000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_negate_25) {
  s21_decimal src1, origin, result;
  // src1 = 13436577854.000000000000;
  src1.bits[0] = 0b00100110011110011110000000000000;
  src1.bits[1] = 0b01100101111110011111000000101100;
  src1.bits[2] = 0b00000000000000000000001011011000;
  src1.bits[3] = 0b00000000000011000000000000000000;
  // origin = -13436577854.000000000000;
  origin.bits[0] = 0b00100110011110011110000000000000;
  origin.bits[1] = 0b01100101111110011111000000101100;
  origin.bits[2] = 0b00000000000000000000001011011000;
  origin.bits[3] = 0b10000000000011000000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_negate_26) {
  s21_decimal src1, origin, result;
  // src1 = 79228162514264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  // origin = -79228162514264337593543950335;
  origin.bits[0] = 0b11111111111111111111111111111111;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b11111111111111111111111111111111;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_negate_27) {
  s21_decimal src1, origin, result;
  // src1 = 79228162514264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  // origin = -79228162514264337593543950335;
  origin.bits[0] = 0b11111111111111111111111111111111;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b11111111111111111111111111111111;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_negate_28) {
  s21_decimal src1, origin, result;
  // src1 = 665464545;
  src1.bits[0] = 0b00100111101010100010111011100001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  // origin = -665464545;
  origin.bits[0] = 0b00100111101010100010111011100001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_negate_29) {
  s21_decimal src1, origin, result;
  // src1 = 2.7986531268974139743;
  src1.bits[0] = 0b11111110100100001101100101011111;
  src1.bits[1] = 0b10000100011001000010000111101000;
  src1.bits[2] = 0b00000000000000000000000000000001;
  src1.bits[3] = 0b00000000000100110000000000000000;
  // origin = -2.7986531268974139743;
  origin.bits[0] = 0b11111110100100001101100101011111;
  origin.bits[1] = 0b10000100011001000010000111101000;
  origin.bits[2] = 0b00000000000000000000000000000001;
  origin.bits[3] = 0b10000000000100110000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_negate_30) {
  s21_decimal src1, origin, result;
  // src1 = -2156878451.8547640000000000;
  src1.bits[0] = 0b10010011100100010011000000000000;
  src1.bits[1] = 0b00100110110100100010010100001001;
  src1.bits[2] = 0b00000000000100011101011101011110;
  src1.bits[3] = 0b10000000000100000000000000000000;
  // origin = 2156878451.8547640000000000;
  origin.bits[0] = 0b10010011100100010011000000000000;
  origin.bits[1] = 0b00100110110100100010010100001001;
  origin.bits[2] = 0b00000000000100011101011101011110;
  origin.bits[3] = 0b00000000000100000000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_negate_31) {
  s21_decimal src1, origin, result;
  // src1 = 0.5456465465486476846545465485;
  src1.bits[0] = 0b00001011000011110111000010001101;
  src1.bits[1] = 0b10010110101100000101100101010001;
  src1.bits[2] = 0b00010001101000010111101110000001;
  src1.bits[3] = 0b00000000000111000000000000000000;
  // origin = -0.5456465465486476846545465485;
  origin.bits[0] = 0b00001011000011110111000010001101;
  origin.bits[1] = 0b10010110101100000101100101010001;
  origin.bits[2] = 0b00010001101000010111101110000001;
  origin.bits[3] = 0b10000000000111000000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_negate_32) {
  s21_decimal src1, origin, result;
  // src1 = -776890.75455454213415678965898;
  src1.bits[0] = 0b11000010010111101111100010001010;
  src1.bits[1] = 0b01011100000101000111000011011000;
  src1.bits[2] = 0b11111011000001101110010110100011;
  src1.bits[3] = 0b10000000000101110000000000000000;
  // origin = 776890.75455454213415678965898;
  origin.bits[0] = 0b11000010010111101111100010001010;
  origin.bits[1] = 0b01011100000101000111000011011000;
  origin.bits[2] = 0b11111011000001101110010110100011;
  origin.bits[3] = 0b00000000000101110000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_negate_33) {
  s21_decimal src1, origin, result;
  // src1 = -732123534337593543950335.12;
  src1.bits[0] = 0b11000011000110111111111110101000;
  src1.bits[1] = 0b10100001110111010100101100101110;
  src1.bits[2] = 0b00000000001111001000111101010001;
  src1.bits[3] = 0b10000000000000100000000000000000;
  // origin = 732123534337593543950335.12;
  origin.bits[0] = 0b11000011000110111111111110101000;
  origin.bits[1] = 0b10100001110111010100101100101110;
  origin.bits[2] = 0b00000000001111001000111101010001;
  origin.bits[3] = 0b00000000000000100000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_negate_34) {
  s21_decimal src1, origin, result;
  // src1 = 675432788976.5424354657687;
  src1.bits[0] = 0b10111110000100011000010110010111;
  src1.bits[1] = 0b11011001001111010001001011000110;
  src1.bits[2] = 0b00000000000001011001011001001000;
  src1.bits[3] = 0b00000000000011010000000000000000;
  // origin = -675432788976.5424354657687;
  origin.bits[0] = 0b10111110000100011000010110010111;
  origin.bits[1] = 0b11011001001111010001001011000110;
  origin.bits[2] = 0b00000000000001011001011001001000;
  origin.bits[3] = 0b10000000000011010000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_negate_35) {
  s21_decimal src1, origin, result;
  // src1 = -579895323215489956.67897455465;
  src1.bits[0] = 0b11100110001001011001001101101001;
  src1.bits[1] = 0b00111000110110101110001010110100;
  src1.bits[2] = 0b10111011010111111101000100011110;
  src1.bits[3] = 0b10000000000010110000000000000000;
  // origin = 579895323215489956.67897455465;
  origin.bits[0] = 0b11100110001001011001001101101001;
  origin.bits[1] = 0b00111000110110101110001010110100;
  origin.bits[2] = 0b10111011010111111101000100011110;
  origin.bits[3] = 0b00000000000010110000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_negate_36) {
  s21_decimal src1, origin, result;
  // src1 = 123523543453453453.0;
  src1.bits[0] = 0b01001001011001111111110110000010;
  src1.bits[1] = 0b00010001001001000111000000010101;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  // origin = -123523543453453453.0;
  origin.bits[0] = 0b01001001011001111111110110000010;
  origin.bits[1] = 0b00010001001001000111000000010101;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000010000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_negate_37) {
  s21_decimal src1, origin, result;
  // src1 = 31231232456315.0;
  src1.bits[0] = 0b11100001001010100010000011001110;
  src1.bits[1] = 0b00000000000000010001110000001011;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  // origin = -31231232456315.0;
  origin.bits[0] = 0b11100001001010100010000011001110;
  origin.bits[1] = 0b00000000000000010001110000001011;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000010000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_negate_38) {
  s21_decimal src1, origin, result;
  // src1 = 78987543557678337.5935439503;
  src1.bits[0] = 0b00111011110001111000001010001111;
  src1.bits[1] = 0b00101001100010100010010001100011;
  src1.bits[2] = 0b00000010100011010101111010100001;
  src1.bits[3] = 0b00000000000010100000000000000000;
  // origin = -78987543557678337.5935439503;
  origin.bits[0] = 0b00111011110001111000001010001111;
  origin.bits[1] = 0b00101001100010100010010001100011;
  origin.bits[2] = 0b00000010100011010101111010100001;
  origin.bits[3] = 0b10000000000010100000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_negate_39) {
  s21_decimal src1, origin, result;
  // src1 = -754567488438.97816770;
  src1.bits[0] = 0b01011010011001011000011011000010;
  src1.bits[1] = 0b00010111001011000011100101001001;
  src1.bits[2] = 0b00000000000000000000000000000100;
  src1.bits[3] = 0b10000000000010000000000000000000;
  // origin = 754567488438.97816770;
  origin.bits[0] = 0b01011010011001011000011011000010;
  origin.bits[1] = 0b00010111001011000011100101001001;
  origin.bits[2] = 0b00000000000000000000000000000100;
  origin.bits[3] = 0b00000000000010000000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_negate_40) {
  s21_decimal src1, origin, result;
  // src1 = -2.514475768684753643;
  src1.bits[0] = 0b10101100110010000011001011101011;
  src1.bits[1] = 0b00100010111001010011011001100011;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000100100000000000000000;
  // origin = 2.514475768684753643;
  origin.bits[0] = 0b10101100110010000011001011101011;
  origin.bits[1] = 0b00100010111001010011011001100011;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000100100000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_negate_41) {
  s21_decimal src1, origin, result;
  // src1 = -0.0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000010000000000000000;
  // origin = 0.0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000010000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_negate_42) {
  s21_decimal src1, origin, result;
  // src1 = 0.0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  // origin = -0.0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000010000000000000000;
  int check_origin = 0;
  int check = s21_negate(src1, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

///////////////---------s21_truncate--------//////////////

START_TEST(s21_truncate_1) {
  s21_decimal src1, origin, result;
  // src1 = 2.1234;
  src1.bits[0] = 0b00000000000000000101001011110010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001000000000000000000;
  // origin = 2;
  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_truncate_2) {
  s21_decimal src1, origin, result;
  // src1 = 457.000001;
  src1.bits[0] = 0b00011011001111010100010001000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  // origin = 457;
  origin.bits[0] = 0b00000000000000000000000111001001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_truncate_3) {
  s21_decimal src1, origin, result;
  // src1 = 2.000;
  src1.bits[0] = 0b00000000000000000000011111010000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000110000000000000000;
  // origin = 2;
  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_truncate_5) {
  s21_decimal src1, origin, result;
  // src1 = -3;
  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  // origin = -3;
  origin.bits[0] = 0b00000000000000000000000000000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_truncate_6) {
  s21_decimal src1, origin, result;
  // src1 = 2.222212;
  src1.bits[0] = 0b00000000001000011110100010000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  // origin = 2;
  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_truncate_7) {
  s21_decimal src1, origin, result;
  // src1 = 2.22221200000001000;
  src1.bits[0] = 0b00000111100011111010001111101000;
  src1.bits[1] = 0b00000011000101010111110100000001;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000100010000000000000000;
  // origin = 2;
  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_truncate_8) {
  s21_decimal src1, origin, result;
  // src1 = 3.745754741;
  src1.bits[0] = 0b11011111010000111010111001110101;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000010010000000000000000;
  // origin = 3;
  origin.bits[0] = 0b00000000000000000000000000000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_truncate_9) {
  s21_decimal src1, origin, result;
  // src1 = 2.222212;
  src1.bits[0] = 0b00000000001000011110100010000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  // origin = 2;
  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_truncate_10) {
  s21_decimal src1, origin, result;
  // src1 = -364748;
  src1.bits[0] = 0b00000000000001011001000011001100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  // origin = -364748;
  origin.bits[0] = 0b00000000000001011001000011001100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_truncate_11) {
  s21_decimal src1, origin, result;
  // src1 = 987456543210.0;
  src1.bits[0] = 0b00011001111101110000001100100100;
  src1.bits[1] = 0b00000000000000000000100011111011;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  // origin = 987456543210;
  origin.bits[0] = 0b11101000111111110001100111101010;
  origin.bits[1] = 0b00000000000000000000000011100101;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_truncate_12) {
  s21_decimal src1, origin, result;
  // src1 = -9878798789.5867800;
  src1.bits[0] = 0b11001110100110111101100110011000;
  src1.bits[1] = 0b00000001010111101111011100100110;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001110000000000000000;
  // origin = -9878798789;
  origin.bits[0] = 0b01001100110100101000000111000101;
  origin.bits[1] = 0b00000000000000000000000000000010;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_truncate_13) {
  s21_decimal src1, origin, result;
  // src1 = 9999999999999999999;
  src1.bits[0] = 0b10001001111001111111111111111111;
  src1.bits[1] = 0b10001010110001110010001100000100;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  // origin = 9999999999999999999;
  origin.bits[0] = 0b10001001111001111111111111111111;
  origin.bits[1] = 0b10001010110001110010001100000100;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_truncate_14) {
  s21_decimal src1, origin, result;
  // src1 = 18446744073709551615;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  // origin = 18446744073709551615;
  origin.bits[0] = 0b11111111111111111111111111111111;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_truncate_15) {
  s21_decimal src1, origin, result;
  // src1 = 18446744073709551615.0;
  src1.bits[0] = 0b11111111111111111111111111110110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000001001;
  src1.bits[3] = 0b00000000000000010000000000000000;
  // origin = 18446744073709551615;
  origin.bits[0] = 0b11111111111111111111111111111111;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_truncate_16) {
  s21_decimal src1, origin, result;
  // src1 = -796214545.3526545454564545456;
  src1.bits[0] = 0b10111111111111101001001110110000;
  src1.bits[1] = 0b11101010111111101111100111101000;
  src1.bits[2] = 0b00011001101110100010000111100001;
  src1.bits[3] = 0b10000000000100110000000000000000;
  // origin = -796214545;
  origin.bits[0] = 0b00101111011101010100010100010001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_truncate_17) {
  s21_decimal src1, origin, result;
  // src1 = -545454512454545.35265454545645;
  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;
  // origin = -545454512454545;
  origin.bits[0] = 0b10000110011101001011101110010001;
  origin.bits[1] = 0b00000000000000011111000000010110;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_truncate_18) {
  s21_decimal src1, origin, result;
  // src1 = -7961327845421.843434341378545;
  src1.bits[0] = 0b11110011001100111010100111110001;
  src1.bits[1] = 0b01001011001101011000000011010000;
  src1.bits[2] = 0b00011001101110010111010010111111;
  src1.bits[3] = 0b10000000000011110000000000000000;
  // origin = -7961327845421;
  origin.bits[0] = 0b10100100000111100100000000101101;
  origin.bits[1] = 0b00000000000000000000011100111101;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_truncate_19) {
  s21_decimal src1, origin, result;
  // src1 = 12345677.987654345678987654346;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;
  // origin = 12345677;
  origin.bits[0] = 0b00000000101111000110000101001101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_truncate_20) {
  s21_decimal src1, origin, result;
  // src1 = 12345677.987654345678987654346;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;
  // origin = 12345677;
  origin.bits[0] = 0b00000000101111000110000101001101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_truncate_21) {
  s21_decimal src1, origin, result;
  // src1 = 87654323456.98765456789876530;
  src1.bits[0] = 0b10110010000010100010111100110010;
  src1.bits[1] = 0b10011001010111000101110110000000;
  src1.bits[2] = 0b00011100010100101001100001111111;
  src1.bits[3] = 0b00000000000100010000000000000000;
  // origin = 87654323456;
  origin.bits[0] = 0b01101000100110101101010100000000;
  origin.bits[1] = 0b00000000000000000000000000010100;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_truncate_22) {
  s21_decimal src1, origin, result;
  // src1 = -854764561465456456.9876545679;
  src1.bits[0] = 0b11000100000001000100000010001111;
  src1.bits[1] = 0b01000000100100100110001100010101;
  src1.bits[2] = 0b00011011100111100111001001011101;
  src1.bits[3] = 0b10000000000010100000000000000000;
  // origin = -854764561465456456;
  origin.bits[0] = 0b00000100101111011011011101001000;
  origin.bits[1] = 0b00001011110111001011101111010111;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_truncate_23) {
  s21_decimal src1, origin, result;
  // src1 = 0.0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  // origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_truncate_24) {
  s21_decimal src1, origin, result;
  // src1 = -69.1234567;
  src1.bits[0] = 0b00101001001100110110011100000111;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001110000000000000000;
  // origin = -69;
  origin.bits[0] = 0b00000000000000000000000001000101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_truncate_25) {
  s21_decimal src1, origin, result;
  // src1 = 13436577854.000000000000;
  src1.bits[0] = 0b00100110011110011110000000000000;
  src1.bits[1] = 0b01100101111110011111000000101100;
  src1.bits[2] = 0b00000000000000000000001011011000;
  src1.bits[3] = 0b00000000000011000000000000000000;
  // origin = 13436577854;
  origin.bits[0] = 0b00100000111000011110100000111110;
  origin.bits[1] = 0b00000000000000000000000000000011;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_truncate_26) {
  s21_decimal src1, origin, result;
  // src1 = 79228162514264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  // origin = 79228162514264337593543950335;
  origin.bits[0] = 0b11111111111111111111111111111111;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b11111111111111111111111111111111;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_truncate_27) {
  s21_decimal src1, origin, result;
  // src1 = 79228162514264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  // origin = 79228162514264337593543950335;
  origin.bits[0] = 0b11111111111111111111111111111111;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b11111111111111111111111111111111;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_truncate_28) {
  s21_decimal src1, origin, result;
  // src1 = 665464545;
  src1.bits[0] = 0b00100111101010100010111011100001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  // origin = 665464545;
  origin.bits[0] = 0b00100111101010100010111011100001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_truncate_29) {
  s21_decimal src1, origin, result;
  // src1 = 2.7986531268974139743;
  src1.bits[0] = 0b11111110100100001101100101011111;
  src1.bits[1] = 0b10000100011001000010000111101000;
  src1.bits[2] = 0b00000000000000000000000000000001;
  src1.bits[3] = 0b00000000000100110000000000000000;
  // origin = 2;
  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_truncate_30) {
  s21_decimal src1, origin, result;
  // src1 = -2156878451.8547640000000000;
  src1.bits[0] = 0b10010011100100010011000000000000;
  src1.bits[1] = 0b00100110110100100010010100001001;
  src1.bits[2] = 0b00000000000100011101011101011110;
  src1.bits[3] = 0b10000000000100000000000000000000;
  // origin = -2156878451;
  origin.bits[0] = 0b10000000100011110101101001110011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_truncate_31) {
  s21_decimal src1, origin, result;
  // src1 = 0.5456465465486476846545465485;
  src1.bits[0] = 0b00001011000011110111000010001101;
  src1.bits[1] = 0b10010110101100000101100101010001;
  src1.bits[2] = 0b00010001101000010111101110000001;
  src1.bits[3] = 0b00000000000111000000000000000000;
  // origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_truncate_32) {
  s21_decimal src1, origin, result;
  // src1 = -776890.75455454213415678965898;
  src1.bits[0] = 0b11000010010111101111100010001010;
  src1.bits[1] = 0b01011100000101000111000011011000;
  src1.bits[2] = 0b11111011000001101110010110100011;
  src1.bits[3] = 0b10000000000101110000000000000000;
  // origin = -776890;
  origin.bits[0] = 0b00000000000010111101101010111010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_truncate_33) {
  s21_decimal src1, origin, result;
  // src1 = -732123534337593543950335.12;
  src1.bits[0] = 0b11000011000110111111111110101000;
  src1.bits[1] = 0b10100001110111010100101100101110;
  src1.bits[2] = 0b00000000001111001000111101010001;
  src1.bits[3] = 0b10000000000000100000000000000000;
  // origin = -732123534337593543950335;
  origin.bits[0] = 0b11010011110111101111111111111111;
  origin.bits[1] = 0b01111111000011110000001101001111;
  origin.bits[2] = 0b00000000000000001001101100001000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_truncate_34) {
  s21_decimal src1, origin, result;
  // src1 = 675432788976.5424354657687;
  src1.bits[0] = 0b10111110000100011000010110010111;
  src1.bits[1] = 0b11011001001111010001001011000110;
  src1.bits[2] = 0b00000000000001011001011001001000;
  src1.bits[3] = 0b00000000000011010000000000000000;
  // origin = 675432788976;
  origin.bits[0] = 0b01000010111011100111001111110000;
  origin.bits[1] = 0b00000000000000000000000010011101;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_truncate_35) {
  s21_decimal src1, origin, result;
  // src1 = -579895323215489956.67897455465;
  src1.bits[0] = 0b11100110001001011001001101101001;
  src1.bits[1] = 0b00111000110110101110001010110100;
  src1.bits[2] = 0b10111011010111111101000100011110;
  src1.bits[3] = 0b10000000000010110000000000000000;
  // origin = -579895323215489956;
  origin.bits[0] = 0b01011011001010110110101110100100;
  origin.bits[1] = 0b00001000000011000011001110111001;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_truncate_36) {
  s21_decimal src1, origin, result;
  // src1 = 123523543453453453.0;
  src1.bits[0] = 0b01001001011001111111110110000010;
  src1.bits[1] = 0b00010001001001000111000000010101;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  // origin = 123523543453453453;
  origin.bits[0] = 0b00100000111100001100110010001101;
  origin.bits[1] = 0b00000001101101101101100000000010;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_truncate_37) {
  s21_decimal src1, origin, result;
  // src1 = 31231232456315.0;
  src1.bits[0] = 0b11100001001010100010000011001110;
  src1.bits[1] = 0b00000000000000010001110000001011;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  // origin = 31231232456315;
  origin.bits[0] = 0b10010110100001000011011001111011;
  origin.bits[1] = 0b00000000000000000001110001100111;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_truncate_38) {
  s21_decimal src1, origin, result;
  // src1 = 78987543557678337.5935439503;
  src1.bits[0] = 0b00111011110001111000001010001111;
  src1.bits[1] = 0b00101001100010100010010001100011;
  src1.bits[2] = 0b00000010100011010101111010100001;
  src1.bits[3] = 0b00000000000010100000000000000000;
  // origin = 78987543557678337;
  origin.bits[0] = 0b10011011011011111010010100000001;
  origin.bits[1] = 0b00000001000110001001111011000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_truncate_39) {
  s21_decimal src1, origin, result;
  // src1 = -754567488438.97816770;
  src1.bits[0] = 0b01011010011001011000011011000010;
  src1.bits[1] = 0b00010111001011000011100101001001;
  src1.bits[2] = 0b00000000000000000000000000000100;
  src1.bits[3] = 0b10000000000010000000000000000000;
  // origin = -754567488438;
  origin.bits[0] = 0b10101111101110100010001110110110;
  origin.bits[1] = 0b00000000000000000000000010101111;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_truncate_40) {
  s21_decimal src1, origin, result;
  // src1 = -2.514475768684753643;
  src1.bits[0] = 0b10101100110010000011001011101011;
  src1.bits[1] = 0b00100010111001010011011001100011;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000100100000000000000000;
  // origin = -2;
  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_truncate_42) {
  s21_decimal src1, origin, result;
  // src1 = 0.0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  // origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

///////////////-----------s21_round----------///////////////
START_TEST(s21_round_1) {
  s21_decimal src, origin, result;
  // src = 5.0;
  src.bits[0] = 0b00000000000000000000000000110010;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;
  // origin = 5;
  origin.bits[0] = 0b00000000000000000000000000000101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_round_2) {
  s21_decimal src, origin, result;
  // src = 3.4;
  src.bits[0] = 0b00000000000000000000000000100010;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;
  // origin = 3;
  origin.bits[0] = 0b00000000000000000000000000000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_round_3) {
  s21_decimal src, origin, result;
  // src = 0.0;
  src.bits[0] = 0b00000000000000000000000000000000;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;
  // origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_round_4) {
  s21_decimal src, origin, result;
  // src = -2.4363463;
  src.bits[0] = 0b00000001011100111100000111000111;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000001110000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;
  // origin = -2;
  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_round_7) {
  s21_decimal src, origin, result;
  // src = 652.34631;
  src.bits[0] = 0b00000011111000110110011011000111;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000001010000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;
  // origin = 652;
  origin.bits[0] = 0b00000000000000000000001010001100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_round_8) {
  s21_decimal src, origin, result;
  // src = 4.97623323;
  src.bits[0] = 0b00011101101010010010000100011011;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000010000000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;
  // origin = 5;
  origin.bits[0] = 0b00000000000000000000000000000101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_round_9) {
  s21_decimal src, origin, result;
  // src = 65658654.59;
  src.bits[0] = 0b10000111010110110010011111110011;
  src.bits[1] = 0b00000000000000000000000000000001;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000100000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;
  // origin = 65658655;
  origin.bits[0] = 0b00000011111010011101111100011111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_round_10) {
  s21_decimal src, origin, result;
  // src = -364748.110;
  src.bits[0] = 0b00010101101111011001110101001110;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000000110000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;
  // origin = -364748;
  origin.bits[0] = 0b00000000000001011001000011001100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_round_11) {
  s21_decimal src, origin, result;
  // src = 1.9874565432111;
  src.bits[0] = 0b01101000011010011010001100101111;
  src.bits[1] = 0b00000000000000000001001000010011;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000011010000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;
  // origin = 2;
  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_round_12) {
  s21_decimal src, origin, result;
  // src = -98.78798789312;
  src.bits[0] = 0b00010110010010101110101011000000;
  src.bits[1] = 0b00000000000000000000100011111100;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000010110000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;
  // origin = -99;
  origin.bits[0] = 0b00000000000000000000000001100011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_round_13) {
  s21_decimal src, origin, result;
  // src = 999999999999999999911.3;
  src.bits[0] = 0b10110010001111111111110010001001;
  src.bits[1] = 0b00011001111000001100100110111010;
  src.bits[2] = 0b00000000000000000000001000011110;
  src.bits[3] = 0b00000000000000010000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;
  // origin = 999999999999999999911;
  origin.bits[0] = 0b11011110100111111111111110100111;
  origin.bits[1] = 0b00110101110010011010110111000101;
  origin.bits[2] = 0b00000000000000000000000000110110;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_round_14) {
  s21_decimal src, origin, result;
  // src = -545454512454545.35265454545645;
  src.bits[0] = 0b10000010111000100101101011101101;
  src.bits[1] = 0b11111001111010000010010110101101;
  src.bits[2] = 0b10110000001111101111000010010100;
  src.bits[3] = 0b10000000000011100000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;
  // origin = -545454512454545;
  origin.bits[0] = 0b10000110011101001011101110010001;
  origin.bits[1] = 0b00000000000000011111000000010110;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_round_15) {
  s21_decimal src, origin, result;
  // src = 545454512454545.35265454545645;
  src.bits[0] = 0b10000010111000100101101011101101;
  src.bits[1] = 0b11111001111010000010010110101101;
  src.bits[2] = 0b10110000001111101111000010010100;
  src.bits[3] = 0b00000000000011100000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;
  // origin = 545454512454545;
  origin.bits[0] = 0b10000110011101001011101110010001;
  origin.bits[1] = 0b00000000000000011111000000010110;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_round_16) {
  s21_decimal src, origin, result;
  // src = 7961327845421.879754123131254;
  src.bits[0] = 0b01001110111001000011100101110110;
  src.bits[1] = 0b01001011001101011010000111011001;
  src.bits[2] = 0b00011001101110010111010010111111;
  src.bits[3] = 0b00000000000011110000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;
  // origin = 7961327845422;
  origin.bits[0] = 0b10100100000111100100000000101110;
  origin.bits[1] = 0b00000000000000000000011100111101;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_round_17) {
  s21_decimal src, origin, result;
  // src = 12345677.987654345678987654346;
  src.bits[0] = 0b10010001000010101111010011001010;
  src.bits[1] = 0b11000000010001011101010111110010;
  src.bits[2] = 0b00100111111001000001101100000000;
  src.bits[3] = 0b00000000000101010000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;
  // origin = 12345678;
  origin.bits[0] = 0b00000000101111000110000101001110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_round_18) {
  s21_decimal src, origin, result;
  // src = -12345677.987654345678987654346;
  src.bits[0] = 0b10010001000010101111010011001010;
  src.bits[1] = 0b11000000010001011101010111110010;
  src.bits[2] = 0b00100111111001000001101100000000;
  src.bits[3] = 0b10000000000101010000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;
  // origin = -12345678;
  origin.bits[0] = 0b00000000101111000110000101001110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_round_19) {
  s21_decimal src, origin, result;
  // src = 87654323456.9876545678987653;
  src.bits[0] = 0b00010001110011011101000110000101;
  src.bits[1] = 0b11110101101111000110111111000000;
  src.bits[2] = 0b00000010110101010000111100111111;
  src.bits[3] = 0b00000000000100000000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;
  // origin = 87654323457;
  origin.bits[0] = 0b01101000100110101101010100000001;
  origin.bits[1] = 0b00000000000000000000000000010100;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_round_20) {
  s21_decimal src, origin, result;
  // src = 336565445454313.859865545;
  src.bits[0] = 0b00111110111111000101101111001001;
  src.bits[1] = 0b00111111110101011110000010001011;
  src.bits[2] = 0b00000000000000000100011101000101;
  src.bits[3] = 0b00000000000010010000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;
  // origin = 336565445454314;
  origin.bits[0] = 0b10111111110100011110100111101010;
  origin.bits[1] = 0b00000000000000010011001000011010;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_round_21) {
  s21_decimal src, origin, result;
  // src = -15456451234534;
  src.bits[0] = 0b10111100010010010000101011100110;
  src.bits[1] = 0b00000000000000000000111000001110;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000000000000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;
  // origin = -15456451234534;
  origin.bits[0] = 0b10111100010010010000101011100110;
  origin.bits[1] = 0b00000000000000000000111000001110;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_round_23) {
  s21_decimal src, origin, result;
  // src = 79228162514264337593543950335;
  src.bits[0] = 0b11111111111111111111111111111111;
  src.bits[1] = 0b11111111111111111111111111111111;
  src.bits[2] = 0b11111111111111111111111111111111;
  src.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;
  // origin = 79228162514264337593543950335;
  origin.bits[0] = 0b11111111111111111111111111111111;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b11111111111111111111111111111111;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_round_24) {
  s21_decimal src, origin, result;
  // src = 2.7986531268974139743;
  src.bits[0] = 0b11111110100100001101100101011111;
  src.bits[1] = 0b10000100011001000010000111101000;
  src.bits[2] = 0b00000000000000000000000000000001;
  src.bits[3] = 0b00000000000100110000000000000000;
  int check = s21_round(src, &result);
  int check_origin = 0;
  // origin = 3;
  origin.bits[0] = 0b00000000000000000000000000000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

////////////////---------s21_floor---------///////////////////

START_TEST(s21_floor_1) {
  s21_decimal src, origin, result;
  // src = 5.0;
  src.bits[0] = 0b00000000000000000000000000110010;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 5;
  origin.bits[0] = 0b00000000000000000000000000000101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_2) {
  s21_decimal src, origin, result;
  // src = 3.4;
  src.bits[0] = 0b00000000000000000000000000100010;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 3;
  origin.bits[0] = 0b00000000000000000000000000000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_3) {
  s21_decimal src, origin, result;
  // src = 0.0;
  src.bits[0] = 0b00000000000000000000000000000000;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_4) {
  s21_decimal src, origin, result;
  // src = -2.4363463;
  src.bits[0] = 0b00000001011100111100000111000111;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000001110000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = -3;
  origin.bits[0] = 0b00000000000000000000000000000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_6) {
  s21_decimal src, origin, result;
  // src = -0.45;
  src.bits[0] = 0b00000000000000000000000000101101;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000000100000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = -1;
  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_7) {
  s21_decimal src, origin, result;
  // src = 652.34631;
  src.bits[0] = 0b00000011111000110110011011000111;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000001010000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 652;
  origin.bits[0] = 0b00000000000000000000001010001100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_8) {
  s21_decimal src, origin, result;
  // src = 4.97623323;
  src.bits[0] = 0b00011101101010010010000100011011;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000010000000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 4;
  origin.bits[0] = 0b00000000000000000000000000000100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_9) {
  s21_decimal src, origin, result;
  // src = 65658654.59;
  src.bits[0] = 0b10000111010110110010011111110011;
  src.bits[1] = 0b00000000000000000000000000000001;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000100000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 65658654;
  origin.bits[0] = 0b00000011111010011101111100011110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_10) {
  s21_decimal src, origin, result;
  // src = -364748.110;
  src.bits[0] = 0b00010101101111011001110101001110;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000000110000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = -364749;
  origin.bits[0] = 0b00000000000001011001000011001101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_11) {
  s21_decimal src, origin, result;
  // src = 1.9874565432111;
  src.bits[0] = 0b01101000011010011010001100101111;
  src.bits[1] = 0b00000000000000000001001000010011;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000011010000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 1;
  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_12) {
  s21_decimal src, origin, result;
  // src = -98.78798789312;
  src.bits[0] = 0b00010110010010101110101011000000;
  src.bits[1] = 0b00000000000000000000100011111100;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000010110000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = -99;
  origin.bits[0] = 0b00000000000000000000000001100011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_13) {
  s21_decimal src, origin, result;
  // src = 999999999999999999911.3;
  src.bits[0] = 0b10110010001111111111110010001001;
  src.bits[1] = 0b00011001111000001100100110111010;
  src.bits[2] = 0b00000000000000000000001000011110;
  src.bits[3] = 0b00000000000000010000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 999999999999999999911;
  origin.bits[0] = 0b11011110100111111111111110100111;
  origin.bits[1] = 0b00110101110010011010110111000101;
  origin.bits[2] = 0b00000000000000000000000000110110;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_14) {
  s21_decimal src, origin, result;
  // src = -545454512454545.35265454545645;
  src.bits[0] = 0b10000010111000100101101011101101;
  src.bits[1] = 0b11111001111010000010010110101101;
  src.bits[2] = 0b10110000001111101111000010010100;
  src.bits[3] = 0b10000000000011100000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = -545454512454546;
  origin.bits[0] = 0b10000110011101001011101110010010;
  origin.bits[1] = 0b00000000000000011111000000010110;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_15) {
  s21_decimal src, origin, result;
  // src = 545454512454545.35265454545645;
  src.bits[0] = 0b10000010111000100101101011101101;
  src.bits[1] = 0b11111001111010000010010110101101;
  src.bits[2] = 0b10110000001111101111000010010100;
  src.bits[3] = 0b00000000000011100000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 545454512454545;
  origin.bits[0] = 0b10000110011101001011101110010001;
  origin.bits[1] = 0b00000000000000011111000000010110;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_16) {
  s21_decimal src, origin, result;
  // src = 7961327845421.879754123131254;
  src.bits[0] = 0b01001110111001000011100101110110;
  src.bits[1] = 0b01001011001101011010000111011001;
  src.bits[2] = 0b00011001101110010111010010111111;
  src.bits[3] = 0b00000000000011110000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 7961327845421;
  origin.bits[0] = 0b10100100000111100100000000101101;
  origin.bits[1] = 0b00000000000000000000011100111101;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_17) {
  s21_decimal src, origin, result;
  // src = 12345677.987654345678987654346;
  src.bits[0] = 0b10010001000010101111010011001010;
  src.bits[1] = 0b11000000010001011101010111110010;
  src.bits[2] = 0b00100111111001000001101100000000;
  src.bits[3] = 0b00000000000101010000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 12345677;
  origin.bits[0] = 0b00000000101111000110000101001101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_18) {
  s21_decimal src, origin, result;
  // src = -12345677.987654345678987654346;
  src.bits[0] = 0b10010001000010101111010011001010;
  src.bits[1] = 0b11000000010001011101010111110010;
  src.bits[2] = 0b00100111111001000001101100000000;
  src.bits[3] = 0b10000000000101010000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = -12345678;
  origin.bits[0] = 0b00000000101111000110000101001110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_19) {
  s21_decimal src, origin, result;
  // src = 87654323456.9876545678987653;
  src.bits[0] = 0b00010001110011011101000110000101;
  src.bits[1] = 0b11110101101111000110111111000000;
  src.bits[2] = 0b00000010110101010000111100111111;
  src.bits[3] = 0b00000000000100000000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 87654323456;
  origin.bits[0] = 0b01101000100110101101010100000000;
  origin.bits[1] = 0b00000000000000000000000000010100;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_20) {
  s21_decimal src, origin, result;
  // src = 336565445454313.859865545;
  src.bits[0] = 0b00111110111111000101101111001001;
  src.bits[1] = 0b00111111110101011110000010001011;
  src.bits[2] = 0b00000000000000000100011101000101;
  src.bits[3] = 0b00000000000010010000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 336565445454313;
  origin.bits[0] = 0b10111111110100011110100111101001;
  origin.bits[1] = 0b00000000000000010011001000011010;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_21) {
  s21_decimal src, origin, result;
  // src = -15456451234534;
  src.bits[0] = 0b10111100010010010000101011100110;
  src.bits[1] = 0b00000000000000000000111000001110;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000000000000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = -15456451234534;
  origin.bits[0] = 0b10111100010010010000101011100110;
  origin.bits[1] = 0b00000000000000000000111000001110;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_22) {
  s21_decimal src, origin, result;
  // src = -0.42354543545;
  src.bits[0] = 0b11011100100001110000101110111001;
  src.bits[1] = 0b00000000000000000000000000001001;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000010110000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = -1;
  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_23) {
  s21_decimal src, origin, result;
  // src = 79228162514264337593543950335;
  src.bits[0] = 0b11111111111111111111111111111111;
  src.bits[1] = 0b11111111111111111111111111111111;
  src.bits[2] = 0b11111111111111111111111111111111;
  src.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 79228162514264337593543950335;
  origin.bits[0] = 0b11111111111111111111111111111111;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b11111111111111111111111111111111;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_24) {
  s21_decimal src, origin, result;
  // src = 2.7986531268974139743;
  src.bits[0] = 0b11111110100100001101100101011111;
  src.bits[1] = 0b10000100011001000010000111101000;
  src.bits[2] = 0b00000000000000000000000000000001;
  src.bits[3] = 0b00000000000100110000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 2;
  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_25) {
  s21_decimal src, origin, result;
  // src = -5.000;
  src.bits[0] = 5000;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0b10000000000000110000000000000000;  // scale 10^3
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = -5;
  origin.bits[0] = 0b00000000000000000000000000000101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

//////////////////---------------div-------------//////////////

START_TEST(s21_div_1) {
  s21_decimal src1, src2, result, origin;
  // 30064771176
  // 3
  // 10021590392
  src1.bits[0] = 0b00000000000000000000000001101000;
  src1.bits[1] = 0b00000000000000000000000000000111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;

  origin.bits[0] = 0b01010101010101010101010101111000;
  origin.bits[1] = 0b00000000000000000000000000000010;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_div(src1, src2, &result);
  int check_origin = 0;
  ck_assert_int_eq(check, check_origin);
  ck_assert_int_eq(result.bits[3], origin.bits[3]);
  ck_assert_int_eq(result.bits[2], origin.bits[2]);
  ck_assert_int_eq(result.bits[1], origin.bits[1]);
  ck_assert_int_eq(result.bits[0], origin.bits[0]);
}
END_TEST

START_TEST(s21_div_2) {
  s21_decimal src1, src2, result;
  int a = 32768;
  int b = -2;
  int res_our_dec = 0;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  int res_origin = -16384;
  int check = s21_div(src1, src2, &result);
  int check_origin = 0;
  s21_from_decimal_to_int(result, &res_our_dec);
  ck_assert_int_eq(res_our_dec, res_origin);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_div_3) {
  s21_decimal src1, src2, result;
  int a = 32768;
  int b = 2;
  int res_our_dec = 0;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  int res_origin = 16384;
  int check = s21_div(src1, src2, &result);
  int check_origin = 0;
  s21_from_decimal_to_int(result, &res_our_dec);
  ck_assert_int_eq(res_our_dec, res_origin);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_div_4) {
  s21_decimal src1, src2, result, origin;
  // -30064771176
  // 2
  // 10021590392
  src1.bits[0] = 0b00000000000000000000000001101000;
  src1.bits[1] = 0b00000000000000000000000000000111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  origin.bits[0] = 0b10000000000000000000000000110100;
  origin.bits[1] = 0b00000000000000000000000000000011;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check = s21_div(src1, src2, &result);
  int check_origin = 0;
  ck_assert_int_eq(check, check_origin);
  ck_assert_int_eq(result.bits[3], origin.bits[3]);
  ck_assert_int_eq(result.bits[2], origin.bits[2]);
  ck_assert_int_eq(result.bits[1], origin.bits[1]);
  ck_assert_int_eq(result.bits[0], origin.bits[0]);
}
END_TEST

START_TEST(s21_div_5) {
  s21_decimal src1, src2, result, origin;
  // 0
  // 0.015
  // 0
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000001111;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000110000000000000000;

  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_div(src1, src2, &result);
  int check_origin = 0;
  ck_assert_int_eq(check, check_origin);
  ck_assert_int_eq(result.bits[3], origin.bits[3]);
  ck_assert_int_eq(result.bits[2], origin.bits[2]);
  ck_assert_int_eq(result.bits[1], origin.bits[1]);
  ck_assert_int_eq(result.bits[0], origin.bits[0]);
}
END_TEST

START_TEST(s21_div_6) {
  s21_decimal src1, src2, result, origin;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b00000000000000000000000000000000;

  origin.bits[0] = 1;
  origin.bits[1] = 0;
  origin.bits[2] = 0;
  origin.bits[3] = 0;
  int check = s21_div(src1, src2, &result);
  int check_origin = 0;
  ck_assert_int_eq(check, check_origin);
  ck_assert_int_eq(result.bits[3], origin.bits[3]);
  ck_assert_int_eq(result.bits[2], origin.bits[2]);
  ck_assert_int_eq(result.bits[1], origin.bits[1]);
  ck_assert_int_eq(result.bits[0], origin.bits[0]);
}
END_TEST

START_TEST(s21_div_7) {
  s21_decimal src1, src2, result, origin;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b10000000000000000000000000000000;

  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b00000000000000000000000000000000;

  origin.bits[0] = 1;
  origin.bits[1] = 0;
  origin.bits[2] = 0;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check = s21_div(src1, src2, &result);
  int check_origin = 0;
  ck_assert_int_eq(check, check_origin);
  ck_assert_int_eq(result.bits[3], origin.bits[3]);
  ck_assert_int_eq(result.bits[2], origin.bits[2]);
  ck_assert_int_eq(result.bits[1], origin.bits[1]);
  ck_assert_int_eq(result.bits[0], origin.bits[0]);
}
END_TEST

START_TEST(s21_div_8) {
  s21_decimal src1, src2, result, origin;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b10000000000000000000000000000000;

  origin.bits[0] = 1;
  origin.bits[1] = 0;
  origin.bits[2] = 0;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check = s21_div(src1, src2, &result);
  int check_origin = 0;
  ck_assert_int_eq(check, check_origin);
  ck_assert_int_eq(result.bits[3], origin.bits[3]);
  ck_assert_int_eq(result.bits[2], origin.bits[2]);
  ck_assert_int_eq(result.bits[1], origin.bits[1]);
  ck_assert_int_eq(result.bits[0], origin.bits[0]);
}
END_TEST

START_TEST(s21_div_9) {
  s21_decimal src1, src2, result, origin;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b10000000000000000000000000000000;

  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b10000000000000000000000000000000;

  origin.bits[0] = 1;
  origin.bits[1] = 0;
  origin.bits[2] = 0;
  origin.bits[3] = 0;
  int check = s21_div(src1, src2, &result);
  int check_origin = 0;
  ck_assert_int_eq(check, check_origin);
  ck_assert_int_eq(result.bits[3], origin.bits[3]);
  ck_assert_int_eq(result.bits[2], origin.bits[2]);
  ck_assert_int_eq(result.bits[1], origin.bits[1]);
  ck_assert_int_eq(result.bits[0], origin.bits[0]);
}
END_TEST

START_TEST(s21_div_10) {
  s21_decimal src1, src2, result, origin;
  src1.bits[0] = 300000;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0;

  src2.bits[0] = 30;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0;

  origin.bits[0] = 10000;
  origin.bits[1] = 0;
  origin.bits[2] = 0;
  origin.bits[3] = 0;
  int check = s21_div(src1, src2, &result);
  int check_origin = 0;
  ck_assert_int_eq(check, check_origin);
  ck_assert_int_eq(result.bits[3], origin.bits[3]);
  ck_assert_int_eq(result.bits[2], origin.bits[2]);
  ck_assert_int_eq(result.bits[1], origin.bits[1]);
  ck_assert_int_eq(result.bits[0], origin.bits[0]);
}
END_TEST

START_TEST(s21_div_11) {
  s21_decimal src1, src2, result, origin;
  src1.bits[0] = 30;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0;

  src2.bits[0] = 100;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0;

  origin.bits[0] = 3;
  origin.bits[1] = 0;
  origin.bits[2] = 0;
  origin.bits[3] = 0b00000000000000010000000000000000;
  int check = s21_div(src1, src2, &result);
  int check_origin = 0;
  ck_assert_int_eq(check, check_origin);
  ck_assert_int_eq(result.bits[3], origin.bits[3]);
  ck_assert_int_eq(result.bits[2], origin.bits[2]);
  ck_assert_int_eq(result.bits[1], origin.bits[1]);
  ck_assert_int_eq(result.bits[0], origin.bits[0]);
}
END_TEST

START_TEST(s21_div_12) {
  s21_decimal src1, src2, result, origin;
  // 79 228 162 514 264 337 593 543 950 335
  // 79 228 162 514 264 337 593 543.950 335
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0;

  src2.bits[0] = 1000000;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0;

  origin.bits[0] = 0b11111111111111111111111111111111;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b11111111111111111111111111111111;
  origin.bits[3] = 0b00000000000001100000000000000000;
  int check = s21_div(src1, src2, &result);
  int check_origin = 0;
  ck_assert_int_eq(check, check_origin);
  ck_assert_int_eq(result.bits[3], origin.bits[3]);
  ck_assert_int_eq(result.bits[2], origin.bits[2]);
  ck_assert_int_eq(result.bits[1], origin.bits[1]);
  ck_assert_int_eq(result.bits[0], origin.bits[0]);
}
END_TEST

START_TEST(s21_div_13) {
  s21_decimal src1, src2, result, origin;
  // 8/5 = 1.6
  src1.bits[0] = 8;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0;

  src2.bits[0] = 5;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0;

  origin.bits[0] = 16;
  origin.bits[1] = 0;
  origin.bits[2] = 0;
  origin.bits[3] = 0b00000000000000010000000000000000;
  int check = s21_div(src1, src2, &result);
  int check_origin = 0;
  ck_assert_int_eq(check, check_origin);
  ck_assert_int_eq(result.bits[3], origin.bits[3]);
  ck_assert_int_eq(result.bits[2], origin.bits[2]);
  ck_assert_int_eq(result.bits[1], origin.bits[1]);
  ck_assert_int_eq(result.bits[0], origin.bits[0]);
}
END_TEST

START_TEST(s21_div_14) {
  s21_decimal src1, src2, result, origin;
  // 38/7 = 5.428 571 428 571 428 571 428 571 428 6
  src1.bits[0] = 38;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0;

  src2.bits[0] = 7;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0;

  origin.bits[0] = 0b00001101101101101101101101101110;
  origin.bits[1] = 0b00101100110010001110100001011000;
  origin.bits[2] = 0b10101111011010000001011100100100;
  origin.bits[3] = 0b00000000000111000000000000000000;
  int check = s21_div(src1, src2, &result);
  int check_origin = 0;
  ck_assert_int_eq(check, check_origin);
  ck_assert_int_eq(result.bits[3], origin.bits[3]);
  ck_assert_int_eq(result.bits[2], origin.bits[2]);
  ck_assert_int_eq(result.bits[1], origin.bits[1]);
  ck_assert_int_eq(result.bits[0], origin.bits[0]);
}
END_TEST

START_TEST(s21_div_15) {
  s21_decimal src1, src2, result;
  src1.bits[0] = 0x0006BFD0;
  src1.bits[1] = 0x00000000;
  src1.bits[2] = 0x00000000;
  src1.bits[3] = 0x00000000;

  src2.bits[0] = 0x00000028;
  src2.bits[1] = 0x00000000;
  src2.bits[2] = 0x00000000;
  src2.bits[3] = 0x00000000;

  int check = s21_div(src1, src2, &result);
  int check_origin = 0;
  ck_assert_int_eq(check_origin, check);
  ck_assert_int_eq(result.bits[3], 0x00000000);
  ck_assert_int_eq(result.bits[2], 0x00000000);
  ck_assert_int_eq(result.bits[1], 0x00000000);
  ck_assert_int_eq(result.bits[0], 0x00002B32);
}
END_TEST

START_TEST(s21_div_null_16) {
  s21_decimal dec1 = {{1110, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};

  s21_decimal res1;
  int res = s21_div(dec1, dec2, &res1);
  ck_assert_int_eq(res, 3);
}
END_TEST

START_TEST(s21_div_17) {
  s21_decimal src1, src2, result;
  // 79 228 162 514 264 337 593 543 950 335
  // 79 228 162 514 264 337 593 543.950 335
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b0000000000000001000000000000000;

  int check = s21_div(src1, src2, &result);
  int check_origin = 0;
  ck_assert_int_eq(check_origin, check);
}

START_TEST(s21_mul_1) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 2;
  // src2 = 3;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_2) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 3;
  // src2 = 2;
  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_3) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 3;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_4) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 2;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_6) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 2;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_7) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 6521;
  // src2 = 74121;
  src1.bits[0] = 0b00000000000000000001100101111001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000010010000110001001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00011100110011110011101011000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_8) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 4;
  // src2 = 97623323;
  src1.bits[0] = 0b00000000000000000000000000000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000101110100011001110100011011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00010111010001100111010001101100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_9) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 65658654;
  // src2 = 5;
  src1.bits[0] = 0b00000011111010011101111100011110;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00010011100100010101101110010110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_10) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -364748;
  // src2 = 1;
  src1.bits[0] = 0b00000000000001011001000011001100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000001011001000011001100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_11) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 1;
  // src2 = 98745654321;
  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111101101100110001110000110001;
  src2.bits[1] = 0b00000000000000000000000000010110;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11111101101100110001110000110001;
  origin.bits[1] = 0b00000000000000000000000000010110;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_12) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -9878798789;
  // src2 = -3;
  src1.bits[0] = 0b01001100110100101000000111000101;
  src1.bits[1] = 0b00000000000000000000000000000010;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11100110011101111000010101001111;
  origin.bits[1] = 0b00000000000000000000000000000110;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_13) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 9999999999999999999;
  // src2 = 1;
  src1.bits[0] = 0b10001001111001111111111111111111;
  src1.bits[1] = 0b10001010110001110010001100000100;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b10001001111001111111111111111111;
  origin.bits[1] = 0b10001010110001110010001100000100;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_14) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 18446744073709551615;
  // src2 = 1;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11111111111111111111111111111111;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_23) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_24) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_25) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_26) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 79228162514264337593543950335;
  // src2 = -1;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11111111111111111111111111111111;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b11111111111111111111111111111111;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_27) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 7922816251427554395;
  // src2 = 65645646;
  src1.bits[0] = 0b01011111000010000000010001011011;
  src1.bits[1] = 0b01101101111100110111111101100111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000011111010011010110001001110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b01011111001100010111011110111010;
  origin.bits[1] = 0b01000100111111001101101110110001;
  origin.bits[2] = 0b00000001101011100011011100011110;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_28) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 665464545;
  // src2 = 8798232189789785;
  src1.bits[0] = 0b00100111101010100010111011100001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00010000010100101110011001011001;
  src2.bits[1] = 0b00000000000111110100000111110010;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11000100010110100111001000111001;
  origin.bits[1] = 0b01100100100011011110110011010011;
  origin.bits[2] = 0b00000000000001001101011111010011;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_33) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -79228162514264337593543950335;
  // src2 = 1;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11111111111111111111111111111111;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b11111111111111111111111111111111;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_34) {
  s21_decimal src1, src2, result;
  // 79 228 162 514 264 337 593 543 950 335
  // 79 228 162 514 264 337 593 543.950 335
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b10000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;

  int value_type_result = s21_mul(src1, src2, &result);
  int value_type_origin = 2;

  ck_assert_int_eq(value_type_result, value_type_origin);
}

START_TEST(s21_mul_35) {
  s21_decimal src1, src2, result;
  // 79 228 162 514 264 337 593 543 950 335
  // 79 228 162 514 264 337 593 543.950 335
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;

  int value_type_result = s21_mul(src1, src2, &result);
  int value_type_origin = 1;
  ck_assert_int_eq(value_type_result, value_type_origin);
}

START_TEST(s21_from_decimal_to_float_1) {
  s21_decimal src;
  int result = 0;
  float number = 0.0;
  long int c = 2147680256;
  src.bits[0] = 18122;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = c;

  result = s21_from_decimal_to_float(src, &number);
  ck_assert_float_eq(number, -18.122);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_float_2) {
  s21_decimal src;
  int result = 0;
  float number = 0.0;
  long int c = 2147483648;
  src.bits[0] = 1812;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = c;
  result = s21_from_decimal_to_float(src, &number);
  ck_assert_float_eq(number, -1812);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_float_3) {
  s21_decimal src;
  int result = 0;
  float number = 0.0;
  src.bits[0] = 0XFFFFFF;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0;
  result = s21_from_decimal_to_float(src, &number);
  ck_assert_float_eq(number, 16777215);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_float_4) {
  s21_decimal src;
  int result = 0;
  float number = 0.0;
  long int c = 2147745792;
  src.bits[0] = 23450987;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = c;
  result = s21_from_decimal_to_float(src, &number);
  ck_assert_float_eq(number, -2345.0987);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_float_5) {
  s21_decimal src;
  int result = 0;
  float number = 0.0;
  long int c = 4294967295;
  src.bits[0] = c;
  src.bits[1] = c;
  src.bits[2] = 0;
  src.bits[3] = 0;
  result = s21_from_decimal_to_float(src, &number);
  ck_assert_float_eq(number, 0xFFFFFFFFFFFFFFFF);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_float_7) {
  s21_decimal dec;
  int result = 0;
  float number = 0.0;
  long int c = 2147483648;
  dec.bits[0] = 1812;
  dec.bits[1] = 0;
  dec.bits[2] = 0;
  dec.bits[3] = c;
  result = s21_from_decimal_to_float(dec, &number);
  ck_assert_float_eq(number, -1812);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_float_8) {
  s21_decimal dec;
  int result = 0;
  float number = 0.0;

  dec.bits[0] = 0XFFFFFF;
  dec.bits[1] = 0;
  dec.bits[2] = 0;
  dec.bits[3] = 0;
  result = s21_from_decimal_to_float(dec, &number);
  ck_assert_float_eq(number, 16777215);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_float_9) {
  s21_decimal dec;
  int result = 0;
  float number = 0.0;
  long int c = 2147745792;
  dec.bits[0] = 23450987;
  dec.bits[1] = 0;
  dec.bits[2] = 0;
  dec.bits[3] = c;
  result = s21_from_decimal_to_float(dec, &number);
  ck_assert_float_eq(number, -2345.0987);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_float_10) {
  s21_decimal dec;
  int result = 0;
  float number = 0.0;
  long int c = 4294967295;
  dec.bits[0] = c;
  dec.bits[1] = c;
  dec.bits[2] = 0;
  dec.bits[3] = 0;
  result = s21_from_decimal_to_float(dec, &number);
  ck_assert_float_eq(number, 0xFFFFFFFFFFFFFFFF);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_floatTest1) {
  s21_decimal src1;
  float src2;
  float *srcp = &src2;
  // s21_decimal src1 = 2546.5;

  src1.bits[0] = 0b00000000000000000110001101111001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  s21_from_decimal_to_float(src1, srcp);
  char var3str[1000];
  char result[1000];
  snprintf(var3str, sizeof(var3str), "%.6f", 2546.5);
  snprintf(result, sizeof(result), "%f", src2);
  ck_assert_str_eq(result, var3str);
}
END_TEST

START_TEST(s21_from_decimal_to_floatTest2) {
  s21_decimal src1;
  float src2;
  float *srcp = &src2;
  // s21_decimal src1 = -0.46453;

  src1.bits[0] = 0b00000000000000001011010101110101;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001010000000000000000;
  s21_from_decimal_to_float(src1, srcp);
  char var3str[1000];
  char result[1000];
  snprintf(var3str, sizeof(var3str), "%.6f", -0.46453);
  snprintf(result, sizeof(result), "%f", src2);
  ck_assert_str_eq(result, var3str);
}
END_TEST

START_TEST(s21_from_decimal_to_floatTest3) {
  s21_decimal src1;
  float src2;
  float *srcp = &src2;
  // s21_decimal src1 = 3.5;

  src1.bits[0] = 0b00000000000000000000000000100011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  s21_from_decimal_to_float(src1, srcp);
  char var3str[1000];
  char result[1000];
  snprintf(var3str, sizeof(var3str), "%.6f", 3.5);
  snprintf(result, sizeof(result), "%f", src2);
  ck_assert_str_eq(result, var3str);
}
END_TEST

START_TEST(s21_from_decimal_to_floatTest4) {
  s21_decimal src1;
  float src2;
  float *srcp = &src2;
  // s21_decimal src1 = 4.5;

  src1.bits[0] = 0b00000000000000000000000000101101;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  s21_from_decimal_to_float(src1, srcp);
  char var3str[1000];
  char result[1000];
  snprintf(var3str, sizeof(var3str), "%.6f", 4.5);
  snprintf(result, sizeof(result), "%f", src2);
  ck_assert_str_eq(result, var3str);
}
END_TEST

START_TEST(s21_from_decimal_to_floatTest5) {
  s21_decimal src1;
  float src2;
  float *srcp = &src2;
  // s21_decimal src1 = -4.5;

  src1.bits[0] = 0b00000000000000000000000000101101;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000010000000000000000;
  s21_from_decimal_to_float(src1, srcp);
  char var3str[1000];
  char result[1000];
  snprintf(var3str, sizeof(var3str), "%.6f", -4.5);
  snprintf(result, sizeof(result), "%f", src2);
  ck_assert_str_eq(result, var3str);
}
END_TEST

START_TEST(s21_from_decimal_to_floatTest6) {
  s21_decimal src1;
  float src2;
  float *srcp = &src2;
  // s21_decimal src1 = -5.49265;

  src1.bits[0] = 0b00000000000010000110000110010001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001010000000000000000;
  s21_from_decimal_to_float(src1, srcp);
  char var3str[1000];
  char result[1000];
  snprintf(var3str, sizeof(var3str), "%.6f", -5.49265);
  snprintf(result, sizeof(result), "%f", src2);
  ck_assert_str_eq(result, var3str);
}
END_TEST

START_TEST(s21_from_decimal_to_floatTest7) {
  s21_decimal src1;
  float src2;
  float *srcp = &src2;
  // s21_decimal src1 = 2.5086531268974139743;

  src1.bits[0] = 0b01100101111011101101100101011111;
  src1.bits[1] = 0b01011100001001010100001101000110;
  src1.bits[2] = 0b00000000000000000000000000000001;
  src1.bits[3] = 0b00000000000100110000000000000000;
  s21_from_decimal_to_float(src1, srcp);
  char var3str[1000];
  char result[1000];
  snprintf(var3str, sizeof(var3str), "%.6f", 2.50865312689741);
  snprintf(result, sizeof(result), "%f", src2);
  ck_assert_str_eq(result, var3str);
}
END_TEST

START_TEST(float_to_decimal_1) {
  float a = 1234567890123456789012345678.0;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_2) {
  float a = 123456789012345678901234567.8;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_3) {
  float a = 12345678901234567890123456.78;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_4) {
  float a = 1234567890123456789012345.678;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_5) {
  float a = 123456789012345678901234.5678;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_6) {
  float a = 12345678901234567890123.45678;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_7) {
  float a = 1234567890123456789012.345678;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_8) {
  float a = 123456789012345678901.2345678;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_9) {
  float a = 12345678901234567890.12345678;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_10) {
  float a = 1234567890123456789.012345678;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_11) {
  float a = 123456789012345678.9012345678;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_12) {
  float a = 12345678901234567.89012345678;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_13) {
  float a = 1234567890123456.7890123456780;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_14) {
  float a = 123456789012345.67890123456780;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_15) {
  float a = 12345678901234.56789012345678;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_16) {
  float a = 1234567890123.4567890123456780;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_17) {
  float a = 123456789012.34567890123456780;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_18) {
  float a = 12345678901.234567890123456780;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_19) {
  float a = 1234567890.1234567890123456780;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_20) {
  float a = 123456789.01234567890123456780;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_21) {
  float a = 12345678.901234567890123456780;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_22) {
  float a = 1234567.8901234567890123456780;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_23) {
  float a = 123456.78901234567890123456780;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_24) {
  float a = 12345.678901234567890123456780;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_25) {
  float a = 1234.5678901234567890123456780;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_26) {
  float a = 123.45678901234567890123456780;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_27) {
  float a = 12.345678901234567890123456780;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_28) {
  float a = 1.2345678901234567890123456780;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_29) {
  float a = 0.12345678901234567890123456780;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_30) {
  float a = 1.2e-27;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_31) {
  float a = 1.2e-26;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_32) {
  float a = 1.2e-25;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_33) {
  float a = 1.2e-24;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_34) {
  float a = 1.2e-23;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_35) {
  float a = 1.2e-22;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_36) {
  float a = 1.2e-21;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_37) {
  float a = 1.2e-20;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_38) {
  float a = 1.2e-19;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_39) {
  float a = 1.2e-18;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_40) {
  float a = 1.2e-17;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_41) {
  float a = 1.2e-16;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_42) {
  float a = 1.2e-15;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_43) {
  float a = 1.2e-14;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_44) {
  float a = 1.2e-13;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_45) {
  float a = 1.2e-12;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_46) {
  float a = 1.2e-11;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_47) {
  float a = 1.2e-10;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_48) {
  float a = 1.2e-9;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_49) {
  float a = 1.2e-8;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_50) {
  float a = MAX_DEC + 1;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(0, b);
}
END_TEST

START_TEST(float_to_decimal_51) {
  float a = MIN_DEC - 1;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(0, b);
}
END_TEST

START_TEST(float_to_decimal_52) {
  float a = 0.0;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(float_to_decimal_53) {
  float a = MAX_DEC;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
}
END_TEST

START_TEST(float_to_decimal_54) {
  s21_decimal val;
  float fl1 = 3;
  float fl2 = 127.1234;
  float fl1_res = 0;
  float fl2_res = 0;

  s21_from_float_to_decimal(fl1, &val);
  s21_from_decimal_to_float(val, &fl1_res);
  ck_assert_double_eq_tol(fl1, fl1_res, 1e-28);
  s21_from_float_to_decimal(fl2, &val);
  s21_from_decimal_to_float(val, &fl2_res);
  ck_assert_double_eq_tol(fl2, fl2_res, 1e-28);
}
END_TEST

START_TEST(float_to_decimal_55) {
  s21_decimal val;
  float fl1 = -128.023;
  float fl2 = 12345.37643764;
  float fl1_res = 0;
  float fl2_res = 0;

  s21_from_float_to_decimal(fl1, &val);
  s21_from_decimal_to_float(val, &fl1_res);
  ck_assert_double_eq_tol(fl1, fl1_res, 1e-28);

  s21_from_float_to_decimal(fl2, &val);
  s21_from_decimal_to_float(val, &fl2_res);
  ck_assert_double_eq_tol(fl2, fl2_res, 1e-28);
}
END_TEST

START_TEST(float_to_decimal_56) {
  s21_decimal val;
  float num = -2147483648;
  s21_from_float_to_decimal(num, &val);
  ck_assert_int_eq(val.bits[0], 2147483648);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 2147483648);
}
END_TEST

START_TEST(float_to_decimal_57) {
  s21_decimal val;
  float fl1 = 22.14836E+03;
  float fl2 = -2.1474836E+09;
  float fl1_res = 0;
  float fl2_res = 0;

  s21_from_float_to_decimal(fl1, &val);
  s21_from_decimal_to_float(val, &fl1_res);
  ck_assert_double_eq_tol(fl1, fl1_res, 1e-28);

  s21_from_float_to_decimal(fl2, &val);
  s21_from_decimal_to_float(val, &fl2_res);
  ck_assert_double_eq_tol(fl2, fl2_res, 1e-28);
}
END_TEST

START_TEST(float_to_decimal_58) {
  s21_decimal val = {0};
  s21_from_float_to_decimal(1.02E+09, &val);
  ck_assert_int_eq(val.bits[0], 1020000000);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(float_to_decimal_59) {
  s21_decimal val = {0};
  float fl1 = -333.2222;
  float fl2 = -2.1474836E+20;
  float fl1_res = 0;
  float fl2_res = 0;

  s21_from_float_to_decimal(fl1, &val);
  s21_from_decimal_to_float(val, &fl1_res);
  ck_assert_double_eq_tol(fl1, fl1_res, 1e-28);

  s21_from_float_to_decimal(fl2, &val);
  s21_from_decimal_to_float(val, &fl2_res);
  ck_assert_double_eq_tol(fl2, fl2_res, 1e-28);
}
END_TEST

START_TEST(float_to_decimal_60) {
  s21_decimal val = {0};
  float a = 1.0 / 0.0;
  s21_from_float_to_decimal(a, &val);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(float_to_decimal_61) {
  s21_decimal val = {0};
  float a = -1.0 / 0.0;
  s21_from_float_to_decimal(a, &val);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(float_to_decimal_62) {
  s21_decimal val = {0};
  float a = 1e-30;
  s21_from_float_to_decimal(a, &val);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(float_to_decimal_63) {
  s21_decimal dec = {0};
  float tmp = 0;
  float tmp1 = 0.03;
  s21_from_float_to_decimal(tmp1, &dec);
  s21_from_decimal_to_float(dec, &tmp);
  ck_assert_float_eq_tol(tmp, tmp1, 1e-06);
}
END_TEST

START_TEST(float_to_decimal_64) {
  s21_decimal dec = {0};
  s21_from_float_to_decimal(-128.023, &dec);
  float tmp = 0;
  s21_from_decimal_to_float(dec, &tmp);
  ck_assert_float_eq_tol(tmp, -128.023, 1e-06);
}
END_TEST

START_TEST(float_to_decimal_65) {
  s21_decimal dec = {0};
  s21_from_float_to_decimal(-2.1474836E+09, &dec);
  float tmp = 0;
  s21_from_decimal_to_float(dec, &tmp);
  ck_assert_float_eq_tol(tmp, -2.1474836E+09, 1e-06);
}
END_TEST

START_TEST(float_to_decimal_66) {
  s21_decimal dec = {0};
  s21_from_float_to_decimal(22.14836E+03, &dec);
  float tmp = 0;
  s21_from_decimal_to_float(dec, &tmp);
  ck_assert_float_eq_tol(tmp, 22.14836E+03, 1e-06);
}
END_TEST

START_TEST(float_to_decimal_67) {
  s21_decimal dec = {0};
  s21_from_float_to_decimal(1.02E+08, &dec);
  float tmp = 0;
  s21_from_decimal_to_float(dec, &tmp);
  ck_assert_float_eq_tol(tmp, 1.02E+08, 1e-06);
}
END_TEST

START_TEST(float_to_decimal_68) {
  s21_decimal dec = {0};
  s21_from_float_to_decimal(-333.2222, &dec);
  float tmp = 0;
  s21_from_decimal_to_float(dec, &tmp);
  ck_assert_float_eq_tol(tmp, -333.2222, 1e-06);
}
END_TEST

START_TEST(float_to_decimal_69) {
  s21_decimal dec = {0};
  float a = 1.0 / 0.0;
  int ret = s21_from_float_to_decimal(a, &dec);
  ck_assert_int_eq(ret, 1);
}
END_TEST

START_TEST(float_to_decimal_70) {
  s21_decimal dec = {0};
  float a = -1.0 / 0.0;
  s21_from_float_to_decimal(a, &dec);
  ck_assert_int_eq(dec.bits[0], 0);
  ck_assert_int_eq(dec.bits[1], 0);
  ck_assert_int_eq(dec.bits[2], 0);
  ck_assert_int_eq(dec.bits[3], 0);
}
END_TEST

Suite *main_suite(void) {
  Suite *suite = suite_create("Cast");
  // Добавление тестов в набор
  TCase *tc1_float = tcase_create("Cast");
  tcase_add_test(tc1_float, s21_from_decimal_to_float_1);
  tcase_add_test(tc1_float, s21_from_decimal_to_float_2);
  tcase_add_test(tc1_float, s21_from_decimal_to_float_3);
  tcase_add_test(tc1_float, s21_from_decimal_to_float_4);
  tcase_add_test(tc1_float, s21_from_decimal_to_float_5);
  tcase_add_test(tc1_float, s21_from_decimal_to_float_7);
  tcase_add_test(tc1_float, s21_from_decimal_to_float_8);
  tcase_add_test(tc1_float, s21_from_decimal_to_float_9);
  tcase_add_test(tc1_float, s21_from_decimal_to_float_10);
  tcase_add_test(tc1_float, s21_from_decimal_to_floatTest1);
  tcase_add_test(tc1_float, s21_from_decimal_to_floatTest2);
  tcase_add_test(tc1_float, s21_from_decimal_to_floatTest3);
  tcase_add_test(tc1_float, s21_from_decimal_to_floatTest4);
  tcase_add_test(tc1_float, s21_from_decimal_to_floatTest5);
  tcase_add_test(tc1_float, s21_from_decimal_to_floatTest6);
  tcase_add_test(tc1_float, s21_from_decimal_to_floatTest7);
  suite_add_tcase(suite, tc1_float);

  // Добавление тестов в набор
  TCase *tc1_float_to_dec = tcase_create("Cast");
  tcase_add_test(tc1_float_to_dec, float_to_decimal_1);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_2);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_3);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_4);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_5);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_6);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_7);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_8);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_9);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_10);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_11);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_12);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_13);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_14);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_15);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_16);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_17);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_18);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_19);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_20);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_21);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_22);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_23);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_24);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_25);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_26);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_27);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_28);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_29);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_30);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_31);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_32);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_33);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_34);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_35);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_36);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_37);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_38);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_39);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_40);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_41);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_42);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_43);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_44);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_45);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_46);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_47);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_48);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_49);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_50);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_51);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_52);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_53);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_54);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_55);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_56);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_57);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_58);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_59);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_60);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_61);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_62);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_63);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_64);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_65);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_66);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_67);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_68);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_69);
  tcase_add_test(tc1_float_to_dec, float_to_decimal_70);
  suite_add_tcase(suite, tc1_float);

  // Добавление тестов в набор
  TCase *tc1_1 = tcase_create("Cast");
  tcase_add_test(tc1_1, int_to_dec_1);
  tcase_add_test(tc1_1, int_to_dec_2);
  tcase_add_test(tc1_1, int_to_dec_3);
  tcase_add_test(tc1_1, int_to_dec_4);
  tcase_add_test(tc1_1, int_to_dec_5);
  tcase_add_test(tc1_1, int_to_dec_6);
  tcase_add_test(tc1_1, int_to_dec_7);
  tcase_add_test(tc1_1, int_to_dec_8);
  tcase_add_test(tc1_1, int_to_dec_9);
  tcase_add_test(tc1_1, int_to_dec_10);
  tcase_add_test(tc1_1, int_to_dec_11);
  tcase_add_test(tc1_1, int_to_dec_12);
  tcase_add_test(tc1_1, int_to_dec_13);
  tcase_add_test(tc1_1, int_to_dec_14);
  tcase_add_test(tc1_1, int_to_dec_15);
  tcase_add_test(tc1_1, int_to_dec_16);
  tcase_add_test(tc1_1, int_to_dec_17);
  tcase_add_test(tc1_1, int_to_dec_18);
  tcase_add_test(tc1_1, int_to_dec_19);
  tcase_add_test(tc1_1, int_to_dec_20);
  tcase_add_test(tc1_1, int_to_dec_21);
  suite_add_tcase(suite, tc1_1);

  TCase *tc1_2 = tcase_create("Cast");
  tcase_add_test(tc1_2, dec_to_int_1);
  tcase_add_test(tc1_2, dec_to_int_2);
  tcase_add_test(tc1_2, dec_to_int_3);
  tcase_add_test(tc1_2, dec_to_int_4);
  tcase_add_test(tc1_2, dec_to_int_5);
  tcase_add_test(tc1_2, dec_to_int_7);
  tcase_add_test(tc1_2, dec_to_int_8);
  tcase_add_test(tc1_2, dec_to_int_9);
  tcase_add_test(tc1_2, dec_to_int_10);
  tcase_add_test(tc1_2, dec_to_int_11);
  tcase_add_test(tc1_2, dec_to_int_12);
  tcase_add_test(tc1_2, dec_to_int_13);
  tcase_add_test(tc1_2, dec_to_int_14);
  tcase_add_test(tc1_2, dec_to_int_15);
  tcase_add_test(tc1_2, dec_to_int_16);
  tcase_add_test(tc1_2, dec_to_int_17);
  tcase_add_test(tc1_2, dec_to_int_18);
  tcase_add_test(tc1_2, dec_to_int_19);
  tcase_add_test(tc1_2, dec_to_int_20);
  tcase_add_test(tc1_2, dec_to_int_21);
  tcase_add_test(tc1_2, dec_to_int_23);
  tcase_add_test(tc1_2, dec_to_int_24);
  suite_add_tcase(suite, tc1_2);

  // Добавление тестов в набор
  TCase *tc1_3 = tcase_create("Cast");
  tcase_add_test(tc1_3, s21_add_1);
  tcase_add_test(tc1_3, s21_add_2);
  tcase_add_test(tc1_3, s21_add_3);
  tcase_add_test(tc1_3, s21_add_4);
  tcase_add_test(tc1_3, s21_add_6);
  tcase_add_test(tc1_3, s21_add_7);
  tcase_add_test(tc1_3, s21_add_8);
  tcase_add_test(tc1_3, s21_add_9);
  tcase_add_test(tc1_3, s21_add_10);
  tcase_add_test(tc1_3, s21_add_11);
  tcase_add_test(tc1_3, s21_add_12);
  tcase_add_test(tc1_3, s21_add_13);
  tcase_add_test(tc1_3, s21_add_14);
  tcase_add_test(tc1_3, s21_add_15);
  tcase_add_test(tc1_3, s21_add_16);
  tcase_add_test(tc1_3, s21_add_18);
  tcase_add_test(tc1_3, s21_add_23);
  tcase_add_test(tc1_3, s21_add_24);
  tcase_add_test(tc1_3, s21_add_25);
  tcase_add_test(tc1_3, s21_add_27);
  tcase_add_test(tc1_3, s21_add_28);
  tcase_add_test(tc1_3, s21_add_29);
  tcase_add_test(tc1_3, s21_add_30);
  tcase_add_test(tc1_3, s21_add_31);
  tcase_add_test(tc1_3, s21_add_36);
  tcase_add_test(tc1_3, s21_add_37);
  tcase_add_test(tc1_3, s21_add_40);
  tcase_add_test(tc1_3, s21_add_41);
  tcase_add_test(tc1_3, s21_add_44);
  tcase_add_test(tc1_3, s21_add_45);
  tcase_add_test(tc1_3, s21_add_51);
  tcase_add_test(tc1_3, s21_add_52);
  tcase_add_test(tc1_3, s21_add_53);
  tcase_add_test(tc1_3, s21_add_54);
  tcase_add_test(tc1_3, s21_add_55);
  tcase_add_test(tc1_3, add_test_1);
  tcase_add_test(tc1_3, add_test_2);
  tcase_add_test(tc1_3, add_test_3);
  tcase_add_test(tc1_3, add_test_4);
  tcase_add_test(tc1_3, add_test_5);
  tcase_add_test(tc1_3, add_test_6);
  tcase_add_test(tc1_3, add_test_7);
  tcase_add_test(tc1_3, add_test_8);
  tcase_add_test(tc1_3, add_test_9);
  tcase_add_test(tc1_3, add_test_10);
  tcase_add_test(tc1_3, add_test_11);
  tcase_add_test(tc1_3, add_test_12);
  tcase_add_test(tc1_3, add_test_13);
  tcase_add_test(tc1_3, add_test_14);
  tcase_add_test(tc1_3, add_test_15);
  tcase_add_test(tc1_3, add_test_16);
  tcase_add_test(tc1_3, add_test_17);
  tcase_add_test(tc1_3, add_test_18);
  tcase_add_test(tc1_3, add_test_19);
  tcase_add_test(tc1_3, add_test_20);
  tcase_add_test(tc1_3, add_test_21);
  tcase_add_test(tc1_3, add_test_22);
  tcase_add_test(tc1_3, add_test_23);
  tcase_add_test(tc1_3, add_test_25);
  tcase_add_test(tc1_3, add_test_26);
  tcase_add_test(tc1_3, add_test_27);
  suite_add_tcase(suite, tc1_3);

  // Добавление тестов в набор
  TCase *tc1_4 = tcase_create("Cast");
  tcase_add_test(tc1_4, s21_sub_1);
  tcase_add_test(tc1_4, s21_sub_2);
  tcase_add_test(tc1_4, s21_sub_3);
  tcase_add_test(tc1_4, s21_sub_4);
  tcase_add_test(tc1_4, s21_sub_6);
  tcase_add_test(tc1_4, s21_sub_7);
  tcase_add_test(tc1_4, s21_sub_8);
  tcase_add_test(tc1_4, s21_sub_9);
  tcase_add_test(tc1_4, s21_sub_10);
  tcase_add_test(tc1_4, s21_sub_11);
  tcase_add_test(tc1_4, s21_sub_15);
  tcase_add_test(tc1_4, s21_sub_16);
  tcase_add_test(tc1_4, s21_sub_17);
  tcase_add_test(tc1_4, s21_sub_22);
  tcase_add_test(tc1_4, s21_sub_23);
  tcase_add_test(tc1_4, s21_sub_24);
  tcase_add_test(tc1_4, s21_sub_26);
  tcase_add_test(tc1_4, s21_sub_28);
  tcase_add_test(tc1_4, s21_sub_30);
  tcase_add_test(tc1_4, s21_sub_35);
  tcase_add_test(tc1_4, s21_sub_36);
  tcase_add_test(tc1_4, s21_sub_39);
  tcase_add_test(tc1_4, s21_sub_51);
  tcase_add_test(tc1_4, s21_sub_52);
  tcase_add_test(tc1_4, s21_sub_53);
  suite_add_tcase(suite, tc1_4);

  // Добавление тестов в набор
  TCase *tc1_div = tcase_create("Cast");
  tcase_add_test(tc1_div, s21_div_1);
  tcase_add_test(tc1_div, s21_div_2);
  tcase_add_test(tc1_div, s21_div_3);
  tcase_add_test(tc1_div, s21_div_4);
  tcase_add_test(tc1_div, s21_div_5);
  tcase_add_test(tc1_div, s21_div_6);
  tcase_add_test(tc1_div, s21_div_7);
  tcase_add_test(tc1_div, s21_div_8);
  tcase_add_test(tc1_div, s21_div_9);
  tcase_add_test(tc1_div, s21_div_10);
  tcase_add_test(tc1_div, s21_div_11);
  tcase_add_test(tc1_div, s21_div_12);
  tcase_add_test(tc1_div, s21_div_13);
  tcase_add_test(tc1_div, s21_div_14);
  tcase_add_test(tc1_div, s21_div_15);
  tcase_add_test(tc1_div, s21_div_null_16);
  tcase_add_test(tc1_div, s21_div_17);
  suite_add_tcase(suite, tc1_div);

  // Добавление тестов в набор
  TCase *tc1_mul = tcase_create("Cast");
  tcase_add_test(tc1_mul, s21_mul_1);
  tcase_add_test(tc1_mul, s21_mul_2);
  tcase_add_test(tc1_mul, s21_mul_3);
  tcase_add_test(tc1_mul, s21_mul_4);
  tcase_add_test(tc1_mul, s21_mul_6);
  tcase_add_test(tc1_mul, s21_mul_7);
  tcase_add_test(tc1_mul, s21_mul_8);
  tcase_add_test(tc1_mul, s21_mul_9);
  tcase_add_test(tc1_mul, s21_mul_10);
  tcase_add_test(tc1_mul, s21_mul_11);
  tcase_add_test(tc1_mul, s21_mul_12);
  tcase_add_test(tc1_mul, s21_mul_13);
  tcase_add_test(tc1_mul, s21_mul_14);
  tcase_add_test(tc1_mul, s21_mul_23);
  tcase_add_test(tc1_mul, s21_mul_24);
  tcase_add_test(tc1_mul, s21_mul_25);
  tcase_add_test(tc1_mul, s21_mul_26);
  tcase_add_test(tc1_mul, s21_mul_27);
  tcase_add_test(tc1_mul, s21_mul_28);
  tcase_add_test(tc1_mul, s21_mul_33);
  tcase_add_test(tc1_mul, s21_mul_34);
  tcase_add_test(tc1_mul, s21_mul_35);
  suite_add_tcase(suite, tc1_mul);

  // Добавление тестов в набор
  TCase *tc1_5 = tcase_create("Cast");
  tcase_add_test(tc1_5, s21_less_1);
  tcase_add_test(tc1_5, s21_less_2);
  tcase_add_test(tc1_5, s21_less_3_zero);
  tcase_add_test(tc1_5, s21_less_4_zero);
  tcase_add_test(tc1_5, s21_less_5_len_int_part);
  tcase_add_test(tc1_5, s21_less_6_len_int_part_positive);
  tcase_add_test(tc1_5, s21_less_7_len_int_part_negative);
  tcase_add_test(tc1_5, s21_less_8_value_int_part_positive);
  tcase_add_test(tc1_5, s21_less_9_value_fract_part_positive);
  tcase_add_test(tc1_5, s21_less_10_max_int_positive);
  tcase_add_test(tc1_5, s21_less_11_max_int_negative);
  tcase_add_test(tc1_5, s21_less_12);
  tcase_add_test(tc1_5, s21_less_13);
  tcase_add_test(tc1_5, s21_less_14);
  tcase_add_test(tc1_5, s21_less_15);
  tcase_add_test(tc1_5, s21_less_16);
  tcase_add_test(tc1_5, s21_less_17);
  tcase_add_test(tc1_5, s21_less_18);
  tcase_add_test(tc1_5, s21_less_19);
  tcase_add_test(tc1_5, s21_less_20);
  tcase_add_test(tc1_5, s21_less_21);
  tcase_add_test(tc1_5, s21_less_22);
  tcase_add_test(tc1_5, s21_less_23);
  tcase_add_test(tc1_5, s21_less_24);
  tcase_add_test(tc1_5, s21_less_25);
  tcase_add_test(tc1_5, s21_less_26);
  tcase_add_test(tc1_5, s21_less_27);
  tcase_add_test(tc1_5, s21_less_28);
  tcase_add_test(tc1_5, s21_less_29);
  tcase_add_test(tc1_5, s21_less_30);
  tcase_add_test(tc1_5, s21_less_31);
  tcase_add_test(tc1_5, s21_less_32);
  tcase_add_test(tc1_5, s21_less_33);
  tcase_add_test(tc1_5, s21_less_34);
  tcase_add_test(tc1_5, s21_less_35);
  tcase_add_test(tc1_5, s21_less_36);
  tcase_add_test(tc1_5, s21_less_37);
  tcase_add_test(tc1_5, s21_less_38);
  tcase_add_test(tc1_5, s21_less_39);
  tcase_add_test(tc1_5, s21_less_40);
  tcase_add_test(tc1_5, s21_less_41);
  tcase_add_test(tc1_5, s21_less_42);
  tcase_add_test(tc1_5, s21_less_43);
  tcase_add_test(tc1_5, s21_less_44);
  tcase_add_test(tc1_5, s21_less_45);
  tcase_add_test(tc1_5, s21_less_46);
  tcase_add_test(tc1_5, s21_less_47);
  tcase_add_test(tc1_5, s21_less_48);
  tcase_add_test(tc1_5, s21_less_49);
  tcase_add_test(tc1_5, s21_less_50);
  tcase_add_test(tc1_5, s21_less_51);
  tcase_add_test(tc1_5, s21_less_52);
  suite_add_tcase(suite, tc1_5);

  // Добавление тестов в набор
  TCase *tc1_greater = tcase_create("Cast");
  tcase_add_test(tc1_greater, s21_greater_1);
  tcase_add_test(tc1_greater, s21_greater_2);
  tcase_add_test(tc1_greater, s21_greater_3);
  tcase_add_test(tc1_greater, s21_greater_4);
  tcase_add_test(tc1_greater, s21_greater_5);
  tcase_add_test(tc1_greater, s21_greater_6);
  tcase_add_test(tc1_greater, s21_greater_7);
  tcase_add_test(tc1_greater, s21_greater_8);
  tcase_add_test(tc1_greater, s21_greater_9);
  tcase_add_test(tc1_greater, s21_greater_10);
  tcase_add_test(tc1_greater, s21_greater_11);
  tcase_add_test(tc1_greater, s21_greater_12);
  tcase_add_test(tc1_greater, s21_greater_13);
  tcase_add_test(tc1_greater, s21_greater_14);
  tcase_add_test(tc1_greater, s21_greater_15);
  tcase_add_test(tc1_greater, s21_greater_16);
  tcase_add_test(tc1_greater, s21_greater_17);
  tcase_add_test(tc1_greater, s21_greater_18);
  tcase_add_test(tc1_greater, s21_greater_19);
  tcase_add_test(tc1_greater, s21_greater_20);
  tcase_add_test(tc1_greater, s21_greater_21);
  tcase_add_test(tc1_greater, s21_greater_22);
  tcase_add_test(tc1_greater, s21_greater_23);
  tcase_add_test(tc1_greater, s21_greater_24);
  tcase_add_test(tc1_greater, s21_greater_25);
  tcase_add_test(tc1_greater, s21_greater_26);
  tcase_add_test(tc1_greater, s21_greater_27);
  tcase_add_test(tc1_greater, s21_greater_28);
  tcase_add_test(tc1_greater, s21_greater_29);
  tcase_add_test(tc1_greater, s21_greater_30);
  tcase_add_test(tc1_greater, s21_greater_31);
  tcase_add_test(tc1_greater, s21_greater_32);
  tcase_add_test(tc1_greater, s21_greater_33);
  tcase_add_test(tc1_greater, s21_greater_34);
  tcase_add_test(tc1_greater, s21_greater_35);
  tcase_add_test(tc1_greater, s21_greater_36);
  tcase_add_test(tc1_greater, s21_greater_37);
  tcase_add_test(tc1_greater, s21_greater_38);
  tcase_add_test(tc1_greater, s21_greater_39);
  tcase_add_test(tc1_greater, s21_greater_40);
  suite_add_tcase(suite, tc1_greater);

  // Добавление тестов в набор
  TCase *tc1_equal = tcase_create("Cast");
  tcase_add_test(tc1_equal, s21_is_equalal_1);
  tcase_add_test(tc1_equal, s21_is_equalal_2);
  tcase_add_test(tc1_equal, s21_is_equalal_3_fraction);
  tcase_add_test(tc1_equal, s21_is_equalal_4_sign);
  tcase_add_test(tc1_equal, s21_is_equalal_5_sign);
  tcase_add_test(tc1_equal, s21_is_equalal_6);
  tcase_add_test(tc1_equal, s21_is_equalal_7);
  tcase_add_test(tc1_equal, s21_is_equalal_8);
  tcase_add_test(tc1_equal, s21_is_equalal_9_ss);
  tcase_add_test(tc1_equal, s21_is_equalal_10);
  tcase_add_test(tc1_equal, s21_is_equalal_12_value);
  tcase_add_test(tc1_equal, s21_is_equalal_13_value);
  tcase_add_test(tc1_equal, s21_is_equalal_14_value);
  tcase_add_test(tc1_equal, s21_is_equalal_15);
  tcase_add_test(tc1_equal, s21_is_equalal_17);
  tcase_add_test(tc1_equal, s21_is_equalal_18);
  tcase_add_test(tc1_equal, s21_is_equalal_19);
  tcase_add_test(tc1_equal, s21_is_equalal_20);
  tcase_add_test(tc1_equal, s21_is_equalal_21);
  tcase_add_test(tc1_equal, s21_is_equalal_22);
  tcase_add_test(tc1_equal, s21_is_equalal_23);
  tcase_add_test(tc1_equal, s21_is_equalal_24);
  tcase_add_test(tc1_equal, s21_is_equalal_25);
  tcase_add_test(tc1_equal, s21_is_equalal_26);
  tcase_add_test(tc1_equal, s21_is_equalal_27);
  tcase_add_test(tc1_equal, s21_is_equalal_28);
  tcase_add_test(tc1_equal, s21_is_equalal_29);
  tcase_add_test(tc1_equal, s21_is_equalal_30);
  tcase_add_test(tc1_equal, s21_is_equalal_31);
  tcase_add_test(tc1_equal, s21_is_equalal_32);
  tcase_add_test(tc1_equal, s21_is_equalal_33);
  tcase_add_test(tc1_equal, s21_is_equalal_34);
  tcase_add_test(tc1_equal, s21_is_equalal_35);
  tcase_add_test(tc1_equal, s21_is_equalal_36);
  tcase_add_test(tc1_equal, s21_is_equalal_37);
  tcase_add_test(tc1_equal, s21_is_equalal_38);
  tcase_add_test(tc1_equal, s21_is_equalal_39);
  tcase_add_test(tc1_equal, s21_is_equalal_40);
  tcase_add_test(tc1_equal, s21_is_equalal_41);
  tcase_add_test(tc1_equal, s21_is_equalal_42);
  tcase_add_test(tc1_equal, s21_is_equalal_43);
  tcase_add_test(tc1_equal, s21_is_equalal_44);
  tcase_add_test(tc1_equal, s21_is_equalal_45);
  tcase_add_test(tc1_equal, s21_is_equalal_46);
  tcase_add_test(tc1_equal, s21_is_equalal_47);
  tcase_add_test(tc1_equal, s21_is_equalal_48);
  tcase_add_test(tc1_equal, s21_is_equalal_49);
  tcase_add_test(tc1_equal, s21_is_equalal_50);
  tcase_add_test(tc1_equal, s21_is_equalal_51);
  tcase_add_test(tc1_equal, s21_is_equalal_52);
  tcase_add_test(tc1_equal, s21_is_equalal_53);
  tcase_add_test(tc1_equal, s21_is_equalal_54);
  suite_add_tcase(suite, tc1_equal);

  // Добавление тестов в набор
  TCase *tc1_less_or_equal = tcase_create("Cast");
  tcase_add_test(tc1_less_or_equal, s21_less_or_equal_1);
  tcase_add_test(tc1_less_or_equal, s21_less_or_equal_2);
  tcase_add_test(tc1_less_or_equal, s21_less_or_equal_3);
  tcase_add_test(tc1_less_or_equal, s21_less_or_equal_4);
  tcase_add_test(tc1_less_or_equal, s21_less_or_equal_5);
  tcase_add_test(tc1_less_or_equal, s21_less_or_equal_6);
  tcase_add_test(tc1_less_or_equal, s21_less_or_equal_7);
  tcase_add_test(tc1_less_or_equal, s21_less_or_equal_8);
  tcase_add_test(tc1_less_or_equal, s21_less_or_equal_9);
  tcase_add_test(tc1_less_or_equal, s21_less_or_equal_10);
  tcase_add_test(tc1_less_or_equal, s21_less_or_equal_11);
  tcase_add_test(tc1_less_or_equal, s21_less_or_equal_12);
  tcase_add_test(tc1_less_or_equal, s21_less_or_equal_13);
  tcase_add_test(tc1_less_or_equal, s21_less_or_equal_14);
  tcase_add_test(tc1_less_or_equal, s21_less_or_equal_15);
  tcase_add_test(tc1_less_or_equal, s21_less_or_equal_16);
  tcase_add_test(tc1_less_or_equal, s21_less_or_equal_17);
  tcase_add_test(tc1_less_or_equal, s21_less_or_equal_18);
  tcase_add_test(tc1_less_or_equal, s21_less_or_equal_19);
  tcase_add_test(tc1_less_or_equal, s21_less_or_equal_20);
  tcase_add_test(tc1_less_or_equal, s21_less_or_equal_21);
  tcase_add_test(tc1_less_or_equal, s21_less_or_equal_22);
  tcase_add_test(tc1_less_or_equal, s21_less_or_equal_23);
  tcase_add_test(tc1_less_or_equal, s21_less_or_equal_24);
  tcase_add_test(tc1_less_or_equal, s21_less_or_equal_25);
  tcase_add_test(tc1_less_or_equal, s21_less_or_equal_26);
  tcase_add_test(tc1_less_or_equal, s21_less_or_equal_27);
  tcase_add_test(tc1_less_or_equal, s21_less_or_equal_28);
  tcase_add_test(tc1_less_or_equal, s21_less_or_equal_29);
  tcase_add_test(tc1_less_or_equal, s21_less_or_equal_30);
  tcase_add_test(tc1_less_or_equal, s21_less_or_equal_31);
  tcase_add_test(tc1_less_or_equal, s21_less_or_equal_32);
  tcase_add_test(tc1_less_or_equal, s21_less_or_equal_33);
  tcase_add_test(tc1_less_or_equal, s21_less_or_equal_34);
  tcase_add_test(tc1_less_or_equal, s21_less_or_equal_35);
  tcase_add_test(tc1_less_or_equal, s21_less_or_equal_36);
  tcase_add_test(tc1_less_or_equal, s21_less_or_equal_37);
  tcase_add_test(tc1_less_or_equal, s21_less_or_equal_38);
  tcase_add_test(tc1_less_or_equal, s21_less_or_equal_39);
  tcase_add_test(tc1_less_or_equal, s21_less_or_equal_40);
  suite_add_tcase(suite, tc1_less_or_equal);

  // Добавление тестов в набор
  TCase *tc1_greater_or_equal = tcase_create("Cast");
  tcase_add_test(tc1_greater_or_equal, s21_greater_or_equal_1);
  tcase_add_test(tc1_greater_or_equal, s21_greater_or_equal_2);
  tcase_add_test(tc1_greater_or_equal, s21_greater_or_equal_3);
  tcase_add_test(tc1_greater_or_equal, s21_greater_or_equal_4);
  tcase_add_test(tc1_greater_or_equal, s21_greater_or_equal_5);
  tcase_add_test(tc1_greater_or_equal, s21_greater_or_equal_6);
  tcase_add_test(tc1_greater_or_equal, s21_greater_or_equal_7);
  tcase_add_test(tc1_greater_or_equal, s21_greater_or_equal_8);
  tcase_add_test(tc1_greater_or_equal, s21_greater_or_equal_9);
  tcase_add_test(tc1_greater_or_equal, s21_greater_or_equal_10);
  tcase_add_test(tc1_greater_or_equal, s21_greater_or_equal_11);
  tcase_add_test(tc1_greater_or_equal, s21_greater_or_equal_12);
  tcase_add_test(tc1_greater_or_equal, s21_greater_or_equal_13);
  tcase_add_test(tc1_greater_or_equal, s21_greater_or_equal_14);
  tcase_add_test(tc1_greater_or_equal, s21_greater_or_equal_15);
  tcase_add_test(tc1_greater_or_equal, s21_greater_or_equal_16);
  tcase_add_test(tc1_greater_or_equal, s21_greater_or_equal_17);
  tcase_add_test(tc1_greater_or_equal, s21_greater_or_equal_18);
  tcase_add_test(tc1_greater_or_equal, s21_greater_or_equal_19);
  tcase_add_test(tc1_greater_or_equal, s21_greater_or_equal_20);
  tcase_add_test(tc1_greater_or_equal, s21_greater_or_equal_21);
  tcase_add_test(tc1_greater_or_equal, s21_greater_or_equal_22);
  tcase_add_test(tc1_greater_or_equal, s21_greater_or_equal_23);
  tcase_add_test(tc1_greater_or_equal, s21_greater_or_equal_24);
  tcase_add_test(tc1_greater_or_equal, s21_greater_or_equal_25);
  tcase_add_test(tc1_greater_or_equal, s21_greater_or_equal_26);
  tcase_add_test(tc1_greater_or_equal, s21_greater_or_equal_27);
  tcase_add_test(tc1_greater_or_equal, s21_greater_or_equal_28);
  tcase_add_test(tc1_greater_or_equal, s21_greater_or_equal_29);
  tcase_add_test(tc1_greater_or_equal, s21_greater_or_equal_30);
  tcase_add_test(tc1_greater_or_equal, s21_greater_or_equal_31);
  tcase_add_test(tc1_greater_or_equal, s21_greater_or_equal_32);
  tcase_add_test(tc1_greater_or_equal, s21_greater_or_equal_33);
  tcase_add_test(tc1_greater_or_equal, s21_greater_or_equal_34);
  tcase_add_test(tc1_greater_or_equal, s21_greater_or_equal_35);
  tcase_add_test(tc1_greater_or_equal, s21_greater_or_equal_36);
  tcase_add_test(tc1_greater_or_equal, s21_greater_or_equal_37);
  tcase_add_test(tc1_greater_or_equal, s21_greater_or_equal_38);
  tcase_add_test(tc1_greater_or_equal, s21_greater_or_equal_39);
  tcase_add_test(tc1_greater_or_equal, s21_greater_or_equal_40);
  suite_add_tcase(suite, tc1_greater_or_equal);

  // Добавление тестов в набор
  TCase *tc1_not_equal = tcase_create("Cast");
  tcase_add_test(tc1_not_equal, s21_not_equal_1_1);
  tcase_add_test(tc1_not_equal, s21_not_equal_2_1);
  tcase_add_test(tc1_not_equal, s21_not_equal_3_fraction_1);
  tcase_add_test(tc1_not_equal, s21_not_equal_4_sign_1);
  tcase_add_test(tc1_not_equal, s21_not_equal_5_sign_1);
  tcase_add_test(tc1_not_equal, s21_not_equal_6_1);
  tcase_add_test(tc1_not_equal, s21_not_equal_7_1);
  tcase_add_test(tc1_not_equal, s21_not_equal_8_1);
  tcase_add_test(tc1_not_equal, s21_not_equal_9_ss_1);
  tcase_add_test(tc1_not_equal, s21_not_equal_10_1);
  tcase_add_test(tc1_not_equal, s21_not_equal_11_zero_1);
  tcase_add_test(tc1_not_equal, s21_not_equal_12_value_1);
  tcase_add_test(tc1_not_equal, s21_not_equal_13_value_1);
  tcase_add_test(tc1_not_equal, s21_not_equal_14_value_1);
  tcase_add_test(tc1_not_equal, s21_not_equal_1);
  tcase_add_test(tc1_not_equal, s21_not_equal_2);
  tcase_add_test(tc1_not_equal, s21_not_equal_3);
  tcase_add_test(tc1_not_equal, s21_not_equal_4);
  tcase_add_test(tc1_not_equal, s21_not_equal_5);
  tcase_add_test(tc1_not_equal, s21_not_equal_6);
  tcase_add_test(tc1_not_equal, s21_not_equal_7);
  tcase_add_test(tc1_not_equal, s21_not_equal_8);
  tcase_add_test(tc1_not_equal, s21_not_equal_9);
  tcase_add_test(tc1_not_equal, s21_not_equal_10);
  tcase_add_test(tc1_not_equal, s21_not_equal_11);
  tcase_add_test(tc1_not_equal, s21_not_equal_12);
  tcase_add_test(tc1_not_equal, s21_not_equal_13);
  tcase_add_test(tc1_not_equal, s21_not_equal_14);
  tcase_add_test(tc1_not_equal, s21_not_equal_15);
  tcase_add_test(tc1_not_equal, s21_not_equal_16);
  tcase_add_test(tc1_not_equal, s21_not_equal_17);
  tcase_add_test(tc1_not_equal, s21_not_equal_18);
  tcase_add_test(tc1_not_equal, s21_not_equal_19);
  tcase_add_test(tc1_not_equal, s21_not_equal_20);
  tcase_add_test(tc1_not_equal, s21_not_equal_21);
  tcase_add_test(tc1_not_equal, s21_not_equal_22);
  tcase_add_test(tc1_not_equal, s21_not_equal_23);
  tcase_add_test(tc1_not_equal, s21_not_equal_24);
  tcase_add_test(tc1_not_equal, s21_not_equal_25);
  tcase_add_test(tc1_not_equal, s21_not_equal_26);
  tcase_add_test(tc1_not_equal, s21_not_equal_27);
  tcase_add_test(tc1_not_equal, s21_not_equal_28);
  tcase_add_test(tc1_not_equal, s21_not_equal_29);
  tcase_add_test(tc1_not_equal, s21_not_equal_30);
  tcase_add_test(tc1_not_equal, s21_not_equal_31);
  tcase_add_test(tc1_not_equal, s21_not_equal_32);
  tcase_add_test(tc1_not_equal, s21_not_equal_33);
  tcase_add_test(tc1_not_equal, s21_not_equal_34);
  tcase_add_test(tc1_not_equal, s21_not_equal_35);
  tcase_add_test(tc1_not_equal, s21_not_equal_36);
  tcase_add_test(tc1_not_equal, s21_not_equal_37);
  tcase_add_test(tc1_not_equal, s21_not_equal_38);
  tcase_add_test(tc1_not_equal, s21_not_equal_39);
  tcase_add_test(tc1_not_equal, s21_not_equal_40);
  suite_add_tcase(suite, tc1_not_equal);

  // Добавление тестов в набор
  TCase *tc1_negate = tcase_create("Cast");
  tcase_add_test(tc1_negate, s21_negate_1);
  tcase_add_test(tc1_negate, s21_negate_2);
  tcase_add_test(tc1_negate, s21_negate_3);
  tcase_add_test(tc1_negate, s21_negate_4);
  tcase_add_test(tc1_negate, s21_negate_5);
  tcase_add_test(tc1_negate, s21_negate_6);
  tcase_add_test(tc1_negate, s21_negate_7);
  tcase_add_test(tc1_negate, s21_negate_8);
  tcase_add_test(tc1_negate, s21_negate_9);
  tcase_add_test(tc1_negate, s21_negate_10);
  tcase_add_test(tc1_negate, s21_negate_11);
  tcase_add_test(tc1_negate, s21_negate_12);
  tcase_add_test(tc1_negate, s21_negate_13);
  tcase_add_test(tc1_negate, s21_negate_14);
  tcase_add_test(tc1_negate, s21_negate_15);
  tcase_add_test(tc1_negate, s21_negate_16);
  tcase_add_test(tc1_negate, s21_negate_17);
  tcase_add_test(tc1_negate, s21_negate_18);
  tcase_add_test(tc1_negate, s21_negate_19);
  tcase_add_test(tc1_negate, s21_negate_20);
  tcase_add_test(tc1_negate, s21_negate_21);
  tcase_add_test(tc1_negate, s21_negate_22);
  tcase_add_test(tc1_negate, s21_negate_23);
  tcase_add_test(tc1_negate, s21_negate_24);
  tcase_add_test(tc1_negate, s21_negate_25);
  tcase_add_test(tc1_negate, s21_negate_26);
  tcase_add_test(tc1_negate, s21_negate_27);
  tcase_add_test(tc1_negate, s21_negate_28);
  tcase_add_test(tc1_negate, s21_negate_29);
  tcase_add_test(tc1_negate, s21_negate_30);
  tcase_add_test(tc1_negate, s21_negate_31);
  tcase_add_test(tc1_negate, s21_negate_32);
  tcase_add_test(tc1_negate, s21_negate_33);
  tcase_add_test(tc1_negate, s21_negate_34);
  tcase_add_test(tc1_negate, s21_negate_35);
  tcase_add_test(tc1_negate, s21_negate_36);
  tcase_add_test(tc1_negate, s21_negate_37);
  tcase_add_test(tc1_negate, s21_negate_38);
  tcase_add_test(tc1_negate, s21_negate_39);
  tcase_add_test(tc1_negate, s21_negate_40);
  tcase_add_test(tc1_negate, s21_negate_41);
  tcase_add_test(tc1_negate, s21_negate_42);
  suite_add_tcase(suite, tc1_negate);

  // Добавление тестов в набор
  TCase *tc1_truncate = tcase_create("Cast");
  tcase_add_test(tc1_truncate, s21_truncate_1);
  tcase_add_test(tc1_truncate, s21_truncate_2);
  tcase_add_test(tc1_truncate, s21_truncate_3);
  tcase_add_test(tc1_truncate, s21_truncate_5);
  tcase_add_test(tc1_truncate, s21_truncate_6);
  tcase_add_test(tc1_truncate, s21_truncate_7);
  tcase_add_test(tc1_truncate, s21_truncate_8);
  tcase_add_test(tc1_truncate, s21_truncate_9);
  tcase_add_test(tc1_truncate, s21_truncate_10);
  tcase_add_test(tc1_truncate, s21_truncate_11);
  tcase_add_test(tc1_truncate, s21_truncate_12);
  tcase_add_test(tc1_truncate, s21_truncate_13);
  tcase_add_test(tc1_truncate, s21_truncate_14);
  tcase_add_test(tc1_truncate, s21_truncate_15);
  tcase_add_test(tc1_truncate, s21_truncate_16);
  tcase_add_test(tc1_truncate, s21_truncate_17);
  tcase_add_test(tc1_truncate, s21_truncate_18);
  tcase_add_test(tc1_truncate, s21_truncate_19);
  tcase_add_test(tc1_truncate, s21_truncate_20);
  tcase_add_test(tc1_truncate, s21_truncate_21);
  tcase_add_test(tc1_truncate, s21_truncate_22);
  tcase_add_test(tc1_truncate, s21_truncate_23);
  tcase_add_test(tc1_truncate, s21_truncate_24);
  tcase_add_test(tc1_truncate, s21_truncate_25);
  tcase_add_test(tc1_truncate, s21_truncate_26);
  tcase_add_test(tc1_truncate, s21_truncate_27);
  tcase_add_test(tc1_truncate, s21_truncate_28);
  tcase_add_test(tc1_truncate, s21_truncate_29);
  tcase_add_test(tc1_truncate, s21_truncate_30);
  tcase_add_test(tc1_truncate, s21_truncate_31);
  tcase_add_test(tc1_truncate, s21_truncate_32);
  tcase_add_test(tc1_truncate, s21_truncate_33);
  tcase_add_test(tc1_truncate, s21_truncate_34);
  tcase_add_test(tc1_truncate, s21_truncate_35);
  tcase_add_test(tc1_truncate, s21_truncate_36);
  tcase_add_test(tc1_truncate, s21_truncate_37);
  tcase_add_test(tc1_truncate, s21_truncate_38);
  tcase_add_test(tc1_truncate, s21_truncate_39);
  tcase_add_test(tc1_truncate, s21_truncate_40);
  tcase_add_test(tc1_truncate, s21_truncate_42);
  suite_add_tcase(suite, tc1_truncate);

  // Добавление тестов в набор
  TCase *tc1_round_ = tcase_create("Cast");
  tcase_add_test(tc1_round_, s21_round_1);
  tcase_add_test(tc1_round_, s21_round_2);
  tcase_add_test(tc1_round_, s21_round_3);
  tcase_add_test(tc1_round_, s21_round_4);
  tcase_add_test(tc1_round_, s21_round_7);
  tcase_add_test(tc1_round_, s21_round_8);
  tcase_add_test(tc1_round_, s21_round_9);
  tcase_add_test(tc1_round_, s21_round_10);
  tcase_add_test(tc1_round_, s21_round_11);
  tcase_add_test(tc1_round_, s21_round_12);
  tcase_add_test(tc1_round_, s21_round_13);
  tcase_add_test(tc1_round_, s21_round_14);
  tcase_add_test(tc1_round_, s21_round_15);
  tcase_add_test(tc1_round_, s21_round_16);
  tcase_add_test(tc1_round_, s21_round_17);
  tcase_add_test(tc1_round_, s21_round_18);
  tcase_add_test(tc1_round_, s21_round_19);
  tcase_add_test(tc1_round_, s21_round_20);
  tcase_add_test(tc1_round_, s21_round_21);
  tcase_add_test(tc1_round_, s21_round_23);
  tcase_add_test(tc1_round_, s21_round_24);
  suite_add_tcase(suite, tc1_round_);

  // Добавление тестов в набор
  TCase *tc1_floor = tcase_create("Cast");
  tcase_add_test(tc1_floor, s21_floor_1);
  tcase_add_test(tc1_floor, s21_floor_2);
  tcase_add_test(tc1_floor, s21_floor_3);
  tcase_add_test(tc1_floor, s21_floor_4);
  tcase_add_test(tc1_floor, s21_floor_6);
  tcase_add_test(tc1_floor, s21_floor_7);
  tcase_add_test(tc1_floor, s21_floor_8);
  tcase_add_test(tc1_floor, s21_floor_9);
  tcase_add_test(tc1_floor, s21_floor_10);
  tcase_add_test(tc1_floor, s21_floor_11);
  tcase_add_test(tc1_floor, s21_floor_12);
  tcase_add_test(tc1_floor, s21_floor_13);
  tcase_add_test(tc1_floor, s21_floor_14);
  tcase_add_test(tc1_floor, s21_floor_15);
  tcase_add_test(tc1_floor, s21_floor_16);
  tcase_add_test(tc1_floor, s21_floor_17);
  tcase_add_test(tc1_floor, s21_floor_18);
  tcase_add_test(tc1_floor, s21_floor_19);
  tcase_add_test(tc1_floor, s21_floor_20);
  tcase_add_test(tc1_floor, s21_floor_21);
  tcase_add_test(tc1_floor, s21_floor_22);
  tcase_add_test(tc1_floor, s21_floor_23);
  tcase_add_test(tc1_floor, s21_floor_24);
  tcase_add_test(tc1_floor, s21_floor_25);
  suite_add_tcase(suite, tc1_floor);

  return suite;
}

int main() {
  // Создание тестового набора
  Suite *suite = main_suite();

  // Создание раннера тестов
  SRunner *runner = srunner_create(suite);

  // Запуск всех тестов
  srunner_run_all(runner, CK_NORMAL);

  // Получение количества неуспешных тестов
  int failed = srunner_ntests_failed(runner);

  // Освобождение памяти
  srunner_free(runner);

  // Возврат кода ошибки, если есть неуспешные тесты
  return (failed == 0) ? 0 : 1;
}
