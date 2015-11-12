// Problem source: http://www.cprogramming.com/challenges/factorial.html
/*
Here's a challenge that's a bit more mathematical in nature. Write a program that determines the number of trailing zeros at the end of X! (X factorial), where X is an arbitrary number. For instance, 5! is 120, so it has one trailing zero. (How can you handle extremely values, such as 100!?) The input format should be that the program asks the user to enter a number, minus the !. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef CHAR_BIT
#  define CHAR_BIT __CHAR_BIT__
#endif

// TODO: CONSIDER: Adjust for big int!

const int INTEGER_STRING_SIZE = (sizeof(int)*CHAR_BIT-1)/3 + 3;

unsigned long factorial( int n );
uint32_t multiplication_is_safe(uint64_t a, uint64_t b);
size_t highestOneBitPosition(uint64_t a);


int main(int argc, char *argv[])
{
	// printf("%d\n", CHAR_BIT);
	//return 0;
	
	int x;
	printf("Enter an integer to take its factorial.\n");
	scanf("%d", &x);
	
	unsigned long y = factorial(x);
	printf("\nfinal factorial: %lu\n",  y);
	if ( y == -1 )
	{
		printf("The number is too large to represent in a normal unsigned integer.\n");
		printf("Big integer is not yet implemented.\n");
		exit(1);
	}
	
	char * numstring = malloc(INTEGER_STRING_SIZE);
	
	sprintf(numstring,"%lu",y);
	
	int strLen = strlen(numstring);
	
	int trailingZeros = 0;
	
	/*
	printf("strlen %d\n", strLen);
	printf("str    %s\n", numstring);
	*/
	for (int i = strLen - 1; i >= 0; i--)
	{
		if (numstring[i] != '0')
		{
			break;
		}
		else
		{
			trailingZeros += 1;
		}
	}
	printf("trailing zeros: %d\n", trailingZeros);
	
	return 0;
}

unsigned long factorial( int n )
{
	unsigned long retval = 1;
	for (unsigned long i = n; i > 0;  i--)
	{
		if( multiplication_is_safe(retval, i) ) {
			retval *= i;
			printf("factorial: %lu\n",  retval);
		}
		else {
			return -1;
		}
	}
	return retval;
}

// Function by 'Head Geek'
// Source: http://stackoverflow.com/questions/199333/how-to-detect-integer-overflow-in-c-c
// Modified for unsigned long
uint32_t multiplication_is_safe(uint64_t a, uint64_t b)
{
    size_t a_bits=highestOneBitPosition(a), b_bits=highestOneBitPosition(b);
    return (a_bits+b_bits<=32);
}

// Function by 'Head Geek'
// Source: http://stackoverflow.com/questions/199333/how-to-detect-integer-overflow-in-c-c
// Modified for unsigned long
size_t highestOneBitPosition(uint64_t a)
{
    size_t bits=0;
    while (a!=0)
    {
        ++bits;
        a>>=1;
    };
    return bits;
}