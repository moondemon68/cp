#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<LL,LL>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL a[3], b[3];
    cin >> b[0] >> b[1] >> b[2];
    a[0] = b[0];
    a[1] = b[1];
    a[2] = b[2];
    sort (a,a+3);
    cout << "First" << endl;
    cout << a[2]*2 - a[0] - a[1] << endl;
    LL p;
    cin >> p;
    b[p-1]+=a[2]*2 - a[0] - a[1];
    a[0] = b[0];
    a[1] = b[1];
    a[2] = b[2];
    sort (a,a+3);
    if (a[2]-a[1] == a[1]-a[0]) {
        cout << a[2]-a[1] << endl;
        LL x;
        cin >> x;
        return 0;
    }

    cout << a[2]*2 - a[0] - a[1] << endl;
    cin >> p;
    b[p-1]+=a[2]*2 - a[0] - a[1];
    a[0] = b[0];
    a[1] = b[1];
    a[2] = b[2];
    sort (a,a+3);
    if (a[2]-a[1] == a[1]-a[0]) {
        cout << a[2]-a[1] << endl;
        LL x;
        cin >> x;
        return 0;
    }

    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}