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
    int n,k,a;
    cin >> n >> k >> a;
    int t[n+5],s[n+5];
    for (int i=1;i<=n;i++) cin >> t[i] >> s[i];
    int ans=INT_MAX;
    for (int i=1;i<=n;i++) {
        int drunk=a*t[i];
        int ses=k/(a*t[i]);
        int left=k-ses*a*t[i];
        int x=(t[i]+s[i])*(k/(a*t[i]))+left/a;
        if (left==0) x-=s[i];
        //cout << x << endl;
        ans=min(ans,x);
    }    
    cout << ans << endl;
    return 0;
}
