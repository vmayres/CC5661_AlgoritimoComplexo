import math

def Merge(V,p, q, r):
    n_left = q - p + 1
    n_right = r - q
    L = [0] * n_left
    R = [0] * n_right

    for i in range(n_left):
        L[i] = V[p + i]

    for j in range(n_right):
        R[j] = V[q + j + 1]
    
    i=0
    j=0
    k=p

    while i < n_left and j < n_right:
        if L[i] <= R[j]:
            V[k] = L[i]
            i += 1
        else:
            V[k] = R[j]
            j += 1
        k += 1

    while i < n_left:
        V[k] = L[i]
        i += 1
        k += 1

    while j < n_right:
        V[k] = R[j]
        j += 1
        k += 1


def MergeSort(V, left, right):
    if left < right:
        mid = math.floor((left + right) / 2)
        MergeSort(V, left, mid)
        MergeSort(V, mid + 1, right)
        Merge(V, left, mid, right)


if __name__ == "__main__":
    V = [3, 41, 52, 26, 38, 57, 9, 49]
    MergeSort(V, 0, len(V) - 1)
    print(V)