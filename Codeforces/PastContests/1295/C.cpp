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
        string s,t;
        cin >> s >> t;
        vector<int> a[30];
        for (int i=0;i<s.size();i++) {
            a[s[i]-'a'].pb(i);
        }
        int ans = 1, p = -1;
        for (int i=0;i<t.size();i++) {
            int l = 0, h = a[t[i]-'a'].size()-1, x = -1;
            if (h == -1) {
                ans = -1;
                break;
            }
            while (l <= h) {
                int mid = (l+h)/2;
                if (a[t[i]-'a'][mid] <= p) {
                    l = mid + 1;
                } else {
                    h = mid - 1;
                    x = mid;
                }
            }
            // cout << x << " ";
            if (x == -1) {
                ans++;
                i--;
                p = -1;
            } else {
                p = a[t[i]-'a'][x];
            }
            // cout << p << endl;
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}