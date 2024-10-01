def Heapify(v, n , i):
    l = 2*i + 1
    r = 2*i + 2

    if l < n and v[l] > v[i]:
        maior = l
    else:
        maior = i
    if r < n and v[r] > v[maior]:
        maior = r

    if maior != i:
        v[i], v[maior] = v[maior], v[i]
        Heapify(v, n, maior)

def buildHeap(v, n):
    ini = (n//2) -1
    for i in range(ini, -1, -1):
        Heapify(v, n, i)

def HeapSort(v, n):
    buildHeap(v, n)
    for i in range(n-1, 0, -1):
        v[0], v[i] = v[i], v[0]
        Heapify(v, i, 0)

if __name__ == '__main__':
    v = [12, 11, 13, 5, 6, 7]
    HeapSort(v, len(v)) # n = len(v)
    print(v)
