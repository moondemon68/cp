//Menggantikan Admin
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
    int n;
    cin >> n;
    map<string,int> m;
    while (n--) {
        string s;
        cin >> s;
        if (s[0]=='D') {
            string p;
            cin >> p;
            m[p]++;
        } else {
            string p;
            cin >> p;
            cout << m[p] << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}