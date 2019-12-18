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
    int tc;
    cin >> tc;
    while (tc--) {
      LL a,b,c;
      cin >> a >> b >> c;
      cout << a*(c/2)-b*(c/2)+a*(c%2) << endl;
    }
    return 0;
}
