#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

// Tinh n! = cach goi de quy
int factorial_1(int n) {
	if (n == 1)
		return 1;
	return n * factorial_1(n - 1);
}

// Tinh n! = cach goi de quy duoi (tail recursion)
int factorial_2(int n, int result = 1) {
	if (n == 1)
		return result;
	return factorial_2(n - 1, result * n);
}

// Tinh n! = cach dung vong lap
int factorial_3(int n) {
	int result = 1;
	for (int i = 2; i <= n; ++i) {
		result *= i;
	}
	return result;
}

int main() {
	int n;
	printf("Nhap vao n (n > 0): ");
	scanf("%d", &n);
	printf("Ket qua %d! = %d (factorial_1)\n", n, factorial_1(n));
	printf("Ket qua %d! = %d (factorial_2)\n", n, factorial_2(n));
	printf("Ket qua %d! = %d (factorial_3)\n", n, factorial_3(n));
	return 0;
}