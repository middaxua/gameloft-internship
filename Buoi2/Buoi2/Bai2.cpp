#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	int n;
	do {
		printf("Nhap vao so nguyen duong de thoat chuong trinh: ");
		scanf("%d", &n);
	} while (n <= 0);
	return 0;
}