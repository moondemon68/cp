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
    int tc;
    cin >> tc;
    while (tc--) {
        string s,t,p;
        cin >> s >> t >> p;
        int a[30];
        memset (a,0,sizeof(a));
        for (int i=0;i<p.size();i++) {
            a[p[i]-'a'+1]++;
        }
        bool y=1;
        int l=0,r=0;
        while (l<s.size()&&r<t.size()) {
            if (s[l]==t[r]) {
                l++;
                r++;
            } else if (a[t[r]-'a'+1]>0) {
                a[t[r]-'a'+1]--;
                r++;
            } else {
                y=0;
                break;
            }
        }
        while (r<t.size()) {
            if (a[t[r]-'a'+1]>0) {
                a[t[r]-'a'+1]--;
                r++;
            }
            else {
                y=0;
                break;
            }
        }
        if (!y||l!=s.size()) cout << "NO" << endl;
        else {
            cout << "YES" << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}