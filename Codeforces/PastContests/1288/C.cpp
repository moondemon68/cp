#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

LL f[100005];
 
LL fpow(LL a, LL b) {
	LL res = 1;
	while (b) {
		if (b&1) {
			res = res*a;
			res %= MOD;
		} 
		b /= 2;
		a = a*a;
		a %= MOD;
	}
	return res;
}
 
LL inv(LL a) {
	return fpow(a, MOD-2);
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    f[0] = 1;
	for (LL i=1;i<=100000;i++) f[i]=(f[i-1]*i)%MOD;
    LL n,m;
    cin >> n >> m;
    LL ans = 1;
    for (int i=n;i<=n+2*m-1;i++) {
        ans *= i;
        ans %= MOD;
    }
    // cout << ans << endl;
    ans *= inv(f[2*m]);
    ans %= MOD;
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}