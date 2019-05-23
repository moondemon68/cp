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
    int x[n+5],h[n+5];
    for (int i=1;i<=n;i++) cin >> x[i] >> h[i];
    x[n+1]=INT_MAX;
    int ans=1,p=x[1];
    for (int i=2;i<=n;i++) {
        if (x[i]-h[i]>p) {
            ans++;
            p=x[i];
        } else if (x[i]+h[i]<x[i+1]) {
            ans++;
            p=x[i]+h[i];
        } else p=x[i];
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}