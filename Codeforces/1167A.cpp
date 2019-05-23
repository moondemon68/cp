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
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int p=-1;
        for (int i=0;i<s.size();i++) {
            if (s[i]=='8') {
                p=i;
                break;
            }
        }
        if (p==-1) {
            cout << "NO" << endl;
        }
        else if (s.size()-p-1>=10) {
            cout << "YES" << endl;
        } else cout << "NO" << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}