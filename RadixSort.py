import math

def getDigit0(n, d):
    return n//int(math.pow(10,d))%10

def CountSort(v, d):
    cont = [0] * 10
    output = [0] * len(v)

    for i in range(len(v)):
        cont[getDigit0(v[i], d)] += 1

    for i in range(1, 10):
        if i != 0:
            cont[i] += cont[i-1]

    for i in range(len(v)-1, -1, -1):
        cont[getDigit0(v[i], d)] -= 1
        output[ cont[getDigit0(v[i], d)] ] = v[i]
    
    return output

def RadixSort(v):
    maior = max(v)
    num_digits = math.floor(math.log10(maior) + 1)
    for d in range(0, num_digits, 1):
        v = CountSort(v, d)
    return v


if __name__ == '__main__':
    v = [170, 45, 75, 90, 802, 24, 2, 66]
    v = RadixSort(v)
    print(v)