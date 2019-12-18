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
        queue<int> zz,zo,oz,oo;
        string a[n+5];
        set<string> s;
        for (int i=1;i<=n;i++) {
            cin >> a[i];
            s.insert(a[i]);
        }
        for (int i=1;i<=n;i++) {
            if (a[i].size() == 1) {
                if (a[i][0] == '0') zz.push(i);
                else oo.push(i);
            } else {
                if (a[i][0] == '0' && a[i][a[i].size()-1] == '0') zz.push(i);
                else if (a[i][0] == '0' && a[i][a[i].size()-1] == '1') zo.push(i);
                else if (a[i][0] == '1' && a[i][a[i].size()-1] == '0') oz.push(i);
                else if (a[i][0] == '1' && a[i][a[i].size()-1] == '1') oo.push(i);
            }
        }
        vector<int> ans;
        if (oo.size() > 0 && zz.size() > 0 && zo.size() + oz.size() == 0) {
            cout << -1 << endl;
        } else {
            if (zo.size() == oz.size() || zo.size() == oz.size() + 1 || oz.size() == zo.size() + 1) {
                cout << 0 << endl;
                cout << endl;
            } else if (zo.size() > oz.size()) {
                int x = zo.size(), y = oz.size();
                while (x > y + 1 && !zo.empty()) {
                    string p = a[zo.front()], q = a[zo.front()];
                    reverse(p.begin(), p.end());
                    if (s.find(p) == s.end()) {
                        s.erase(q);
                        s.insert(p);
                        x--;
                        y++;
                        ans.pb(zo.front());
                    }
                    zo.pop();
                }
                cout << ans.size() << endl;
                for (int i=0;i<ans.size();i++) cout << ans[i] << " ";
                cout << endl;
            } else {
                int x = zo.size(), y = oz.size();
                while (y > x + 1 && !oz.empty()) {
                    string p = a[oz.front()], q = a[oz.front()];
                    reverse(p.begin(), p.end());
                    if (s.find(p) == s.end()) {
                        s.erase(q);
                        s.insert(p);
                        y--;
                        x++;
                        ans.pb(oz.front());
                    }
                    oz.pop();
                }
                cout << ans.size() << endl;
                for (int i=0;i<ans.size();i++) cout << ans[i] << " ";
                cout << endl;
            }
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}