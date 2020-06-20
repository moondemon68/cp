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
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        int a[2*n+5];
        for (int i=1;i<=2*n;i++) cin >> a[i];
        vector<int> e,o;
        for (int i=1;i<=2*n;i++) {
            if (a[i] % 2 == 0) e.pb(i);
            else o.pb(i);
        }
        if (e.size() % 2 == 0) {
            if (e.size() > o.size()) {
                for (int i=0;i<e.size()-2;i+=2) cout << e[i] << " " << e[i+1] << endl; 
                for (int i=0;i<o.size();i+=2) cout << o[i] << " " << o[i+1] << endl; 
            } else {
                for (int i=0;i<e.size();i+=2) cout << e[i] << " " << e[i+1] << endl; 
                for (int i=0;i<o.size()-2;i+=2) cout << o[i] << " " << o[i+1] << endl; 
            }
        } else {
            for (int i=1;i<e.size();i+=2) cout << e[i] << " " << e[i-1] << endl; 
            for (int i=1;i<o.size();i+=2) cout << o[i] << " " << o[i-1] << endl; 
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}