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
    int q;
    cin >> q;
    int maxmax=0,maxmin=0;
    while (q--) {
        char t;
        cin >> t;
        int a,b;
        cin >> a >> b;
        if (t=='+') {
            maxmax=max(maxmax,max(a,b));
            maxmin=max(maxmin,min(a,b));
        } else {
            if (maxmin<=min(a,b)&&maxmax<=max(a,b)) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }    
    return 0;
}
