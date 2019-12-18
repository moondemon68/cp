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
    int k;
    cin >> k;
    for (int i=5;i<=k;i++) {
        if (k%i==0&&(k/i)>=5) {
            string a="aeiou";
            int r=i,c=k/i;
            char p[r+5][c+5];
            for (int i=1;i<=r;i++) {
                for (int j=1;j<=c;j++) {
                    p[i][j]=a[(i+j)%5];
                }
            }
            for (int i=1;i<=r;i++) {
                for (int j=1;j<=c;j++) {
                    cout << p[i][j];
                }
            }
            return 0;
        }
    }
    cout << -1 << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}