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
        for (int i=1;i<=n;i++) {
            cin >> a[i];
        }
        int cnt[n+5];
        memset (cnt,0,sizeof(cnt));
        for (int i=1;i<=n;i++) {
            cnt[a[i]]++;
        }
        vector<int> p;
        for (int i=1;i<=n;i++) {
            if (cnt[i]>0) {
                p.pb(cnt[i]);
            }
        }
        sort (p.begin(),p.end());
        reverse(p.begin(),p.end());
        int ans=0,maxi=p[0];
        for (int i=0;i<p.size();i++) {
            //cout << p[i] << " " << maxi << endl;
            if (p[i]>=maxi) {
                if (maxi>=0) ans+=maxi;
                maxi--;
            } else {
                ans+=p[i];
                maxi=p[i]-1;
            }
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}