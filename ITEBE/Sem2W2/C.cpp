// Unique Substring Finding -> Hashing (2 hashkeys)
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

LL compHash(string s,LL p, LL m) {
    LL ret=0,pPow=1;
    for (int i=0;i<(int)s.size();i++) {
        ret+=(s[i]-'a'+1)*pPow;
        ret%=m;
        pPow*=p;
        pPow%=m;
    }
    return ret;
}

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

LL inverseModulo(LL a,LL m) {
    LL x,y;
    LL ans=gcd(a,m,x,y);
    return (x%m+m)%m;
}

LL fastPow(LL a,LL x,LL m) {
    LL ret=1;
    while (x>0) {
        if (x&1) {
            ret*=a;
            ret%=m;
        }
        x=x>>1;
        a*=a;
        a%=m;
    }
    return ret;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--) {
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        LL hash1[n+5];
        memset (hash1,0,sizeof(hash1));
        hash1[0]=compHash(s.substr(0,k),5,MOD);
        //cout << hash1[0] << endl;
        for (int i=1;i<=n-k;i++) {
            //cout << hash1[i-1] << endl;
            LL x=(hash1[i-1]-(s[i-1]-'a'+1));
            //cout << "*" << x << endl;
            LL p=inverseModulo(5,MOD);
            x=(x*p)%MOD;
            x+=(s[i+k-1]-'a'+1)*fastPow(5,k-1,MOD);
            x%=MOD;
            hash1[i]=x;
            //cout << hash1[i] << endl;
        }

        LL hash2[n+5];
        memset (hash2,0,sizeof(hash2));
        hash2[0]=compHash(s.substr(0,k),7,MOD+2);
        //cout << hash1[0] << endl;
        for (int i=1;i<=n-k;i++) {
            LL x=(hash2[i-1]-(s[i-1]-'a'+1));
            LL p=inverseModulo(7,MOD+2);
            x=(x*p)%(MOD+2);
            x+=(s[i+k-1]-'a'+1)*fastPow(7,k-1,(MOD+2));
            x%=(MOD+2);
            hash2[i]=x;
        }

        set<pair<LL,LL>> ans;
        for (int i=0;i<=n-k;i++) {
            ans.insert(mp(hash1[i],hash2[i]));
        }
        cout << ans.size() << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}