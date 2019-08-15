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
    int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    LL c[30];
    memset (c,0,sizeof(c));
    for (int i=0;i<s.size();i++) {
        c[s[i]-'A']++;
    }
    for (int i=1;i<=m;i++) {
        char p;
        string q;
        cin >> p >> q;
        LL tmp=c[p-'A'];
        c[p-'A']=0;
        for (int j=0;j<q.size();j++) {
            c[q[j]-'A']+=tmp;
        }
    }
    LL ans=0;
    for (int i=0;i<26;i++) ans+=c[i];
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}