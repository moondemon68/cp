#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

LL f[100005], g[100005], h[100005];
int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    f[1]=1;
    f[2]=2;
    f[3]=2;
    for (int i=4;i<=100000;i++) {
        f[i] = f[i-1] * (i-2);
        f[i] %= MOD;
    }
    g[1]=1;
    for (int i=2;i<=100000;i++) {
        g[i] = g[i-1] * 2;
        g[i] %= MOD;
    }
    h[1]=0;
    h[2]=0;
    h[3]=0;
    h[4]=4;
    for (int i=5;i<=100000;i++) {
        h[i] = h[i-1] * 2;
        h[i] %= MOD;
    }
    while (tc--) {
        int n;
        cin >> n;
        // int a[n+5];
        // for (int i=1;i<=n;i++) cin >> a[i];
        // bool y=1;
        // for (int i=1;i<n;i++) {
        //     if (a[i+1]-a[i] != 1) y=0;
        // }
        // if (y) {
        //     cout << g[n] << endl;
        //     continue;
        // }
        // y = 1;
        // for (int i=1;i<=n;i++) {
        //     if ((i == 1 && a[i] != 0) || (i != 1 && a[i] != n-1)) y = 0;
        // }
        // if (y) {
        //     cout << f[n] << endl;
        //     continue;
        // }
        // y = 1;
        // for (int i=1;i<=n;i++) {
        //     if (a[i] < i - 1) y = 0;
        // }
        // if (y) {
        //     cout << h[n] << endl;
        //     continue;
        // }
        // cout << 0 << endl;

        int a[n+5];
        for (int i=1;i<=n;i++) a[i]=i;
        vector<string> ss;
        int ans=0;
        do {
            int maxa[n+5],mini[n+5];
            maxa[0]=INT_MIN, mini[0]=INT_MAX;
            for (int i=1;i<=n;i++) {
                maxa[i] = max(maxa[i-1], a[i]);
                mini[i] = min(mini[i-1], a[i]);
            }
            bool y=1;
            string s;
            for (int i=1;i<=n;i++) {
                if ((maxa[i] - mini[i] != 0 && i == 1) || (maxa[i] - mini[i] != n-1 && i > 1)) y=0;
                s+=maxa[i]-mini[i]+'0';
            }
            ss.pb(s);
            if (y) ans++;
        } while (next_permutation(a+1,a+n+1));
        sort (ss.begin(), ss.end());
        ss.pb("*");
        int cnt = 0;
        int b[n+5];
        for (int i=0;i<n;i++) b[i] = i;
        for (int i=0;i<ss.size()-1;i++) {
            if (ss[i] != ss[i+1]) {
                cnt++;
                int cp = 0;
                for (int j=0;j<n-1;j++) {
                    if ((ss[i][j]-'0') < (ss[i][j+1]-'0') && (ss[i][j]-'0' == b[j])) cp++;
                }
                cout << ss[i] << " " << cnt <<  " " << cp << endl;
                cnt = 0;
            } else {
                cnt++;
            }
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}

// 0 n-1 n-1 n-1 ... --> 1,2,2,4,12,48,240,1440,10080
// 0 1 2 3 4 ... -->     1,2,4,8,16,32,64,128
// sisanya -->           0,0,0,4,8,16