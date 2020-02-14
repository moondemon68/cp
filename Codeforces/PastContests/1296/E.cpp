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
    string s;
    cin >> s;
    string t = s;
    sort (t.begin(), t.end());
    string k = "", p = "", q = "";
    int ans[n+5];
    memset (ans,-1,sizeof(ans));
    for (int i=0;i<s.size();i++) {
        k += s[i];
        p += s[i];
        q += t[i];
        sort (p.begin(), p.end());
        if (p == q) {
            int start = i-k.size()+1;
            ans[start] = 0;
            for (int j=0;j<k.size();j++) {
                for (int l=j+1;l<k.size();l++) {
                    if (k[j] > k[l] && (ans[start+j] == ans[start+l] || ans[start+l] == -1)) {
                        ans[start+l] = 1-ans[start+j];
                    }
                }
            }
            for (int j=0;j<k.size();j++) {
                for (int l=j+1;l<k.size();l++) {
                    if (k[j] > k[l] && ans[start+j] == ans[start+l]) {
                        cout << k << endl;
                        cout << "NO" << endl;
                        // return 0;
                    }
                }
            }
            k = "";
            p = "";
            q = "";
        }
    }
    cout << "YES" << endl;
    for (int i=0;i<n;i++) cout << ans[i];
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}