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
    int q;
    cin >> q;
    while (q--) {
        LL a,b;
        cin >> a >> b;
        string s="",t="";
        while (a) {
            s+=(a%2)+'0';
            a/=2;
        }
        while (b) {
            t+=(b%2)+'0';
            b/=2;
        }
        reverse(s.begin(),s.end());
        reverse(t.begin(),t.end());
        int ans=0;
        while (s.size()>t.size()) {
            ans++;
            s.pop_back();
        }
        while (t.size()>s.size()) {
            ans++;
            t.pop_back();
        }
        while (!s.empty() && !t.empty() && s!=t) {
            ans+=2;
            s.pop_back();
            t.pop_back();
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}