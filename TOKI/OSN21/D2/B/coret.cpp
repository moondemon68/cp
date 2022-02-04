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
    ofstream cout("oprek.txt");
    for (int i=1;i<=127;i++) {
        for (int j=1;j<=127;j++) {
            if ((i^j) > max(i, j)) {
                cout << i << " " << j << " " << "Y" << endl;
            } else {
                cout << i << " " << j << " " << "N" << endl;
            }
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}