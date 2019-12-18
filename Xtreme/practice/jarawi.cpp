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

set<int> p[26];

bool issub(string t) {
    int x=0;
    for (int i=0;i<t.size();i++) {
        auto y = p[t[i]-'a'].lower_bound(x);
        if (i>=1 && t[i]==t[i-1]) y = next(y);
        if (y == p[t[i]-'a'].end()) return 0;
        else {
            x = *y;
        }
    }
    return 1;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    reverse(s.begin(),s.end());
    for (int i=0;i<s.size();i++) {
        p[s[i]-'a'].insert(i);
    }
    int n;
    cin >> n;
    while (n--) {
        string t;
        cin >> t;
        reverse(t.begin(),t.end());
        int ans = 0;
        while (!t.empty()) {
            if (issub(t)) {
                ans = t.size();
                break;
            }
            t.pop_back();
            //cout << t << endl;
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}