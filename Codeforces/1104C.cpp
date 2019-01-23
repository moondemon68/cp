#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

bool a[5][5];
void buang() {
    for (int i=1;i<=4;i++) {
        if (a[1][i]&&a[2][i]&&a[3][i]&&a[4][i]) {
            a[1][i]=0;
            a[2][i]=0;
            a[3][i]=0;
            a[4][i]=0;
        }
    }
    for (int i=1;i<=4;i++) {
        if (a[i][1]&&a[i][2]&&a[i][3]&&a[i][4]) {
            a[i][1]=0;
            a[i][2]=0;
            a[i][3]=0;
            a[i][4]=0;
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    memset (a,0,sizeof(a));
    for (int i=0;i<s.size();i++) {
        if (s[i]=='0') {
            bool y=0;
            for (int j=1;j<=3;j++) {
                for (int k=1;k<=4;k++) {
                    if (!a[j][k]&&!a[j+1][k]) {
                        cout << j << " " << k << endl;
                        a[j][k]=1;
                        a[j+1][k]=1;
                        y=1;
                    }
                    if (y) break;
                }
                if (y) break;
            }
        } else if (s[i]=='1') {
            bool y=0;
            for (int j=3;j<=4;j++) {
                for (int k=1;k<=3;k++) {
                    if (!a[j][k]&&!a[j][k+1]) {
                        cout << j << " " << k << endl;
                        a[j][k]=1;
                        a[j][k+1]=1;
                        y=1;
                    }
                    if (y) break;
                }
                if (y) break;
            }
            if (!y) {
                for (int j=1;j<=2;j++) {
                    for (int k=1;k<=3;k++) {
                        if (!a[j][k]&&!a[j][k+1]) {
                            cout << j << " " << k << endl;
                            a[j][k]=1;
                            a[j][k+1]=1;
                            y=1;
                        }
                        if (y) break;
                    }
                    if (y) break;
                }
            }
        }
        buang();
    }    
    return 0;
}
