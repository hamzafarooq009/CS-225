/* 
 * CS:APP Data Lab 
 * 
 * Hamza Farooq 21100197
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
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
//1
int bitAnd(int x, int y) { //and of two numbers, by using de morgans law
  int z = ~(~x | ~y);
  return z;
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
//2
int getByte(int x, int n) {
  int leftshifted_n = n << 3;
  int shifted_x = x >> leftshifted_n;
  int mask = 0xFF;
  int result = mask & shifted_x;
  return result;
}

/* 
 * anyEvenBit - return 1 if any even-numbered bit in word set to 1
 *   Examples anyEvenBit(0xA) = 0, anyEvenBit(0xE) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
//3
int anyEvenBit(int x) {
  
  //making a mask 
  int b0 = 0x55;

  int b1 = b0 << 8;
  int b2 = b1 << 8;
  int b3 = b2 << 8;

  int mask = b0 | b1 | b2 | b3;

  int result = x & mask;
  
  int ans = !(!result);
  
  return ans;
}

/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
//4
int allOddBits(int x) {
  int inv_x = ~(x);
  //making a mask 
  int b0 = 0xaa;

  int b1 = b0 << 8;
  int b2 = b1 << 8;
  int b3 = b2 << 8;

  int mask = b0 | b1 | b2 | b3;

  int result = mask & inv_x;

  int ans = (!result);

  return ans;
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */

//5
//////////////////////////////////////////////////see again
int logicalShift(int x, int n) {
  //first need to see if it is negative
  //0x1 = 0000 0000 0000 0000 0000 0000 0000 0001
  //~(0x1) = 1111 1111 1111 1111 1111 1111 1111 1110
  //0x87654321 = 1000 0111 0110 0101 0100 0011 0010 0001
  //0x08765432 = 0000 1000 0111 0110 0101 0100 0011 0010
  //init_mask <<(27) = 1111 0000 0000 0000 0000 0000 0000 0000 (need to take complement of this to mask it using add) 
  //31-4 = 27

  int init_mask = ~(0x1);
  int mask = ~(init_mask <<(31-n));
  int shifted_result = x >> n;
  int final_result = shifted_result & mask;

  return final_result;
}
/* 
 * rotateRight - Rotate x to the right by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateRight(0x87654321,4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3 
 */
//6
///////////////////////////////////////////////////////////
            //(1st)                              (last)
//0x87654321 = 1000 0111 0110 0101 0100 0011 0010 0001
//0x76543218 = 0111 0110 0101 0100 0011 0010 0001 1000

//0x80000000 = 1000 0000 0000 0000 0000 0000 0000 0000

//need to confirm this
int rotateRight(int x, int n) {
  int x_copy = x >> 28;//now take last 4 bits from it only
  int mask1 = ~((~(0x1)) << 3);
  int x_copy_masked = x_copy & mask1; //0000 0000 0000 00000 0000 0000 0000 1000

  int x_og_shifted = x >> (32-n);
  int result = x_og_shifted | x_copy_masked;

  return result;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
//7
int tmin(void) {
  int b0 = 0x1;
  int result = b0<<31;

  return result;
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
//8

//(5,3) = -4_ 2_ 1_ = cant
//(-4,3) = -4  2  1 = can by onning -4 only
int fitsBits(int x, int n) {

}

/* 
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2 
 */
//9

//96 = 0x60 = 0110 0000
//     0x20 = 0010 0000 

//check again
int leastBitPos(int x) {
  //first making a mask to extract the LSB
  int mask = ~x + 0x01;
  int result = x & mask;
  return result;
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
//10
//check again
int divpwr2(int x, int n) {
  //we know that right shift is equivalent to dividing the number by 2^n
  //we need to round them towards 0 as well 
  //This can be solved by bias, 0 for positive number and 1 for negative numbers
  //The program will still round down but since we had added one, we will get the required
  //result.

  int mask = (1 << n) + (~0);
  int bias = (x >>31) & mask;
  int result = (x + bias) >> n;
  return result;
}
/* 
 * isNonNegative - return 1 if x >= 0, return 0 otherwise 
 *   Example: isNonNegative(-1) = 0.  isNonNegative(0) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */

//11
int isNonNegative(int x) {
  //need to check the signed bit
  int shift = x >>31;
  int b0 = 0x1;
  int lastbit = shift & b0;
  int result = (!lastbit);

  return result;
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
//12

/////////////////////////////////////////////////////////////////////////////////////////
int isLessOrEqual(int x, int y) {

  int sign_x = x >> 31; //to get the MSB of x
  int sign_y = y >> 31; //to get the MSB of y
  int diff = y + (~x+1);// to get value of (y-x) difference
  int sign_diff = !(diff >> 31);//to get the MSB of diff
  int sign_comparison = !(sign_x ^ sign_y); //for same sign XOR operator is used to get zero
  
  int diff_sign = (!sign_y) & sign_x; //only results in 1 if x is negative and y is positive.
  int same_sign = sign_comparison & sign_diff;
  int result = diff_sign | same_sign;
  return result; 
}
/*
 * satMul2 - multiplies by 2, saturating to Tmin or Tmax if overflow
 *   Examples: satMul2(0x30000000) = 0x60000000
 *             satMul2(0x40000000) = 0x7FFFFFFF (saturate to TMax)
 *             satMul2(0x60000000) = 0x80000000 (saturate to TMin)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
//13
//need to study underflow and overflow
int satMul2(int x) {

  return 2;
}
/*
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 *   Examples: isPower2(5) = 0, isPower2(8) = 1, isPower2(0) = 0
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
//14
int isPower2(int x) {
  //a number which is power of two has only one bit set
  //If the number is neither zero nor a power of two, it will have 1 in more than one place. So if x is a power of 2 then x & (x-1) will be 0.
  //making (x-1) from x by: x + (~0)
  //first check if its the power of two by applying and between x and x-1
  int x_1 = x + (~0x0);
  int pow2 = !(x & x_1);

  //check if the number is negative
  int check_neg= !((x>>31)&(0x1));

  //need to check 3 cases
  int result = pow2 & !(!x) & (check_neg);
  return result;
}
