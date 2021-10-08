t = int(input())
sentences = []
cnt = [[0 for _ in range(1001)] for _ in range(1001)]
occ = [0 for _ in range(1001)]
for i in range(t):
    a = list(map(int, input().split(' ')))
    sentences.append(a)
    for j in range(len(a)):
        for k in range(len(a)):
            if a[j] != -1 and a[k] != -1:
                cnt[a[j]][a[k]] += 1
        if a[j] != -1:
            occ[j] += 1

# for i in range(7):
#     for j in range(7):
#         print(cnt[i][j], end = ' ')
#     print()
# print()

ansmax = 0
answer = 0
for sentence in sentences:
    loc = -1
    for i in range(len(sentence)):
        if sentence[i] == -1:
            loc = i
            break
    ans = [0 for _ in range(1001)]
    for k in range(1001):
        for i in range(len(sentence)):
            if loc != i and occ[k] > 0:
                ans[k] += cnt[k][sentence[i]] / (occ[k] * occ[k])
        if ans[k] > ansmax:
            ansmax = ans[k]
            answer = k
    print(answer)
    