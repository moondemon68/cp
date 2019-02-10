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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ifstream cin ("input-B.txt");
    ofstream cout ("output-B.txt");
    
    int tc;
    cin >> tc;
    while (tc--) {
        string s;
        cin >> s;
        s+="--------------------------------------------------------------------------------------------";
        string t;
        cin >> t;
        for (int i=1;i<=s.size();i++) {
            if (s[i-1]=='-') break;
            if (s[i-1]==t[0]) {
                bool y=1;
                for (int j=0;j<t.size();j++) {
                    if (s[i+j-1]!=t[j]) y=0;
                }
                if (y) cout << i << " ";
            }
        }
        cout << endl;
    }
    return 0;
}