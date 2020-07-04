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
        bool y = 0;
        queue<char> q;
        for (int i=0;i<s.size();i++) {
            if (q.empty()) q.push(s[i]);
            else if (s[i] != q.front()) {
                q.pop();
                y = !y;
            }
            else q.push(s[i]);
        }
        if (y) cout << "DA" << endl;
        else cout << "NET" << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}