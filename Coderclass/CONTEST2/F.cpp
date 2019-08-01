#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<int,int>
#define LL long long
using namespace std;

const int M = 1e9+9;
const int N = 5e5+5;
long long pre[N];
long long erp[N];

long long egcd(long long a, long long b, long long &x, long long &y){
    if(a == 0){
        x = 0, y = 1;
        return b;
    }
    long long x1,y1;
    long long d = egcd(b%a,a,x1,y1);
    x = y1 - (b/a) * x1;
    y = x1;
    return d;
}

long long inv(long long a, long long b){
    long long x,y;
    egcd(a,b,x,y);
    return (x%b + b)%b;
}

long long C(int a, int b){
    a--, b--;
    long long ret = 1;
    ret *= pre[a]; ret %= M;
    ret *= erp[b]; ret %= M;
    ret *= erp[a-b]; ret %= M;
    return ret;
}

long long F(long long x1, long long y1, long long x2, long long y2){
    long long rx1 = x1 + 1; long long ry1 = y1;
    long long rx2 = x2 + 1 + 1; long long ry2 = y2 + 1;
    //cerr << rx2 << " " << ry2 << " => " << C(rx2,ry2) << " and " << rx1 << " " << ry1 << " => " << C(rx1,ry1) << '\n';
    long long ret = C(rx2, ry2) - C(rx1,ry1);
    return (ret%M + M)%M;
}

long long D(long long n, long long m, long long l, long long r){
    long long x1 = n-1, y1 = n-m + 1;
    long long x2 = n-1+l-1, y2 = n-m+l;
    long long ret = F(x1,y1,x2,y2);
    //cerr << x1 << " " << y1 << " " << x2 << " " << y2 << " => " << ret << '\n';
    //cerr << '\n';
    x1 = n+r-1, y1 = n-m+1;
    x2 = n+l-1+r-1, y2 = n-m+l;
    long long ret2 = F(x1,y1,x2,y2);
    //cerr << x1 << " " << y1 << " " << x2 << " " << y2 << " ==> " << ret2 << '\n';
    ret2 -= ret;
    return (ret2 % M + M)%M;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    pre[0] = 1;
    erp[0] = inv(pre[0],M);
    for(int i=1;i<=N-5;i++){
        pre[i] = pre[i-1] * i;
        pre[i] %= M;
        erp[i] = inv(pre[i],M);
    }

    int tc;
    cin >> tc;
    while(tc--){
        int n,m,l,r;
        cin >> n >> m >> l >> r;
        cout << D(n,m,l,r) << '\n';
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}