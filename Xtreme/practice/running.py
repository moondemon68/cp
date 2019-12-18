t = int(input())
f = []
for i in range(22005):
    if (i == 0):
        f.append(1)
    elif (i == 1):
        f.append(2)
    else:
        f.append(f[i-1]+f[i-2])
for i in range(t):
    n = int(input())
    print(f[n-1])