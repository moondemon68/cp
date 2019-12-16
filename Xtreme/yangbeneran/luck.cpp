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
    int n;
    cin >> n;
    int ans=0;
    int num[105];
    int x=0;
    for (int i=1;i<=n;i++) {
        string s;
        cin >> s;
        int p=0;
        for (int i=0;i<s.size();i++) {
            p+=s[i]-'0';
            p*=2;
        }
        p/=2;
        num[i]=p;
        x=s.size();
    }
    int wins[n+5];
    memset(wins,0,sizeof(wins));
    for (int i=0;i<(1<<x);i++) {
        int cnt[105];
        memset (cnt,0,sizeof(cnt));
        for (int j=1;j<=n;j++) {
            int g = i^num[j];
            cnt[j]=__builtin_popcount (g);
            cnt[j]=x-cnt[j];
        }
        int maxx=0;
        for (int j=1;j<=n;j++) {
            if (cnt[j]>maxx) {
                maxx=cnt[j];
            }
        }
        int cntmax=0,loc=0;
        for (int j=1;j<=n;j++) {
            if (maxx==cnt[j]) {
                cntmax++;
                loc=j;
            }
        }
        if (cntmax>1) loc=0;
        wins[loc]++;
    }
    sort (wins+1,wins+n+1);
    cout << wins[1] << endl;
    //cout << ans << endl;  
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}