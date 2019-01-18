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
        int n;
        cin >> n;
        int a[n+5];
        for (int i=1;i<=n;i++) cin >> a[i];
        int x=a[2]-a[1];
        bool y=1;
        for (int i=1;i<n;i++) {
            if (a[i+1]-a[i]!=x) y=0;
        }
        if (y) {
            cout << "arithmetic" << endl;
            continue;
        }
        y=1;
        sort (a+1,a+n+1);
        x=a[2]-a[1];
        for (int i=1;i<n;i++) {
            if (a[i+1]-a[i]!=x) y=0;
        }
        if (y) {
            cout << "permuted arithmetic" << endl;
            continue;
        } else {
            cout << "non-arithmetic" << endl;
            continue;
        }
    }    
    return 0;
}

