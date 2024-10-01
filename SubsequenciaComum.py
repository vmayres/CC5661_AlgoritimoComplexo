def maiorsc(texto1, texto2):
    i = len(texto1) - 1
    j = len(texto2) - 1
    return MSC(texto1, texto2, i, j)

def MSC(texto1, texto2, i, j):
    if i < 0 or j < 0:
        return ""
    if texto1[i] == texto2[j]:
        return MSC(texto1, texto2, i-1, j-1) + texto1[i]
    else:
        seq1 = MSC(texto1, texto2, i-1, j)
        seq2 = MSC(texto1, texto2, i, j-1)
        if len(seq1) > len(seq2):
            return seq1
        else:
            return seq2
        

X = "ace"
Y = " adcbe"

print(maiorsc(X, Y))


X = "xxxxxxxxace"
Y = "yyyyyyyyadcbe"

print(maiorsc(X, Y))