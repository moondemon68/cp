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
    double a[1000005];
    a[0]=0;
    for (int i=1;i<=1000000;i++) {
        a[i]=log10(i)+a[i-1];
    }
    int n;
    while (cin >> n) {
        if (n==0||n==1) {
            cout << 1 << endl;
            continue;
        }
        cout  << fixed << setprecision(0) << ceil(a[n]) << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}