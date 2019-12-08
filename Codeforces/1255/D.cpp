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
    string p = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int tc;
    cin >> tc;
    while (tc--) {
        int r, c, k;
        cin >> r >> c >> k;
        string a[r+5];
        for (int i=0;i<r;i++) {
            string s;
            cin >> s;
            if (i % 2 == 1) reverse(s.begin(), s.end());
            a[i] = s;
        }
        queue<char> q;
        for (int i=0;i<k;i++) q.push(p[i]);
        int cnt=0;
        for (int i=0;i<r;i++) {
            for (int j=0;j<c;j++) {
                if (a[i][j] == 'R') cnt++;
            }
        }
        int n = cnt/k, m = cnt%k;
        cnt = 0;
        char cur = q.front();
        q.pop();
        char ans[r+5][c+5];
        for (int i=0;i<r;i++) {
            for (int j=0;j<c;j++) {
                if (a[i][j] == 'R') cnt++;
                ans[i][j] = cur;
                if (m) {
                    if (cnt == n+1) {
                        cnt = 0;
                        if (!q.empty()) {
                            cur = q.front();
                            q.pop();
                        }
                        m--;
                    }
                } else {
                    if (cnt == n) {
                        cnt = 0;
                        if (!q.empty()) {
                            cur = q.front();
                            q.pop();
                        }
                    }
                }
                //cout << cnt << " ";
            }
        }
        for (int i=0;i<r;i++) {
            if (i%2==0) {
                for (int j=0;j<c;j++) cout << ans[i][j];
            } else {
                for (int j=c-1;j>=0;j--) cout << ans[i][j];
            }
            cout << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}