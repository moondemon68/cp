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
        int a[n+5];
        for (int i=1;i<=n;i++) cin >> a[i];
        priority_queue<pair<int,int>> p;
        vector<int> ans;
        for (int i=1;i<=n;i++) p.push({a[i],i});
        ans.pb(p.top().se);
        pii tmp=p.top();
        p.pop();
        p.push({tmp.fi-1,tmp.se});
        bool y=1;
        while (!p.empty()) {
            cout << p.top().fi << " " << p.top().se << endl;
            while (p.top().fi == 0) p.pop();
            if (p.top().se == ans.back()) {
                tmp = p.top();
                p.pop();
                if (p.empty()) {
                    y=0;
                    break;
                } else {
                    pii tmp2 = p.top();
                    ans.pb(tmp2.se);
                    p.pop();
                    p.push({tmp2.fi-1,tmp2.se});
                    p.push(tmp);
                }
            } else {
                tmp = p.top();
                ans.pb(tmp.se);
                p.pop();
                p.push({tmp.fi-1,tmp.se});
            }
        }
        if (y) cout << "true" << endl;
        else cout << "false" << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}