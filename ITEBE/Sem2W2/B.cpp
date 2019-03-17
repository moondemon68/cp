// Fibonacci Matrix Exponentiation
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
    LL v[3][3];
    matrix(){}
};

matrix mul(matrix a,matrix b) {
    matrix ans;
    for (int i=1;i<=2;i++) {
        for (int j=1;j<=2;j++) {
            ans.v[i][j]=0;
            for (int k=1;k<=2;k++) {
                ans.v[i][j]+=(a.v[i][k]*b.v[k][j])%MOD;
            }
        }
    }
    return ans;
}

matrix power(matrix a,int x) {
    matrix ret;
    for (int i=1;i<=2;i++) {
        for (int j=1;j<=2;j++) {
            if (i==j) ret.v[i][j]=1;
            else ret.v[i][j]=0;
        }
    }
    while (x>0) {
        //cout << x;
        if (x&1) ret=mul(ret,a);
        x=x>>1;
        a=mul(a,a);
    }
    return ret;
}

LL fib(int x) {
    if (x==0) return 0;
    if (x==1) return 1;
    matrix f;
    f.v[1][1]=0;
    f.v[1][2]=1;
    f.v[2][1]=1;
    f.v[2][2]=1;
    matrix g=power(f,x-2);
    return (g.v[2][1]*1+g.v[2][2]*1)%MOD;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //for (int i=0;i<=10;i++) cout << fib(i) << endl;
    int tc;
    cin >> tc;
    while (tc--) {
        int l,r;
        cin >> l >> r;
        LL ans=fib(r+2)-fib(l+1);
        if (ans<0) ans+=MOD;
        cout << ans << endl; 
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}