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
    vector<int> v[20005];
    for (int i=1;i<=20000;i++) {
        for (int j=1;j*j<=i;j++) {
            if (i%j == 0) {
                v[i].pb(j);
                v[i].pb(i/j);
            }
        }
    }
    int tc;
    cin >> tc;
    while (tc--) {
        int a,b,c;
        cin >> a >> b >> c;
        int ans = INT_MAX, ansa = -1, ansb = -1, ansc = -1;
        for (int k=1;k<=20000;k++) {
            for (int i=0;i<v[k].size();i++) {
                int newb = v[k][i];
                if (abs(c-k)+abs(newb-b) > ans) continue;
                for (int j=0;j<v[newb].size();j++) {
                    int newa = v[newb][j];
                    int score = abs(newa-a) + abs(newb-b) + abs(c-k);
                    if (score < ans) {
                        ans = score;
                        ansa = newa;
                        ansb = newb;
                        ansc = k;
                    }
                }
            }
        }
        cout << ans << endl << ansa << " " << ansb << " " << ansc << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}