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
    LL n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    bool a[1005];
    memset (a,0,sizeof(a));
    for (LL i=1;i<=k;i++) {
        char c;
        cin >> c;
        a[c-'a']=1;
    }
    s+='}';
    LL cnt=0, ans=0;
    for (LL i=0;i<s.size();i++) {
        if (a[s[i]-'a']) {
            cnt++;
        } else {
            ans+=(cnt)*(cnt+1)/2;
            cnt = 0;
        }
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}