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

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // ifstream cin("capastaty_input.txt");
    // ofstream cout("capastaty_output.txt");

    LL tc;
    cin >> tc;
    for (LL t=1;t<=tc;t++) {
        int n; double p;
        cin >> n >> p;
        double q = 1-p;
        
        double ans[n+5];
        memset (ans,0,sizeof(ans));

        // i == 2
        for (int i=1;i<=n;i++) ans[i] += 1;

        // level
        for (int i=3;i<=n;i++) {
            double pembagi = i*(i-1)/2;
            double curp = pembagi;
            double curq = pembagi - n + 1;
            for (int j=n;j>=1;j--) {
                ans[j] += (p * curp/pembagi + q * curq/pembagi);
                curp -= p;
                curq += p;
            }
        }

        cout << "Case #" << t << ": " << endl;
        for (int i=1;i<=n;i++) cout << fixed << setprecision(10) << ans[i] << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}