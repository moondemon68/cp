#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

LL k, a[200005];

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n >> k;
    for (int i=1;i<=n;i++) cin >> a[i];
    a[0]=0;
    for (int i=1;i<=n;i++) {
        a[i]+=a[i-1];
    }
    for (int i=1;i<=n;i++) {
        a[i]-=i;
        a[i]%=k;
    }
    LL ans=0;
    map<LL,int> c;
    c[a[0]]++;
    if (k > n) k = n+1;
    for (int i=1;i<k;i++) {
        ans += c[a[i]];
        c[a[i]]++;
    }
    for (int i=k;i<=n;i++) {
        c[a[i-k]]--;
        ans += c[a[i]];
        c[a[i]]++;
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}