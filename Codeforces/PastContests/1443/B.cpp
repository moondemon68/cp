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
        int a,b;
        cin >> a >> b;
        string s;
        cin >> s;
        int start = -1, end = -1;
        for (int i=0;i<s.size();i++) {
            if (s[i] == '1') {
                start = i;
                break;
            }
        }
        if (start == -1) {
            cout << 0 << endl;
            continue;
        }
        for (int i=s.size()-1;i>=start;i--) {
            if (s[i] == '1') {
                end = i;
                break;
            }
        }
        s += 'x';
        char cur = '1';
        int cnt = 0;
        vector<pair<char, int>> v;
        for (int i=start;i<=end+1;i++) {
            if (cur == s[i]) {
                cnt++;
            } else {
                v.pb({cur, cnt});
                cur = s[i];
                cnt = 1;
            }
        }
        bool done[(int)s.size()+5];
        memset (done,0,sizeof(done));
        if (v.size() == 1) {
            cout << a << endl;
            continue;
        }
        if (v.size() % 2 == 1) {
            v.pb({'0', 0});
        }
        int ans = 0;
        for (int i=1;i<v.size()-1;i+=2) {
            if (v[i].se * b <= a) {
                ans += v[i].se * b;
                v[i].fi = '0';
                v[i-1].fi = '0';
                v[i+1].fi = '1';
                v[i].se = 0;
                v[i-1].se = 0;
                v[i+1].se = 0;
            }
        }
        for (int i=0;i<v.size();i++) {
            if (v[i].fi == '1') ans += a; 
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}