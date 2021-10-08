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
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        int cnt[105];
        memset (cnt,0,sizeof(cnt));
        for (int i=1;i<=n;i++) {
            int x;
            cin >> x;
            cnt[x]++;
        }
        int mex1 = 0, mex2 = 0;
        for (int i=0;i<=n;i++) {
            if (cnt[i] > 0) {
                cnt[i]--;
                mex1++;
            } else break;
        }
        for (int i=0;i<=n;i++) {
            if (cnt[i] > 0) {
                cnt[i]--;
                mex2++;
            } else break;
        }
        // cout << mex1 << " " << mex2 << endl;
        cout << mex1 + mex2 << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}