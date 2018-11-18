import sys
sys.stdin = open('C-large.in', 'r')
sys.stdout = open('C-ans.out', 'w')

tc=int(input())
MOD=1000000007
fa=[0 for i in range(300005)]
fa[0]=fa[1]=1

for i in range(2,300003):
    fa[i]=fa[i-1]*i

def c(n,r):
    return fa[n]//(fa[r]*fa[n-r])

for t in range(tc):
    n,m=[int(s) for s in input().split(" ")]
    ans=fa[2*n]
    for i in range(1,m+1):
        if (i%2!=m%2):
            #print(i*f(2*n-m+i-1)*(2**(m+1-i)))
            ans+=c(m,i-1)*fa[2*n-m+i-1]*(2**(m+1-i))
        else:
            #print(i*f(2*n-m+i-1)*(2**(m+1-i)))
            ans-=c(m,i-1)*fa[2*n-m+i-1]*(2**(m+1-i))
    print("Case #{}: {}".format(t+1, ans%MOD))
