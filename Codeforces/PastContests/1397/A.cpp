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
        int a[26];
        memset (a,0,sizeof(a));
        for (int i=1;i<=n;i++) {
            string s;
            cin >> s;
            for (char c : s) {
                a[c-'a']++;
            }
        }
        bool y = 1;
        for (int i=0;i<26;i++) {
            if (a[i] % n != 0) y = 0;
        }
        if (y) cout << "YES"; else cout << "NO";
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}