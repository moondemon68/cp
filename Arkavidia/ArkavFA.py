n=int(input())
a=[input().split() for i in range(n)]
x=[0 for i in range(n)]
y=[0 for i in range(n)]
for i in range(n):
    x[i]=int(a[i][0])
    y[i]=int(a[i][1])

c=x[i]+y[i]
c//=2

def cmp(v):
    return abs(c-v)

x=sorted(x,key=cmp)
for j in range(n):
    for i  in range(n):
        if (int(x[i])==int(a[j][0])):
            print(i+1)
