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
    LL h;
    int n;
    cin >> h >> n;
    LL d[n+5];
    for (int i=1;i<=n;i++) cin >> d[i];
    LL sum=0;
    for (int i=1;i<=n;i++) sum+=d[i];
    LL ans=0,th=h;
    for (int i=1;i<=n;i++) {
        th+=d[i];
        ans++;
        if (th<=0) {
            cout << ans << endl;
            return 0;
        } 
    }
    if (sum>=0) {
        cout << -1 << endl;
        return 0;
    }
    ans=0;
    d[0]=0;
    for (int i=1;i<=n;i++)  {
        d[i]+=d[i-1];
    }
    LL mini=12345678987654321;
    for (int i=1;i<=n;i++) {
        cout << d[i] << " ";
        mini=min(mini,d[i]);   
    }
    h+=mini;
    ans=h/sum*n;
    ans*=-1;
    cout << ans/n*sum << endl;
    h=h+ans/n*sum-mini;
    cout << h << endl;
    if (h<=0) {
        cout << ans << endl;
        return 0;
    }
    for (int i=1;i<=n;i++) {
        ans++;
        if (h+d[i]<=0) {
            cout << ans << endl;
            return 0;
        } 
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}