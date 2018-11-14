n=int(input());
a=list(map(str,input().split()))
y=1
for i in range(n):
    if (a[i]=='mumble'):
        continue
    else:
        if (int(a[i])!=i+1):
            y=0
if (y==1):
    print("makes sense")
else:
    print("something is fishy")
