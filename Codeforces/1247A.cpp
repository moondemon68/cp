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

int left(int x) {
    while (x) {
        if (x<10) return x;
        x/=10;
    }
    return 0;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a,b;
    cin >> a >> b;
    for (int i=1;i<100000;i++) {
        if (left(i)==a && left(i+1)==b) {
            cout << i << " " << i+1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}