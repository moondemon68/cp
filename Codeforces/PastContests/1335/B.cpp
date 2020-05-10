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
        int n,a,b;
        cin >> n >> a >> b;
        string s = "";
        for (int i=0;i<b;i++) {
            s += 'a'+i;
        }
        for (int i=b+1;i<=a;i++) s += s.back();
        for (int i=0;i<n;i++) {
            cout << s[i%s.size()];
        }
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}