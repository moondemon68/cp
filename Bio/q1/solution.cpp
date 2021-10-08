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
    ifstream cin("2.txt");
    ofstream cout("2out.txt");
    int tc;
    cin >> tc;
    while (tc--) {
        int n, l;
        cin >> n >> l;
        string a[n+5];
        for (int i=1;i<=n;i++) cin >> a[i];
        int x = 0;
        map<string,int> m;
        vector<int> ans;
        for (int i=0;i<l;i++) {
            string s = "";
            for (int j=1;j<=n;j++) s += a[j][i];
            if (m[s] == 0) m[s] = ++x;
            ans.pb(m[s]);
        }
        cout << x << endl;
        for (auto p : ans) cout << p << " ";
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}