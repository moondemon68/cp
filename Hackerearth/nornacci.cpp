#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--) {
        int a,b,n;
        cin >> a >> b >> n;
        int x[n+5],e[n+5];
        x[1]=a; e[1]=a; x[2]=b; e[2]=b;
        for (int i=3;i<=n;i++) {
            x[i]=x[i-1]^x[i-2];
            cout << x[i] << " ";
        }
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}