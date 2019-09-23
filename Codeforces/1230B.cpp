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
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (k==0) {
        cout << s << endl;
    } else {
        if (n==1&&s[0]!='0') {
            cout << 0 << endl;
            return 0;
        }
        if (s[0]!='1') {
            s[0]='1';
            k--;
        }
        for (int i=1;i<s.size();i++) {
            if (s[i]!='0'&&k>0) {
                s[i]='0';
                k--;
            }
        }
        cout << s << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}