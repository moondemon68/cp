#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

int n;
int a[105];

bool check(int x) {
    int cnt = 0;
    for (int i=1;i<=n;i++) {
        cnt += a[i];
        if (cnt == x) cnt = 0;
        else if (cnt > x) return 0;
    }
    if (cnt == 0) return 1;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    string s;
    cin >> s;
    int t = 0;
    for (int i=1;i<=n;i++) {
        a[i]=s[i-1]-'0';
        t+=a[i];
    }
    bool y = 0;
    for (int i=0;i<t;i++) {
        if (check(i)) y = 1;
    }
    if (y || t == 0)  cout << "YES" << endl; else cout << "NO" << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}