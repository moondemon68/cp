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
        int n;
        cin >> n;
        vector<string> v;
        for (int i=1;i<=n;i++) {
            string s;
            cin >> s;
            v.pb(s);
        }
        int ans=0;
        for (int i=0;i<v.size();i++) {
            for (int j=i+1;j<v.size();j++) {
                if (v[i] == v[j]) {
                    ans++;
                    for (int k=0;k<=9;k++) {
                        string x = v[j];
                        x[0] = k + '0';
                        bool y = 0;
                        for (int l=0;l<v.size();l++) {
                            if (x == v[l]) y = 1;
                        }
                        if (!y) {
                            v[j] = x;
                            break;
                        }
                    }
                }
            }
        }
        cout << ans << endl;
        for (int i=0;i<v.size();i++) cout << v[i] << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}