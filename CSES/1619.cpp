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
    vector<pii> a;
    for (int i=1;i<=n;i++) {
        int x,y;
        cin >> x >> y;
        a.pb({x,1});
        a.pb({y,-1});
    }
    sort (a.begin(),a.end());
    int p=0,ans=0;
    for (int i=0;i<a.size();i++) {
        p+=a[i].se;
        ans=max(ans,p);
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}