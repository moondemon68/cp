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
    int n;
    cin >> n;
    LL a[n+5];
    for (int i=1;i<=n;i++) {
        a[i] = rand()%(1<<30);
    }

    LL p = 0;
    for (int i=1;i<=n;i++) p |= a[i];
    cout << p << endl;
    p = 0;
    for (int i=1;i<=n/2;i++) p |= a[i];
    cout << p << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}