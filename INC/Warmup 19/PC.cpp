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
    LL p;
    cin >> p;
    LL x=p;
    string s;
    cin >> s;
    string t="";
    while (p) {
        if (p%2==0) t+='0'; else t+='1';
        p/=2;
    }
    if (s.size()<t.size()) {
        cout << 0 << endl;
        return 0;
    }
    int ans=0;
    while (s.size()>t.size()) {
        bool y=1;
        for (int i=1;i<s.size();i++) {
            if (s[i]=='1'&&y) {
                ans++;
                s.erase(s.begin()+i);
                y=0;
                break;
            }
        }
        for (int i=1;i<s.size();i++) {
            if (s[i]=='0'&&y) {
                ans++;
                s.erase(s.begin()+i);
                y=0;
                break;
            }
        }
    }
    //cout << s << endl << t << endl;
    LL c=0;
    for (int i=0;i<s.size();i++) {
        c+=s[i]-'0';
        c*=2;
    }
    c/=2;
    if (c>x) cout << ans+1 << endl;
    else cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}