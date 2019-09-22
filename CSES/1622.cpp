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
    string s;
    cin >> s;
    vector<string> p;
    sort (s.begin(),s.end());
    do {
        p.pb(s);
    } while (next_permutation(s.begin(),s.end()));
    cout << p.size() << endl;
    for (int i=0;i<p.size();i++) cout << p[i] << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}