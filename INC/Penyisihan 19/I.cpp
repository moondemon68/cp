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
    int n;
    cin >> n;
    string s,t;
    cin >> s >> t;
    int ans=0,c=0,p=0;
    for (int j=1;j<=26;j++) {
        p=0;
        for (int i=0;i<s.size();i++) {
            if (s[i]-'a'==c) p++;
            else if (t[i]-'a'==c) p++;
        }
        ans=max(ans,p);
        c++;
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}