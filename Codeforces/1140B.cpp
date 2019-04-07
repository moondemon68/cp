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
        int ans1=0,ans2=0;
        for (int i=0;i<s.size();i++) {
            if (s[i]=='>') break;
            else ans1++;
        }
        for (int i=s.size()-1;i>=0;i--) {
            if (s[i]=='<') break;
            else ans2++;
        }
        cout << min(ans1,ans2) << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}