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
    cin >> n >> k;
    int a[105];
    for (int i=1;i<=n;i++) cin >> a[i];
    int ans=0;
    for (int i=1;i<=n;i++) {
        int neg=0,pos=0;
        for (int j=1;j<=n;j++) {
            if ((j-i)%k==0) continue;
            if (a[j]==1) pos++; else neg++; 
        }
        ans=max(ans,abs(neg-pos));
    }    
    cout << ans << endl;
    return 0;
}
