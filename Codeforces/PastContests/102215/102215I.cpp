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
    LL a,b;
    cin >> a >> b;
    if (a%b==0) {
        cout << (a-b)*(a/b)+(a/b-1)*b << endl;
    } else {
        cout << (a-b)*(a/b+1)+(a/b-1)*b+a%b << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}