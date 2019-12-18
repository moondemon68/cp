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

bool small(string s,string t) {
    for (int i=0;i<min(s.size(), t.size());i++) {
        if (s[i] < t[i]) return 1;
        else if (s[i] > t[i]) return 0;
    }
    return s.size() < t.size();
}

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
        string t;
        cin >> t;
        string ans="---";
        if (s < t) {
            cout << s << endl;
            continue;
        }
        string word = s;
        for (int i=0;i<s.size();i++) {
            for (int j=i+1;j<s.size();j++) {
                if (s[i] > s[j]) {
                    swap(s[i], s[j]);
                    if (s < word) word = s;
                    swap(s[i], s[j]);
                }
            }
        }
        if (word < t) cout << word << endl;
        else cout << "---" << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}