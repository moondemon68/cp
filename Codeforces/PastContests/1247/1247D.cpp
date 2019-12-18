#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<int,int>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin >> n >> k;
    LL a[n+5];
    for (int i=1;i<=n;i++) {
        cin >> a[i];
    }
    LL c[100005];
    memset (c,0,sizeof(c));
    for (int i=1;i<=n;i++) c[a[i]]++;
    vector<LL> poss;
    for (int i=1;i<=100000;i++) {
        LL x=1, cnt=0;
        for (int j=1;j<=k;j++) {
            x *= i;
            if (x > 10000000000) break;
            cnt++;
        }
        if (cnt == k) poss.pb(x);
    }
    // for (int i=0;i<poss.size();i++) cout << poss[i] << " ";
    // for (int i=1;i<=100000;i++) {
    //     if (c[i] > 0) cout << i << " " << c[i] << endl; 
    // }
    LL ans=0;
    for (int i=1;i<=100000;i++) {
        if (c[i] > 0) {
            // cout << i <<  " " << c[i] << " ";
            LL add = 0;
            for (int j=0;j<poss.size();j++) {
                LL tmp = poss[j] / i;
                if (poss[j]%i != 0 || tmp > 100000 || c[i]==0 || c[poss[j]/i]==0) continue;
                // cout << "* " << c[poss[j]/i] <<  " "<< c[i] << endl;
                if (poss[j]/i != i) add += c[poss[j]/i] * c[i];
                else add += c[i] * (c[i]-1);
            }
            ans += add;
            // if (add > 0) cout << add << endl;
        }
    }
    cout << ans/2 << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}