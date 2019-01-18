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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    while (cin >> n >> k) {
        int cnt[500];
        memset (cnt,0,sizeof(cnt));    
        for (int i=2;i<=n;i++) {
            int x=i,y=2;
            while (x>1) {
                if (x%y==0) {
                    x/=y;
                    cnt[y]++;
                } else y++;
            }
        }
        for (int i=2;i<=k;i++) {
            int x=i,y=2;
            while (x>1) {
                if (x%y==0) {
                    x/=y;
                    cnt[y]--;
                } else y++;
            }
        }
        for (int i=2;i<=n-k;i++) {
            int x=i,y=2;
            while (x>1) {
                if (x%y==0) {
                    x/=y;
                    cnt[y]--;
                } else y++;
            }
        }
        LL ans=1;
        for (int i=1;i<=470;i++) {
            ans*=cnt[i]+1;
        }
        cout << ans << endl;
    }
    return 0;
}
