// DP Matrix Exponentiation
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

struct matrix{
    LL v[105][105];
    matrix(){}
};

matrix mul(matrix a,matrix b,int m) {
    matrix ans;
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=m;j++) {
            ans.v[i][j]=0;
            for (int k=1;k<=m;k++) {
                ans.v[i][j]+=((a.v[i][k]%MOD)*(b.v[k][j]%MOD))%MOD;
            }
        }
    }
    return ans;
}

matrix power(matrix a,LL x,int m) {
    matrix ret;
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=m;j++) {
            if (i==j) ret.v[i][j]=1;
            else ret.v[i][j]=0;
        }
    }
    while (x>0) {
        //cout << x;
        if (x&1) ret=mul(ret,a,m);
        x=x>>1;
        a=mul(a,a,m);
    }
    return ret;
}

LL fib(matrix a,LL n,int m) {
    if (n<m) return 1;
    matrix ans=power(a,n-1,m);
    return (ans.v[1][1]+ans.v[1][2])%MOD;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //for (int i=0;i<=10;i++) cout << fib(i) << endl;
    LL n;
    int m;
    cin >> n >> m;
    matrix a;
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=m;j++) {
            if (i==1&&(j==1||j==m)) a.v[i][j]=1;
            else if (i==j+1) a.v[i][j]=1;
            else a.v[i][j]=0;
            //cout << a.v[i][j];
        }
        //cout << endl;
    }
    LL ans=fib(a,n,m);
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}