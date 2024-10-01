#include <stdio.h>

void imprimir(int V[], int n) {
	if (n == 0) {
		printf("NAN, Vetor inexistente\n");
	}
	if (n == 1) {
		printf("%d ", V[0]);
	}
	else {
		imprimir(V, n - 1);
		printf("%d ", V[n-1]);
	}
}

int Vet[] = { 1,2,3,4,5,6,7,8,9,0 };

/*
int main(void) {
	imprimir(Vet, 10);
}
*/