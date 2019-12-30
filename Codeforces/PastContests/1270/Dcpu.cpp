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

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k,m;
    cin >> n >> k >> m;
    int a[10] = {321376743,64146243,670700897,575471266,303438330,113152943,114637600,468461998,868859319,744812570};
    for (int i=1;i<=n;i++) {
        vector<pii> p;
        for (int j=1;j<=k;j++) {
            int x;
            cin >> x;
            x--;
            p.pb({a[x], x});
        }
        sort (p.begin(), p.end());
        cout << p[m-1].se+1 << " " << p[m-1].fi << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}