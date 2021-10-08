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
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<string> v;
    string cur = "";
    for (int i=0;i<s.size();i++) {
        cur += s[i];
        string t = cur;
        while (t.size() < k) {
            t += cur;
        }
        v.pb(t.substr(0, k));
    }
    sort(v.begin(), v.end());
    cout << v[0] << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}