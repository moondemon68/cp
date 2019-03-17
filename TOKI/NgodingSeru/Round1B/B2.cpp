#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

bool primaga[10000005];
vector<int> primes;
void sieve(int x) {
    memset (primaga,1,sizeof(primaga));
    for (int i=2;i*i<=x;i++) {
        for (int j=i*i;j<=x;j+=i) {
            primaga[j]=0;
        }
    }
    for (int i=2;i<=x;i++) {
        if (primaga[i]) primes.pb(i);
    }
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin >> n >> k;
    primes.pb(1);
    sieve(10000000);
    for (int i=1;i<(int)primes.size();i++) {
        primes[i]*=k;
    }
    for (int i=0;i<(int)primes.size();i++) {
        //cout << primes[i] << " ";
        if (primes[i]>n) {
            cout << i << endl;
            return 0;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}