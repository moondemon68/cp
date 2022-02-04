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
    int n, k;
    cin >> n;
    int a[n+5];
    for (int i=1;i<=n;i++) a[i] = i;
    int b[n+5];
    memset(b,0,sizeof(b));
    int c[n+5][n+5];
    memset(c,0,sizeof(c));
    do {
        int cnt = 0;
        for (int j=1;j<n;j++) {
            if (a[j] < a[j+1]) cnt++;
        }
        b[cnt]++;
        c[a[1]][cnt]++;
    } while (next_permutation(a+1,a+n+1));
    for (int i=0;i<n;i++) {
        cout << b[i] << " ";
    }
    cout << endl;
    for (int i=1;i<=n;i++) {
        for (int j=0;j<n;j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
/*
1
1 1
1 4 1
1 11 11 1
1 26 66 26 1
1 57 302 302 57 1
1 120 1191 2416 1191 120 1
1 247 4293 15619 15619 4293 247 1
1 502 14608 88234 156190 88234 14608 502 1
1 1013 47840 455192 1310354 1310354 455192 47840 1013 1 
1 2036 152637 2203488 9738114 15724248 9738114 2203488 152637 2036 1 
*/