#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

bool cmp(pii a,pii b) {
    if (a.se==b.se) return a.fi<b.fi;
    else return a.se<b.se;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    pii a[n+5];
    for (int i=1;i<=n;i++) {
        int x,y;
        cin >> x >> y;
        a[i].fi=x;
        a[i].se=x+y-1;
    }
    sort (a+1,a+n+1,cmp);
    int t=0,ans=0;
    for (int i=1;i<=n;i++) {
        //cout << a[i].fi << a[i].se << endl;
        if (a[i].fi>t) {
            t=a[i].se;
            ans++;
        }
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}