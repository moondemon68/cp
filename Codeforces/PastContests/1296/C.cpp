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
        int n;
        cin >> n;
        string s;
        cin >> s;
        int mini = INT_MAX, ansl = -1, ansr = -1;
        map<LL,int> m;
        set<LL> st;
        LL cur = 0;
        st.insert(0);
        m[0] = -1;
        for (int i=0;i<s.size();i++) {
            if (s[i] == 'L') {
                cur += 200000;
            } else if (s[i] == 'R') {
                cur -= 200000;
            } else if (s[i] == 'U') {
                cur++;
            } else {
                cur--;
            }
            if (st.find(cur) != st.end()) {
                int cr = i, cl = m[cur]+1;
                if (cr-cl < mini) {
                    mini = cr-cl;
                    ansl = cl;
                    ansr = cr;
                }
            }
            st.insert(cur);
            m[cur] = i;
        }
        if (mini == INT_MAX) cout << -1 << endl;
        else cout << ansl+1 << " " << ansr+1 << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}