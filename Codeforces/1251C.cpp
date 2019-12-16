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
        string s;
        cin >> s;
        queue<int> q;
        string ans="";
        for (int i=0;i<s.size();i++) {
            if ((s[i]-'0')%2==1) q.push(s[i]-'0'); else ans+=s[i];
        }
        for (int i=0;i<ans.size();i++) {
            while (!q.empty() && (ans[i]-'0')>q.front()) {
                cout << q.front();
                q.pop();
            }
            cout << ans[i];
        }
        while (!q.empty()) {
            cout << q.front();
            q.pop();
        }
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}