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

LL seedP[1000005], seedQ[1000005];
LL p[1000005], q[1000005];
int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ifstream cin("dislodging_logs_input.txt");
    ofstream cout("dislodging_logs_output.txt");

    LL tc;
    cin >> tc;
    for (LL t=1;t<=tc;t++) {
        LL n,m,k,s;
        cin >> n >> m >> k >> s;
        for (LL i=1;i<=k;i++) cin >> seedP[i];
        LL seedA, seedB, seedC, seedD;
        cin >> seedA >> seedB >> seedC >> seedD;
        for (LL i=1;i<=k;i++) p[i] = seedP[i];
        for (LL i=k+1;i<=n;i++) {
            p[i] = ((seedA * p[i-2] + seedB * p[i-1] + seedC) % seedD) + 1;
        }
        for (LL i=1;i<=k;i++) cin >> seedQ[i];
        cin >> seedA >> seedB >> seedC >> seedD;
        for (LL i=1;i<=k;i++) q[i] = seedQ[i];
        for (LL i=k+1;i<=m;i++) {
            q[i] = ((seedA * q[i-2] + seedB * q[i-1] + seedC) % seedD) + 1;
        }
        sort (p+1,p+n+1);
        sort (q+1,q+m+1);

        // INPUT DEBUG
        // cout << "REAL INPUT" << endl;
        // cout << n << " " << m << " " << k << " " << s << endl;
        // for (LL i=1;i<=n;i++) {
        //     cout << p[i] << " ";
        // }
        // cout << endl;
        // for (LL i=1;i<=m;i++) {
        //     cout << q[i] << " ";
        // }
        // cout << endl;

        // Real calc
        // cout << "DEBUG" << endl;
        LL l = 0, r = max(p[n], q[m]), ans = INT_MAX;
        while (l <= r) {
            LL mid = (l+r)/2;
            LL x = 0;
            for (LL i=1;i<=n;i++) {
                if (x == m) break;
                bool kiri = 0;
                LL palingKiri = INT_MAX;
                if (q[x+1] < p[i]) {
                    kiri = 1;
                    palingKiri = q[x+1];
                }
                if (kiri) {
                    while (1) {
                        if (x == m) break;
                        LL target = q[x+1];
                        LL move = 0;
                        if (target > p[i]) {
                            LL keKiri = abs(palingKiri-p[i]), keKanan = abs(target-p[i]);
                            if (keKiri <= keKanan) {
                                move = 2 * keKiri + keKanan;
                            } else {
                                move = 2 * keKanan + keKiri;
                            }
                        } else {
                            move = abs(palingKiri-p[i]);
                        }
                        if (move <= mid) x++;
                        else break;
                    }
                } else {
                    while (1) {
                        if (x == m) break;
                        LL move = q[x+1]-p[i];
                        if (move <= mid) x++;
                        else break;
                    }
                }
            }
            if (x == m) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        cout << "Case #" << t << ": " << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}