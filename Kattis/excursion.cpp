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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    LL ans=0;
    LL cnt=0;
    string t="";
    for (LL i=0;i<s.size();i++) {
        if (s[i]=='0') {
            ans+=i-cnt;
            cnt++;
        } else t+=s[i];
    }
    cnt=0;
    for (LL i=0;i<t.size();i++) {
        if (t[i]=='1') {
            ans+=i-cnt;
            cnt++;
        }
    }
    cout << ans << endl;
    return 0;
}
