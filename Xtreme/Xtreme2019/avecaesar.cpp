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
        string s;
        cin >> s;
        vector<string> p;
        s+='A'-1;
        string t="";
        for (int i=0;i<s.size()-1;i++) {
            if (s[i]>s[i+1]) {
                t+=s[i];
                p.pb(t);
                t="";
            } else {
                t+=s[i];
            }
        }
        vector<string> q;
        for (int i=0;i<p.size();i++) {
            q.pb(p[i]);
        }
        sort (q.begin(),q.end());
        bool y=1;
        for (int i=0;i<p.size();i++) {
            if (p[i]!=q[i]) y=0;
        }
        cout << y;
        
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}