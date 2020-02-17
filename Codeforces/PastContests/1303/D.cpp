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
    map<LL, LL> p;
    while (tc--) {
        LL n, m;
        cin >> n >> m;
        LL tn = n;
        LL cnt = 0;
        for (LL i=1;i<1152921504606846976;i*=2) {
            p[i] = cnt;
            cnt++;
        }
        LL need[65];
        memset (need, 0, sizeof(need));
        string s = "";
        while (s.size() < 60) {
            if (n%2 == 0) {
                s += '0';
            } else {
                s += '1';
            }
            n /= 2;
        }
        for (LL i=0;i<60;i++) {
            need[i] = s[i]-'0';
        }
        LL have[65];
        memset (have,0,sizeof(have));
        LL tot = 0;
        for (int i=1;i<=m;i++) {
            LL x;
            cin >> x;
            tot += x;
            have[p[x]]++;
        }
        if (tot < tn) {
            cout << -1 << endl;
            continue;
        }
        LL ans = 0;
        for (LL i=0;i<60;i++) {
            if (need[i] == 1 && have[i] == 0) {
                LL x = 1;
                for (LL j=i+1;j<60;j++) {
                    if (have[j] != 0) {
                        for (LL k=j;k>i;k--) {
                            ans++;
                            have[k]--;
                            have[k-1] += 2;
                        }
                        break;
                    }
                }
            }
            if (need[i] == 1 && have[i] > 0) {
                need[i] = 0;
                have[i]--;
            }
            if (need[i] == 0) {
                have[i+1] += have[i]/2;
            }
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}