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
    int a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    int cnt[105];
    memset (cnt,0,sizeof(cnt));
    for (int i=1;i<=n;i++) cnt[a[i]]++;
    int ans=0;
    for (int i=1;i<=100;i++) ans=max(ans,cnt[i]);
    ans=(ans+k-1)/k*k;
    int d=ans;
    ans=0;
    for (int i=1;i<=100;i++) {
      if (cnt[i]>0) ans+=d-cnt[i];
    }
    cout << ans << endl;
    return 0;
}
