//Naik Level
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
    int n,m;
    cin >> n >> m;
    int a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=(1<<n);i++) {
        int x=i;
        vector<int> v;
        while (v.size()<n) {
            v.pb(x%2);
            x/=2;
        }
        int ans=0;
        for (int j=0;j<v.size();j++) {
            if (v[j]==1) ans+=a[j+1];
        }
        if (ans==m) {
            cout << "bisa" << endl;
            return 0;
        }
    }
    cout << "tidak bisa" << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}