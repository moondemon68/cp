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
        int l,r,d;
        cin >> l >> r >> d;
        if (d<l) cout << d << endl;
        else if (r<d) cout << d << endl; 
        else cout << (r/d+1)*d << endl;
    }    
    return 0;
}
