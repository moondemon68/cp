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
    while (q--) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        if (a!=c) cout << a << " " << c;
        else if (b!=c) cout << b << " " <<  c;
        else if (a!=d) cout << a << " " << d;
        else if (b!=d) cout << b << " " << d;
        cout << endl;
    }    
    return 0;
}
