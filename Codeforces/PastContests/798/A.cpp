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
    string s;
    cin >> s;
    int cnt = 0;
    for (int i=0;i<s.size()/2;i++) {
        if (s[i] != s[s.size()-i-1]) cnt++;
    }
    if (s.size() % 2 == 1) {
        if (cnt <= 1) cout << "YES";
        else cout << "NO";
    } else {
        if (cnt == 1) cout << "YES";
        else cout << "NO";
    }
    cout << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}