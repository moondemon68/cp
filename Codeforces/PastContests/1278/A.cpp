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
        string s,t;
        cin >> s >> t;
        bool y=0;
        sort (s.begin(), s.end());
        for (int i=0;i<t.size();i++) {
            for (int j=i;j<t.size();j++) {
                if (j-i+1 != s.size()) continue;
                string p="";
                for (int k=i;k<=j;k++) p+=t[k];
                sort (p.begin(), p.end());
                if (p == s) y = 1;
            }
        }
        if (y) cout << "YES"; else cout << "NO";
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}