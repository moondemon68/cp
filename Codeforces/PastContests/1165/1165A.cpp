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
    int n,x,y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    int ans=0;
    for (int i=s.size()-1;i>s.size()-1-y;i--) {
        if (s[i]=='1') {
            s[i]='0';
            ans++;
        }
    }
    if (s[s.size()-1-y]=='0') ans++;
    for (int i=s.size()-1-y-1;i>s.size()-1-x;i--)  {
        if (s[i]=='1') {
            s[i]='0';
            ans++;
        }
    }
    //cout << s << endl;
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}