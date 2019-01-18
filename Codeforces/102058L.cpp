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
    LL k;
    cin >> k;
    string t=s;
    reverse(t.begin(),t.end());
    for (int i=0;i<s.size();i++) {
        if (s[i]!=t[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }    
    cout << "YES" << endl;
    return 0;
}
