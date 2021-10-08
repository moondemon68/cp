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
        vector<pii> ans;
        priority_queue<int> p;
        for (int i=1;i<=n;i++) p.push(i);
        while (p.size() > 1) {
            int x = p.top();
            p.pop();
            int y = p.top();
            p.pop();
            p.push((x+y+1)/2);
            ans.pb({x,y});
        }
        cout << p.top() << endl;
        for (int i=0;i<ans.size();i++) cout << ans[i].fi << " " << ans[i].se << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}