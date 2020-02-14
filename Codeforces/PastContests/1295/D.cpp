#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

LL phi(LL n) 
{ 
    LL result = n; // Initialize result as n 
  
    // Consider all prime factors of n and subtract their 
    // multiples from result 
    for (LL p = 2; p * p <= n; ++p) { 
          
        // Check if p is a prime factor. 
        if (n % p == 0) { 
              
            // If yes, then update n and result 
            while (n % p == 0) 
                n /= p; 
            result -= result / p; 
        } 
    } 
  
    // If n has a prime factor greater than sqrt(n) 
    // (There can be at-most one such prime factor) 
    if (n > 1) 
        result -= result / n; 
    return result; 
} 

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--) {
        LL a,m;
        cin >> a >> m;
        cout << phi(m / __gcd(a,m)) << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}