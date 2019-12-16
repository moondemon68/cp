#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

bool v[1000005];

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    vector<int> ans;
    memset (v,0,sizeof(v));
    int cnt=0, p=0;
    set<int> s;
    for (int i=1;i<=n;i++) {
        if (a[i]>0) {
            if (v[a[i]]) {
                cout << -1 << endl;
                return 0;
            } else {
                if (s.find(a[i]) == s.end()) {
                    s.insert(a[i]);
                    v[a[i]] = 1;
                    cnt++;
                } else {
                    cout << -1 << endl;
                    return 0;
                }
            }
        } else {
            a[i]*=-1;
            if (v[a[i]]) {
                v[a[i]] = 0;
                cnt--;
            } else {
                cout << -1 << endl;
                return 0;
            }
        }
        p++;
        if (cnt == 0) {
            ans.pb(p);
            p=0;
            s.clear();
        }
    }
    int tot = 0;
    for (int i=0;i<ans.size();i++) tot+=ans[i];
    if (tot!=n) cout << -1 << endl;
    else {
        cout << ans.size() << endl;
        for (int i=0;i<ans.size();i++) cout << ans[i] << " ";
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}