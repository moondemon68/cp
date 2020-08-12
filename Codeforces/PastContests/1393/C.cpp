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
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        int c[n+5];
        memset (c,0,sizeof(c));
        for (int i=1;i<=n;i++) {
            int x;
            cin >> x;
            c[x]++;
        }
        vector<int> v;
        for (int i=1;i<=n;i++) {
            if (c[i] > 0) v.pb(c[i]);
        }
        sort (v.begin(), v.end());
        reverse (v.begin(), v.end());

        if (v.size() == 1) {
            cout << 0 << endl;
            continue;
        }
        int cnt = 0, maxi=0;
        for (int i=0;i<v.size();i++) {
            if (v[i] == v[0]) cnt++;
        }
        cout << (n-v[0]*cnt)/(v[0]-1)+cnt-1 << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}