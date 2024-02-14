#include <stdio.h>
#include <math.h>

int inputIntNonNegative() {
	int num;
	printf("Please enter a positive number\n");
	scanf("%d", &num);

	while (!num)
	{
		printf("The number you entered is incorrect, please enter a positive number\n");
		scanf("%d", &num);
	}

	return num;
}

int numberLength(int num) {
	int numLength = 0;
	for (;num != 0;numLength++) {
		num = num / 10;
	}
	return numLength;
}

int rotateNumber(int number, int spins) {
	int numLength = numberLength(number);
	int x;

	spins = spins % numLength;

	for (int i = 0; i < spins; i++)
	{
		x = number % 10;
		number /= 10;
		number = number + (x * (int)pow(10, numLength -1));
	}
	return number;
}

int main() {
	int a, b;

		printf("please enter the first number\n");
		scanf_s("%d", &a);

		printf("please enter the second number\n");
		scanf_s("%d", &b);

		printf("%d\n", rotateNumber(a, b));
}

/*
int prime(int num) {
	if (num < 2 || num % 2 == 0)
		return 0;

	int sqrtNum = sqrt(num);

	for (int i = 3;i <= sqrtNum;i += 2) {
		if (num % i == 0)
			return 0;
	}
	return 1;
}

void primeNumbers(int num1, int num2) {
	if (num1 % 2 == 0)
		num1++;

	printf("The prime numbers between %d and %d:\n", num1, num2);

	while (num1 <= num2)
	{
		if (prime(num1))
			printf("%d\n", num1);
		num1 += 2;
	}
}

	int main() {
		int a, b;

		printf("please enter the first number\n");
		scanf_s("%d", &a);

		printf("please enter the second number\n");
		scanf_s("%d", &b);

		primeNumbers(a, b);
}
*/

/*int multiplication(int num1, int num2) {
	int product = 0, productIsNegative = 0, smallerNum, biggerNum;

	if ((num1 < 0 && num2>0) || (num1 > 0 && num2 < 0)) {
		productIsNegative = 1;
	}

	num1 = (num1 < 0) ? -num1 : num1;
	num2 = (num2 < 0) ? -num2 : num2;

	smallerNum = (num1 < num2) ? num1 : num2;
	biggerNum = (num1 < num2) ? num2 : num1;

	while (smallerNum > 0) {
		product += biggerNum;
		smallerNum--;
	}

	return (productIsNegative) ? -product : product;

	int main() {
		int a, b, product;

		printf("please enter the first number\n");
		scanf_s("%d", &a);

		printf("please enter the second number\n");
		scanf_s("%d", &b);

		printf("the product from your numbers is: %d\n", multiplication(a, b));

	}
}
*/