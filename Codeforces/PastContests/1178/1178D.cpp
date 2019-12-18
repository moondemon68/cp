#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

bitset<2005> prima;
void sieve(int x) {
    prima.set();
    prima[1]=0;
    for (int i=2;i*i<=x;i++) {
        if (!prima[i]) continue;
        for (int j=i*i;j<=x;j+=i) {
            prima[j]=0;
        }
    }
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >>n;
    sieve(2000);
    vector<pii> ans;
    for (int i=1;i<n;i++) {
        ans.pb({i,i+1});
    }
    ans.pb({n,1});
    int l=2,h=n;
    while (!prima[n]) {
        n++;
        ans.pb({l,h});
        l++;
        h--;
    }
    cout << ans.size() << endl;
    for (int i=0;i<ans.size();i++) {
        cout << ans[i].fi << " " << ans[i].se << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}