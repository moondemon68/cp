x,k,d = input().split()

x = int(x)
k = int(k)
d = int(d)
req = x//d

if req >= k:
    print(abs(x-k*d))
else:
    f = k-req
    if f%2 == 0:
        print(abs(x-req*d))
    else:
        print(abs(x-req*d-d))