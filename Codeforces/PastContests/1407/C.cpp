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
    int a[n+5];
    memset (a,0,sizeof(a));
    int l = 1, r = 2, cnt = n;
    while (cnt > 1) {
        if (l == r) r++;
        cout << "? " << l << " " << r << endl;
        int x;
        cin >> x;
        cout << "? " << r << " " << l << endl;
        int y;
        cin >> y;
        if (x > y) {
            a[l] = x;
            cnt--;
            while (l <= n && a[l] != 0) {
                if (a[l] != 0) {
                    l++;
                }
            }
        } else {
            a[r] = y;
            cnt--;
            while (r <= n && a[r] != 0) {
                if (a[r] != 0) {
                    r++;
                }
            }
        }
    }
    cout << "! ";
    for (int i=1;i<=n;i++) {
        if (a[i] == 0) cout << n << " ";
        else cout << a[i] << " ";
    }
    cout << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}