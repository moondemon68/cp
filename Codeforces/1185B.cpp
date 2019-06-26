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
        string s,t;
        cin >> s >> t;
        s+='*';
        t+='*';
        int cnt=1;
        vector<pair<int,char>> a,b;
        for (int i=0;i<s.size()-1;i++) {
            if (s[i]!=s[i+1]) {
                a.pb(mp(cnt,s[i]));
                cnt=1;
            } else cnt++;
        }
        for (int i=0;i<t.size()-1;i++) {
            if (t[i]!=t[i+1]) {
                b.pb(mp(cnt,t[i]));
                cnt=1;
            } else cnt++;
        }
        if (a.size()!=b.size()) {
            cout << "NO" << endl;
            continue;
        }
        bool y=1;
        for (int i=0;i<a.size();i++) {
            if (a[i].se!=b[i].se) {
                y=0;
                break;
            } else {
                if (a[i].fi>b[i].fi) {
                    y=0;
                    break;
                }
            }
        }
        if (y) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}