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

LL seedL[1000005], seedH[1000005];
LL l[1000005], h[1000005];
int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ifstream cin("perimetric_chapter_1_input.txt");
    ofstream cout("perimetric_chapter_1_output.txt");

    LL tc;
    cin >> tc;
    for (LL t=1;t<=tc;t++) {
        LL n,k,w;
        cin >> n >> k >> w;
        for (LL i=1;i<=k;i++) cin >> seedL[i];
        LL seedA, seedB, seedC, seedD;
        cin >> seedA >> seedB >> seedC >> seedD;
        for (LL i=1;i<=k;i++) l[i] = seedL[i];
        for (LL i=k+1;i<=n;i++) {
            l[i] = ((seedA * l[i-2] + seedB * l[i-1] + seedC) % seedD) + 1;
        }
        for (LL i=1;i<=k;i++) cin >> seedH[i];
        cin >> seedA >> seedB >> seedC >> seedD;
        for (LL i=1;i<=k;i++) h[i] = seedH[i];
        for (LL i=k+1;i<=n;i++) {
            h[i] = ((seedA * h[i-2] + seedB * h[i-1] + seedC) % seedD) + 1;
        }

        // INPUT DEBUG
        // cout << "REAL INPUT" << endl;
        // cout << n << " " << k << " " << w << endl;
        // for (LL i=1;i<=n;i++) {
        //     cout << l[i] << " ";
        // }
        // cout << endl;
        // for (LL i=1;i<=n;i++) {
        //     cout << h[i] << " ";
        // }
        // cout << endl;

        // Real calc
        // cout << "DEBUG" << endl;
        LL ans = 1, sum = 0;
        LL startL = 0;
        LL heightSum = 0;
        LL perimeterBaru = 0;
        unordered_map<LL,LL> maxY; // height tiap Y
        unordered_map<LL,LL> heightSumUntilX;
        for (LL i=1;i<=n;i++) {
            if (i == 1 || l[i] > l[i-1] + w) { // putus
                sum += perimeterBaru;
                sum %= MOD;
                startL = l[i];
                heightSum = h[i] * 2;
                perimeterBaru = w * 2 + heightSum;
                for (LL j=startL;j<=startL+w;j++) {
                    if (j == startL+w) maxY[j] = 0; else maxY[j] = h[i];
                    heightSumUntilX[j] = h[i];
                }
                heightSumUntilX[l[i]+w] = h[i] * 2;
            } else { // nyambung
                perimeterBaru = (((l[i] + w) - startL)) * 2;
                heightSum = heightSumUntilX[l[i]-1];
                for (LL j=l[i];j<=l[i]+w;j++) {
                    if (j == l[i]+w) maxY[j] = 0; else maxY[j] = max(maxY[j], h[i]);
                    heightSum += abs(maxY[j]-maxY[j-1]);
                    heightSumUntilX[j] = heightSum;
                }
                perimeterBaru += heightSum;
            }
            // for (LL j=0;j<=20;j++) cout << maxY[j] << " ";
            // cout << endl;
            // for (LL j=0;j<=20;j++) cout << heightSumUntilX[j] << " ";
            // cout << endl;
            ans *= (perimeterBaru + sum) % MOD;
            ans %= MOD;
            // cout << perimeterBaru + sum << " ";
        }
        // cout << "HeightSumUntilX" << endl;
        cout << "Case #" << t << ": " << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}