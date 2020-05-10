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
        set<int> s;
        int cnt[n+5];
        memset (cnt,0,sizeof(cnt));
        for (int i=1;i<=n;i++) {
            int x;
            cin >> x;
            s.insert(x);
            cnt[x]++;
        }
        vector<pii> a;
        for (int i=1;i<=n;i++) {
            if (cnt[i] > 0) a.pb({cnt[i], i});
        }
        int ans = 0;
        sort(a.begin(), a.end());
        for (int i=0;i<a.size();i++) {
            a[i].fi--;
            if (a.back().fi >= (i+1)) ans = i+1;
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}