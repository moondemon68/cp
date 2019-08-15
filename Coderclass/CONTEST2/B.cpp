#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<int,int>
#define LL unsigned long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL a,b;
    cin >> a >> b;
    LL p,q;
    a--;
    if (a%4==0) p=a; 
    else if (a%4==1) p=1;
    else if (a%4==2) p=a+1;
    else p=0;
    if (b%4==0) q=b; 
    else if (b%4==1) q=1;
    else if (b%4==2) q=b+1;
    else q=0;
    p=p^q;
    //cout << p << q;
    vector<LL> pp;
    while (p>0) {
        pp.pb(p%2);
        p/=2;
    }
    if (pp.empty()) {
        cout << 0 << endl;
        return 0;
    }
    for (int i=pp.size()-1;i>=0;i--) cout << pp[i];
    cout << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}