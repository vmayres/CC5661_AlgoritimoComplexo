#include <stdio.h>

int exp(int base, int pot) {
	if (pot == 0) {
		return 1;
	}
	else {
		return base * exp(base, pot - 1);
	}
}

/*
int main(void) {
	printf("%d\n", exp(2, 3));
	printf("%d\n", exp(2, 4));
	printf("%d\n", exp(3, 2));
	printf("%d\n", exp(3, 4));
}*/