import sys

# read 2 integers
x, y = map(int, input().split())
print(x+y)

# read array
a = list(map(int, input().split()))
tot = 0
for i in range(len(a)):
    tot += a[i]
print(tot)