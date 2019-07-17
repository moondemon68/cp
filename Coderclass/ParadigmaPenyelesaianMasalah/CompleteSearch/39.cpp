//Misi Rahasia
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
    bool a[n+5][n+5];
    memset (a,0,sizeof(a));
    for (int i=1;i<=m;i++) {
        int x,y;
        cin >> x >> y;
        a[x][y]=1;
        a[y][x]=1;
    }
    int ans=0;
    for (int i=1;i<=(1<<n);i++) {
        int x=i;
        vector<int> v;
        while ((int)v.size()<n) {
            v.pb(x%2);
            x/=2;
        }
        vector<int> p;
        for (int j=0;j<(int)v.size();j++) {
            if (v[j]==1) p.pb(j+1);
        }
        bool y=1;
        for (int j=0;j<(int)p.size();j++) {
            for (int k=j+1;k<(int)p.size();k++) {
                if (!a[p[j]][p[k]]) y=0;
            }
        }
        if (y) ans=max(ans,(int)p.size());
    } 
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}