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
    double a[200005];
    for (int i=1;i<=n;i++) cin >> a[i]; 
    sort (a+1,a+n+1);
    bool y=1;
    double ans=124897595;
    for (int i=1;i<=n;i++) {
        if (a[i]/(double)i>1) y=0;
        ans=min(ans,a[i]/i); 
    }   
    if (y) cout << ans << endl; else cout << "impossible" << endl;
    return 0;
}
