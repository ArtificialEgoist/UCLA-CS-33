/* 
 * CS:APP Data Lab 
 * 
 * <Nathan Tung: 004-059-195>
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

#include "btest.h"

/*
 * Instructions to Students:
 *
 * STEP 1: Fill in the following struct with your identifying info.
 */
id_struct studentID =
{
  /* UID number: */
  "004059195",
  /* Last Name: */
  "Tung",
  /* First Name: */
  "Nathan",
};

#if 0
/*
 * Instructions to Students:
 *
 * STEP 2: Read the following instructions carefully.
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
  4. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the btest harness to check your solutions for correctness.
 */


#endif
/* 
 * anyEvenBit - return 1 if any even-numbered bit in word set to 1
 *   Examples anyEvenBit(0xA) = 0, anyEvenBit(0xE) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyEvenBit(int x) {
/*Shift each Byte into the lowest position, then essentially  AND them with a mask that represents all even bits. The double bang shows whether there are any even bits in our final result.*/
	int x1 = x>>24;
	int x2 = x>>16;
	int x3 = x>>8;
	int test = 85;	
	int x4 = x&test;

	int x5 = x1|x2|x3;

	return !!(x4|(x5&test));

}

/* 
 * bitNor - ~(x|y) using only ~ and & 
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y) {
/*Using De Morgan's law, we know that the following statement is equivalent.*/
	return (~x)&(~y);
}
/*
 * bitParity - returns 1 if x contains an odd number of 0's
 *   Examples: bitParity(5) = 0, bitParity(7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int bitParity(int x) {
/*Use xor on x continuously until the number is essentially halved into a single bit. In the case of an odd number of 0's, that bit ANDed with 1 returns 1.*/
	x = x^(x>>16);
	x = x^(x>>8);
	x = x^(x>>4);
	x = x^(x>>2);
	x = x^(x>>1);

	return x&1;
}

/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
/*Determine whether x would be true or false, then make all the bits equal to that. We then return the corresponding value.*/
	int a=!x;
	a = a<<31;
	a|=a>>1;
	a|=a>>2;
	a|=a>>4;
	a|=a>>8;
	a|=a>>16;
	return (a&z)|(~a&y);
}
/* 
 * isLess - if x < y  then return 1, else return 0 
 *   Example: isLess(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLess(int x, int y) {
/*x is less than y if their difference (of y-x) is greater than zero AND it is not the case of overflow, where y is negative, x is positive, and the difference is greater than zero. The other case is where the difference is negative BUT y is positive and x is negative. We can return the OR of both these conditions.*/
	int signy = y>>31;
	int signx = x>>31;
	int diff = y+(~x+1);
	int diffsign = diff>>31;

	int one = !(signy & !signx & !diffsign) & !diffsign & !!(diff^0);
	int two = !signy & signx & diffsign;
	return one | two;

/*
	int one = !(!!signy & !signx & !diffsign) & !diffsign & !!(diff^0);
	int two = !signy & !!signx & !!diffsign;
	return one | two;
*/

}
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
/*Only Tmax and minus one will return itself when its negative is taken. By elminating the second possibility, we can test if x is truly Tmax.*/
	int tmax=~(x+1);
	return !(x^tmax) & !!(~x);
}
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
/*If there are any 1's, make all the bits 1. Otherwise, it's all 0. The bits are xored with 1, and a single bit is returned. If and only if x is 0 will x^1 give 1.*/
	x|=x>>1;
	x|=x>>2;
	x|=x>>4;
	x|=x>>8;
	x|=x>>16;

	return (x^1)&1;
}
/* 
 * reverseBytes - reverse the bytes of x
 *   Example: reverseBytes(0x01020304) = 0x04030201
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3
 */
int reverseBytes(int x) {
/*Move each byte of interest into its corresponding place. Then mask it so that only the byte of interest remains. Return the OR of all the bytes for reverse.*/
	int a = x>>24;
	int b = x>>8;
	int c = x<<8;
	int d = x<<24;
	int mask = 255;

	a = a&mask;
	b = b&(mask<<8);
	c = c&(mask<<16);
	d = d&(mask<<24);

	return a|b|c|d;
}
/* 
 * sign - return 1 if positive, 0 if zero, and -1 if negative
 *  Examples: sign(130) = 1
 *            sign(-23) = -1
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 2
 */
int sign(int x) {
/*Extract the sign by shifting right 31 times, then shift it left once. A negative yields s=-2 but a zero or positive yields s=0. Double-bang x gives 0 only if x is zero. Thus by ORing the two, we gain the corresponding values.*/
	int s = x>>31;
	s = s<<1;
	return (s|(!!x));
}
/* 
 * subOK - Determine if can compute x-y without overflow
 *   Example: subOK(0x80000000,0x80000000) = 1,
 *            subOK(0x80000000,0x70000000) = 0, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int subOK(int x, int y) {
/*Subraction is okay only when no overflow occurs. Overflow occurs when x and y have different sign bits, but y and the difference have identical sign bits. We extract each sign bit, then xor them accordingly. Essentially, we return whether these conditions for overflow are met.*/
	int diff = x+(~y+1);
	int signx = x>>31;
	int signy = y>>31;
	int subsign = diff>>31;

	int a = signy^subsign;
	int b = signx^signy;

	return !(!a&b);
}
/*
 * trueThreeFourths - multiplies by 3/4 rounding toward 0,
 *   avoiding errors due to overflow
 *   Examples: trueThreeFourths(11) = 8
 *             trueThreeFourths(-9) = -6
 *             trueThreeFourths(1073741824) = 805306368 (no overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int trueThreeFourths(int x) {
/*First, we obtain the absolute value of the value x. Then we obtain quarter, which is a fourth of x. By taking its negative, shifting it by two, then adding it to the absolute value of x, we obtain three-fourths of x. Using the sign, we can determine whether to make it negative again or not.*/
	int sign = x>>31;
	int absx = (x^sign) + ~sign + 1;
	int quarter = (~absx+1);
	quarter = quarter >> 2;

	absx = absx+quarter;

	return (~sign&absx)|(sign&(~absx+1));
}

/* 
 * tc2sm - Convert from two's complement to sign-magnitude 
 *   where the MSB is the sign bit
 *   You can assume that x > TMin
 *   Example: tc2sm(-5) = 0x80000005.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 4
 */
int tc2sm(int x) {
/*Determine the sign by shifting, then find the absolute value of x. We OR the absolute value with its sign shifted back (filling all non-sign places with 0's) to give us the sign-magnitude.*/
	int sign = x>>31;
	int absval = (x^sign) + ~sign + 1;

	return absval|(sign<<31);
}
