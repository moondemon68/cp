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
    for (int t=1;t<=tc;t++) {
        int n,k;
        cin >> n >> k;
        int a[n+5],b[n+5];
        for (int i=1;i<=n;i++) cin >> a[i];
        for (int i=1;i<=n;i++) cin >> b[i];
        int ans=0;
        for (int l=1;l<=n;l++) {
            for (int r=l;r<=n;r++) {
                int maxa=0,maxb=0;
                for (int k=l;k<=r;k++) {
                    maxa=max(maxa,a[k]);
                    maxb=max(maxb,b[k]);
                }
                if (abs(maxa-maxb)<=k) ans++;
            }
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}