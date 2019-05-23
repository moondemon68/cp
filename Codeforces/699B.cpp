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
    char a[n+5][m+5];
    for (int i=1;i<=n;i++) {
        string s;
        cin >> s;
        for (int j=1;j<=m;j++) {
            a[i][j]=s[j-1];
        }
    }
    int row[1005];
    for (int i=1;i<=n;i++) {
        row[i]=0;
        for (int j=1;j<=m;j++) {
            if (a[i][j]=='*') row[i]++;
        }
    }
    int col[1005];
    for (int i=1;i<=m;i++) {
        col[i]=0;
        for (int j=1;j<=n;j++) {
            if (a[j][i]=='*') col[i]++;
        }
    }
    vector<int> ansr,ansc;
    for (int i=1;i<=n;i++) if (row[i]>0) ansr.pb(i);
    for (int i=1;i<=m;i++) if (col[i]>0) ansc.pb(i);
    if (ansr.size()>1||ansc.size()>1) {
        cout << "NO" << endl;
    } else if (ansr.size()==1&&ansc.size()==1) {
        cout << "YES" << endl;
        cout << ansr[0] << " " << ansc[0] << endl;
    } else if (ansr.size()==1) {
        cout << "YES" << endl;
        cout << ansr[0] << " 1" << endl;
    } else {
        cout << "YES" << endl;
        cout << "1 " << ansc[0] << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}