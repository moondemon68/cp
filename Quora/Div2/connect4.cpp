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

int dx[8] = {0,-1,-1,-1,0,1,1,1};
int dy[8] = {1,0,-1,1,-1,0,-1,1};

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a[10][10];
    for (int i=1;i<=7;i++) {
        for (int j=1;j<=7;j++) {
            a[i][j] = 2;
        }
    }
    int turn = 1;
    for (int t=1;t<=42;t++) {
        int x;
        cin >> x;
        int place = 1;
        for (int i=1;i<=6;i++) {
            if (a[i][x] == 2) place = i;
        }
        a[place][x] = turn;
        // for (int i=1;i<=6;i++) {
        //     for (int j=1;j<=7;j++) {
        //         cout << a[i][j];
        //     }
        //     cout << endl;
        // }

        for (int i=1;i<=6;i++) {
            for (int j=1;j<=7;j++) {
                if (a[i][j] == 2) continue;
                for (int k=0;k<4;k++) {
                    int cnt = 0;
                    for (int p=0;p<4;p++) {
                        int ni = dx[k]*p + i, nj = dy[k]*p + j;
                        if (ni >= 1 && ni <= 6 && nj >= 1 && nj <= 7 && a[ni][nj] == turn) {
                            cnt++;
                        }
                    }
                    if (cnt == 4) {
                        if (turn == 1) cout << "RED " << t << endl;
                        else cout << "YELLOW " << t << endl;
                        return 0;
                    }
                }
            }
        }
        turn = 1 - turn;
    }
    cout << "DRAW" << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}