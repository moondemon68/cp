#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

int r,c;
bool valid(int a,int b) {
    return a>=1&&a<=r&&b>=1&&b<=c;
}
char a[1005][1005];
bool vis[1005][1005];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ifstream cin ("d_big.in");
    ofstream cout ("d_big.out");
    int l,h;
    cin >> r >> c >> l >> h;
    for (int i=1;i<=r;i++) {
        string s;
        cin >> s;
        for (int j=1;j<=c;j++) {
            a[i][j]=s[j-1];
        }
    }
    memset (vis,0,sizeof(vis));
    vector<pair<pii,pii>> ans;
    for (int si=1;si<=r;si++) {
        for (int sj=1;sj<=c;sj++) {
            if (!vis[si][sj]) {
                for (int f=1;f<=h;f++) {
                    if (h%f==0) {
                        int ei=si+f-1,ej=sj+h/f-1,m=0,t=0,x=0;
                        for (int i=si;i<=ei;i++) {
                            for (int j=sj;j<=ej;j++) {
                                if (vis[i][j]||!valid(i,j)) {
                                    x=1;
                                }
                                if (a[i][j]=='M') m++; else t++;
                            }
                        }
                        if (x==1) {
                            m=0;t=0;
                        }
                        if (m>=l&&t>=l) {
                            for (int i=si;i<=ei;i++) {
                                for (int j=sj;j<=ej;j++) {
                                    vis[i][j]=1;
                                }
                            }
                            ans.pb(mp(mp(si-1,sj-1),mp(ei-1,ej-1)));
                            break;
                        }
                    }
                }
            }
        }
    }
    cout << ans.size() << endl;
    for (int i=0;i<(int)ans.size();i++) {
        cout << ans[i].fi.fi << " " << ans[i].fi.se << " " << ans[i].se.fi << " " << ans[i].se.se << endl;
    }
    return 0;
}