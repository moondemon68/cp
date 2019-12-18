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
    int q;
    cin >> q;
    while (q--) {
        LL n;
        cin >> n;
        LL ans=0;
        while (n>1&&ans>=0) {
            if (n%2==0) {
                ans++;
                n/=2;
            } else if (n%3==0) {
                n/=3;
                n*=2;
                ans++;
            } else if (n%5==0) {
                n/=5;
                n*=4;
                ans++;
            } else {
                ans=-1;
                break;
            }
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}