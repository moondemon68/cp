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
    ifstream cin("1.in");
    ofstream cout("1.out");
    int a[10005];
    memset (a,0,sizeof(a));
    int p = 0, x;
    while (cin >> x) {
        a[p] = x;
        p++;
    }
    a[1] = 12;
    a[2] = 2;
    for (int i=0;i<p;i++) {
        cerr << i << endl;
        if (a[i] == 1) {
            a[a[i+3]] = a[a[i+1]] + a[a[i+2]];
            i += 3;
        } else if (a[i] == 2) {
            a[a[i+3]] = a[a[i+1]] * a[a[i+2]];
            i += 3;
        } else if (a[i] == 99) {
            cout << a[0] << endl;
            return 0;
        } else {
            cerr << "nyangkut di " << i << endl;
            return 0;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}