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
    while (tc--) {
        int n,x;
        cin >> n >> x;
        int cnt[1005];
        memset (cnt,0,sizeof(cnt));
        for (int i=1;i<=n;i++) {
            int p;
            cin >> p;
            cnt[p]++;
        }
        int p = 1;
        while (x--) {
            while (1) {
                if (cnt[p] > 0) {
                    p++;
                    continue;
                } else {
                    cnt[p]++;
                    break;
                }
            }
        }
        for (int i=1;i<=500;i++) {
            if (cnt[i] == 0) {
                cout << i-1 << endl;
                break;
            }
        }
        
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}