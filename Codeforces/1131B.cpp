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
    clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int a[n+5],b[n+5];
    for (int i=1;i<=n;i++) cin >> a[i] >> b[i];
    int ans=1,prev=0;
    a[0]=0; b[0]=0;
    for (int i=1;i<=n;i++) {
        if (max(a[i],b[i])!=max(a[i-1],b[i-1])) ans+=max(0,max(a[i],b[i])-max(a[i-1],b[i-1])+1);
    }
    cout << ans << endl;
    cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}