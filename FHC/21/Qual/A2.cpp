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
    ifstream cin("consistency_chapter_2_input.txt");
    ofstream cout("consistency_chapter_2_output.txt");
    int tc;
    cin >> tc;
    for (int t=1;t<=tc;t++) {
        string s;
        cin >> s;
        int m;
        cin >> m;
        int d[30][30];
        for (int i=0;i<26;i++) {
            for (int j=0;j<26;j++) {
                d[i][j] = 1000000;
            }
            d[i][i] = 0;
        }
        for (int i=1;i<=m;i++) {
            string p;
            cin >> p;
            d[p[0]-'A'][p[1]-'A'] = 1;
        }
        for (int k=0;k<26;k++) {
            for (int i=0;i<26;i++) {
                for (int j=0;j<26;j++) {
                    if (d[i][j] > d[i][k] + d[k][j]) {
                        d[i][j] = d[i][k] + d[k][j];
                    }
                }
            }
        }
        int ans = INT_MAX;
        for (int i=0;i<26;i++) {
            int cur = 0;
            for (int j=0;j<s.size();j++) {
                cur += d[s[j]-'A'][i];
            }
            ans = min(ans, cur);
        }
        if (ans >= 1000000) ans = -1;
        cout << "Case #" << t << ": " << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}