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
    int n,k;
    cin >> n >> k;
    int a[n+5];
    for (int i=1;i<=n;i++) {
        cin >> a[i];
    }    
    vector<int> v;
    int o=0,e=0;
    for (int i=1;i<n;i++) {
        if (a[i]%2==0) e++; else o++;
        if (o==e) v.pb(abs(a[i]-a[i+1]));
    }
    sort (v.begin(),v.end());
    v.pb(123456789);
    int ans=0;
    while (k>0) {
        k-=v[ans];
        if (k>=0) ans++;
    }
    cout << ans << endl;

    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}