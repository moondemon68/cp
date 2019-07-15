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

map<LL,LL> d;

LL fastpow(LL a,LL b) {
    if (b==0) return 1;
    else if (b==1) return a;
    else if (d[b]!=0) return d[b];
    else if (b%2==0) return d[b]=((fastpow(a,b/2)%MOD)*(fastpow(a,b/2)%MOD))%MOD;
    else return d[b]=(((fastpow(a,b/2)%MOD)*(fastpow(a,b/2)%MOD))%MOD*a)%MOD;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n;
    cin >> n;
    cout << fastpow(2,n)-1 << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}