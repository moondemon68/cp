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
    int n;
    cin >> n;
    int o=0,t=0;
    for (int i=1;i<=n;i++) {
        int x;
        cin >> x;
        if (x==1) o++; else t++;
    }
    if (t>0) {
        cout << 2 << " ";
        t--;
    }
    if (o>0) {
        cout << 1 << " ";
        o--;
    }
    while (t>0) {
        cout << 2 << " ";
        t--;
    }
    while (o>0) {
        cout << 1 << " ";
        o--;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}