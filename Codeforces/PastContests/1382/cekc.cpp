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
    string a;
    // cin >> a;
    a = "0110011011";
    string b;
    b = "1000110100";
    int n;
    n = a.size() * 2;
    for (int j=1;j<=a.size();j++) {
        if (a[j-1] == '1') cout << j << " ";
    }
    cout << endl;
    for (int i=1;i<=n;i++) {
        int x;
        cin >> x;
        for (int j=1;j<=x;j++) {
            if (a[j-1] == '0') a[j-1] = '1'; else a[j-1] = '0';
        }
        reverse(a.begin(), a.begin()+x);
        cout << a << endl;
        if (a == b) break;
        for (int j=1;j<=a.size();j++) {
            if (a[j-1] == '1') cout << j << " ";
        }
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}