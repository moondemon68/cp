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
    stack<int> s;
    for (int i=1;i<=11;i++) {
        int x;
        cin >> x;
        s.push(x);
    }
    float p = 0;
    for (int i=11;i>=1;i--) {
        int x = s.top();
        s.pop();
        float a = sqrt(abs(x));
        int b = x*x*x * 5;
        float res = a + b;
        if (res > 400) printf("f(%d) = MAGNA NIMIS!\n", x);
        else printf("f(%d) = %.2f\n", x, res);
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}