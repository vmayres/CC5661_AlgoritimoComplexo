#include <stdio.h>

int SomaVetor(int V[10], int n) {
	if (n == 1) {
		return V[0];
	}
	else {
		return V[n - 1] + SomaVetor(V, n - 1);
	}
	
}

int V[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

/*
int main(void) {
	printf("%d",SomaVetor(V, 10));
}*/