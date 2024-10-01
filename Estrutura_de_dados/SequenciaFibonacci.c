#include <stdio.h>
#include <stdlib.h>

int fib(int n) {
	if (n <= 1) {
		return n;
	}
	else {
		return fib(n - 1) + fib(n - 2);
	}
	
}

int main(void) {
	int n;
	printf("Digite N da sequencia de fibonacci: ");
	scanf_s("%d", &n);
	for (int i = 0; i <= n; i++) {
		printf("%d, ", fib(i));
	}
	return 0;
}