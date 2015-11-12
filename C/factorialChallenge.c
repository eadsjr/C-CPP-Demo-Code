// Problem source: http://www.cprogramming.com/challenges/factorial.html
/*
Here's a challenge that's a bit more mathematical in nature. Write a program that determines the number of trailing zeros at the end of X! (X factorial), where X is an arbitrary number. For instance, 5! is 120, so it has one trailing zero. (How can you handle extremely values, such as 100!?) The input format should be that the program asks the user to enter a number, minus the !. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef CHAR_BIT
#  define CHAR_BIT __CHAR_BIT__
#endif


const int INTEGER_STRING_SIZE = (sizeof(int)*CHAR_BIT-1)/3 + 3;

uint64_t countTrailingZeros( uint64_t );
uint64_t factorial( int n );
uint32_t multiplicationIsSafe(uint64_t a, uint64_t b);
size_t highestOneBitPosition(uint64_t a);

int main(int argc, char *argv[])
{
	printf("Program will output trailing zeros to the factorial of given integer.\n");

	char c;
	printf("The hard way? ( y / n ): ");
	scanf("%c", &c);

	if( c == 'n' )
	{
		printf("The easy way. Counting zeros in input digit.\n");
		int x;
		printf("Enter a positive integer: ");
		scanf("%d", &x);

		printf("trailing zeros: %llu\n", countTrailingZeros(x)*x);
	}
	else
	{
		printf("The hard way. Calculating factorial.\n");
		int x;
		printf("Enter a positive integer: ");
		scanf("%d", &x);

		uint64_t y = factorial(x);
		printf("\nfinal factorial: %llu\n",  y);
		printf("trailing zeros: %llu\n", countTrailingZeros(y));
	}
	return 0;
}

uint64_t countTrailingZeros( uint64_t n )
{
	char * numstring = malloc(INTEGER_STRING_SIZE);
	
	sprintf(numstring,"%llu",n);
	
	int strLen = strlen(numstring);
	
	uint64_t trailingZeros = 0;
	
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
	return trailingZeros;
}

// TODO: CONSIDER: Adjust for big int!
uint64_t factorial( int n )
{
	uint64_t retval = 1;
	for (int i = n; i > 0;  i--)
	{
		if( multiplicationIsSafe(retval, n) ) {
			retval *= n;
			printf("factorial iteration %d: %llu\n",  n-i, retval);
		}
		else {
			printf("Number has exceeded unsigned long long integer max: %llu\n", UINT64_MAX);
			printf("Big integer is not yet implemented.\n");
			exit(1);
			return -1;
		}
	}
	return retval;
}

// Function by 'Head Geek'
// Source: http://stackoverflow.com/questions/199333/how-to-detect-integer-overflow-in-c-c
// Modified for unsigned long, naming conventions
uint32_t multiplicationIsSafe(uint64_t a, uint64_t b)
{
    size_t a_bits=highestOneBitPosition(a), b_bits=highestOneBitPosition(b);
    return (a_bits+b_bits<=64);
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