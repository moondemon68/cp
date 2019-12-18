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
        LL n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        LL x = 0;
        for (int i=0;i<s.size();i++) {
            if (s[i]=='0') {
                if ((i-x)<=k) {
                    k-=(i-x);
                    swap(s[i], s[x]);
                    x++;
                } else if (k>0) {
                    swap(s[i], s[i-k]);
                    k=0;
                }
                //cout << i << " " << k << endl;
            }
        }
        cout << s << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}