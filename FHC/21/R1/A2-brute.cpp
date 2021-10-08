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
    ifstream cin("A1_input.txt");
    // ofstream cout("A2_brute_val_output.txt");
    int tc;
    cin >> tc;
    for (int t=1;t<=tc;t++) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int sum = 0;
        for (int j=0;j<s.size();j++) {
            for (int k=1;k<=s.size()-j;k++) {
                string ss = s.substr(j, k);
                int ans = INT_MAX;
                for (int w=0;w<=1;w++) {
                    int type = w;
                    if (type == 0 && ss[0] == 'O') continue;
                    if (type == 1 && ss[0] == 'X') continue;
                    int cur = 0;
                    for (int i=0;i<ss.size();i++) {
                        if (type == 0) {
                            if (ss[i] == 'O') {
                                type = 1;
                                cur++;
                            }
                        } else if (type == 1) {
                            if (ss[i] == 'X') {
                                type = 0;
                                cur++;
                            }
                        }
                    }
                    ans = min(ans, cur);
                }
                sum += ans;
            }
        }
        cout << "Case #" << t << ": " << ans << endl;
        // cout << sum << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
/*
1
9
XFOFXFOFX
*/