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
    int n;
    cin >> n;
    int a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    int ans1=0, ans2=0;
    sort (a+1,a+n+1);
    bool b[n+5];
    memset (b,0,sizeof(b));
    for (int i=1;i<=n;i++) {
        int x = a[i];
        if (!b[x-1]) {
            b[x-1]=1;
        } else if (!b[x]) {
            b[x]=1;
        } else if (!b[x+1]) {
            b[x+1]=1;
        }
    }
    for (int i=0;i<=n+1;i++) {
        if (b[i]) ans2++;
    }
    memset (b,0,sizeof(b));
    for (int i=1;i<=n;i++) {
        b[a[i]]=1;
    }
    for (int i=1;i<=n;i++) {
        if (b[i]) {
            ans1++;
            i+=2;
        }
    }
    cout << ans1 << " " << ans2 << endl;;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}