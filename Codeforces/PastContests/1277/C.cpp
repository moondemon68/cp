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
        vector<pair<char,int>> v;
        s+='*';
        s+='*';
        s+='*';
        s+='*';
        int ans=0;
        for (int i=0;i<s.size()-4;i++) {
            if (s[i] == 't' && s[i+1] == 'w' && s[i+2] == 'o' && s[i+3] == 'n' && s[i+4] == 'e') {
                ans++;
                s[i+2] = '^';
            }
        }
        for (int i=0;i<s.size()-2;i++) {
            if (s[i] == 't' && s[i+1] == 'w' && s[i+2] == 'o') {
                ans++;
                s[i+1] = '^';
            }
        }
        for (int i=0;i<s.size()-2;i++) {
            if (s[i] == 'o' && s[i+1] == 'n' && s[i+2] == 'e') {
                ans++;
                s[i+1] = '^';
            }
        }
        cout << ans << endl;
        for (int i=0;i<s.size();i++) if (s[i] == '^') cout << i+1 << " ";
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}