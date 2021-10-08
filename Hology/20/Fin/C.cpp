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
    string s;
    cin >> s;
    string t = s;
    reverse(t.begin(), t.end());
    bool pal = 1;
    for (int i=0;i<s.size();i++) {
        if (s[i] != t[i]) pal = 0;
    }
    if (!pal) {
        cout << "TIDAK DAPAT" << endl;
        return 0;
    }
    string can = "HIMOoTUVvWwXxY";
    for (int i=0;i<s.size();i++) {
        bool ada = 0;
        for (int j=0;j<can.size();j++) {
            if (can[j] == s[i]) ada = 1;
        }
        if (!ada) {
            cout << "TIDAK DAPAT" << endl;
            return 0;
        }
    }
    cout << "DAPAT" << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}