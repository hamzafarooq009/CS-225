/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:

  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:

  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
    cannot use arrays, structs, or unions.


  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
    than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
    return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
    int result = (1 << x);
    result += 4;
    return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
    cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
    check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
    that you are allowed to use for your implementation of the function. 
    The max operator count is checked by dlc. Note that '=' is not 
    counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
    header comment for each function. If there are any inconsistencies 
    between the maximum ops in the writeup and in this file, consider
    this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
  This file is part of the GNU C Library.

  The GNU C Library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  The GNU C Library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
  include it implicitly at the start of every compilation.  It must
  not itself include <features.h> or any other header that includes
  <features.h> because the implicit include comes before any feature
  test macros that may be defined in a source file before it first
  explicitly includes a system header.  GCC knows the name of this
  header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
  and complex.  If the GCC (4.9 and later) predefined macros
  specifying compiler intent are available, use them to determine
  whether the overall intent is to support these features; otherwise,
  presume an older compiler has intent to support these features and
  define these macros by default.  */
/* wchar_t uses Unicode 8.0.0.  Version 8.0 of the Unicode Standard is
  synchronized with ISO/IEC 10646:2014, plus Amendment 1 (published
  2015-05-15).  */
/* We do not support C11 <threads.h>.  */
/* 
 * float_abs - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_abs(unsigned uf) {
  //covert uf to absolute value
  //single precision floating point (1-8-23 = 32bits) //sign bit, biased exp, and a frac
  //in Spfp, the bias is 127
  //Biased exponent = exp - bias
  //positive and negative inf, sign = 0 for +ve, and 1 for -ve infinity, biased exp = all 1bits, frac = all 0 bits
  //for NAN: sign is either 0 or 1, biased exp = all 1bits, fraction = anything except all zeroes.
  //when uf is NaN return uf

  //setting sign bit to 0
  unsigned int abs_uf = uf & 0x7fffffff;

  //inorder to check NAN
  unsigned int exp_checker= 0x7f800000;

  //either inf or NAN
  unsigned int nan_check = 0;
  if((abs_uf & exp_checker) == exp_checker){
    nan_check = 1;
  }
  
  //infchecker
  unsigned int inf_check = 0;
  if(abs_uf != exp_checker){
    inf_check = 1;
  }

  if(nan_check && inf_check){
    return uf;
  }
  else
  {
    return abs_uf;
  }
  
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
  //setting sign bit to 0
  unsigned int abs_uf = uf & 0x7fffffff;

  //inorder to check NAN
  unsigned int exp_checker= 0x7f800000;

  //either inf or NAN
  unsigned int nan_check = 0;
  if((abs_uf & exp_checker) == exp_checker){
    nan_check = 1;
  }
  
  //infchecker
  unsigned int inf_check = 0;
  if(abs_uf != exp_checker){
    inf_check = 1;
  }

  if(nan_check && inf_check){
    return uf;
  }
  //now if the uf is a positive value then we need to 
  //replace 0 of sign bit by 1
  else if(abs_uf == uf){
    unsigned int neg_of_pos_result = uf | 0x80000000;
    return neg_of_pos_result;
  }
  else
  {
    return abs_uf;
  }
}
/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int float_f2i(unsigned uf) {
  // conversion from floating point to integer
  //signed bit -> int is positive(0) or negative(1)
  int sign_bit = uf >> 31;

  //now we need to extract the exponent part
  int exp_part = uf & 0x7f800000;

  //now we need to get the decimal value of exponent
  //for this right shift exp by 23 bits
  int exp_part_value = exp_part >> 23;

  //now extract frac bits
  //take & of uf with the mask having all frac bits onn
  unsigned int frac_part = (uf & 0x7fffff)|0x800000;

  //now deduct the bias from the value of exp_part

  //An exp bias is included, because exp bits needs to represent the positive and negative values

  //Any exp bits that represents number less than 127 would result in a negative exponential number
  //but if we have number greater than the exp bias, our exp value would be a +ve number
  // For single precision the bias is 127
  int Bias = 127;

  //(-1)^signbit * (1+frac_part) *2^E
  //for negative values we need to return 0

  if(exp_part_value < Bias){
    return 0x0;
  }

  //E = exp - 127(for single precision)
  int E = exp_part_value - 127;


  //for out of range intergers
  //for infinity or nan
  if(E > 31 || exp_part_value == 0xff){
    return 0x80000000u;
  }

  //if E is greater than 23 then left shift frac by E-23 bits
  if (E > 23){
    frac_part = frac_part << (E - 23);
  }
  else{
    frac_part = frac_part >> (23 - E);
  }
  
  
  //Now check the sign for the 2s compliment version
  if(sign_bit == 0){
    return frac_part;
  }
  else{
    return ~frac_part+1;
  }
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
  
  //getiing the sign_bit of x
  int tMin = 0x80000000;
  int tMax = ~tMin;

  /*
  Sign bit-> 1 and rest of bits 0 if x is negative
  All zeros if x is positive
  */
  unsigned signbit = x & tMin;

  //if sign bit is -ve, we will take the absolute of it
  // unsigned absX;
  if(signbit){
    x = ~x + 1;
  }
  
  //for exp part, make a copy of x
  unsigned tmp_x = x;
  int E = 0;
  //right shifting tmp_x to count the number of bits right to MSB
  while ((tmp_x >> 1) != 0){
    tmp_x = tmp_x >> 1;
    E++;
  }
  //now left shift the exp 23 bits
  //0x7f = 0 0000000 00000000000000001111111
  //0x7f = 127
  // E = exp + 127(shift the E left shift by 23)
  unsigned int exp_part = (E + 127);
  exp_part = exp_part << 23;

  //now left shift x to (31-E) bits to clear all zeros that are present left to most significant bit
  unsigned int frac = x << (31 - E);
  frac = frac << 1;

  unsigned int round = frac << 23;
  round = round >> 23;
  frac = frac >> 9;
  //right shifting frac part by 9 bits to frac designated position
  //s eeeeeeee fffffffffffffffffffff


  //0x100 = 0 0000000 00000000000000100000000
  //if the value is greater than 0x100, then its value would become 1
  //if less than 0x100, value would be 0
  //other value would be an add between the frac part and 0x1
  //rounding conversion without using macros
  //now we need to handle overflows

  if (round > 256) {
    round = 0x1;
  }
  else if (round < 256){
    round = 0x0;
  }
  else{
    round = frac & 0x1;  
  } 
  
  if(x){
    int flp = (signbit | exp_part | frac); 
    return flp + round;
  }
  return 0;
}
/* 
 * float_half - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_half(unsigned uf) {
  //there are 3 cases we need to deal with
  /*
  Case1-> exp part is all 0 or 1 then return uf
  Case2-> first 7 digits of exp_part is 0s
  Case3->exp_part mins 1
  */
  //to check if exponent part bits are all 1
  if((uf & 0x7f800000) == 0x7f800000){
    return uf;
  }

  if(uf & 0x7f000000){
    return uf + 0xff800000;
  }

  //right shifting by 1 means dividing it it by 2^-1 i.e half
  unsigned uf2 = uf >> 1;
  
  if ((uf & 3) == 3)
    uf2 += 1;

  if (uf & 0x80000000)
    uf2 += (0x40000000);
  
  return uf2;
}
