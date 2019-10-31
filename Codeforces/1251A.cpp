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
        vector<int> adj[35];
        string s;
        cin >> s;
        s+='*';
        int cnt=0;
        for (int i=0;i<s.size()-1;i++) {
            cnt++;
            if (s[i]==s[i+1]) {
                continue;
            } else {
                adj[s[i]-'a'].pb(cnt%2);
                cnt=0;
            }
        }
        for (int i=0;i<26;i++) {
            if (adj[i].empty()) continue;
            sort(adj[i].begin(),adj[i].end());
        }
        for (int i=0;i<26;i++) {
            if (!adj[i].empty() && adj[i][adj[i].size()-1]==1) {
                char c = 'a';
                c+=i;
                cout << c;
            }
        }
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}