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

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ifstream cin("B_input.txt");
    ofstream cout("B_output.txt");
    int tc;
    cin >> tc;
    for (int t=1;t<=tc;t++) {
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        if (a >= (n + m - 1) && b >= (n + m - 1)) {
            cout << "Case #" << t << ": " << "Possible" << endl;
            int c[n+5][m+5];
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    c[i][j] = 1;
                }
            }
            for (int i = 1; i < n; i++) {
                for (int j = 2; j < m; j++) {
                    c[i][j] = 1000;
                }
            }
            c[1][1] = a - (n + m - 2);
            c[1][m] = b - (n + m - 2);
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    cout << c[i][j] << " ";
                }
                cout << endl;
            }
        } else {
            cout << "Case #" << t << ": " << "Impossible" << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}