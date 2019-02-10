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
    clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int k,n;
    cin >> k >> n;
    vector<string> v;
    string g[n+5][3];
    for (int i=1;i<=3*n;i++) {
        int a;
        char b;
        cin >>a >>b;
        string s;
        s+=(char)a+'0';
        s+=b;
        v.pb(s);
        g[i/3+1][i%3+1]=s;
    }
    sort (v.begin(),v.end());
    int cnt[k+5][2];
    memset (cnt,0,sizeof(cnt));
    for (int i=0;i<v.size();i++) {
        if (v[i][1]=='B') cnt[v[i][0]-'0'][0]++; else cnt[v[i][0]-'0'][1]++;
    }
    string ans="";
    for (int i=1;i<=k;i++) ans+='X';
    for (int i=0;i<k;i++) {
        if (cnt[i][0]>=cnt[i][1]) ans[i]='B'; else ans[i]='R';
    }
    cout << ans << endl;
    cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}