
def CountSort(v):
    maior = v[0]
    for i in range(len(v)):
        if v[i] > maior:
            maior = v[i]
    m = maior

    contador = [0] * (m+1)
    for i in range(len(v)):
        contador[v[i]] += 1

    n = 0
    for i in range(len(contador)):
        if contador[i] > 0:
            for j in range(contador[i]):
                v[n] = i
                n += 1

if __name__ == '__main__':
    v = [12, 11, 13, 5, 6, 7]
    CountSort(v)
    print(v)