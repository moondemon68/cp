#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

LL poww(LL a, LL b) {
    if (b==0) return 1;
    if (b==1) return a;
    if (b%2==0) return (poww(a,b/2)*poww(a,b/2))%MOD;
    else return ((poww(a,b/2)*poww(a,b/2))%MOD * (a%MOD))%MOD;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n,m;
    cin >> n >> m;
    cout << poww(poww(2,m)-1,n) << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}