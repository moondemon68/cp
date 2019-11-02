#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<LL,LL>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL f[100005];
    f[0]=1;
    f[1]=1;
    for (LL i=2;i<=100000;i++) {
        f[i]=f[i-1]+f[i-2];
        f[i]%=MOD;
    }
    bool y=1;
    LL ans=1;
    string s;
    cin >> s;
    s+='*';
    vector<LL> p;
    for (LL i=0;i<s.size()-1;i++) {
        if (s[i]=='u') {
            LL cnt=0;
            while (s[i]=='u') {
                i++;
                cnt++;
            }
            p.pb(cnt);
            i--;
        } else if (s[i]=='n') {
            LL cnt=0;
            while (s[i]=='n') {
                i++;
                cnt++;
            }
            p.pb(cnt);
            i--;
        } else if (s[i]=='m') y=0;
        else if (s[i]=='w') y=0;
    }
    for (LL i=0;i<p.size();i++) {
        ans *= f[p[i]];
        ans %= MOD;
    }
    if (y) cout << ans << endl; else cout << 0 << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}