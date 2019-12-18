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
    int n;
    cin >> n;
    string s,t;
    cin >> s >> t;
    queue<int> l[27],r[27];
    for (int i=0;i<s.size();i++) {
        if (s[i]=='?') l[26].push(i+1); else l[s[i]-'a'].push(i+1);
        if (t[i]=='?') r[26].push(i+1); else r[t[i]-'a'].push(i+1);
    }
    vector<pii> ans;
    for (int i=0;i<26;i++) {
        while (!r[i].empty()&&!l[i].empty()) {
            ans.pb(mp(l[i].front(),r[i].front()));
            l[i].pop();
            r[i].pop();
        }
    }
    for (int i=0;i<26;i++) {
        while (!l[26].empty()&&!r[i].empty()) {
            ans.pb(mp(l[26].front(),r[i].front()));
            l[26].pop();
            r[i].pop();
        }
    }
    for (int i=0;i<26;i++) {
        while (!r[26].empty()&&!l[i].empty()) {
            ans.pb(mp(l[i].front(),r[26].front()));
            l[i].pop();
            r[26].pop();
        }
    }
    for (int i=0;i<26;i++) {
        while (!r[26].empty()&&!l[26].empty()) {
            ans.pb(mp(l[26].front(),r[26].front()));
            l[26].pop();
            r[26].pop();
        }
    }
    cout << ans.size() << endl;
    for (int i=0;i<ans.size();i++) {
        cout << ans[i].fi << " " << ans[i].se << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}