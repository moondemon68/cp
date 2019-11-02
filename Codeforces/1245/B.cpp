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
        int a,b,c;
        cin >> a >> b >> c;
        string s;
        cin >> s;
        int p=0;
        vector<char> ans;
        for (int i=0;i<s.size();i++) {
            if (s[i]=='R' && b>0) {
                ans.pb('P');
                b--;
                p++;
            } else if (s[i]=='P' && c>0) {
                ans.pb('S');
                c--;
                p++;
            } else if (s[i]=='S' && a>0) {
                ans.pb('R');
                a--;
                p++;
            } else {
                ans.pb('X');
            }
        }
        if (p >= (n+1)/2) {
            cout << "YES" << endl;
            for (int i=0;i<ans.size();i++) {
                if (ans[i]=='X') {
                    if (a) {
                        cout << 'R';
                        a--;
                    } else if (b) {
                        cout << 'P';
                        b--;
                    } else if (c) {
                        cout << 'S';
                        c--;
                    }
                } else {
                    cout << ans[i];
                }
            }
            cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}