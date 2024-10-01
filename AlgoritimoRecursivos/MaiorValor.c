#include <stdio.h>
#include <stdlib.h>

int maiorValor(int V[], int n) {
    if (n == 1) {
        return V[0];
    }
    else {
        if (V[n - 1] > V[n - 2]) {
            return V[n - 1];
        }
        else {
            maiorValor(V, n - 1);
        }
    }
}

int main(void) {
    int n, num;
    printf("Enter the number of elements in the array: ");
    scanf_s("%d", &n);

    int vetor[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &num);
        vetor[i] = num;
    }

    printf("%d", maiorValor(vetor, n));

    return 0;
}