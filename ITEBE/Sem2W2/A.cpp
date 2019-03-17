#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

LL gcd(LL a,LL b,LL &x,LL &y) {
    if (a==0) {
        x=0;
        y=1;
        return b;
    }
    LL x1,y1;
    LL d=gcd(b%a,a,x1,y1);
    x=y1-(b/a)*x1;
    y=x1;
    return d;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--) {
        LL a,n,b,m;
        cin >> a >> n >> b >> m;
        if (__gcd(n,m)==1) {
            LL x,y;
            LL ans=gcd(n,m,x,y);
            LL lcm=n*m/__gcd(n,m),d=__gcd(n,m);
            LL ans1=a;
            LL ans2=(((x*(b-a)/d)%(m/d))*n)%lcm;
            LL tmp=ans1+ans2;
            tmp%=lcm;
            if (tmp<0) tmp+=lcm;
            cout << tmp << " " << lcm << endl;
        }
        else {
            LL g=__gcd(n,m);
            if ((a%g)!=(b%g)) {
                cout << "no solution" << endl;
            } else {
                LL x,y;
                LL ans=gcd(n,m,x,y);
                LL lcm=n*m/__gcd(n,m),d=__gcd(n,m);
                LL ans1=a;
                LL ans2=(((x*(b-a)/d)%(m/d))*n)%lcm;
                LL tmp=ans1+ans2;
                tmp%=lcm;
                if (tmp<0) tmp+=lcm;
                cout << tmp << " " << lcm << endl;
            }
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}