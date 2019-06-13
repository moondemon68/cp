#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

bool cmp(int a[],int b[]) return a.size()>b.size();

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    pii a[n+5],b[m+5];
    for (int i=1;i<=n;i++) cin >> a[i].fi >> a[i].se;
    for (int i=1;i<=m;i++) cin >> b[i].fi >> b[i].se;
    vector<int> see[n+5];
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (abs(a[i].se-b[j].se)<=a[j].fi-a[i].fi) see[i].pb(j);
        }
    }
    sort (see.begin(),see.end(),cmp);
    for (int i=0)
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}