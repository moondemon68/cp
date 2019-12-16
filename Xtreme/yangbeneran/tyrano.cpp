#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<LL,LL>
#define LL long long
using namespace std;

LL fac[100001]; 
/* Iterative Function to calculate (x^y)%p 
  in O(log y) */
LL power(LL x, LL y, LL p) 
{ 
    LL res = 1;      // Initialize result 
  
    x = x % p;  // Update x if it is more than or 
                // equal to p 
  
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p; 
    } 
    return res; 
} 
  
// Returns n^(-1) mod p 
LL modInverse(LL n, LL p) 
{ 
    return power(n, p-2, p); 
} 
  
// Returns nCr % p using Fermat's little 
// theorem. 
LL nCrModPFermat(LL n, LL r, LL p) 
{ 
   // Base case 
   if (r==0) 
      return 1; 
  
    // Fill factorial array so that we 
    // can find all factorial of r, n 
    // and n-r 
    
  
    return (fac[n]* modInverse(fac[r], p) % p * 
            modInverse(fac[n-r], p) % p) % p; 
} 

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fac[0] = 1; 
    for (LL i=1 ; i<=100000; i++) fac[i] = (fac[i-1]*i)%MOD; 
    LL n,q,k;
    cin >> n >> k >> q;
    LL a[n+5];
    for (LL i=1;i<=n;i++) cin >> a[i];
    while (q--) {
        char c;
        cin >> c;
        if (c=='U') {
            LL x,y;
            cin >> x >> y;
            a[x]=y;
        } else {
            LL ans=0;
            LL l,r;
            cin >> l >> r;
            for (LL i=l;i<=r;i++) {
                // cout << r-i+k-1 << " " << k-1 << endl;
                ans+=(nCrModPFermat(r-i+k-1,k-1,MOD)*(a[i]%MOD))%MOD;
                ans%=MOD;
            }
            cout << ans%MOD << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}