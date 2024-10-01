//algoritomo ser implementado por lista dinamica
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Merge(int v[], int p, int q, int r){
    int n_left = q - p + 1;
    int n_right = r - q;
    int L[100]; //vetor estatico
    int R[100]; //vetor estatico

    for( int i = 0; i < n_left; i++){
        L[i] = v[p + i];
    }

    for( int i = 0; i < n_right; i++){
        R[i] = v[q + i + 1];
    }

    int i=0, j=0, k=p;

    while((i < n_left) && (j < n_right)){
        if (L[i] <= R[j]){
            v[k] = L[i];
            i++;
        }
        else{
            v[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n_left){
        v[k] = L[i];
        i++;
        k++;
    }

    while (j < n_right){
        v[k] = R[j];
        j++;
        k++;
    }
    
}

void MergeSort(int v[], int left, int right){
    if(left < right){
        int val = (left + right) / 2;
        int mid = floor(val);
        MergeSort(v, left, mid);
        MergeSort(v, (mid+1), right);
        Merge(v, left, mid, right);
    }
}

void main(){
    int v[] = {12, 11, 13, 5, 6, 7, 4, 17, 21, 0};
    int n = sizeof(v)/sizeof(v[0]); //tamanho do vetor -> n = 10
    MergeSort(v, 0, n-1);

    //Imprime o vetor ordenado
    for(int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}