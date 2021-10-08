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
    double a[10], b[10];
    for (int i=1;i<=5;i++) cin >> a[i];
    for (int i=1;i<=5;i++) cin >> b[i];
    vector<double> v;
    for (int i=1;i<=5;i++) cout << a[i]-b[i];
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}