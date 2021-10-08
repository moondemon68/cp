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

int getnum(char c) {
    if (c == 'A') return 12;
    else if (c == 'K') return 11;
    else if (c == 'Q') return 10;
    else if (c == 'J') return 9;
    else if (c == 'X') return 8;
    else return (int)(c - '2');
}

char getchar(int c) {
    if (c == 12) return 'A';
    if (c == 11) return 'K';
    if (c == 10) return 'Q';
    if (c == 9) return 'J';
    if (c == 8) return 'X';
    return (char)(c + '2');
}

int pow(int n, int k) {
    int ret = 1;
    for (int i=1;i<=k;i++) ret *= n;
    return ret;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin >> n >> k;
    if (k > 6) {
        cout << "impossible" << endl;
        return 0;
    }
    string s;
    cin >> s;
    string t;
    cin >> t;
    int cnt[13];
    for (int i=0;i<13;i++) cnt[i] = 4;
    for (int i=0;i<s.size();i++) {
        cnt[getnum(s[i])]--;
    }
    int it = pow(13, k);
    int a[13];
    int maxscore = 0;
    string ans = "";
    for (int i=0;i<it; i++) {
        int x = i;
        bool fail = 0;
        vector<int> v;
        for (int j=0;j<13;j++) a[j] = cnt[j];
        int prev = 0;
        while (v.size() < k) {
            v.pb(x % 13);
            a[x % 13]--;
            if (a[x % 13] < 0) {
                fail = 1;
                break;
            }
            x /= 13;
        }
        for (int j=0;j<13;j++) a[j] = 4;
        for (int j=0;j<v.size();j++) {
            a[v[j]]--;
            if (a[v[j]] == 3) prev += 0;
            else if (a[v[j]] == 2) prev += 1;
            else if (a[v[j]] == 1) prev += 19;
            else if (a[v[j]] == 0) prev += 1739;
        }
        if (fail) continue;
        for (int j=0;j<n;j++) {
            int next = prev;
            a[getnum(s[j])]--;
            // cout << getnum(s[j]) << " " << a[getnum(s[j])] << endl;
            if (a[getnum(s[j])] == 3) next += 0;
            else if (a[getnum(s[j])] == 2) next += 1;
            else if (a[getnum(s[j])] == 1) next += 19;
            else if (a[getnum(s[j])] == 0) next += 1739;
            if (prev == next && t[j] == 'y') {
                fail = 1;
            }
            if (prev < next && t[j] == 'n') {
                fail = 1;
            }
            prev = next;
        }
        if (fail) continue;

        string answ = "";
        for (int j=0;j<v.size();j++) {
            answ += getchar(v[j]);
        }
        // cout << prev << " " << answ << endl;
        if (prev > maxscore) {
            maxscore = prev;
            string answ = "";
            for (int j=0;j<v.size();j++) {
                answ += getchar(v[j]);
            }
            ans = answ;
        } else if (prev == maxscore) {
            string answ = "";
            for (int j=0;j<v.size();j++) {
                answ += getchar(v[j]);
            }
            int y = 0;
            for (int j=0;j<v.size();j++) {
                // cout << v[j] << " " << getnum(ans[j]) << endl;
                if (v[j] < getnum(ans[j])) {
                    y = 1;
                    break;
                } else if (v[j] > getnum(ans[j])) {
                    y = -1;
                    break;
                }
            }
            if (y == 1) ans = answ;
        }
    }
    if (ans == "") cout << "impossible" << endl; else cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}