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
    ifstream cin("2.in");
    ofstream cout("2.out");
    int a[10005];
    memset (a,0,sizeof(a));
    int p = 0, x;
    while (cin >> x) {
        a[p] = x;
        p++;
    }
    for (int g=0;g<=99;g++) {
        for (int h=0;h<=99;h++) {
            int b[10005];
            for (int i=0;i<p;i++) b[i] = a[i];
            b[1] = g;
            b[2] = h;
            for (int i=0;i<p;i++) {
                if (b[i] == 1) {
                    b[b[i+3]] = b[b[i+1]] + b[b[i+2]];
                    i += 3;
                } else if (b[i] == 2) {
                    b[b[i+3]] = b[b[i+1]] * b[b[i+2]];
                    i += 3;
                } else if (b[i] == 99) {
                    //cout << g << " " << h << " " << b[0] << " " << endl;
                    if (b[0] == 19690720) {
                        cout << g*100 + h << endl;
                        return 0;
                    }
                } else {
                    break;
                }
            }
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}