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
    int tc;
    cin >> tc;
    while (tc--) {
        int n,k;
        cin >> n >> k;
        if (n<k||k%3==2||k%3==1) {
            if (n%3==0) cout << "Bob";
            else cout << "Alice";
        } else if (n==k) {
            cout << "Alice";
        } else {
            n%=(k+1);
            if (n%3==0&&n!=k) cout << "Bob";
            else cout << "Alice";
        }
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}