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
    int l=1,h=1000000000;
    while (l<=h) {
        int m=(l+h)/2;
        cout << "Q " << m << endl;
        char c;
        cin >> c;
        if (c=='=') {
            return 0;
        } else if (c=='>') {
            l=m+1;
        } else {
            h=m-1;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}