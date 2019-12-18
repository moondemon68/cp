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
    int n;
    cin >> n;
    int a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    int ans=0;
    int x=1;
    while (x<=n) {
        int p=n;
        for (int i=x;i<=n;i++) {
            if (a[i]<a[x]) {
                p=i;
                break;
            }
        }
        int maxi=0,maks=0;
        for (int i=x;i<=p;i++) {
            if (a[i]>=maks) {
                maks=a[i];
                maxi=i;
            }
        }
        ans++;
        x=maxi+1;
    }
    cout << ans << endl;
    
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}