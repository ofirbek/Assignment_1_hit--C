#define _CRT_SECURE_NO_WARNINGS
#define N 3

/*Libraries*/
#include <stdio.h>
#include <math.h>

/*
	Assigned by:
		Ofir_Baibekov #316223585
		Yarden_Shelly #211409131
*/

/* Function declarations */

void Ex1();
void Ex2();
void Ex3();

/* Declarations of other sub-functions */

int multiplication(int, int);

void primeNumbers(int, int);
int prime(int);

int rotateNumber(int, int);
int numberLength(int);

int inputIntNonNegative();

/* ------------------------------- */

int main()
{
	int select = 0, i, all_Ex_in_loop = 0;
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
	if (scanf_s("%d", &all_Ex_in_loop) == 1)
		do
		{
			for (i = 1; i <= N; i++)
				printf("Ex%d--->%d\n", i, i);
			printf("EXIT-->0\n");
			do {
				select = 0;
				printf("please select 0-%d : ", N);
				scanf_s("%d", &select);
			} while ((select < 0) || (select > N));
			switch (select)
			{
			case 1: Ex1(); break;
			case 2: Ex2(); break;
			case 3: Ex3(); break;
			}
		} while (all_Ex_in_loop && select);
		return 0;
}

/* Function definitions */

void Ex1() {
	int num1 = 0, num2 = 0, answer = 0;
	printf("\nplease enter two multipliers: ");
	scanf_s("%d%d", &num1, &num2);
	answer = multiplication(num1, num2);
	printf("%d * %d = %d\n", num1, num2, answer);
}

void Ex2() {
	int num1 = 0, num2 = 0;
	printf("\nplease enter the lower bound: ");
	num1 = inputIntNonNegative();
	printf("please enter the upper bound: ");
	num2 = inputIntNonNegative();
	primeNumbers(num1, num2);
}

void Ex3() {
	int number = 0, spins = 0, answer = 0;
	printf("\nplease enter the number: ");
	number = inputIntNonNegative();
	printf("please enter the amount of spins: ");
	spins = inputIntNonNegative();
	answer = rotateNumber(number, spins);
	printf("The number %d after %d spins is: %d\n", number, spins, answer);
}

/* Sub-Function definitions */

int multiplication(int num1, int num2) {
	int product = 0, productIsNegative = 0, smallerNum, biggerNum;

	//Checks whether the product should be positive or negative
	if ((num1 < 0 && num2>0) || (num1 > 0 && num2 < 0)) {
		productIsNegative = 1;
	}

	//Makes sure the numbers are positive for the calculation
	num1 = (num1 < 0) ? -num1 : num1;
	num2 = (num2 < 0) ? -num2 : num2;

	//Checks which number is the biggest and the smallest
	smallerNum = (num1 < num2) ? num1 : num2;
	biggerNum = (num1 < num2) ? num2 : num1;

	//loop that performs the multiplication operation
	while (smallerNum > 0) {
		product += biggerNum;
		smallerNum--;
	}

	return (productIsNegative) ? -product : product;
}

void primeNumbers(int num1, int num2) {
	//Makes sure the number is odd
	if (num1 % 2 == 0)
		num1++;

	printf("The prime numbers between %d and %d:\n", num1, num2);

	//loop that prints all required primes using an additional function
	while (num1 <= num2)
	{
		if (prime(num1))
			printf("%d\n", num1);
		num1 += 2;
	}
}

int prime(int num) {
	//an even number cannot be prime
	if (num < 2 || num % 2 == 0)
		return 0;

	int sqrtNum = sqrt(num);

	//loop that checks whether a number is prime effectively
	for (int i = 3;i <= sqrtNum;i += 2) {
		if (num % i == 0)
			return 0;
	}
	return 1;
}

int rotateNumber(int number, int spins) {
	int numLength = numberLength(number);
	int x;

	spins = spins % numLength;

	//loop that rotates the digits according to the spins number
	for (int i = 0; i < spins; i++)
	{
		x = number % 10;
		number /= 10;
		number = number + (x * (int)pow(10, numLength - 1));
	}
	return number;
}

int numberLength(int num) {
	int numLength = 0;

	//A loop that calculates the number of digits in the num variable
	for (;num != 0;numLength++) {
		num = num / 10;
	}
	return numLength;
}

int inputIntNonNegative() {
	int num;
	printf("Please enter a positive number\n");
	scanf_s("%d", &num);

	//loop that requests a positive number from the user until he enters a positive number
	while (num < 0)
	{
		printf("The number you entered is incorrect, please enter a positive number\n");
		scanf_s("%d", &num);
	}

	return num;
}

/* ------------------- */