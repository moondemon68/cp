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
    string alla="", allb="";
    for (int i=1;i<=300;i++) alla += 'a';
    for (int i=1;i<=300;i++) allb += 'b';
    cout << alla << endl;
    int ca, cb;
    cin >> ca;
    if (ca == 0) return 0;
    cout << allb << endl;
    cin >> cb;
    if (cb == 0) return 0;
    int cnt = 600 - ca - cb;
    int cnta = 300 - ca, cntb = 300 - cb;
    if (cnta == 0) {
        string s = "";
        for (int i=1;i<=cntb;i++) s += 'b';
        cout << s << endl;
        int x;
        cin >> x;
        return 0;
    } else if (cntb == 0) {
        string s = "";
        for (int i=1;i<=cnta;i++) s += 'a';
        cout << s << endl;
        int x;
        cin >> x;
        return 0;
    }
    // cout << cnt << " " << cnta << " " << cntb << endl;
    string test = "", ans = "";
    for (int i=1;i<=cnt;i++) {
        test += 'a';
        ans += 'a';
    }
    for (int i=0;i<cnt-1;i++) {
        test[i] = 'b';
        cout << test << endl;
        int x;
        cin >> x;
        if (x > cntb) {
            test[i] = 'a';
        } else {
            cntb--;
        }
    }
    if (cntb > 0) test.back() = 'b';
    cout << test << endl;
    int x;
    cin >> x;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}