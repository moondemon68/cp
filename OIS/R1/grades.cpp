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
    int a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    int r=-1,l=-1;
    for (int i=1;i<=n;i++) {
        if (a[i]>=6) r=i;
    }
    for (int i=n;i>=1;i--) {
        if (a[i]<6) l=i;
    }
    if (l==-1||r==1 || l>r) cout << -1 << endl;
    else cout << r-l+1 << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}