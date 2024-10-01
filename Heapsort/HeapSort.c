#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void trocar(int *i, int *j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}

void Heapify(int v[], int n, int i) {
	int l = 2 * i + 1; // esuqerda
	int r = 2 * i + 2; // direita

	int maior = 0;


	if (l < n && v[l] > v[i]) {
		maior = l;
	}
	else {
		maior = i;
	}
	if (r < n && v[r] > v[maior]) {
		maior = r;
	}

	if (maior != i) {
		trocar(&v[i], &v[maior]);
		Heapify(v, n, i);
	}
}

void buildHeap(int v[], int n) {
	int ini = (n / 2) - 1; // ultimo pai
	//verifica se todos nao folhas tem propriedade de heap
	for (int i = ini; i > 0; i--) {
		Heapify(v, n, i-1);
	}
}

void HeapSort(int v[], int n) {
	buildHeap(v, n);
	for (int i = n; i > 0; i--) {
		trocar(&v[0], &v[i]);
		Heapify(v, i, 0);
	}
}

void main() {
	int v[] = { 12, 11, 13, 5, 6, 7 };
	int n = (sizeof(v) / sizeof(v[0])) - 1;
	HeapSort(v, n);

	//Print array
	for (int i = 0; i <= n; i++) {
		printf("%d ", v[i]);
	}
	printf("\n");
}