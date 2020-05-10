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
    int tc;
    cin >> tc;
    for (int t=1;t<=tc;t++){
        int ans = -1;
        int x,y;
        string s;
        cin >> x >> y >> s;
        for (int i=0;i<s.size();i++) {
            if (s[i] == 'S') y--;
            else if (s[i] == 'N') y++;
            else if (s[i] == 'E') x++;
            else x--;
            if ((abs(x) + abs(y)) <= (i+1)) {
                ans = i+1;
                break;
            }
        }
        if (ans == -1) cout << "Case #" << t << ": " << "IMPOSSIBLE" << endl;
        else cout << "Case #" << t << ": " << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}