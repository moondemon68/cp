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
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int a[n+5];
        int p = n, x = 1;
        for (int i=1;i<=n;i++) {
            if (i == n || s[i-1] == '>') {
                for (int j=i;j>=x;j--) {
                    a[j] = p;
                    p--;
                }
                x = i+1;
            }
        }
        for (int i=1;i<=n;i++) cout << a[i] << " ";
        cout << endl;
        p = 1;
        x = 1;
        for (int i=1;i<=n;i++) {
            if (i == n || s[i-1] == '<') {
                for (int j=i;j>=x;j--) {
                    a[j] = p;
                    p++;
                }
                x = i+1;
            }
        }
        for (int i=1;i<=n;i++) cout << a[i] << " ";
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}