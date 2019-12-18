#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
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
    vector<int> p;
    int ans=0;
    for (int i=1;i<=n;i++) {
        int x;
        cin >> x;
        if (x%2==0) ans+=x;
        else p.pb(x);
    }
    sort (p.begin(),p.end());
    for (int i=0;i<p.size();i++) ans+=p[i];
    if (p.size()%2==1) ans-=p[0];
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}