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
    string s;
    cin >> s;
    string t="";
    for (int i=0;i<s.size();i++) {
        if (s[i]=='a'||s[i]=='b') t+=s[i];
    }
    vector<LL> p;
    t+='b';
    LL cnt=0;
    for (int i=0;i<t.size();i++) {
        if (t[i]=='a') cnt++;
        else {
            p.pb(cnt+1);
            cnt=0;
        }
    }
    LL ans=1;
    for (int i=0;i<p.size();i++) {
        ans*=p[i];
        ans%=MOD;
    }
    cout << ans-1 << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}