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
    int a,b,m;
    cin >> a >> b >> m;
    set<int> s;
    s.insert(a);
    s.insert(b);
    for (int i=1;i<=1000000;i++) {
        int x=a+b;
        x%=m;
        s.insert(x);
        a=b;
        b=x;
    }
    cout << s.size() << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}