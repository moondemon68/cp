//Prima
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

bitset<1000005> prima;
vector<int> p;  //bil. prima (OPTIONAL)

void sieve(int x) {
    prima.set();
    prima[0]=0;
    prima[1]=0;
    for (int i=2;i*i<=x;i++) {
        for (int j=i*i;j<=x;j+=i) {
            prima[j]=0;
        }
    }
    //masukin bilangan prima ke vector p (OPTIONAL)
    for (int i=2;i<=x;i++) {
        if (prima[i]) p.pb(i);
    }
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin >> n >> k;
    sieve(1000005);
    for (int i=0;i<n;i++) {
        cout << p[i*k] << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}