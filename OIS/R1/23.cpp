#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

vector<int> v;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i=1;i<=100000000;i++) {
        int x=i, p=0, q=0;
        while (x) {
            p+=x%2;
            x/=2;
        }
        x=i;
        while (x) {
            q+=x%3;
            x/=3;
        }
        if (p == q) v.pb(i);
    }
    int t;
    cin >> t; 
    while (t--) {
        int x;
        cin >> x;
        int l=0,h=v.size()-1,ans=-1;
        while (l<=h) {
            int m = (l+h)/2;
            if (x >= v[m]) {
                l=m+1;
                ans= m;
            } else {
                h=m-1;
            }
        }
        cout << ans+1 << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}