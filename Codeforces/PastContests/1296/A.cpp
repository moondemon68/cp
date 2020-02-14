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
        int o = 0, e = 0;
        for (int i=1;i<=n;i++) {
            int x;
            cin >> x;
            if (x % 2==0) e++; else o++;
        }
        if (o%2==1) cout << "YES";
        else if (e != n && e != 0) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}