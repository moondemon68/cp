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
    for (int t=1;t<=tc;t++) {
        string s;
        cin >> s;
        string a,b;
        a="";b="";
        for (int i=0;i<s.size();i++) {
            if (s[i]=='4') {
                a+='2'; b+='2';
            } else {
                a+=s[i]; b+='0';
            }
        }
        cout << "Case #" << t << ": ";
        cout << a << " ";
        bool y=0;
        for (int i=0;i<b.size();i++) {
            if (b[i]=='0'&&!y) continue;
            if (b[i]!='0') y=1;
            cout << b[i];
        }
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}