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
    int l=0,r=s.size()-1;
    string ans="";
    while (r-l>=3) {
        if (s[l]==s[r]) {
            ans+=s[l];
            l++;
            r--;
        } else if (s[l]==s[r-1]) {
            ans+=s[l];
            l++;
            r-=2;
        } else {
            ans+=s[l+1];
            if (s[l+1]==s[r]) r--;
            else r-=2;
            l+=2;
        }
    }
    cout << ans;
    if (r>=l) ans+=s[l];
    reverse(ans.begin(),ans.end());
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}