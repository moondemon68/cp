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
    else return a.se>b.se;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin >> n >> k;
    int a[n+5];
    for (int i=1;i<=n;i++) {
        cin >> a[i];
    }
    sort (a+1,a+n+1);
    vector<pii> ans;
    for (int i=1;i<=k;i++) {
        int x;
        cin >> x;
        int cnt=0;
        int l=1,r=n;
        while (l<r) {
            if (a[l]+a[r]==x) {
                cnt++;
                l++;
                r--;
            } else if (a[l]+a[r]>x) {
                r--;
            } else {
                l++;
            }
        }
        ans.pb(mp(x,cnt));
    }
    sort (ans.begin(),ans.end(),cmp);
    for (int i=0;i<ans.size();i++) {
        cout << ans[i].fi << " " << ans[i].se << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}