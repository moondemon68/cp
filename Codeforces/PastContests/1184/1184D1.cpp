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
    int n,k,m,t;
    cin >> n >> k >> m >> t;
    int s=1,e=n;
    while (t--) {
        int op,x;
        cin >> op >> x;
        if (op==0) {
            int s1=s,e1=x,s2=x+1,e2=e;
            if (k>=s1&&k<=e1) {
                s=s1;
                e=e1;
            } else {
                int p=s2-1;
                s=s2;
                e=e2;
            }
            int p=s-1;
            s-=p;
            e-=p;
            k-=p;
        } else {
            e++;
            if (x<=k) k++; 
        }
        cout << e << " " << k << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}