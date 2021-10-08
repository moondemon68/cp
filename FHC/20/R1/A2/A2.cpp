#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<LL,LL>
#define LL long long
using namespace std;

LL seedL[1000005], seedH[1000005], seedW[1000005];
LL l[1000005], h[1000005], r[1000005], w[1000005];
int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // ifstream cin("perimetric_chapter_1_input.txt");
    // ofstream cout("perimetric_chapter_1_output.txt");

    LL tc;
    cin >> tc;
    for (LL t=1;t<=tc;t++) {
        vector<int> v;
        LL n,k;
        cin >> n >> k;
        for (LL i=1;i<=k;i++) cin >> seedL[i];
        LL seedA, seedB, seedC, seedD;
        cin >> seedA >> seedB >> seedC >> seedD;
        for (LL i=1;i<=k;i++) l[i] = seedL[i];
        for (LL i=k+1;i<=n;i++) {
            l[i] = ((seedA * l[i-2] + seedB * l[i-1] + seedC) % seedD) + 1;
        }
        for (LL i=1;i<=k;i++) cin >> seedW[i];
        cin >> seedA >> seedB >> seedC >> seedD;
        for (LL i=1;i<=k;i++) {
            w[i] = seedW[i];
            r[i] = l[i]+w[i];
        }
        for (LL i=k+1;i<=n;i++) {
            w[i] = ((seedA * w[i-2] + seedB * w[i-1] + seedC) % seedD) + 1;
            r[i] = l[i]+w[i];
        }
        for (LL i=1;i<=k;i++) cin >> seedH[i];
        cin >> seedA >> seedB >> seedC >> seedD;
        for (LL i=1;i<=k;i++) h[i] = seedH[i];
        for (LL i=k+1;i<=n;i++) {
            h[i] = ((seedA * h[i-2] + seedB * h[i-1] + seedC) % seedD) + 1;
        }

        // INPUT DEBUG
        cout << "REAL INPUT" << endl;
        cout << n << " " << k << endl;
        cout << "L: ";
        for (LL i=1;i<=n;i++) {
            cout << l[i] << " ";
        }
        cout << endl;
        cout << "R: ";
        for (LL i=1;i<=n;i++) {
            cout << r[i] << " ";
        }
        cout << endl;
        // cout << "W: ";
        // for (LL i=1;i<=n;i++) {
        //     cout << w[i] << " ";
        // }
        // cout << endl;
        cout << "H: ";
        for (LL i=1;i<=n;i++) {
            cout << h[i] << " ";
        }
        cout << endl;

        // Real calc
        // cout << "DEBUG" << endl;
        LL ans = 1, sum = 0;
        set<pair<pii,pii>> s;
        for (int i=1;i<=n;i++) {
            pair<pii,pii> cur = {{l[i], r[i]},{h[i], h[i]}};
            bool udah = 0;
            for (auto it = s.begin(); it != s.end(); it++) {
                pair<pii,pii> now = *it;
                if (next(it, 1) == s.end()) {   // ujung kanan
                    if (now.fi.se >= cur.fi.fi && now.fi.fi <= cur.fi.fi) {
                        s.erase(it);
                        udah = 1;
                        s.insert({{min(now.fi.fi, cur.fi.fi), max(now.fi.se, cur.fi.se)},{now.se.fi, cur.se.se}});
                    }   
                    break;
                }
                if (now.fi.fi >= cur.fi.fi && now.fi.se <= cur.fi.se) { // now di dalem cur
                    s.erase(it++);
                    cout << "HALO" << endl;
                    continue;
                }
                pair<pii,pii> now2 = *next(it, 1);
                if (now.fi.se >= cur.fi.fi && now.fi.fi <= cur.fi.fi && now2.fi.fi <= cur.fi.se) {
                    s.erase(it);
                    s.erase(next(it, 1));
                    udah = 1;
                    s.insert({{min(now.fi.fi, cur.fi.fi), max(now2.fi.se, cur.fi.se)}, {now.se.fi, now2.se.se}});
                }
            }
            if (!udah) s.insert(cur);
            for (auto it = s.begin(); it != s.end(); it++) {
                pair<pii,pii> now = *it;
                cout << now.fi.fi << " " << now.fi.se << " " << now.se.fi << " " << now.se.se << endl;
            }
            cout << endl;
        }

        cout << "Case #" << t << ": " << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}