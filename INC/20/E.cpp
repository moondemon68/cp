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

int a[1005][1005], b[1005][1005];
int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    a[0][0] = 0;
    a[0][1] = 0;
    a[0][2] = 0;
    a[0][3] = 3;
    a[0][4] = 4;
    a[1][0] = 2;
    a[1][1] = 4;
    a[1][2] = 0;
    a[1][3] = 0;
    a[1][4] = 1;
    a[2][0] = 0;
    a[2][1] = 0;
    a[2][2] = 3;
    a[2][3] = 4;
    a[2][4] = 0;
    a[3][0] = 5;
    a[3][1] = 0;
    a[3][2] = 0;
    a[3][3] = 0;
    a[3][4] = 2;
    a[4][0] = 0;
    a[4][1] = 3;
    a[4][2] = 4;
    a[4][3] = 0;
    a[4][4] = 0;
    if (n <= 3) {
        cout << "-1" << endl;
        return 0;
    }
    if (n == 5) {
        for (int i=0;i<5;i++) {
            for (int j=0;j<5;j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        return 0;
    }
    memset (a,0,sizeof(a));
    a[0][0] = 0;
    a[0][1] = 0;
    a[0][2] = 5;
    a[0][3] = 0;
    a[0][4] = 0;
    a[0][5] = 0;
    a[0][6] = 6;
    a[1][0] = 4;
    a[1][1] = 0;
    a[1][2] = 0;
    a[1][3] = 0;
    a[1][4] = 6;
    a[1][5] = 0;
    a[1][6] = 1;
    a[2][0] = 0;
    a[2][1] = 5;
    a[2][2] = 6;
    a[2][3] = 0;
    a[2][4] = 0;
    a[2][5] = 0;
    a[2][6] = 0;
    a[3][0] = 0;
    a[3][1] = 0;
    a[3][2] = 0;
    a[3][3] = 5;
    a[3][4] = 0;
    a[3][5] = 6;
    a[3][6] = 0;
    a[4][0] = 0;
    a[4][1] = 6;
    a[4][2] = 0;
    a[4][3] = 0;
    a[4][4] = 0;
    a[4][5] = 5;
    a[4][6] = 0;
    a[5][0] = 7;
    a[5][1] = 0;
    a[5][2] = 0;
    a[5][3] = 0;
    a[5][4] = 0;
    a[5][5] = 0;
    a[5][6] = 4;
    a[6][0] = 0;
    a[6][1] = 0;
    a[6][2] = 0;
    a[6][3] = 6;
    a[6][4] = 5;
    a[6][5] = 0;
    a[6][6] = 0;
    // for (int i=0;i<7;i++) {
    //     for (int j=0;j<7;j++) {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // memset (b,0,sizeof(b));
    for (int i=9;i<=n;i+=2) {
        if (i % 4 == 1) {
            memset (b,0,sizeof(b));
            for (int j=0;j<i/2-1;j++) {
                for (int k=0;k<i/2-1;k++) {
                    b[j][k] = a[j][k];
                    if (a[j][k] > 0) b[j][k] += 2;
                }
            }
            for (int j=0;j<i/2-1;j++) {
                for (int k=i/2;k<i;k++) {
                    b[j][k+2] = a[j][k];
                    if (a[j][k] > 1) b[j][k+2] += 2;
                    if (j == i/2-1) b[j][k] = 0;
                }
            }
            for (int j=i/2;j<i;j++) {
                for (int k=0;k<i/2-1;k++) {
                    b[j+2][k] = a[j][k];
                    if (a[j][k] > 1) b[j+2][k] += 2;
                    if (j == i/2+1 || k == i/2-1) b[j][k] = 0;
                }
            }
            for (int j=i/2;j<i;j++) {
                for (int k=i/2;k<i;k++) {
                    b[j+2][k+2] = a[j][k];
                    if (a[j][k] > 1) b[j+2][k+2] += 2;
                    if (j == i/2+1 || k == i/2+1) b[j][k] = 0;
                }
            }
            b[i/2][i/2] = i-2;
            swap(b[i/2-1][i/2-1], b[i/2-2][i/2-2]);
            b[i/2+1][i/2-2] = i-1;
            b[i/2-2][i/2+1] = i-1;
            b[0][i/2-2] = 0;
            b[0][i/2-1] = i-2;
            b[i/2-1][i/2-2] = i-2;
            b[i-1][i/2+2] = 0;
            b[i-1][i/2+1] = i-2;
            b[i/2+1][i/2+2] = i-2;
            b[i-1][i/2] = i-1;
            b[i/2][i-2] = i-1;
            // for (int j=0;j<i;j++) {
            //     for (int k=0;k<i;k++) {
            //         cout << b[j][k] << " ";
            //     }
            //     cout << endl;
            // }
        }
        else if (i % 4 == 3) {
            memset (a,0,sizeof(a));
            for (int j=0;j<i/2-1;j++) {
                for (int k=0;k<i/2-1;k++) {
                    a[j][k] = b[j][k];
                    if (b[j][k] > 0) a[j][k] += 2;
                }
            }
            for (int j=0;j<i/2-1;j++) {
                for (int k=i/2;k<i;k++) {
                    a[j][k+2] = b[j][k];
                    if (b[j][k] > 1) a[j][k+2] += 2;
                    if (j == i/2-1) a[j][k] = 0;
                }
            }
            for (int j=i/2;j<i;j++) {
                for (int k=0;k<i/2-1;k++) {
                    a[j+2][k] = b[j][k];
                    if (b[j][k] > 1) a[j+2][k] += 2;
                    if (j == i/2+1 || k == i/2-1) a[j][k] = 0;
                }
            }
            for (int j=i/2;j<i;j++) {
                for (int k=i/2;k<i;k++) {
                    a[j+2][k+2] = b[j][k];
                    if (b[j][k] > 1) a[j+2][k+2] += 2;
                    if (j == i/2+1 || k == i/2+1) a[j][k] = 0;
                }
            }
            a[i/2][i/2] = i-2;
            swap(a[i/2-1][i/2-1], a[i/2-2][i/2-2]);
            a[i/2+1][i/2-2] = i-1;
            a[i/2-2][i/2+1] = i-1;
            a[0][i/2-2] = 0;
            a[0][i/2-1] = i-2;
            a[i/2-1][i/2-2] = i-2;
            a[i-1][i/2+2] = 0;
            a[i-1][i/2+1] = i-2;
            a[i/2+1][i/2+2] = i-2;
            a[i-1][i/2] = i-1;
            a[i/2][i-2] = i-1;
            // for (int j=0;j<i;j++) {
            //     for (int k=0;k<i;k++) {
            //         cout << a[j][k] << "\t";
            //     }
            //     cout << endl;
            // }
        }
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (n % 4 == 1) {
                cout << b[i][j] << "\t";
            } else {
                cout << a[i][j] << " ";
            }
        }
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}