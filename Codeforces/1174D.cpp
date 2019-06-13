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
    vector<int> ans;
    if (k>=(1<<n)) {
        for (int i=0;i<(1<<n);i++) ans.pb(i);
    } else {
        bool y[300005];
        memset (y,0,sizeof(y));
        for (int i=1;i<(1<<n);i++) {
            if (!y[i]) {
                y[i]=1;
                y[i^k]=1;
                ans.pb(i);
            }
        }
    }
    cout << ans.size()-1 << endl;
    int x=ans.size();
    for (int i=0;i<x-1;i++) cout << (ans[i]^ans[i+1]) << " ";
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}