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
        int z=0,o=0;
        vector<int> p;
        for (int i=1;i<=n;i++) {
            string s;
            cin >> s;
            for (int j=0;j<s.size();j++) {
                if (s[j]=='0') z++; else o++;
            }
            p.pb(s.size());
        }
        sort (p.begin(),p.end());
        int ans=0;
        for (int i=0;i<p.size();i++) {
            while (z>=2 && p[i]>=2) {
                p[i]-=2;
                z-=2;
            }
            while (o>=2 && p[i]>=2) {
                p[i]-=2;
                o-=2;
            }
        }
        for (int i=0;i<p.size();i++) {
            if (p[i]==0) ans++;
            else {
                if (z && p[i]) {
                    z--;
                    p[i]--;
                } else if (o && p[i]) {
                    o--;
                    p[i]--;
                }
                if (p[i]==0) ans++;
            }
        }
        cout << ans << "\n";
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}