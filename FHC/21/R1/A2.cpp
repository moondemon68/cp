#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<LL,LL>
#define LL long long
using namespace std;

const int MAXN = 1000000;
LL z[MAXN+5], zz[MAXN+5];
int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ifstream cin("A1_input.txt");
    ofstream cout("A2_val_output.txt");
    LL tc;
    cin >> tc;
    for (LL t=1;t<=tc;t++) {
        LL n;
        cin >> n;
        string s;
        cin >> s;
        LL totalans = 0, ans = 0, type = 0;  // type: 0 FO, 1 FX
        LL p = 0;
        for (LL i = 0; i < s.size(); i++) {
            if (s[i] == 'O' || s[i] == 'X') {
                p = i;
                break;
            }
        }
        LL cur = 0;
        if (s[p] == 'O') {
            // dont switch
        } else {
            // switch X and O, so that it will always start at O
            for (LL i = 0; i < s.size(); i++) {
                if (s[i] == 'O') s[i] = 'X';
                else if (s[i] == 'X') s[i] = 'O';
            }
        }

        // it will always start with O or F
        // calculate all substring starting from 0
        for (LL i = 0; i < s.size(); i++) {
            if (type == 0) {
                if (s[i] == 'O' || s[i] == 'F') {
                    // pass
                } else {
                    type = 1;
                    cur++;
                }
            } else {
                if (s[i] == 'X' || s[i] == 'F') {
                    // pass
                } else {
                    type = 0;
                    cur++;
                }
            }
            ans += cur;
            ans %= MOD;
        }
        cout << "Case #" << t << ": " << cur << endl;
        continue;

        if (ans == 0) {
            cout << "Case #" << t << ": " << ans << endl;
            continue;
        }
        // tambel depan belakang
        if (s[n-1] == 'F') {
            char c;
            for (LL i = n-1; i >= 0; i--) {
                if (s[i] != 'F') {
                    c = s[i];
                    break;
                }
            }
            for (LL i = n-1; i >= 0; i--) {
                if (s[i] == 'F') {
                    s[i] = c;
                } else {
                    break;
                }
            }
        }
        if (s[0] == 'F') {
            char c;
            for (LL i = 0; i < n; i++) {
                if (s[i] != 'F') {
                    c = s[i];
                    break;
                }
            }
            for (LL i = 0; i < n; i++) {
                if (s[i] == 'F') {
                    s[i] = c;
                } else {
                    break;
                }
            }
        }
        // cout << s << endl;

        string w = s;
        for (LL i = w.size()-1; i >= 0; i -= 0) {
            if (w[i] == 'O') {
                i--;
                while (i >= 0 && w[i] == 'F') {
                    w[i] = 'O';
                    i--;
                }
            } else if (w[i] == 'X') {
                i--;
                while (i >= 0 && w[i] == 'F') {
                    w[i] = 'X';
                    i--;
                }
            } else {
                i--;
            }
        }
        string y = s;
        for (LL i = 0; i < y.size(); i += 0) {
            if (y[i] == 'O') {
                i++;
                while (i < y.size() && y[i] == 'F') {
                    y[i] = 'O';
                    i++;
                }
            } else if (y[i] == 'X') {
                i++;
                while (i < y.size() && y[i] == 'F') {
                    y[i] = 'X';
                    i++;
                }
            } else {
                i++;
            }
        }
        memset(z,0,sizeof(z));
        memset(zz,0,sizeof(zz));
        z[n-1] = 1;
        for (LL i = n - 2; i >= 0; i--) {
            if (w[i] == w[i+1]) z[i] = z[i+1] + 1;
            else z[i] = 1;
        }
        zz[n - 1] = n;
        for (LL i = n-2; i >= 0; i--) {
            if (y[i] == y[i+1]) zz[i] = zz[i+1];
            else zz[i] = i + 1;
        }
        // cout << w << endl;
        // for (LL i = 0; i < s.size(); i++) cout << z[i];
        // cout << endl << endl;
        // cout << y << endl;
        // for (LL i = 0; i < s.size(); i++) cout << zz[i];
        // cout << endl << endl;

        type = 0;
        totalans = 0;
        // cout << totalans << endl;
        for (LL i = 0; i < s.size(); i++) {
            // cout << i << " " << type << " ";
            if (type == 0) {
                if (w[i] == 'O') {
                    totalans += ans;
                } else if (w[i] == 'X') {
                    type = 1;
                    ans -= n - zz[i - 1];
                    ans += MOD;
                    ans %= MOD;
                    totalans += ans;
                }
            } else if (type == 1) {
                if (w[i] == 'O') {
                    type = 0;
                    ans -= n - zz[i - 1];
                    ans += MOD;
                    ans %= MOD;
                    totalans += ans;
                } else if (w[i] == 'X') {
                    totalans += ans;
                }
            }
            totalans %= MOD;
            // cout << w[i] << " " << ans << " " << totalans << endl;
        }
        cout << "Case #" << t << ": " << totalans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
/*
1
9
OFXFOFXFO

44

1
9
OFXFXFXFO

14

1
10
FOOFOFXXOF

36

1
22
FOXXFOXOFFOXFFFXOOOOFX

546
*/