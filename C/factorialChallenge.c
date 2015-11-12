// Problem source: http://www.cprogramming.com/challenges/factorial.html
/*
Here's a challenge that's a bit more mathematical in nature. Write a program that determines the number of trailing zeros at the end of X! (X factorial), where X is an arbitrary number. For instance, 5! is 120, so it has one trailing zero. (How can you handle extremely values, such as 100!?) The input format should be that the program asks the user to enter a number, minus the !. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef CHAR_BIT
# define CHAR_BIT __CHAR_BIT__
#endif

// TODO: Adjust for big int!

const int INTEGER_STRING_SIZE = (sizeof(int)*CHAR_BIT-1)/3 + 3;

int factorial( int inp);

int main(int argc, char *argv[])
{
	//printf("%d\n", CHAR_BIT);
	//return 0;
	
	int x;
	scanf("%d", &x);
	
	int y = factorial(x);
	printf("fact: %d\n",  y);

	
	
	char * numstring = malloc(INTEGER_STRING_SIZE);
	
	sprintf(numstring,"%d",y);
	
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
	printf("%d\n", trailingZeros);
	
	return 0;
}

int factorial( int inp )
{
	int retval = 1;
	for (int i = inp; i > 0;  i--)
	{
		retval *= i;
	}
	return retval;
}