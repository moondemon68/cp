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

LL seedS[1000005], seedX[1000005], seedY[1000005];
LL s[1000005], x[1000005], y[1000005];

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ifstream cin("capastaty_input.txt");
    ofstream cout("capastaty_output.txt");

    LL tc;
    cin >> tc;
    for (LL t=1;t<=tc;t++) {
        LL n,k;
        cin >> n >> k;
        for (LL i=1;i<=k;i++) cin >> seedS[i];
        LL seedA, seedB, seedC, seedD;
        cin >> seedA >> seedB >> seedC >> seedD;
        for (LL i=1;i<=k;i++) s[i] = seedS[i];
        for (LL i=k+1;i<=n;i++) {
            s[i] = ((seedA * s[i-2] + seedB * s[i-1] + seedC) % seedD);
        }

        for (LL i=1;i<=k;i++) cin >> seedX[i];
        cin >> seedA >> seedB >> seedC >> seedD;
        for (LL i=1;i<=k;i++) x[i] = seedX[i];
        for (LL i=k+1;i<=n;i++) {
            x[i] = ((seedA * x[i-2] + seedB * x[i-1] + seedC) % seedD);
        }

        for (LL i=1;i<=k;i++) cin >> seedY[i];
        cin >> seedA >> seedB >> seedC >> seedD;
        for (LL i=1;i<=k;i++) y[i] = seedY[i];
        for (LL i=k+1;i<=n;i++) {
            y[i] = ((seedA * y[i-2] + seedB * y[i-1] + seedC) % seedD);
        }
        // ngubah y jadi x+y
        for (LL i=1;i<=n;i++) {
            y[i] += x[i];
        }

        // INPUT DEBUG
        // cout << "REAL INPUT" << endl;
        // cout << "N: " << n << " K: " << k << endl;
        // cout << "S: ";
        // for (LL i=1;i<=n;i++) {
        //     cout << s[i] << " ";
        // }
        // cout << endl;
        // cout << "X: ";
        // for (LL i=1;i<=n;i++) {
        //     cout << x[i] << " ";
        // }
        // cout << endl;
        // cout << "Y: ";
        // for (LL i=1;i<=n;i++) {
        //     cout << y[i] << " ";
        // }
        // cout << endl;

        // Real calc
        // cout << "DEBUG" << endl;
        LL ans = 0;

        stack<pii> kurang, lebih;
        stack<pii> aman;    // batas bawah, atas

        for (LL i=1;i<=n;i++) {
            if (s[i] < x[i]) kurang.push({x[i]-s[i], i});
            else if (s[i] > y[i]) lebih.push({s[i]-y[i], i});
            // else aman.push({s[i]-x[i], y[i]-s[i]});
        }

        // resolve kurang sama lebih dulu
        while (!kurang.empty() && !lebih.empty()) {
            LL curK = kurang.top().fi;
            LL idxK = kurang.top().se;
            kurang.pop();
            LL curL = lebih.top().fi;
            LL idxL = lebih.top().se;
            lebih.pop();
            LL gerak = min(curK, curL);
            ans += gerak;
            s[idxK] += gerak;
            s[idxL] -= gerak;
            LL newK = curK - gerak;
            LL newL = curL - gerak;
            if (newK > 0) kurang.push({newK, idxK});
            if (newL > 0) lebih.push({newL, idxL});
        }

        // bikin aman
        for (int i=1;i<=n;i++) {
            if (x[i] <= s[i] && s[i] <= y[i]) aman.push({s[i]-x[i], y[i]-s[i]});
        }

        // kurang doang
        while (!kurang.empty() && !aman.empty()) {
            LL curK = kurang.top().fi;
            kurang.pop();
            LL curL = aman.top().fi;
            aman.pop();
            LL gerak = min(curK, curL);
            ans += gerak;
            LL newK = curK - gerak;
            LL newL = curL - gerak;
            if (newK > 0) kurang.push({newK, 0});
            if (newL > 0) aman.push({newL, 0});
        }

        // lebih doang
        while (!lebih.empty() && !aman.empty()) {
            LL curK = lebih.top().fi;
            lebih.pop();
            LL curL = aman.top().se;
            aman.pop();
            LL gerak = min(curK, curL);
            ans += gerak;
            LL newK = curK - gerak;
            LL newL = curL - gerak;
            if (newK > 0) lebih.push({newK, 0});
            if (newL > 0) aman.push({0, newL});
        }

        if (!kurang.empty() || !lebih.empty()) ans = -1;

        cout << "Case #" << t << ": " << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}