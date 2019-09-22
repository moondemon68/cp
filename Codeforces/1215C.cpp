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
    stack<int> ab,ba;
    for (int i=0;i<n;i++) {
        if (s[i]=='a'&&t[i]=='b') ab.push(i);
        if (s[i]=='b'&&t[i]=='a') ba.push(i);
    }
    vector<pii> ans;
    while(ab.size()>1) {
        int x,y;
        x=ab.top();
        ab.pop();
        y=ab.top();
        ab.pop();
        ans.pb({x,y});
    }
    while(ba.size()>1) {
        int x,y;
        x=ba.top();
        ba.pop();
        y=ba.top();
        ba.pop();
        ans.pb({x,y});
    }
    if (ab.size()!=ba.size()) {
        cout << -1 << endl;
        return 0;
    } 
    while (!ab.empty() && !ba.empty()) {
        ans.pb({ab.top(),ab.top()});
        ans.pb({ab.top(),ba.top()});
        ab.pop();
        ba.pop();
    }
    cout << ans.size() << endl;
    for (int i=0;i<ans.size();i++) {
        cout << ans[i].fi+1 << " " << ans[i].se+1 << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}