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
    int ans=0,run=0;
    for (int i=0;i<s.size();i++) {
        if ((s[i]-'0')%3==0)  {
            ans++;
            run=0;
        }
        else {
            run+=(s[i]-'0')%3;
            run%=3;
            if (run==0) ans++; 
        }
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}