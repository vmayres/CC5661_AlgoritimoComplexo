#include<stdio.h>

int funcao(int a, int b) {
	if (b == 0) {
		return 0;
	}
	if (b == 1) {
		return a;
	}
	else {
		return a + funcao(a, b - 1);
	}

}

/*
int main(void) {
	printf("%d\n", funcao(1, 2));
	printf("%d\n", funcao(4, 2));
	printf("%d\n", funcao(7, 2));
}
*/