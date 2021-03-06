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
    for (int t=1;t<=tc;t++) {
        int n;
        cin >> n;
        priority_queue<int,vector<int>,greater<int>> p;
        int ans=0;
        cout << "Case #" << t << ": ";
        for (int i=1;i<=n;i++) {
            int x;
            cin >> x;
            p.push(x);
            if (p.top() <= ans) p.pop();
            if (p.size() >= ans+1) ans++;
            cout << ans << " ";
        }
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}