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
    int ans=0;
    int k=5;
    for (int i=0;i<pow(8,k);i++) {
        int x=i;
        vector<int> p;
        while (p.size()!=k) {
            p.pb(x%8);
            x/=8;
        }
        set<pii> s;
        s.insert(mp(0,0));
        int px=0,py=0;
        int mx[]={1,1,0,-1,-1,-1,0,1};
        int my[]={0,-1,-1,-1,0,1,1,1};
        for (int j=0;j<p.size();j++) {
            px+=mx[p[j]];
            py+=my[p[j]];
            if (px<0||px>k||py<0||py>k) break;
            if (s.find(mp(px,py))!=s.end()) break;
            s.insert(mp(px,py));
        }
        if (s.size()==k+1) ans++;
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}