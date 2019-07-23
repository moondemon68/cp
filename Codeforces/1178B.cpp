#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

LL a[1000005];

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    s+='*';
    memset (a,0,sizeof(a));
    LL cnt=0;
    vector<LL> p;
    for (int i=0;i<s.size();i++) {
        if (s[i]=='v') cnt++;
        else {
            if (cnt-1>0) p.pb(cnt-1);
            cnt=0;
        }
        if (s[i]=='o') p.pb(0);
    }
    if (!p.empty()) a[0]=p[0];
    for (int i=1;i<p.size();i++) a[i]=p[i]+a[i-1];
    //for (int i=0;i<p.size();i++) cout << a[i] << " "; cout << endl;
    //for (int i=0;i<p.size();i++) cout << p[i] << " "; cout << endl;
    LL ans=0;
    for (int i=0;i<p.size();i++) {
        if (p[i]==0) {
            ans+=a[i-1]*(a[p.size()-1]-a[i-1]);
        }
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}