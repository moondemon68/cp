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

vector<LL> p;
bool prime[1000005];
void sieve(LL x) {
    memset (prime,1,sizeof(prime));
    prime[1] = 0;
    for (LL i=2;i*i<=x;i++) {
        if (!prime[i]) continue;
        for (LL j=i*i;j<=x;j+=i) {
            prime[j] = 0;
        }
    }
    for (LL i=2;i<=x;i++) {
        if (prime[i]) p.pb(i);
    }
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieve(1000000);
    
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}