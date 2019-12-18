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
    int r,c;
    cin >> r >> c;
    string a[r+5];
    for (int i=0;i<r;i++) {
        cin >> a[i];
    }
    bool v[r+5][c+5];
    memset (v,0,sizeof(v));
    for (int i=1;i<r-1;i++) {
        for (int j=1;j<c-1;j++) {
            if (a[i][j]=='*'&&a[i-1][j]=='*'&&a[i+1][j]=='*'&&a[i][j-1]=='*'&&a[i][j+1]=='*') {
                bool y=1;
                v[i][j]=1;
                for (int k=i;k>=0;k--) {
                    if (a[k][j]=='*') v[k][j]=1;
                    else break;
                }
                for (int k=i;k<r;k++) {
                    if (a[k][j]=='*') v[k][j]=1;
                    else break;
                }
                for (int k=j;k>=0;k--) {
                    if (a[i][k]=='*') v[i][k]=1;
                    else break;
                }
                for (int k=j;k<c;k++) {
                    if (a[i][k]=='*') v[i][k]=1;
                    else break;
                }
                for (int k=0;k<r;k++) {
                    for (int l=0;l<c;l++) {
                        //cout << v[k][l];
                        if (a[k][l]=='*'&&!v[k][l]) {
                            cout << "NO" << endl;
                            return 0;
                        }
                    }
                    //cout << endl;
                }
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}