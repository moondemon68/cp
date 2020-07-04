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
    int g,t;
    cin >> g >> t;
    int a[g+5];
    for (int i=1;i<=g;i++) cin >> a[i];
    int cnt = 0;
    vector<int> n,p;
    p.pb(0);
    for (int i=1;i<=g;i++) {
        if (a[i] < 0) {
            n.pb(-1*a[i]);
        } else if (a[i] > 0) {
            p.pb(a[i]);
        } else {
            cnt++;
        }
    }
    n.pb(0);
    sort (n.begin(), n.end());

    int ans = 0, ans2 = 0;
    for (int i=0;i<n.size();i++) {
        int x = i, rem = t-n[i]-n[i];
        int l = 1, h = p.size()-1;
        while (l <= h) {
            int m = (l+h) / 2;
            if (p[m] >= rem) {
                ans = m;
                l = m+1;
            } else {
                h = m-1;
            }
        }
        if (rem >= 0) ans += i;
        cout << rem << endl;
    }

    for (int i=0;i<p.size();i++) {
        int x = i, rem = t-p[i]-p[i];
        int l = 1, h = n.size()-1;
        while (l <= h) {
            int m = (l+h) / 2;
            if (n[m] >= rem) {
                ans2 = m;
                l = m+1;
            } else {
                h = m-1;
            }
        }
        if (rem >= 0) ans2 += i;
        cout << rem << endl;
    }
    cout << max(ans, ans2)+cnt << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}