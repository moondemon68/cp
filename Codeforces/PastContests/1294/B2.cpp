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
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        pii a[n+5];
        for (int i=1;i<=n;i++) cin >> a[i].fi >> a[i].se;
        sort (a+1,a+n+1);
        string s = "";
        for (int i=1;i<=n;i++) {
            if (i == 1) {
                for (int j=0;j<a[i].fi;j++) s+='R';
                for (int j=0;j<a[i].se;j++) s+='U';
            } else {
                if (a[i].se<a[i-1].se) {
                    s = "*";
                    break;
                } else {
                    for (int j=0;j<a[i].fi-a[i-1].fi;j++) s+='R';
                    for (int j=0;j<a[i].se-a[i-1].se;j++) s+='U';
                }
            }
        }
        if (s == "*") cout << "NO" << endl;
        else cout << "YES" << endl << s << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}