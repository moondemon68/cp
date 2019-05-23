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
    int ans=0;
    for (int i=0;i<s.size()-1;i++) {
        if (i%2==0&&s[i]==s[i+1]) {
            ans++;
            s.erase(s.begin()+i);
            i--;
        }
    }
    bool y=0;
    if (s.size()%2==1) {
        y=1;
        ans++;
    } 
    if (!y) cout << ans << endl << s << endl; else {
        cout << ans << endl;
        for (int i=0;i<s.size()-1;i++) cout << s[i];
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}