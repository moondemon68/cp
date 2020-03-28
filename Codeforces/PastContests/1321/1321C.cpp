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
    string s;
    cin >> s;
    int ans = 0;
    for (int i=0;i<200;i++) {
        char c = 'a'-1;
        int x = -1;
        for (int j=0;j<s.size();j++) {
            if (s[j] > c && ((j < s.size()-1 && s[j+1]-s[j] == -1) || (j > 0 && s[j-1]-s[j] == -1))) {
                c = s[j];
                x = j;
            }
        }
        if (x != -1) {
            ans++;
            s.erase(s.begin()+x);
        }
    }
    cout << ans << endl;
    // cout << s << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}