#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

int a[100005];

void sieve(int x) {
    memset (a,-1,sizeof(a));
    int p=0;
    for (int i=2;i<=x;i++) {
        if (a[i]!=-1) continue;
        p++;
        for (int j=i;j<=x;j+=i) {
            if (a[j]==-1) a[j]=p;
        }
    }
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    sieve(100000);
    for (int i=2;i<=n;i++) cout << a[i] << " ";
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}