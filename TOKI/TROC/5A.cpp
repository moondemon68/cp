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
    string s,t;
    cin >> s >> t;
    if (s.size()<t.size()) {
        cout << "YA" << endl << s << endl;
        return 0;
    }
    for (int i=0;i<=s.size()-t.size();i++) {
        bool y=1;
        for (int j=0;j<t.size();j++) {
            //cout << t[j] << s[i+j];
            if (t[j]!=s[i+j]) y=0; 
        }
        if (y) {
            cout << "TIDAK" << endl;
            return 0;
        }
    }
    cout << "YA" << endl;
    cout << s << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}