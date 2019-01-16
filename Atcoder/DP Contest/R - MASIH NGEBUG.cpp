//BUG: Entah knp dpt jwbn 2xnya yg bener
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

struct Matrix{
    LL x[55][55];
};

int n;

Matrix mult(Matrix a,Matrix b) {
    Matrix ret;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            for (int k=1;k<=n;k++) {
                ret.x[i][j]+=a.x[i][k]*b.x[k][j];
                ret.x[i][j]%=MOD;
            }
        }
    }
    return ret;
}

Matrix matpow(Matrix a,LL k) {
    Matrix ans;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            ans.x[i][j]=(i==j);
        }
    }
    while (k) {
        if (k%2==1) ans=mult(ans,a);
        a=mult(a,a);
        k/=2; 
    }
    return ans;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL k;
    cin >> n >> k;
    Matrix a;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) cin >> a.x[i][j];
    }
    Matrix ans=matpow(a,k);
    LL answer=0;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            //cout << ans.x[i][j];
            answer+=ans.x[i][j];
            answer%=MOD;
        }
    }
    cout << answer << endl;
    return 0;
}
