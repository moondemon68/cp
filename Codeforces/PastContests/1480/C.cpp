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
    int n;
    cin >> n;
    int l = 1, r = n, ans = -1;
    while (l < r) {
        int m = (l + r) / 2;
        int x, y;
        cout << "? " << m << endl;
        cin >> x;
        cout << "? " << m+1 << endl;
        cin >> y;
        if (x < y) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    cout << "! " << l << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}