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
    LL a[n+5];
    for (int i=1;i<n;i++) cin >> a[i];
    LL b[n+5];
    b[1]=0;
    for (int i=2;i<=n;i++) {
        b[i]=b[i-1]+a[i-1];
    }
    //for (int i=1;i<=n;i++) cout << b[i] << " ";
    //cout << endl;
    LL minx=12345678987654321;
    for (int i=1;i<=n;i++) {
        minx=min(minx,b[i]);
    }
    LL x=1-minx;
    set<LL> ans;
    for (int i=1;i<=n;i++) {
        if (b[i]+x>n) {
            cout << "-1" << endl;
            return 0;
        }  else {
            ans.insert(b[i]);
        }
    }
    if (ans.size()!=n) {
        cout << -1 << endl;
        return 0;
    }
    for (int i=1;i<=n;i++) {
        cout << b[i]+x << " ";
    }
    cout << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}