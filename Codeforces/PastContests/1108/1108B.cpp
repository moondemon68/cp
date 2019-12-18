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
    int n;
    cin >> n;
    int d[n+5];
    for (int i=1;i<=n;i++) cin >> d[i];    
    sort (d+1,d+n+1);
    bool y[n+5];
    memset (y,0,sizeof(y));
    int x=d[n];
    for (int i=1;i<=n;i++) {
        if ((x%d[i]==0)&&(d[i]!=d[i+1])) y[i]=1;
    }
    int ans=0;
    for (int i=1;i<=n;i++) {
        if (!y[i]) ans=d[i];
    }
    cout << x << " " << ans << endl;
    return 0;
}
