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
    int m;
    cin >> m;
    int b[m+5];
    for (int i=1;i<=m;i++) cin >> b[i];
    sort (a+1,a+n+1);
    sort (b+1,b+m+1);
    int ans=0;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (abs(a[i]-b[j])<=1) {
                //cout << a[i] << " " << b[j] << endl;
                b[j]=-1000;
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}