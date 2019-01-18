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
    for (int t=1;t<=tc;t++) {
        int n,k;
        cin >> n >> k;
        cout << "Case #" << t << ": ";
        int x=1;
        for (int i=1;i<=n;i++) x*=2;
        k%=x;
        x--;
        if (k>=x) cout << "ON" << endl;
        else cout << "OFF" << endl;
    }    
    return 0;
}
