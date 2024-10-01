def QuickSort(v, p, r):
    if p < r:
        q = Partition(v, p, r)
        QuickSort(v, p, q-1)
        QuickSort(v, q+1, r)

def Partition(v, p, r):
    x = v[r]
    i = p - 1
    for j in range(p, r):
        if v[j] <= x:
            i += 1
            v[i], v[j] = v[j], v[i]  # troca(v, i, j)
    v[i+1], v[r] = v[r], v[i+1] ##troca(v,i+1,r)##
    return i+1

if __name__ == '__main__':
    v = [12, 11, 13, 5, 6, 7]
    QuickSort(v, 0, len(v)-1)
    print(v)