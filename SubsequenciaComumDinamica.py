def maiorsc(text1, text2):
    m = len(text1)
    n = len(text2)
    tb = [[0] * (n + 1) for _ in range(m + 1)] #compreençao de lista em python ( x -> variavel    _  -> variavel anonima)

    for i in range(1,m+1):
        for j in range(1,n+1):
            if text1[i-1] == text2[j-1]:
                tb[i][j] = tb[i-1][j-1] + 1
            else:
                tb[i][j] = max(tb[i-1][j], tb[i][j-1])

    print(tb)


maiorsc("ace", "adcbe")

