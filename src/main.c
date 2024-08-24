#include <math.h>
#include <stdio.h>

#include "s21_decimal.h"

int main() {
  {
    s21_decimal src1, src2;
    float num1 = -0.94e03;
    float num2 = -112.0e2;
    float res_origin = -12139.99;
    s21_from_float_to_decimal(num1, &src1);
    s21_from_float_to_decimal(num2, &src2);
    s21_decimal res_dec = {0};
    float res_float = 0.0;
    s21_add(src1, src2, &res_dec);
    s21_from_decimal_to_float(res_dec, &res_float);
    PrintDecimalBinary(&res_dec);
    PrintDecimalDec(res_dec);
    PrintDecimalBinary(&src1);
    PrintDecimalDec(src1);
    PrintDecimalBinary(&src2);
    PrintDecimalDec(src2);
    printf("%.10f %.10f", res_float, res_origin);
  }
  // {
  // 	s21_decimal src1, src2;
  // 	float num1 = -0.94e03;
  // 	float num2 = -112.0234;
  // 	float res_origin = -1052.0233;
  // 	s21_from_float_to_decimal(num1, &src1);
  // 	s21_from_float_to_decimal(num2, &src2);
  // 	s21_decimal res_dec = {0};
  // 	float res_float = 0.0;
  // 	s21_add(src1, src2, &res_dec);
  // 	s21_from_decimal_to_float(res_dec, &res_float);
  // 			PrintDecimalBinary(&res_dec);
  // 	PrintDecimalDec(res_dec);
  // 	PrintDecimalBinary(&src1);
  // 	PrintDecimalDec(src1);
  // 	PrintDecimalBinary(&src2);
  // 	PrintDecimalDec(src2);
  // 	printf("%.10f %.10f", res_float, res_origin);
  // }
  // {
  // 	s21_decimal src1, src2;
  // 	float num1 = -0.9403;
  // 	float num2 = -112.0234;
  // 	float res_origin = -112.9635999;
  // 	s21_from_float_to_decimal(num1, &src1);
  // 	s21_from_float_to_decimal(num2, &src2);
  // 	s21_decimal res_dec = {0};
  // 	float res_float = 0.0;
  // 	s21_add(src1, src2, &res_dec);
  // 	s21_from_decimal_to_float(res_dec, &res_float);
  // 	PrintDecimalBinary(&res_dec);
  // 	PrintDecimalDec(res_dec);
  // 	PrintDecimalBinary(&src1);
  // 	PrintDecimalDec(src1);
  // 	PrintDecimalBinary(&src2);
  // 	PrintDecimalDec(src2);
  // 	printf("%.10f %.10f", res_float, res_origin);

  // }

  // {
  // 	s21_decimal src1, src2;
  // 	float num1 = -0.9403;
  // 	float num2 = 0.000234;
  // 	float res_origin = -0.9400659;
  // 	s21_from_float_to_decimal(num1, &src1);
  // 	s21_from_float_to_decimal(num2, &src2);
  // 	s21_decimal res_dec = {0};
  // 	float res_float = 0.0;
  // 	s21_add(src1, src2, &res_dec);
  // 	s21_from_decimal_to_float(res_dec, &res_float);
  // 	PrintDecimalBinary(&res_dec);
  // 	PrintDecimalDec(res_dec);
  // 	PrintDecimalBinary(&src1);
  // 	PrintDecimalDec(src1);
  // 	PrintDecimalBinary(&src2);
  // 	PrintDecimalDec(src2);
  // 	printf("%.10f %.10f", res_float, res_origin);

  // }

  // {
  // 	s21_decimal src1, src2;
  // 	float num1 = -940.3;
  // 	float num2 = 0.000234;
  // 	float res_origin = -940.299;
  // 	s21_from_float_to_decimal(num1, &src1);
  // 	s21_from_float_to_decimal(num2, &src2);
  // 	s21_decimal res_dec = {0};
  // 	float res_float = 0.0;
  // 	s21_add(src1, src2, &res_dec);
  // 	s21_from_decimal_to_float(res_dec, &res_float);
  // 	PrintDecimalBinary(&res_dec);
  // 	PrintDecimalDec(res_dec);
  // 	PrintDecimalBinary(&src1);
  // 	PrintDecimalDec(src1);
  // 	PrintDecimalBinary(&src2);
  // 	PrintDecimalDec(src2);
  // 	printf("%.10f %.10f", res_float, res_origin);
  // }
  // {
  // 	s21_decimal src1, src2, origin, result;
  // 	int value_type_result, value_type_origin;
  // 	// src1 = -364748;
  // 	// src2 = 1;
  // 	src1.bits[0] = 0b00000000000001011001000011001100;
  // 	src1.bits[1] = 0b00000000000000000000000000000000;
  // 	src1.bits[2] = 0b00000000000000000000000000000000;
  // 	src1.bits[3] = 0b10000000000000000000000000000000;
  // 	src2.bits[0] = 0b00000000000000000000000000000001;
  // 	src2.bits[1] = 0b00000000000000000000000000000000;
  // 	src2.bits[2] = 0b00000000000000000000000000000000;
  // 	src2.bits[3] = 0b00000000000000000000000000000000;
  // 	value_type_result = s21_add(src1, src2, &result);
  // 	value_type_origin = 0;
  // 	origin.bits[0] = 0b00000000000001011001000011001011;
  // 	origin.bits[1] = 0b00000000000000000000000000000000;
  // 	origin.bits[2] = 0b00000000000000000000000000000000;
  // 	origin.bits[3] = 0b10000000000000000000000000000000;
  // 	PrintDecimalBinary(&src1);
  // 	PrintDecimalDec(src1);
  // 	PrintDecimalBinary(&src2);
  // 	PrintDecimalDec(src2);
  // 	PrintDecimalBinary(&origin);
  // 	PrintDecimalDec(origin);
  // 	PrintDecimalBinary(&result);
  // 	PrintDecimalDec(result);
  // }

  // s21_decimal src1, src2, src3, src4, src5, src6, src7;
  // float temp1 = 123456789.0;
  // float temp2 = 1234567.890;
  // float temp3 = 12.34567890;
  // float temp4 = 12345.67890;
  // float temp5 = 0.1234567890;
  // float temp6 = 0.000000001234567890;
  // float temp7 = 0.00000000000000000000001234567890;
  // s21_from_float_to_decimal(temp1, &src1);
  // s21_from_float_to_decimal(temp2, &src2);
  // s21_from_float_to_decimal(temp3, &src3);
  // s21_from_float_to_decimal(temp4, &src4);
  // s21_from_float_to_decimal(temp5, &src5);
  // s21_from_float_to_decimal(temp6, &src6);
  // s21_from_float_to_decimal(temp7, &src7);
  // PrintDecimalBinary(&src1);
  // PrintDecimalDec(src1);
  // printf("\nNEXT\n\n");
  // PrintDecimalBinary(&src2);
  // PrintDecimalDec(src2);
  // printf("\nNEXT\n\n");
  // PrintDecimalBinary(&src3);
  // PrintDecimalDec(src3);
  // printf("\nNEXT\n\n");
  // PrintDecimalBinary(&src4);
  // PrintDecimalDec(src4);
  // printf("\nNEXT\n\n");
  // PrintDecimalBinary(&src5);
  // PrintDecimalDec(src5);
  // printf("\nNEXT\n\n");
  // PrintDecimalBinary(&src6);
  // PrintDecimalDec(src6);
  // printf("\nNEXT\n\n");
  // PrintDecimalBinary(&src7);
  // PrintDecimalDec(src7);

  //{
  //	s21_decimal src1, src2, result, origin;
  //	// 79 228 162 514 264 337 593 543 950 335
  //	// 79 228 162 514 264 337 593 543.950 335
  //	src1.bits[0] = 0b00000000000000000000000000000001;
  //	src1.bits[1] = 0b00000000000000000000000000000000;
  //	src1.bits[2] = 0b00000000000000000000000000000000;
  //	src1.bits[3] = 0b00000000000000000000000000000000;
  //	SetExp(&src1, 28);

  //	src2.bits[0] = 0b00000000000000000000000000000101;
  //	src2.bits[1] = 0b00000000000000000000000000000000;
  //	src2.bits[2] = 0b00000000000000000000000000000000;
  //	src2.bits[3] = 0b00000000000000000000000000000000;
  //	SetExp(&src2, 1);

  //	int check = s21_mul(src1, src2, &result);
  //	PrintDecimalBinary(&src1);
  //	PrintDecimalDec(src1);
  //	PrintDecimalBinary(&src2);
  //	PrintDecimalDec(src2);
  //	PrintDecimalBinary(&result);
  //	PrintDecimalDec(result);
  //	printf("err = %d\n", check);
  //}
  // printf("\nNEXT\n\n");
  //{
  //	s21_decimal src1, src2, result, origin;
  //	// 79 228 162 514 264 337 593 543 950 335
  //	// 79 228 162 514 264 337 593 543.950 335
  //	src1.bits[0] = 0b00000000000000000000000000000001;
  //	src1.bits[1] = 0b00000000000000000000000000000000;
  //	src1.bits[2] = 0b00000000000000000000000000000000;
  //	src1.bits[3] = 0b00000000000000000000000000000000;
  //	SetExp(&src1, 28);

  //	src2.bits[0] = 0b00000000000000000000000000000010;
  //	src2.bits[1] = 0b00000000000000000000000000000000;
  //	src2.bits[2] = 0b00000000000000000000000000000000;
  //	src2.bits[3] = 0b00000000000000000000000000000000;

  //	int check = s21_div(src1, src2, &result);
  //	PrintDecimalBinary(&src1);
  //	PrintDecimalDec(src1);
  //	PrintDecimalBinary(&src2);
  //	PrintDecimalDec(src2);
  //	PrintDecimalBinary(&result);
  //	PrintDecimalDec(result);
  //	printf("err = %d\n", check);
  //}
  //   {  // мелкие цифры для начала только для деления
  //     s21_decimal src1, src2, result, origin;

  //     // 120
  //     // 0.5
  //     src1.bits[0] = 0b00000000000000000000000001111000;
  //     src1.bits[1] = 0b00000000000000000000000000000000;
  //     src1.bits[2] = 0b00000000000000000000000000000000;
  //     src1.bits[3] = 0b00000000000000000000000000000000;

  //     src2.bits[0] = 0b00000000000000000000000000000101;
  //     src2.bits[1] = 0b00000000000000000000000000000000;
  //     src2.bits[2] = 0b00000000000000000000000000000000;
  //     src2.bits[3] = 0b00000000000000010000000000000000;
  //     // 240

  //     origin.bits[0] = 0b00000000000000000000000011110000;
  //     origin.bits[1] = 0b00000000000000000000000000000000;
  //     origin.bits[2] = 0b00000000000000000000000000000000;
  //     origin.bits[3] = 0b00000000000000010000000000000000;
  //     int check = s21_div(src1, src2, &result);
  //     int check_origin = 0;
  //     PrintDecimalBinary(&src1);
  //     PrintDecimalDec(src1);
  //     PrintDecimalBinary(&src2);
  //     PrintDecimalDec(src2);
  //     PrintDecimalBinary(&result);
  //     PrintDecimalDec(result);
  //     printf("err = %d\n", check);
  //   }
  // 	printf("\nNEXT\n\n");
  //   {
  //     s21_decimal src1, src2, result, origin;
  //     // 79 228 162 514 264 337 593 543 950 335
  //     // 79 228 162 514 264 337 593 543.950 335
  //     src1.bits[0] = 0b11111111111111111111111111111111;
  //     src1.bits[1] = 0b11111111111111111111111111111111;
  //     src1.bits[2] = 0b11111111111111111111111111111111;
  //     src1.bits[3] = 0b10000000000000000000000000000000;

  //     src2.bits[0] = 0b00000000000000000000000000000001;
  //     src2.bits[1] = 0b00000000000000000000000000000000;
  //     src2.bits[2] = 0b00000000000000000000000000000000;
  //     src2.bits[3] = 0b00000000000000010000000000000000;

  //     int check = s21_mul(src1, src2, &result);
  //     PrintDecimalBinary(&src1);
  //     PrintDecimalDec(src1);
  //     PrintDecimalBinary(&src2);
  //     PrintDecimalDec(src2);
  //     PrintDecimalBinary(&result);
  //     PrintDecimalDec(result);
  //     printf("err = %d\n", check);
  //   }
  // 	printf("\nNEXT\n\n");
  //   {
  //     s21_decimal src1, src2, result, origin;
  //     // 79 228 162 514 264 337 593 543 950 335
  //     // 79 228 162 514 264 337 593 543.950 335
  //     src1.bits[0] = 0b11111111111111111111111111111111;
  //     src1.bits[1] = 0b11111111111111111111111111111111;
  //     src1.bits[2] = 0b11111111111111111111111111111111;
  //     src1.bits[3] = 0b10000000000000000000000000000000;

  //     src2.bits[0] = 0b00000000000000000000000000000001;
  //     src2.bits[1] = 0b00000000000000000000000000000000;
  //     src2.bits[2] = 0b00000000000000000000000000000000;
  //     src2.bits[3] = 0b00000000000000010000000000000000;

  //     int check = s21_div(src1, src2, &result);
  //     PrintDecimalBinary(&src1);
  //     PrintDecimalDec(src1);
  //     PrintDecimalBinary(&src2);
  //     PrintDecimalDec(src2);
  //     PrintDecimalBinary(&result);
  //     PrintDecimalDec(result);
  //     printf("err = %d\n", check);
  //   }
  //   	printf("\nNEXT\n\n");
  //   {
  //     s21_decimal src1, src2, result, origin;
  //     // 79 228 162 514 264 337 593 543 950 335
  //     // 79 228 162 514 264 337 593 543.950 335
  //     src1.bits[0] = 0b11111111111111111111111111111111;
  //     src1.bits[1] = 0b11111111111111111111111111111111;
  //     src1.bits[2] = 0b11111111111111111111111111111111;
  //     src1.bits[3] = 0b00000000000000000000000000000000;

  //     src2.bits[0] = 0b00000000000000000000000000000001;
  //     src2.bits[1] = 0b00000000000000000000000000000000;
  //     src2.bits[2] = 0b00000000000000000000000000000000;
  //     src2.bits[3] = 0b00000000000000010000000000000000;

  //     int check = s21_div(src1, src2, &result);
  //     PrintDecimalBinary(&src1);
  //     PrintDecimalDec(src1);
  //     PrintDecimalBinary(&src2);
  //     PrintDecimalDec(src2);
  //     PrintDecimalBinary(&result);
  //     PrintDecimalDec(result);
  //     printf("err = %d\n", check);
  //   }
  // 	printf("\nNEXT\n\n");
  //   {
  //     s21_decimal src1, src2, result, origin;
  //     // 79 228 162 514 264 337 593 543 950 335
  //     // 79 228 162 514 264 337 593 543.950 335
  //     src1.bits[0] = 0b11111111111111111111111111111111;
  //     src1.bits[1] = 0b11111111111111111111111111111111;
  //     src1.bits[2] = 0b11111111111111111111111111111111;
  //     src1.bits[3] = 0b00000000000000000000000000000000;

  //     src2.bits[0] = 0b00000000000000000000000000000001;
  //     src2.bits[1] = 0b00000000000000000000000000000000;
  //     src2.bits[2] = 0b00000000000000000000000000000000;
  //     src2.bits[3] = 0b00000000000000010000000000000000;

  //     int check = s21_mul(src1, src2, &result);
  //     PrintDecimalBinary(&src1);
  //     PrintDecimalDec(src1);
  //     PrintDecimalBinary(&src2);
  //     PrintDecimalDec(src2);
  //     PrintDecimalBinary(&result);
  //     PrintDecimalDec(result);
  //     printf("err = %d\n", check);
  //   }
  // 	printf("\nNEXT\n\n");
  // 		  {
  //     s21_decimal src1, src2, result, origin;
  //     // 79 228 162 514 264 337 593 543 950 335
  //     // 79 228 162 514 264 337 593 543.950 335
  //     src1.bits[0] = 0b00000000000000000000000000001011;
  //     src1.bits[1] = 0b00000000000000000000000000000000;
  //     src1.bits[2] = 0b00000000000000000000000000000000;
  //     src1.bits[3] = 0b00000000000000000000000000000000;
  // 	SetExp(&src1, 1);

  //     src2.bits[0] = 0b00000000000000000000000000000110;
  //     src2.bits[1] = 0b00000000000000000000000000000000;
  //     src2.bits[2] = 0b00000000000000000000000000000000;
  //     src2.bits[3] = 0b00000000000000000000000000000000;

  //     int check = s21_mul(src1, src2, &result);
  //     PrintDecimalBinary(&src1);
  //     PrintDecimalDec(src1);
  //     PrintDecimalBinary(&src2);
  //     PrintDecimalDec(src2);
  //     PrintDecimalBinary(&result);
  //     PrintDecimalDec(result);
  //     printf("err = %d\n", check);
  //   }
  // 	printf("\nNEXT\n\n");
  // 		  {
  //     s21_decimal src1, src2, result, origin;
  //     // 79 228 162 514 264 337 593 543 950 335
  //     // 79 228 162 514 264 337 593 543.950 335
  //     src1.bits[0] = 0b00000000000000000000000000001011;
  //     src1.bits[1] = 0b00000000000000000000000000000000;
  //     src1.bits[2] = 0b00000000000000000000000000000000;
  //     src1.bits[3] = 0b00000000000000000000000000000000;
  // 	SetExp(&src1, 1);

  //     src2.bits[0] = 0b00000000000000000000000000000110;
  //     src2.bits[1] = 0b00000000000000000000000000000000;
  //     src2.bits[2] = 0b00000000000000000000000000000000;
  //     src2.bits[3] = 0b00000000000000000000000000000000;

  //     int check = s21_div(src1, src2, &result);
  //     PrintDecimalBinary(&src1);
  //     PrintDecimalDec(src1);
  //     PrintDecimalBinary(&src2);
  //     PrintDecimalDec(src2);
  //     PrintDecimalBinary(&result);
  //     PrintDecimalDec(result);
  //     printf("err = %d\n", check);
  //   }
  // 	printf("\nNEXT\n\n");
  // 	  {
  //     s21_decimal src1, src2, result, origin;
  //     // 79 228 162 514 264 337 593 543 950 335
  //     // 79 228 162 514 264 337 593 543.950 335
  //     src1.bits[0] = 0b00000000000000000000000000001010;
  //     src1.bits[1] = 0b00000000000000000000000000000000;
  //     src1.bits[2] = 0b00000000000000000000000000000000;
  //     src1.bits[3] = 0b00000000000000000000000000000000;

  //     src2.bits[0] = 0b00000000000000000000000000000110;
  //     src2.bits[1] = 0b00000000000000000000000000000000;
  //     src2.bits[2] = 0b00000000000000000000000000000000;
  //     src2.bits[3] = 0b00000000000000000000000000000000;

  //     int check = s21_div(src1, src2, &result);
  //     PrintDecimalBinary(&src1);
  //     PrintDecimalDec(src1);
  //     PrintDecimalBinary(&src2);
  //     PrintDecimalDec(src2);
  //     PrintDecimalBinary(&result);
  //     PrintDecimalDec(result);
  //     printf("err = %d\n", check);
  //   }
  // 	printf("\nNEXT\n\n");
  //   {
  //     s21_decimal src1, src2, result, origin;
  //     // 79 228 162 514 264 337 593 543 950 335
  //     // 79 228 162 514 264 337 593 543.950 335
  //     src1.bits[0] = 0b00000000000000000000000000001010;
  //     src1.bits[1] = 0b00000000000000000000000000000000;
  //     src1.bits[2] = 0b00000000000000000000000000000000;
  //     src1.bits[3] = 0b00000000000000000000000000000000;

  //     src2.bits[0] = 0b00000000000000000000000000000110;
  //     src2.bits[1] = 0b00000000000000000000000000000000;
  //     src2.bits[2] = 0b00000000000000000000000000000000;
  //     src2.bits[3] = 0b00000000000000010000000000000000;

  //     int check = s21_div(src1, src2, &result);
  //     PrintDecimalBinary(&src1);
  //     PrintDecimalDec(src1);
  //     PrintDecimalBinary(&src2);
  //     PrintDecimalDec(src2);
  //     PrintDecimalBinary(&result);
  //     PrintDecimalDec(result);
  //     printf("err = %d\n", check);
  //   }
  // 	printf("\nNEXT\n\n");
  //   {  // мелкие цифры для начала только для деления
  //     s21_decimal src1, src2, result, origin;
  //     // 123
  //     // 17.5
  //     src1.bits[0] = 0b00000000000000000000000001111011;
  //     src1.bits[1] = 0b00000000000000000000000000000000;
  //     src1.bits[2] = 0b00000000000000000000000000000000;
  //     src1.bits[3] = 0b00000000000000000000000000000000;

  //     src2.bits[0] = 0b00000000000000000000000010101111;
  //     src2.bits[1] = 0b00000000000000000000000000000000;
  //     src2.bits[2] = 0b00000000000000000000000000000000;
  //     src2.bits[3] = 0b00000000000000010000000000000000;
  //     //7.0285714285714285714285714285714285714285
  //     //714285714285714285714285714285714285714285714285
  //     //714285714285714285714285714285714285714285714285714285714285
  //     //7142857142857142857142857142857142857142857142857142857142857142
  //     //85714285714285714285714285714285714285714285714285714285714285714285714285714285714285714
  //     int check = s21_div(src1, src2, &result);
  //     int check_origin = 0;
  //     PrintDecimalBinary(&src1);
  //     PrintDecimalDec(src1);
  //     PrintDecimalBinary(&src2);
  //     PrintDecimalDec(src2);
  //     PrintDecimalBinary(&result);
  //     PrintDecimalDec(result);
  //     printf("err = %d\n", check);
  //   }

  // 	{
  //     s21_decimal src1, src2, result, origin;
  //     // 79 228 162 514 264 337 593 543 950 335
  //     // 79 228 162 514 264 337 593 543.950 335
  //     src1.bits[0] = 0b11111111111111111111111111111111;
  //     src1.bits[1] = 0b11111111111111111111111111111111;
  //     src1.bits[2] = 0b11111111111111111111111111111111;
  //     src1.bits[3] = 0b10000000000000000000000000000000;

  //     src2.bits[0] = 0b00000000000000000000000000000100;
  //     src2.bits[1] = 0b00000000000000000000000000000000;
  //     src2.bits[2] = 0b00000000000000000000000000000000;
  //     src2.bits[3] = 0b00000000000000000000000000000000;

  //     origin.bits[0] = 0b11111111111111111111111111111111;
  //     origin.bits[1] = 0b11111111111111111111111111111111;
  //     origin.bits[2] = 0b11111111111111111111111111111111;
  //     origin.bits[3] = 0b00000000000001100000000000000000;
  //     int check = s21_mul(src1, src2, &result);
  //     PrintDecimalBinary(&src1);
  //     PrintDecimalDec(src1);
  //     PrintDecimalBinary(&src2);
  //     PrintDecimalDec(src2);
  //     PrintDecimalBinary(&result);
  //     PrintDecimalDec(result);
  //     PrintDecimalBinary(&origin);
  //     PrintDecimalDec(origin);
  //     printf("err = %d\n", check);
  //   }
  //     printf("\nNEXT\n\n");
  //   {
  //     s21_decimal src1, src2, result, origin;
  //     // 79 228 162 514 264 337 593 543 950 335
  //     // 79 228 162 514 264 337 593 543.950 335
  //     src1.bits[0] = 0b11111111111111111111111111111111;
  //     src1.bits[1] = 0b11111111111111111111111111111111;
  //     src1.bits[2] = 0b11111111111111111111111111111111;
  //     src1.bits[3] = 0b00000000000000000000000000000000;

  //     src2.bits[0] = 0b00000000000000000000000000000100;
  //     src2.bits[1] = 0b00000000000000000000000000000000;
  //     src2.bits[2] = 0b00000000000000000000000000000000;
  //     src2.bits[3] = 0b00000000000000000000000000000000;

  //     int check = s21_mul(src1, src2, &result);
  //     PrintDecimalBinary(&src1);
  //     PrintDecimalDec(src1);
  //     PrintDecimalBinary(&src2);
  //     PrintDecimalDec(src2);
  //     PrintDecimalBinary(&result);
  //     PrintDecimalDec(result);
  //     PrintDecimalBinary(&origin);
  //     PrintDecimalDec(origin);
  //     printf("err = %d\n", check);
  //   }
  //     printf("\nNEXT\n\n");
  //   {
  //     s21_decimal src1, src2, result, origin;
  //     // 79 228 162 514 264 337 593 543 950 335
  //     // 79 228 162 514 264 337 593 543.950 335
  //     src1.bits[0] = 0b11111111101111111111111111111111;
  //     src1.bits[1] = 0b11111111111111111111111110111111;
  //     src1.bits[2] = 0b11111111111011111111111111111111;
  //     src1.bits[3] = 0b00000000000000001000000000000000;

  //     src2.bits[0] = 0b11111111101111111111111111111111;
  //     src2.bits[1] = 0b11111111111111111111111110111111;
  //     src2.bits[2] = 0b11111111111111111111111110111111;
  //     src2.bits[3] = 0b00000000000000001000000000000000;

  //     int check = s21_mul(src1, src2, &result);
  //     PrintDecimalBinary(&src1);
  //     PrintDecimalDec(src1);
  //     PrintDecimalBinary(&src2);
  //     PrintDecimalDec(src2);
  //     PrintDecimalBinary(&result);
  //     PrintDecimalDec(result);
  //     PrintDecimalBinary(&origin);
  //     PrintDecimalDec(origin);
  //     printf("err = %d\n", check);
  //   }
  //     printf("\nNEXT\n\n");
  //   {
  //     s21_decimal src1, src2, result, origin;
  //     // 79 228 162 514 264 337 593 543 950 335
  //     // 79 228 162 514 264 337 593 543.950 335
  //     src1.bits[0] = 0b11111111111111111111111111111111;
  //     src1.bits[1] = 0b11111111111111111111111111111111;
  //     src1.bits[2] = 0b11111111111111111111111111111111;
  //     src1.bits[3] = 0b00000000000000000000000000000000;

  //     src2.bits[0] = 0b00000000000000000000000000000100;
  //     src2.bits[1] = 0b00000000000000000000000000000000;
  //     src2.bits[2] = 0b00000000000000000000000000000000;
  //     src2.bits[3] = 0b0000000000000001000000000000000;

  //     int check = s21_div(src1, src2, &result);
  //     PrintDecimalBinary(&src1);
  //     PrintDecimalDec(src1);
  //     PrintDecimalBinary(&src2);
  //     PrintDecimalDec(src2);
  //     PrintDecimalBinary(&result);
  //     PrintDecimalDec(result);
  //     PrintDecimalBinary(&origin);
  //     PrintDecimalDec(origin);
  //     printf("err = %d\n", check);
  //   }
  //     printf("\nNEXT\n\n");
  //   {
  //     s21_decimal src1, src2, result, origin;
  //     src1.bits[0] = 0b11111111111111111111111111111111;
  //     src1.bits[1] = 0b11111111111111111111111111111111;
  //     src1.bits[2] = 0b11111111111111111111111111111111;
  //     src1.bits[3] = 0b10000000000000000000000000000000;

  //     src2.bits[0] = 0b00000000000000000000000000000100;
  //     src2.bits[1] = 0b00000000000000000000000000000000;
  //     src2.bits[2] = 0b00000000000000000000000000000000;
  //     src2.bits[3] = 0b0000000000000001000000000000000;

  //     int check = s21_div(src1, src2, &result);
  //     int check_origin = 0;
  //     PrintDecimalBinary(&src1);
  //     PrintDecimalDec(src1);
  //     PrintDecimalBinary(&src2);
  //     PrintDecimalDec(src2);
  //     PrintDecimalBinary(&result);
  //     PrintDecimalDec(result);
  //     PrintDecimalBinary(&origin);
  //     PrintDecimalDec(origin);
  //     printf("err = %d\n", check);
  //   }

  //   printf("\nNEXT\n\n");

  // 	{  // мелкие цифры для начала только для деления
  //     s21_decimal src1, src2, result, origin;
  //     // 1.12
  //     // 17.5
  //     src1.bits[0] = 0b00000000000000000000000001110000;
  //     src1.bits[1] = 0b00000000000000000000000000000000;
  //     src1.bits[2] = 0b00000000000000000000000000000000;
  //     src1.bits[3] = 0b00000000000000100000000000000000;

  //     src2.bits[0] = 0b00000000000000000000000010101111;
  //     src2.bits[1] = 0b00000000000000000000000000000000;
  //     src2.bits[2] = 0b00000000000000000000000000000000;
  //     src2.bits[3] = 0b00000000000000010000000000000000;
  //     // 0,064
  //     origin.bits[0] = 0b00000000000000000000000001000000;
  //     origin.bits[1] = 0b00000000000000000000000000000000;
  //     origin.bits[2] = 0b00000000000000000000000000000000;
  //     origin.bits[3] = 0b00000000000000110000000000000000;
  //     int check = s21_div(src1, src2, &result);
  //     int check_origin = 0;
  //     PrintDecimalBinary(&src1);
  //     PrintDecimalDec(src1);
  //     PrintDecimalBinary(&src2);
  //     PrintDecimalDec(src2);
  //     PrintDecimalBinary(&result);
  //     PrintDecimalDec(result);
  //     PrintDecimalBinary(&origin);
  //     PrintDecimalDec(origin);
  //     printf("err = %d\n", check);
  //   }
  //   printf("\nNEXT\n\n");
  //   {  // мелкие цифры для начала только для деления
  //     s21_decimal src1, src2, result, origin;
  //     // 1.13
  //     // 17.5
  //     src1.bits[0] = 0b00000000000000000000000001110001;
  //     src1.bits[1] = 0b00000000000000000000000000000000;
  //     src1.bits[2] = 0b00000000000000000000000000000000;
  //     src1.bits[3] = 0b00000000000000100000000000000000;

  //     src2.bits[0] = 0b00000000000000000000000010101111;
  //     src2.bits[1] = 0b00000000000000000000000000000000;
  //     src2.bits[2] = 0b00000000000000000000000000000000;
  //     src2.bits[3] = 0b00000000000000010000000000000000;
  //     // 0,064571428571429
  //     origin.bits[0] = 0b00110101000100000000100100100101;
  //     origin.bits[1] = 0b00000000000000000011101010111010;
  //     origin.bits[2] = 0b00000000000000000000000000000000;
  //     origin.bits[3] = 0b00000000000011110000000000000000;
  //     int check = s21_div(src1, src2, &result);
  //     int check_origin = 0;
  //     PrintDecimalBinary(&src1);
  //     PrintDecimalDec(src1);
  //     PrintDecimalBinary(&src2);
  //     PrintDecimalDec(src2);
  //     PrintDecimalBinary(&result);
  //     PrintDecimalDec(result);
  //     PrintDecimalBinary(&origin);
  //     PrintDecimalDec(origin);
  //     printf("err = %d\n", check);
  //   }
  // 	{
  //     s21_decimal src1, src2, result, origin;
  //     // 79 228 162 514 264 337 593 543 950 335
  //     // 79 228 162 514 264 337 593 543.950 335
  //     src1.bits[0] = 0b11111111111111111111111111111111;
  //     src1.bits[1] = 0b11111111111111111111111111111111;
  //     src1.bits[2] = 0b11111111111111111111111111111111;
  //     src1.bits[3] = 0b10000000000000000000000000000000;

  //     src2.bits[0] = 0b00000000000000000000000000000100;
  //     src2.bits[1] = 0b00000000000000000000000000000000;
  //     src2.bits[2] = 0b00000000000000000000000000000000;
  //     src2.bits[3] = 0b00000000000000000000000000000000;

  //     origin.bits[0] = 0b11111111111111111111111111111111;
  //     origin.bits[1] = 0b11111111111111111111111111111111;
  //     origin.bits[2] = 0b11111111111111111111111111111111;
  //     origin.bits[3] = 0b00000000000001100000000000000000;
  //     int check = s21_mul(src1, src2, &result);
  //     int check_origin = 0;
  // 	PrintDecimalBinary(&src1);
  // 	PrintDecimalDec(src1);
  // 	PrintDecimalBinary(&src2);
  // 	PrintDecimalDec(src2);
  // 	PrintDecimalBinary(&result);
  // 	PrintDecimalDec(result);
  // 	char str[20]  = "hell ";
  // 	printf("%s !%s!\n", str, str);
  //     printf("err = %d\n", check);
  //   }
  //   {
  //     s21_decimal src1, src2, result, origin;
  //     // 79 228 162 514 264 337 593 543 950 335
  //     // 79 228 162 514 264 337 593 543.950 335
  //     src1.bits[0] = 0b11111111111111111111111111111111;
  //     src1.bits[1] = 0b11111111111111111111111111111111;
  //     src1.bits[2] = 0b11111111111111111111111111111111;
  //     src1.bits[3] = 0b00000000000000000000000000000000;

  //     src2.bits[0] = 0b00000000000000000000000000000100;
  //     src2.bits[1] = 0b00000000000000000000000000000000;
  //     src2.bits[2] = 0b00000000000000000000000000000000;
  //     src2.bits[3] = 0b10000000000000000000000000000000;

  //     int check = s21_mul(src1, src2, &result);
  //     PrintDecimalBinary(&result);
  //     int check_origin = 0;

  //   }
  //   {
  //     s21_decimal src1, src2, result, origin;
  //     // 79 228 162 514 264 337 593 543 950 335
  //     // 79 228 162 514 264 337 593 543.950 335
  //     src1.bits[0] = 0b11111111101111111111111111111111;
  //     src1.bits[1] = 0b11111111111111111111111110111111;
  //     src1.bits[2] = 0b11111111111011111111111111111111;
  //     src1.bits[3] = 0b00000000000000001000000000000000;

  //     src2.bits[0] = 0b11111111101111111111111111111111;
  //     src2.bits[1] = 0b11111111111111111111111110111111;
  //     src2.bits[2] = 0b11111111111111111111111110111111;
  //     src2.bits[3] = 0b00000000000000001000000000000000;

  //     int check = s21_mul(src1, src2, &result);
  //     int check_origin = 1;

  //   }
  //   {
  //     s21_decimal src1, src2, result, origin;
  //     // 79 228 162 514 264 337 593 543 950 335
  //     // 79 228 162 514 264 337 593 543.950 335
  //     src1.bits[0] = 0b11111111111111111111111111111111;
  //     src1.bits[1] = 0b11111111111111111111111111111111;
  //     src1.bits[2] = 0b11111111111111111111111111111111;
  //     src1.bits[3] = 0b00000000000000000000000000000000;

  //     src2.bits[0] = 0b00000000000000000000000000000100;
  //     src2.bits[1] = 0b00000000000000000000000000000000;
  //     src2.bits[2] = 0b00000000000000000000000000000000;
  //     src2.bits[3] = 0b0000000000000001000000000000000;

  //     int check = s21_div(src1, src2, &result);
  //     int check_origin = 0;
  // 	PrintDecimalBinary(&src1);
  // 	PrintDecimalDec(src1);
  // 	PrintDecimalBinary(&src2);
  // 	PrintDecimalDec(src2);
  // 	PrintDecimalBinary(&result);
  // 	PrintDecimalDec(result);
  //     printf("err = %d\n", check);
  //   }
  //   {
  //     s21_decimal src1, src2, result, origin;
  //     src1.bits[0] = 0b11111111111111111111111111111111;
  //     src1.bits[1] = 0b11111111111111111111111111111111;
  //     src1.bits[2] = 0b11111111111111111111111111111111;
  //     src1.bits[3] = 0b10000000000000000000000000000000;

  //     src2.bits[0] = 0b00000000000000000000000000000100;
  //     src2.bits[1] = 0b00000000000000000000000000000000;
  //     src2.bits[2] = 0b00000000000000000000000000000000;
  //     src2.bits[3] = 0b0000000000000001000000000000000;

  //     int check = s21_div(src1, src2, &result);
  //     int check_origin = 0;
  // 	PrintDecimalBinary(&src1);
  // 	PrintDecimalDec(src1);
  // 	PrintDecimalBinary(&src2);
  // 	PrintDecimalDec(src2);
  // 	PrintDecimalBinary(&result);
  // 	PrintDecimalDec(result);
  //     printf("err = %d\n", check);
  //   }
  // {
  // 	s21_decimal src1, src2;
  // 	float num1 = 9.99;
  // 	float num2 = 9.99;
  // 	printf("%f\n", num1*num2);

  // 	printf("%.10f\n", num2);
  // 	float res_origin = -12140;
  // 	s21_from_float_to_decimal(num1, &src1);
  // 	s21_from_float_to_decimal(num2, &src2);
  // 	s21_decimal res_dec = {0};
  // 	float res_float = 0.0;
  // 	s21_mul(src1, src2, &res_dec);
  // 	s21_from_decimal_to_float(res_dec, &res_float);
  // 	PrintDecimalBinary(&src1);
  //     PrintDecimalDec(src1);
  //     PrintDecimalBinary(&src2);
  //     PrintDecimalDec(src2);
  // 	PrintDecimalBinary(&res_dec);
  //     PrintDecimalDec(res_dec);
  // 	printf("%f == %f\n", res_float, res_origin);
  // }
  // {
  // 	s21_decimal src1, src2;
  // 	float num1 = -0.94e03;
  // 	float num2 = -112.0234;
  // 	float res_origin = -1052.0234;
  // 	s21_from_float_to_decimal(num1, &src1);
  // 	s21_from_float_to_decimal(num2, &src2);
  // 	s21_decimal res_dec = {0};
  // 	float res_float = 0.0;
  // 	s21_add(src1, src2, &res_dec);
  // 	s21_from_decimal_to_float(res_dec, &res_float);
  // 	PrintDecimalBinary(&src1);
  //     PrintDecimalDec(src1);
  //     PrintDecimalBinary(&src2);
  //     PrintDecimalDec(src2);
  // 	PrintDecimalBinary(&res_dec);
  //     PrintDecimalDec(res_dec);
  // 	printf("%f == %f\n", res_float, res_origin);

  // }
  // {
  //  	s21_decimal src1, src2;
  // 	float num1 = -0.9403;
  // 	float num2 = -112.0234;
  // 	float res_origin = -112.9637;
  // 	s21_from_float_to_decimal(num1, &src1);
  // 	s21_from_float_to_decimal(num2, &src2);
  // 	s21_decimal res_dec = {0};
  // 	float res_float = 0.0;
  // 	s21_add(src1, src2, &res_dec);
  // 	s21_from_decimal_to_float(res_dec, &res_float);
  // 	PrintDecimalBinary(&src1);
  //     PrintDecimalDec(src1);
  //     PrintDecimalBinary(&src2);
  //     PrintDecimalDec(src2);
  // 	PrintDecimalBinary(&res_dec);
  //     PrintDecimalDec(res_dec);
  // 	printf("%f == %f\n", res_float, res_origin);
  // }
  // {
  // 	s21_decimal src1, src2;
  // 	float num1 = -0.9403;
  // 	float num2 = 0.000234;
  // 	float res_origin = -0.9400659;
  // 	s21_from_float_to_decimal(num1, &src1);
  // 	s21_from_float_to_decimal(num2, &src2);
  // 	s21_decimal res_dec = {0};
  // 	float res_float = 0.0;
  // 	s21_add(src1, src2, &res_dec);
  // 	s21_from_decimal_to_float(res_dec, &res_float);
  // 	PrintDecimalBinary(&src1);
  //     PrintDecimalDec(src1);
  //     PrintDecimalBinary(&src2);
  //     PrintDecimalDec(src2);
  // 	PrintDecimalBinary(&res_dec);
  //     PrintDecimalDec(res_dec);
  // 	printf("%f == %f\n", res_float, res_origin);
  // }
  // {
  // 	s21_decimal src1, src2;
  // 	float num1 = -940.3;
  // 	float num2 = 0.000234;
  // 	float res_origin = num1 + num2;//-940.299766;
  // 	s21_from_float_to_decimal(num1, &src1);
  // 	s21_from_float_to_decimal(num2, &src2);
  // 	s21_decimal res_dec = {0};
  // 	float res_float = 0.0;
  // 	s21_add(src1, src2, &res_dec);
  // 	s21_from_decimal_to_float(res_dec, &res_float);
  // 	PrintDecimalBinary(&src1);
  //     PrintDecimalDec(src1);
  //     PrintDecimalBinary(&src2);
  //     PrintDecimalDec(src2);
  // 	PrintDecimalBinary(&res_dec);
  //     PrintDecimalDec(res_dec);
  // 	printf("%f == %f\n", res_float, res_origin);
  // }
  // {

  // 	s21_decimal src1, src2;
  // 	int num1 = -1234;
  // 	float num2 = -1.234;
  // 	float res_origin = -1235.234;
  // 	s21_from_int_to_decimal(num1, &src1);
  // 	s21_from_float_to_decimal(num2, &src2);
  // 	s21_decimal res_dec = {0};
  // 	float res_float = 0.0;
  // 	s21_add(src1, src2, &res_dec);
  // 	s21_from_decimal_to_float(res_dec, &res_float);
  // 	//ck_assert_float_eq(res_float, res_origin);
  // 	PrintDecimalBinary(&src1);
  //     PrintDecimalDec(src1);
  //     PrintDecimalBinary(&src2);
  //     PrintDecimalDec(src2);
  // 	printf("%f == %f\n", res_float, res_origin);
  // 	// PrintDecimalBinary(&origin);
  // 	// PrintDecimalDec(origin);
  // 	// PrintDecimalBinary(&result);
  // 	// PrintDecimalDec(result);
  // }
  // {
  // 	s21_decimal src1, src2, origin, result;
  // 	int value_type_result, value_type_origin;
  // 	src1.bits[0] = 1;
  // 	src1.bits[1] = 0;
  // 	src1.bits[2] = 0;
  // 	src1.bits[3] = 0;

  // 	src2.bits[0] = 0b11111111111111111111111111111111;
  // 	src2.bits[1] = 0b11111111111111111111111111111111;
  // 	src2.bits[2] = 0b11111111111111111111111111111111;
  // 	src2.bits[3] = 0b00000000000000010000000000000000;

  // 	value_type_result = s21_add(src1, src2, &result);
  // 	value_type_origin = 0;
  // 	origin.bits[0] = 0b10011001100110011001100110011010;
  // 	origin.bits[1] = 0b10011001100110011001100110011001;
  // 	origin.bits[2] = 0b00011001100110011001100110011001;
  // 	origin.bits[3] = 0b00000000000000000000000000000000;
  // 	PrintDecimalBinary(&src1);
  //     PrintDecimalDec(src1);
  //     PrintDecimalBinary(&src2);
  //     PrintDecimalDec(src2);
  // 	PrintDecimalBinary(&origin);
  // 	PrintDecimalDec(origin);
  // 	PrintDecimalBinary(&result);
  // 	PrintDecimalDec(result);
  // }
  // { // на выход приходит ноль
  //     s21_decimal src1, src2, origin, result;
  //     int value_type_result, value_type_origin;
  //     // src1 = -79228162514264337593543950335;
  //     // src2 = 1;
  //     src1.bits[0] = 0b11111111111111111111111111111111;
  //     src1.bits[1] = 0b11111111111111111111111111111111;
  //     src1.bits[2] = 0b01111111111111111111111111111111;
  //     src1.bits[3] = 0b10000000000000010000000000000000;
  //     src2.bits[0] = 0b00000000000000000000000000000001;
  //     src2.bits[1] = 0b00000000000000000000000000000000;
  //     src2.bits[2] = 0b00000000000000000000000000000000;
  //     src2.bits[3] = 0b10000000000000010000000000000000;
  // 	PrintDecimalBinary(&src1);
  //     PrintDecimalDec(src1);
  //     PrintDecimalBinary(&src2);
  //     PrintDecimalDec(src2);
  //     value_type_result = s21_mul(src1, src2, &result);
  //     value_type_origin = 0;
  //     origin.bits[0] = 0b11111111111111111111111111111111;
  //     origin.bits[1] = 0b11111111111111111111111111111111;
  //     origin.bits[2] = 0b11111111111111111111111111111111;
  //     origin.bits[3] = 0b10000000000000000000000000000000;
  // 	PrintDecimalBinary(&origin);
  // 	PrintDecimalDec(origin);
  // 	PrintDecimalBinary(&result);
  // 	PrintDecimalDec(result);
  // }

  // { //не читаывается exp
  //     s21_decimal src1, src2, origin, result;
  //     int value_type_result, value_type_origin;
  //     // src1 = -79228162514264337593543950335;
  //     // src2 = 1;
  //     src1.bits[0] = 0b00000000000000000000000000000001;
  //     src1.bits[1] = 0b00000000000000000000000000000000;
  //     src1.bits[2] = 0b00000000000000000000000000000000;
  //     src1.bits[3] = 0b10000000000000010000000000000000;
  //     src2.bits[0] = 0b00000000000000000000000000000001;
  //     src2.bits[1] = 0b00000000000000000000000000000000;
  //     src2.bits[2] = 0b00000000000000000000000000000000;
  //     src2.bits[3] = 0b00000000000000010000000000000000;
  //     PrintDecimalBinary(&src1);
  //     PrintDecimalDec(src1);
  //     PrintDecimalBinary(&src2);
  //     PrintDecimalDec(src2);
  //     value_type_result = s21_mul(src1, src2, &result);
  //     value_type_origin = 0;
  //     origin.bits[0] = 0b11111111111111111111111111111111;
  //     origin.bits[1] = 0b11111111111111111111111111111111;
  //     origin.bits[2] = 0b11111111111111111111111111111111;
  //     origin.bits[3] = 0b10000000000000000000000000000000;
  // 	PrintDecimalBinary(&origin);
  // 	PrintDecimalDec(origin);
  // 	PrintDecimalBinary(&result);
  // 	PrintDecimalDec(result);
  //     printf("%d", value_type_result);
  // }

  // { //бесконечный цикл
  //     s21_decimal src1, src2, result, origin;
  //     // 79 228 162 514 264 337 593 543 950 335
  //     // 79 228 162 514 264 337 593 543.950 335
  //     src1.bits[0] = 0b00000000000000000000000000010100;
  //     src1.bits[1] = 0b00000000000000000000000000000000;
  //     src1.bits[2] = 0b00000000000000000000000000000000;
  //     src1.bits[3] = 0b00000000000000000000000000000000;

  //     src2.bits[0] = 0b00000000000000000000000000000100;
  //     src2.bits[1] = 0b00000000000000000000000000000000;
  //     src2.bits[2] = 0b00000000000000000000000000000000;
  //     src2.bits[3] = 0b00000000000000000000000000000000;

  // 	PrintDecimalBinary(&src1);
  // 	PrintDecimalDec(src1);
  // 	PrintDecimalBinary(&src2);
  // 	PrintDecimalDec(src2);

  //     origin.bits[0] = 0b11111111111111111111111111111111;
  //     origin.bits[1] = 0b11111111111111111111111111111111;
  //     origin.bits[2] = 0b11111111111111111111111111111111;
  //     origin.bits[3] = 0b00000000000001100000000000000000;
  // 	PrintDecimalBinary(&origin);
  // 	PrintDecimalDec(origin);
  //     int check = s21_div(src1, src2, &result);
  // 	PrintDecimalBinary(&result);
  // 	PrintDecimalDec(result);
  //     int check_origin = 0;
  // }

  // {
  // 	int tmp1 = 4294967295;
  // 	float tmp2 = pow(2, 31);
  // 	s21_decimal dec1 = { {tmp1, tmp1, tmp1, tmp2} };
  // 	s21_decimal dec2 = { {1, 0, 0, tmp2} };
  // 	PrintDecimalBinary(&dec1);
  // 	PrintDecimalDec(dec1);
  // 	PrintDecimalBinary(&dec2);
  // 	PrintDecimalDec(dec2);
  // 	s21_decimal res1;
  // 	int ret_s21 = s21_add(dec1, dec2, &res1);
  // 	PrintDecimalBinary(&res1);
  // 	PrintDecimalDec(res1);
  // 	printf("%d == %d\n", 2, ret_s21);
  // 	//ck_assert_int_eq(2, ret_s21);
  // }
  //{
  //	s21_decimal src1, src2, origin, result;
  //	int value_type_result, value_type_origin;
  //	src1.bits[0] = 1;
  //	src1.bits[1] = 0;
  //	src1.bits[2] = 0;
  //	src1.bits[3] = 0;

  //	src2.bits[0] = 0b11111111111111111111111111111111;
  //	src2.bits[1] = 0b11111111111111111111111111111111;
  //	src2.bits[2] = 0b11111111111111111111111111111111;
  //	src2.bits[3] = 0b00000000000000010000000000000000;
  //	PrintDecimalBinary(&src1);
  //	PrintDecimalDec(src1);
  //	PrintDecimalBinary(&src2);
  //	PrintDecimalDec(src2);
  //	value_type_result = s21_add(src1, src2, &result);
  //	value_type_origin = 0;
  //	origin.bits[0] = 0b10011001100110011001100110011010;
  //	origin.bits[1] = 0b10011001100110011001100110011001;
  //	origin.bits[2] = 0b00011001100110011001100110011001;
  //	origin.bits[3] = 0b00000000000000000000000000000000;
  //	PrintDecimalBinary(&origin);
  //	PrintDecimalDec(origin);
  //	PrintDecimalBinary(&result);
  //	PrintDecimalDec(result);
  //}
  //{
  //	s21_decimal src1, src2, result;
  //	src1.bits[0] = 0x0006BFD0;
  //	src1.bits[1] = 0x00000000;
  //	src1.bits[2] = 0x00000000;
  //	src1.bits[3] = 0x00000000;

  //	src2.bits[0] = 0x00000028;
  //	src2.bits[1] = 0x00000000;
  //	src2.bits[2] = 0x00000000;
  //	src2.bits[3] = 0x00000000;
  //	PrintDecimalBinary(&src1);
  //	PrintDecimalDec(src1);
  //	PrintDecimalBinary(&src2);
  //	PrintDecimalDec(src2);
  //	int check = s21_div(src1, src2, &result);
  //	int check_origin = 0;
  //	PrintDecimalBinary(&result);
  //	PrintDecimalDec(result);
  //}
  //{
  //	s21_decimal src1, src2, result, origin;
  //	// 38/7 = 5.428 571 428 571 428 571 428 571 428 6
  //	src1.bits[0] = 38;
  //	src1.bits[1] = 0;
  //	src1.bits[2] = 0;
  //	src1.bits[3] = 0;

  //	src2.bits[0] = 7;
  //	src2.bits[1] = 0;
  //	src2.bits[2] = 0;
  //	src2.bits[3] = 0;
  //	PrintDecimalBinary(&src1);
  //	PrintDecimalDec(src1);
  //	PrintDecimalBinary(&src2);
  //	PrintDecimalDec(src2);
  //	origin.bits[0] = 0b00001101101101101101101101101110;
  //	origin.bits[1] = 0b00101100110010001110100001011000;
  //	origin.bits[2] = 0b10101111011010000001011100100100;
  //	origin.bits[3] = 0b00000000000111000000000000000000;
  //	PrintDecimalBinary(&origin);
  //	PrintDecimalDec(origin);
  //	int check = s21_div(src1, src2, &result);
  //	int check_origin = 0;
  //	PrintDecimalBinary(&result);
  //	PrintDecimalDec(result);
  //}
  //{
  //	s21_decimal src1, src2, result, origin;
  //	// 8/5 = 1.6
  //	src1.bits[0] = 8;
  //	src1.bits[1] = 0;
  //	src1.bits[2] = 0;
  //	src1.bits[3] = 0;

  //	src2.bits[0] = 5;
  //	src2.bits[1] = 0;
  //	src2.bits[2] = 0;
  //	src2.bits[3] = 0;
  //	PrintDecimalBinary(&src1);
  //	PrintDecimalDec(src1);
  //	PrintDecimalBinary(&src2);
  //	PrintDecimalDec(src2);
  //	origin.bits[0] = 16;
  //	origin.bits[1] = 0;
  //	origin.bits[2] = 0;
  //	origin.bits[3] = 0b00000000000000010000000000000000;
  //	PrintDecimalBinary(&origin);
  //	PrintDecimalDec(origin);
  //	int check = s21_div(src1, src2, &result);
  //	int check_origin = 0;
  //	PrintDecimalBinary(&result);
  //	PrintDecimalDec(result);
  //}
  //{
  //	s21_decimal src1, src2, result, origin;
  //	// 79 228 162 514 264 337 593 543 950 335
  //	// 79 228 162 514 264 337 593 543.950 335
  //	src1.bits[0] = 0b11111111111111111111111111111111;
  //	src1.bits[1] = 0b11111111111111111111111111111111;
  //	src1.bits[2] = 0b11111111111111111111111111111111;
  //	src1.bits[3] = 0;

  //	src2.bits[0] = 1000000;
  //	src2.bits[1] = 0;
  //	src2.bits[2] = 0;
  //	src2.bits[3] = 0;
  //	PrintDecimalBinary(&src1);
  //	PrintDecimalDec(src1);
  //	PrintDecimalBinary(&src2);
  //	PrintDecimalDec(src2);
  //	origin.bits[0] = 0b11111111111111111111111111111111;
  //	origin.bits[1] = 0b11111111111111111111111111111111;
  //	origin.bits[2] = 0b11111111111111111111111111111111;
  //	origin.bits[3] = 0b00000000000001100000000000000000;
  //	PrintDecimalBinary(&origin);
  //	PrintDecimalDec(origin);
  //	int check = s21_div(src1, src2, &result);
  //	PrintDecimalBinary(&result);
  //	PrintDecimalDec(result);
  //	int check_origin = 0;
  //}
  //{
  //	s21_decimal src1, src2, result, origin;
  //	src1.bits[0] = 30;
  //	src1.bits[1] = 0;
  //	src1.bits[2] = 0;
  //	src1.bits[3] = 0;

  //	src2.bits[0] = 100;
  //	src2.bits[1] = 0;
  //	src2.bits[2] = 0;
  //	src2.bits[3] = 0;
  //	PrintDecimalBinary(&src1);
  //	PrintDecimalDec(src1);
  //	PrintDecimalBinary(&src2);
  //	PrintDecimalDec(src2);
  //	origin.bits[0] = 3;
  //	origin.bits[1] = 0;
  //	origin.bits[2] = 0;
  //	origin.bits[3] = 0b00000000000000010000000000000000;
  //	PrintDecimalBinary(&origin);
  //	PrintDecimalDec(origin);
  //	int check = s21_div(src1, src2, &result);
  //	PrintDecimalBinary(&result);
  //	PrintDecimalDec(result);
  //	int check_origin = 0;
  //}
  //{
  //	s21_decimal src1, src2, result, origin;
  //	src1.bits[0] = 300000;
  //	src1.bits[1] = 0;
  //	src1.bits[2] = 0;
  //	src1.bits[3] = 0;

  //	src2.bits[0] = 30;
  //	src2.bits[1] = 0;
  //	src2.bits[2] = 0;
  //	src2.bits[3] = 0;
  //	PrintDecimalBinary(&src1);
  //	PrintDecimalDec(src1);
  //	PrintDecimalBinary(&src2);
  //	PrintDecimalDec(src2);
  //	origin.bits[0] = 10000;
  //	origin.bits[1] = 0;
  //	origin.bits[2] = 0;
  //	origin.bits[3] = 0;
  //	PrintDecimalBinary(&origin);
  //	PrintDecimalDec(origin);
  //	int check = s21_div(src1, src2, &result);
  //	PrintDecimalBinary(&result);
  //	PrintDecimalDec(result);
  //	int check_origin = 0;
  //}
  //{
  //	s21_decimal src1, src2, result, origin;
  //	src1.bits[0] = 0b11111111111111111111111111111111;
  //	src1.bits[1] = 0b11111111111111111111111111111111;
  //	src1.bits[2] = 0b11111111111111111111111111111111;
  //	src1.bits[3] = 0b10000000000000000000000000000000;

  //	src2.bits[0] = 0b11111111111111111111111111111111;
  //	src2.bits[1] = 0b11111111111111111111111111111111;
  //	src2.bits[2] = 0b11111111111111111111111111111111;
  //	src2.bits[3] = 0b10000000000000000000000000000000;
  //	PrintDecimalBinary(&src1);
  //	PrintDecimalDec(src1);
  //	PrintDecimalBinary(&src2);
  //	PrintDecimalDec(src2);
  //	origin.bits[0] = 1;
  //	origin.bits[1] = 0;
  //	origin.bits[2] = 0;
  //	origin.bits[3] = 0;
  //	PrintDecimalBinary(&origin);
  //	PrintDecimalDec(origin);
  //	int check = s21_div(src1, src2, &result);
  //	PrintDecimalBinary(&result);
  //	PrintDecimalDec(result);
  //	int check_origin = 0;
  //}
  //{
  //	s21_decimal src1, src2, result, origin;
  //	src1.bits[0] = 0b11111111111111111111111111111111;
  //	src1.bits[1] = 0b11111111111111111111111111111111;
  //	src1.bits[2] = 0b11111111111111111111111111111111;
  //	src1.bits[3] = 0b00000000000000000000000000000000;

  //	src2.bits[0] = 0b11111111111111111111111111111111;
  //	src2.bits[1] = 0b11111111111111111111111111111111;
  //	src2.bits[2] = 0b11111111111111111111111111111111;
  //	src2.bits[3] = 0b10000000000000000000000000000000;
  //	PrintDecimalBinary(&src1);
  //	PrintDecimalDec(src1);
  //	PrintDecimalBinary(&src2);
  //	PrintDecimalDec(src2);
  //	origin.bits[0] = 1;
  //	origin.bits[1] = 0;
  //	origin.bits[2] = 0;
  //	origin.bits[3] = 0b10000000000000000000000000000000;
  //	PrintDecimalBinary(&origin);
  //	PrintDecimalDec(origin);
  //	int check = s21_div(src1, src2, &result);
  //	PrintDecimalBinary(&result);
  //	PrintDecimalDec(result);
  //	int check_origin = 0;
  //}
  //{
  //	s21_decimal src1, src2, result, origin;
  //	src1.bits[0] = 0b11111111111111111111111111111111;
  //	src1.bits[1] = 0b11111111111111111111111111111111;
  //	src1.bits[2] = 0b11111111111111111111111111111111;
  //	src1.bits[3] = 0b10000000000000000000000000000000;

  //	src2.bits[0] = 0b11111111111111111111111111111111;
  //	src2.bits[1] = 0b11111111111111111111111111111111;
  //	src2.bits[2] = 0b11111111111111111111111111111111;
  //	src2.bits[3] = 0b00000000000000000000000000000000;
  //	PrintDecimalBinary(&src1);
  //	PrintDecimalDec(src1);
  //	PrintDecimalBinary(&src2);
  //	PrintDecimalDec(src2);
  //	origin.bits[0] = 1;
  //	origin.bits[1] = 0;
  //	origin.bits[2] = 0;
  //	origin.bits[3] = 0b10000000000000000000000000000000;
  //	PrintDecimalBinary(&origin);
  //	PrintDecimalDec(origin);
  //	int check = s21_div(src1, src2, &result);
  //	PrintDecimalBinary(&result);
  //	PrintDecimalDec(result);
  //	int check_origin = 0;
  //}
  //{
  //	s21_decimal src1, src2, result, origin;
  //	src1.bits[0] = 0b11111111111111111111111111111111;
  //	src1.bits[1] = 0b11111111111111111111111111111111;
  //	src1.bits[2] = 0b11111111111111111111111111111111;
  //	src1.bits[3] = 0b00000000000000000000000000000000;

  //	src2.bits[0] = 0b11111111111111111111111111111111;
  //	src2.bits[1] = 0b11111111111111111111111111111111;
  //	src2.bits[2] = 0b11111111111111111111111111111111;
  //	src2.bits[3] = 0b00000000000000000000000000000000;
  //	PrintDecimalBinary(&src1);
  //	PrintDecimalDec(src1);
  //	PrintDecimalBinary(&src2);
  //	PrintDecimalDec(src2);
  //	origin.bits[0] = 1;
  //	origin.bits[1] = 0;
  //	origin.bits[2] = 0;
  //	origin.bits[3] = 0;
  //	PrintDecimalBinary(&origin);
  //	PrintDecimalDec(origin);
  //	int check = s21_div(src1, src2, &result);
  //	PrintDecimalBinary(&result);
  //	PrintDecimalDec(result);
  //	int check_origin = 0;
  //}
  //{
  //	s21_decimal src1, src2, result, origin;
  //	// 0
  //	// 0.015
  //	// 0
  //	src1.bits[0] = 0b00000000000000000000000000000000;
  //	src1.bits[1] = 0b00000000000000000000000000000000;
  //	src1.bits[2] = 0b00000000000000000000000000000000;
  //	src1.bits[3] = 0b00000000000000000000000000000000;

  //	src2.bits[0] = 0b00000000000000000000000000001111;
  //	src2.bits[1] = 0b00000000000000000000000000000000;
  //	src2.bits[2] = 0b00000000000000000000000000000000;
  //	src2.bits[3] = 0b00000000000000110000000000000000;
  //	PrintDecimalBinary(&src1);
  //	PrintDecimalDec(src1);
  //	PrintDecimalBinary(&src2);
  //	PrintDecimalDec(src2);
  //	origin.bits[0] = 0b00000000000000000000000000000000;
  //	origin.bits[1] = 0b00000000000000000000000000000000;
  //	origin.bits[2] = 0b00000000000000000000000000000000;
  //	origin.bits[3] = 0b00000000000000000000000000000000;
  //	PrintDecimalBinary(&origin);
  //	PrintDecimalDec(origin);
  //	int check = s21_div(src1, src2, &result);
  //	PrintDecimalBinary(&result);
  //	PrintDecimalDec(result);
  //	int check_origin = 0;
  //}
  //{
  //	s21_decimal src1, src2, result, origin;
  //	// -30064771176
  //	// 2
  //	// 10021590392
  //	src1.bits[0] = 0b00000000000000000000000001101000;
  //	src1.bits[1] = 0b00000000000000000000000000000111;
  //	src1.bits[2] = 0b00000000000000000000000000000000;
  //	src1.bits[3] = 0b10000000000000000000000000000000;
  //	src2.bits[0] = 0b00000000000000000000000000000010;
  //	src2.bits[1] = 0b00000000000000000000000000000000;
  //	src2.bits[2] = 0b00000000000000000000000000000000;
  //	src2.bits[3] = 0b00000000000000000000000000000000;
  //	PrintDecimalBinary(&src1);
  //	PrintDecimalDec(src1);
  //	PrintDecimalBinary(&src2);
  //	PrintDecimalDec(src2);
  //	origin.bits[0] = 0b10000000000000000000000000110100;
  //	origin.bits[1] = 0b00000000000000000000000000000011;
  //	origin.bits[2] = 0b00000000000000000000000000000000;
  //	origin.bits[3] = 0b10000000000000000000000000000000;
  //	PrintDecimalBinary(&origin);
  //	PrintDecimalDec(origin);
  //	int check = s21_div(src1, src2, &result);
  //	PrintDecimalBinary(&result);
  //	PrintDecimalDec(result);
  //	int check_origin = 0;
  //}

  //{
  //	s21_decimal src1, src2, result;
  //	int a = 32768;
  //	int b = 2;
  //	int res_our_dec = 0;
  //	s21_from_int_to_decimal(a, &src1);
  //	s21_from_int_to_decimal(b, &src2);
  //	int res_origin = 16384;
  //	int check = s21_div(src1, src2, &result);
  //	PrintDecimalBinary(&result);
  //	PrintDecimalDec(result);
  //	int check_origin = 0;
  //	s21_from_decimal_to_int(result, &res_our_dec);
  //}
  //{
  //	s21_decimal src1, src2, result;
  //	int a = 32768;
  //	int b = -2;
  //	int res_our_dec = 0;
  //	s21_from_int_to_decimal(a, &src1);
  //	s21_from_int_to_decimal(b, &src2);
  //	int res_origin = -16384;
  //	int check = s21_div(src1, src2, &result);
  //	PrintDecimalBinary(&result);
  //	PrintDecimalDec(result);
  //	int check_origin = 0;
  //	s21_from_decimal_to_int(result, &res_our_dec);
  //}
  //{
  //	s21_decimal src1, src2, result, origin;
  //	// 30064771176
  //	// 3
  //	// 10021590392
  //	src1.bits[0] = 0b00000000000000000000000001101000;
  //	src1.bits[1] = 0b00000000000000000000000000000111;
  //	src1.bits[2] = 0b00000000000000000000000000000000;
  //	src1.bits[3] = 0b00000000000000000000000000000000;

  //	src2.bits[0] = 0b00000000000000000000000000000011;
  //	src2.bits[1] = 0b00000000000000000000000000000000;
  //	src2.bits[2] = 0b00000000000000000000000000000000;
  //	src2.bits[3] = 0b00000000000000000000000000000000;
  //	//PrintDecimalBinary(&src1);
  //	//PrintDecimalDec(src1);
  //	//PrintDecimalBinary(&src2);
  //	//PrintDecimalDec(src2);

  //	origin.bits[0] = 0b01010101010101010101010101111000;
  //	origin.bits[1] = 0b00000000000000000000000000000010;
  //	origin.bits[2] = 0b00000000000000000000000000000000;
  //	origin.bits[3] = 0b00000000000000000000000000000000;
  //	PrintDecimalBinary(&origin);
  //	PrintDecimalDec(origin);
  //	int check = s21_div(src1, src2, &result);
  //	PrintDecimalBinary(&result);
  //	PrintDecimalDec(result);
  //	int check_origin = 0;
  //}

  //{
  //	s21_decimal src;
  //	int result = 0;
  //	float number = 0.0;
  //	long int c = 2147745792;
  //	src.bits[0] = 23450987;
  //	src.bits[1] = 0;
  //	src.bits[2] = 0;
  //	src.bits[3] = c;
  //	PrintDecimalBinary(&src);
  //	PrintDecimalDec(src);
  //	float origin = -2345.0987;
  //	result = s21_from_decimal_to_float(src, &number);
  //	printf("%.10f  %.10f\n", number, origin);
  //}
  //{
  //	s21_decimal src1, src2, result, origin;
  //	// 30064771176
  //	// 3
  //	// 10021590392
  //	src1.bits[0] = 0b00000000000000000000000001101000;
  //	src1.bits[1] = 0b00000000000000000000000000000111;
  //	src1.bits[2] = 0b00000000000000000000000000000000;
  //	src1.bits[3] = 0b00000000000000000000000000000000;

  //	src2.bits[0] = 0b00000000000000000000000000000011;
  //	src2.bits[1] = 0b00000000000000000000000000000000;
  //	src2.bits[2] = 0b00000000000000000000000000000000;
  //	src2.bits[3] = 0b00000000000000000000000000000000;

  //	PrintDecimalBinary(&src1);
  //	PrintDecimalDec(src1);
  //	PrintDecimalBinary(&src2);
  //	PrintDecimalDec(src2);

  //	origin.bits[0] = 0b01010101010101010101010101111000;
  //	origin.bits[1] = 0b00000000000000000000000000000010;
  //	origin.bits[2] = 0b00000000000000000000000000000000;
  //	origin.bits[3] = 0b00000000000000000000000000000000;
  //	int check = s21_div(src1, src2, &result);
  //	int check_origin = 0;
  //			PrintDecimalBinary(&result);
  //	PrintDecimalDec(result);
  //			PrintDecimalBinary(&origin);
  //	PrintDecimalDec(origin);
  //}
  // {
  // 	int tmp1 = 4294967295;
  // 	float tmp2 = pow(2, 31);
  // 	s21_decimal dec1 = {{tmp1, tmp1, tmp1, tmp2}};
  // 	s21_decimal dec2 = {{1, 0, 0, tmp2}};
  // 	PrintDecimalBinary(&dec1);
  // 	PrintDecimalDec(dec1);
  // 	PrintDecimalBinary(&dec2);
  // 	PrintDecimalDec(dec2);
  // 	s21_decimal res1;
  // 	int ret_s21 = s21_add(dec1, dec2, &res1);

  // 	PrintDecimalBinary(&res1);
  // 	PrintDecimalDec(res1);
  // 	printf("ret: %d\n", ret_s21);
  // 	//ck_assert_int_eq(2, ret_s21);
  // }
  // {
  // 	s21_decimal src1, src2, origin, result;
  // 	int value_type_result, value_type_origin;
  // 	// src1 = 18446744073709551615.0;
  // 	// src2 = 3556877454;
  // 	src1.bits[0] = 0b11111111111111111111111111110110;
  // 	src1.bits[1] = 0b11111111111111111111111111111111;
  // 	src1.bits[2] = 0b00000000000000000000000000001001;
  // 	src1.bits[3] = 0b00000000000000010000000000000000;
  // 	src2.bits[0] = 0b11010100000000011010010010001110;
  // 	src2.bits[1] = 0b00000000000000000000000000000000;
  // 	src2.bits[2] = 0b00000000000000000000000000000000;
  // 	src2.bits[3] = 0b00000000000000000000000000000000;
  // 	PrintDecimalBinary(&src1);
  // 	PrintDecimalDec(src1);
  // 	PrintDecimalBinary(&src2);
  // 	PrintDecimalDec(src2);
  // 	value_type_result = s21_sub(src1, src2, &result);
  // 	value_type_origin = 0;
  // 	PrintDecimalBinary(&result);
  //  	PrintDecimalDec(result);
  // 	origin.bits[0] = 0b10110111111011111001001001101010;
  // 	origin.bits[1] = 0b11111111111111111111111111110111;
  // 	origin.bits[2] = 0b00000000000000000000000000001001;
  // 	origin.bits[3] = 0b00000000000000010000000000000000;
  // 	PrintDecimalBinary(&origin);
  // 	PrintDecimalDec(origin);
  // 	// ck_assert_int_eq(origin.bits[3], result.bits[3]);
  // 	// ck_assert_int_eq(origin.bits[2], result.bits[2]);
  // 	// ck_assert_int_eq(origin.bits[1], result.bits[1]);
  // 	// ck_assert_int_eq(origin.bits[0], result.bits[0]);
  // 	// ck_assert_int_eq(value_type_result, value_type_origin);
  // }
  // {
  // 	s21_decimal src1, src2, origin, result;
  // 	int value_type_result, value_type_origin;
  // 	src1.bits[0] = 1;
  // 	src1.bits[1] = 0;
  // 	src1.bits[2] = 0;
  // 	src1.bits[3] = 0;

  // 	src2.bits[0] = 0b11111111111111111111111111111111;
  // 	src2.bits[1] = 0b11111111111111111111111111111111;
  // 	src2.bits[2] = 0b11111111111111111111111111111111;
  // 	src2.bits[3] = 0b00000000000000010000000000000000;
  // 	PrintDecimalBinary(&src1);
  // 	PrintDecimalDec(src1);
  // 	PrintDecimalBinary(&src2);
  // 	PrintDecimalDec(src2);
  // 	value_type_result = s21_add(src1, src2, &result);
  // 	value_type_origin = 0;
  // 	PrintDecimalBinary(&result);
  // 	PrintDecimalDec(result);
  // 	origin.bits[0] = 0b10011001100110011001100110011010;
  // 	origin.bits[1] = 0b10011001100110011001100110011001;
  // 	origin.bits[2] = 0b00011001100110011001100110011001;
  // 	origin.bits[3] = 0b00000000000000000000000000000000;
  // 	PrintDecimalBinary(&origin);
  //  	PrintDecimalDec(origin);
  // }
  // {
  // 	s21_decimal src1, src2, origin, result;
  // 	int value_type_result, value_type_origin;
  // 	src1.bits[0] = 0b11111111111111111111111111111111;
  // 	src1.bits[1] = 0b11111111111111111111111111111111;
  // 	src1.bits[2] = 0b11111111111111111111111111111111;
  // 	src1.bits[3] = 0b00000000000000000000000000000000;

  // 	src2.bits[0] = 0b11111111111111111111111111111111;
  // 	src2.bits[1] = 0b11111111111111111111111111111111;
  // 	src2.bits[2] = 0b11111111111111111111111111111111;
  // 	src2.bits[3] = 0b00000000000000000000000000000000;
  // 			PrintDecimalBinary(&src1);
  // 	PrintDecimalDec(src1);
  // 	PrintDecimalBinary(&src2);
  // 	PrintDecimalDec(src2);
  // 	value_type_result = s21_add(src1, src2, &result);
  // 	value_type_origin = 1;
  // 			PrintDecimalBinary(&result);
  // 	PrintDecimalDec(result);
  // 	origin.bits[0] = 0b00000000000000000000000000000000;
  // 	origin.bits[1] = 0b00000000000000000000000000000000;
  // 	origin.bits[2] = 0b00000000000000000000000000000000;
  // 	origin.bits[3] = 0b00000000000000000000000000000000;
  // 		 	PrintDecimalBinary(&origin);
  //  	PrintDecimalDec(origin);
  // }

  // {
  // 	s21_decimal src1, src2, origin, result;
  // 	int value_type_result, value_type_origin;
  // 	// src1 = 20;
  // 	// src2 = -2;
  // 	src1.bits[0] = 0b00000000000000000000000000010100;
  // 	src1.bits[1] = 0b00000000000000000000000000000000;
  // 	src1.bits[2] = 0b00000000000000000000000000000000;
  // 	src1.bits[3] = 0b00000000000000000000000000000000;

  // 	src2.bits[0] = 0b00000000000000000000000000010100;
  // 	src2.bits[1] = 0b00000000000000000000000000000000;
  // 	src2.bits[2] = 0b00000000000000000000000000000000;
  // 	src2.bits[3] = 0b10000000000000010000000000000000;
  // 	PrintDecimalBinary(&src1);
  // 	PrintDecimalDec(src1);
  // 	PrintDecimalBinary(&src2);
  // 	PrintDecimalDec(src2);
  // 	value_type_result = s21_add(src1, src2, &result);
  // 	value_type_origin = 0;
  // 	PrintDecimalBinary(&result);
  // 	PrintDecimalDec(result);
  // 	origin.bits[0] = 0b00000000000000000000000010110100;
  // 	origin.bits[1] = 0b00000000000000000000000000000000;
  // 	origin.bits[2] = 0b00000000000000000000000000000000;
  // 	origin.bits[3] = 0b00000000000000010000000000000000;
  //  	PrintDecimalBinary(&origin);
  //  	PrintDecimalDec(origin);
  // }
  // {
  // 	s21_decimal src1, src2, origin, result;
  // 	int value_type_result, value_type_origin;
  // 	// src1 = -545454512454545.35265454545645;
  // 	// src2 = 54564654;
  // 	src1.bits[0] = 0b10000010111000100101101011101101;
  // 	src1.bits[1] = 0b11111001111010000010010110101101;
  // 	src1.bits[2] = 0b10110000001111101111000010010100;
  // 	src1.bits[3] = 0b10000000000011100000000000000000;
  // 	src2.bits[0] = 0b00000011010000001001011100101110;
  // 	src2.bits[1] = 0b00000000000000000000000000000000;
  // 	src2.bits[2] = 0b00000000000000000000000000000000;
  // 	src2.bits[3] = 0b00000000000000000000000000000000;
  // 	// PrintDecimalBinary(&src1);
  // 	// PrintDecimalDec(src1);
  // 	// PrintDecimalBinary(&src2);
  // 	// PrintDecimalDec(src2);
  // 	value_type_result = s21_add(src1, src2, &result);
  // 	value_type_origin = 0;
  // 	PrintDecimalBinary(&result);
  // 	PrintDecimalDec(result);
  // 	origin.bits[0] = 0b01110001001010101101101011101101;
  // 	origin.bits[1] = 0b00101110001111001110000111111000;
  // 	origin.bits[2] = 0b10110000001111101110111101101101;
  // 	origin.bits[3] = 0b10000000000011100000000000000000;
  // 	PrintDecimalBinary(&origin);
  // 	PrintDecimalDec(origin);
  // }
  // {
  // 	s21_decimal src1, src2, origin, result;
  // 	int value_type_result, value_type_origin;
  // 	src1.bits[0] = 0b11111111111111111111111111110110;
  // 	src1.bits[1] = 0b11111111111111111111111111111111;
  // 	src1.bits[2] = 0b00000000000000000000000000001001;
  // 	src1.bits[3] = 0b00000000000000010000000000000000;
  // 	src2.bits[0] = 0b00111001100010111010010101100010;
  // 	src2.bits[1] = 0b00000000000000000000000000000000;
  // 	src2.bits[2] = 0b00000000000000000000000000000000;
  // 	src2.bits[3] = 0b00000000000000000000000000000000;
  // 	PrintDecimalBinary(&src1);
  // 	PrintDecimalDec(src1);
  // 	PrintDecimalBinary(&src2);
  // 	PrintDecimalDec(src2);
  // 	value_type_result = s21_add(src1, src2, &result);
  // 	value_type_origin = 0;
  // 	PrintDecimalBinary(&result);
  // 	PrintDecimalDec(result);
  // 	origin.bits[0] = 0b00111111011101000111010111001010;
  // 	origin.bits[1] = 0b00000000000000000000000000000010;
  // 	origin.bits[2] = 0b00000000000000000000000000001010;
  // 	origin.bits[3] = 0b00000000000000010000000000000000;

  // 	PrintDecimalBinary(&origin);
  // 	PrintDecimalDec(origin);
  // }

  //{
  //	s21_decimal src;
  //	int result = 0;
  //	float number = 0.0;
  //	long int c = 2147680256;
  //	src.bits[0] = 18122;
  //	src.bits[1] = 0;
  //	src.bits[2] = 0;
  //	src.bits[3] = c;

  //	PrintDecimalBinary(&src);
  //	PrintDecimalDec(src);
  //	result = s21_from_decimal_to_float(src, &number);

  //	printf("result: %lf\n", number);
  //}
  //{
  //	s21_decimal src;
  //	int result = 0;
  //	float number = 0.0;
  //	long int c = 2147680256;
  //	src.bits[0] = 18122;
  //	src.bits[1] = 0;
  //	src.bits[2] = 0;
  //	src.bits[3] = c;
  //	PrintDecimalBinary(&src);
  //	PrintDecimalDec(src);
  //	result = s21_from_decimal_to_float(src, &number);

  //	printf("result: %lf\n", number);
  //}

  // {
  // 	s21_decimal src;
  // 	int result = 0;
  // 	float number = 0.0;
  // 	long int c = 2147745792;
  // 	src.bits[0] = 23450987;
  // 	src.bits[1] = 0;
  // 	src.bits[2] = 0;
  // 	src.bits[3] = c;
  // 	PrintDecimalBinary(&src);
  // 	PrintDecimalDec(src);
  // 	result = s21_from_decimal_to_float(src, &number);

  // 	printf("result: %lf\n", number);
  // }
  //{
  //	s21_decimal src;
  //	src.bits[0] = 0b00000001011100111100000111000111;
  //	src.bits[1] = 0b00000000000000000000000000000000;
  //	src.bits[2] = 0b00000000000000000000000000000000;
  //	src.bits[3] = 0b10000000000001110000000000000000;
  //	int result = 0;
  //	int origin = -2;
  //	int origin_error = 0;
  //	int my_error = s21_from_decimal_to_int(src, &result);
  //	PrintDecimalBinary(&src);
  //	PrintDecimalDec(src);
  //	printf("result: %d", result);
  //}

  //{
  //	s21_decimal src1, src2;
  //	int origin;
  //	// src1 = -87654323456.98765456789876530;
  //	// src2 = -87654323456.98765456789876530;
  //	src1.bits[0] = 0b10110010000010100010111100110010;
  //	src1.bits[1] = 0b10011001010111000101110110000000;
  //	src1.bits[2] = 0b00011100010100101001100001111111;
  //	src1.bits[3] = 0b10000000000100010000000000000000;
  //	src2.bits[0] = 0b10110010000010100010111100110010;
  //	src2.bits[1] = 0b10011001010111000101110110000000;
  //	src2.bits[2] = 0b00011100010100101001100001111111;
  //	src2.bits[3] = 0b10000000000100010000000000000000;
  //		//PrintDecimalBinary(&src1);
  //		//PrintDecimalDec(src1);
  //		//PrintDecimalBinary(&src2);
  //		//PrintDecimalDec(src2);
  //	int result = s21_is_less(src1, src2);
  //	origin = 0;
  //	printf("%d %d\n", origin, result);
  //	//ck_assert_int_eq(origin, result);
  //}
  //{
  //	s21_decimal src1, src2;
  //	int origin;
  //	// src1 = 2.22221200000001000;
  //	// src2 = 2.222212;
  //	src1.bits[0] = 0b00000111100011111010001111101000;
  //	src1.bits[1] = 0b00000011000101010111110100000001;
  //	src1.bits[2] = 0b00000000000000000000000000000000;
  //	src1.bits[3] = 0b00000000000100010000000000000000;
  //	src2.bits[0] = 0b00000000001000011110100010000100;
  //	src2.bits[1] = 0b00000000000000000000000000000000;
  //	src2.bits[2] = 0b00000000000000000000000000000000;
  //	src2.bits[3] = 0b00000000000001100000000000000000;
  //	PrintDecimalBinary(&src1);
  //	PrintDecimalDec(src1);
  //	PrintDecimalBinary(&src2);
  //	PrintDecimalDec(src2);
  //	int result = s21_is_less(src1, src2);
  //	origin = 0;
  //	printf("%d\n", result);
  //	//ck_assert_int_eq(origin, result);
  //}
  {
    // s21_decimal src, origin, result;
    //// src = 5.0;
    // src.bits[0] = 0b00000000000000000000000000110010;
    // src.bits[1] = 0b00000000000000000000000000000000;
    // src.bits[2] = 0b00000000000000000000000000000000;
    // src.bits[3] = 0b00000000000000010000000000000000;
    // PrintDecimalDec(src);
    // int check = s21_floor(src, &result);
    // PrintDecimalDec(result);
    // printf("check: %d\n", check);
    // int check_origin = 0;
    //// origin = 5;
    // origin.bits[0] = 0b00000000000000000000000000000101;
    // origin.bits[1] = 0b00000000000000000000000000000000;
    // origin.bits[2] = 0b00000000000000000000000000000000;
    // origin.bits[3] = 0b00000000000000000000000000000000;

    // ck_assert_int_eq(origin.bits[3], result.bits[3]);
    // ck_assert_int_eq(origin.bits[2], result.bits[2]);
    // ck_assert_int_eq(origin.bits[1], result.bits[1]);
    // ck_assert_int_eq(origin.bits[0], result.bits[0]);
    // ck_assert_int_eq(check, check_origin);
  }

  //{
  //	s21_decimal src1, src2;
  //	int origin;
  //	// src1 = 2.222212;
  //	// src2 = 2.222212;
  //	src1.bits[0] = 0b00000000001000011110100010000100;
  //	src1.bits[1] = 0b00000000000000000000000000000000;
  //	src1.bits[2] = 0b00000000000000000000000000000000;
  //	src1.bits[3] = 0b00000000000001100000000000000000;
  //	src2.bits[0] = 0b00000000001000011110100010000100;
  //	src2.bits[1] = 0b00000000000000000000000000000000;
  //	src2.bits[2] = 0b00000000000000000000000000000000;
  //	src2.bits[3] = 0b00000000000001100000000000000000;
  //	int result = s21_is_less(src1, src2);
  //	origin = 0;
  //	printf("%d = %d\n", result, origin);
  //}
  //
  //{
  //	s21_decimal src1, src2;
  //	int origin;
  //	// src1 = 2.22221200000001000;
  //	// src2 = 2.222212;
  //	src1.bits[0] = 0b00000111100011111010001111101000;
  //	src1.bits[1] = 0b00000011000101010111110100000001;
  //	src1.bits[2] = 0b00000000000000000000000000000000;
  //	src1.bits[3] = 0b00000000000100010000000000000000;
  //	src2.bits[0] = 0b00000000001000011110100010000100;
  //	src2.bits[1] = 0b00000000000000000000000000000000;
  //	src2.bits[2] = 0b00000000000000000000000000000000;
  //	src2.bits[3] = 0b00000000000001100000000000000000;
  //	int result = s21_is_less(src1, src2);
  //	origin = 0;
  //	printf("%d = %d\n", result, origin);
  //}
}
