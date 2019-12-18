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
    int m,n,w,h;
    cin >> m >> n >> w >> h;
    int work[m+5],cd[m+5];
    for (int i=1;i<=m;i++) cin >> work[i];
    for (int i=1;i<=m;i++) cd[i]=0;
    int d[n+5];
    for (int i=1;i<=n;i++) cin >> d[i];
    vector<int> ans[m+5];
    for (int i=1;i<=n;i++) {
        if (d[i]==0) continue;
        for (int j=1;j<=m;j++) {
            //cout << cd[j] << work[j] << endl;
            if (cd[j]==0&&work[j]>0) {
                ans[j].pb(i);
                work[j]-=w;
                cd[j]=h+w+1;
                for (int p=1;p<=w;p++) {
                    //cout << i+p-1;
                    d[i+p-1]--;
                }
            }
            if (d[i]==0) break;
        }
        for (int j=1;j<=m;j++) if (cd[j]!=0) cd[j]--;
    }
    for (int i=1;i<=n;i++) cout << d[i] << " ";
    cout << endl;
    for (int i=1;i<=n;i++) {
        for (int j=0;j<ans[i].size();j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}