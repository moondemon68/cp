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
    string s,t;
    cin >> s >> t;
    int a=s.size(),b=t.size();
    for (int i=0;i<4000000;i++) {
        s+=s[i%a];
        t+=t[i%b];
    }
    int i=0;
    while (n&&i<4000000) {
        //cout << s[i] << t[i] << endl;
        if (s[i]!=t[i]) {
            cout << i << endl;
            n--;
        }
        i++;
    }
    while (n--) cout << -1 << endl;
    //cout << s << endl;
    //cout << t << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}