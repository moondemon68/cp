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
    int n,a,b,c,d;
    cin >> n >> a >> b >> c >> d;
    int ans=0;
    for (int i=0;i<=n;i++) {
        for (int j=0;j<=n;j++) {
            for (int k=0;k<=n;k++) {
                if (i==0 && j==0 && k==0) continue;
                if (a*i+b*j+c*k==d*(i+j+k)) {
                    cout << i << " " << j << " " << k << endl;
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}