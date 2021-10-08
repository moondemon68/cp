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
    int q;
    cin >> q;
    int l = 1, r = 1000, ans = 0;
    while (l <= r) {
        int m = (l+r)/2;
        cout << m << endl;
        string s;
        cin >> s;
        if (s == "BENAR") {
            return 0;
        }
        cin >> s;
        if (s == "KECIL") {
            r = m-1;
        } else {
            l = m+1;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}