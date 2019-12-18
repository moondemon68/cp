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
    clock_t start = clock();
    int q;
    cin >> q;
    set<int> p;
    int a=1;
    for (int i=1;i<=25;i++) {
        a*=2;
        p.insert(a-1);
    }
    while (q--) {
        int n;
        cin >> n;
        if (!p.count(n)) {
            int b=1;
            for (int i=1;i<=25;i++) {
                b*=2;
                if (b>n) {
                    cout << b-1 << endl;
                    break;
                }
            }
        } else {
            int maxi=0;
            for (int i=1;i<n;i++) {
                maxi=max(maxi,__gcd(n^i,n&i));
            }
            cout << maxi << endl;
        }
    }
    //cerr << "time=" << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}