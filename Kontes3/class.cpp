// C++ program Miller-Rabin primality test
#include <bits/stdc++.h>
using namespace std;

// Utility function to do modular exponentiation.
// It returns (x^y) % p
long long power(long long x, unsigned long long y, long long p)
{
    long long res = 1;      // Initialize result
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

// This function is called for all k trials. It returns
// false if n is composite and returns false if n is
// probably prime.
// d is an odd number such that  d*2<sup>r</sup> = n-1
// for some r >= 1
bool miillerTest(long long d, long long n)
{
    // Pick a random number in [2..n-2]
    // Corner cases make sure that n > 4
    long long a = 2 + rand() % (n - 4);

    // Compute a^d % n
    long long x = power(a, d, n);

    if (x == 1  || x == n-1)
       return true;

    // Keep squaring x while one of the following doesn't
    // happen
    // (i)   d does not reach n-1
    // (ii)  (x^2) % n is not 1
    // (iii) (x^2) % n is not n-1
    while (d != n-1)
    {
        x = (x * x) % n;
        d *= 2;

        if (x == 1)      return false;
        if (x == n-1)    return true;
    }

    // Return composite
    return false;
}

// It returns false if n is composite and returns true if n
// is probably prime.  k is an input parameter that determines
// accuracy level. Higher value of k indicates more accuracy.
bool isPrime(long long n, long long k)
{
    // Corner cases
    if (n <= 1 || n == 4)  return false;
    if (n <= 3) return true;

    // Find r such that n = 2^d * r + 1 for some r >= 1
    long long d = n - 1;
    while (d % 2 == 0)
        d /= 2;

    // Iterate given nber of 'k' times
    for (long long i = 0; i < k; i++)
         if (miillerTest(d, n) == false)
              return false;

    return true;
}

int main () {
  int tc;
  cin >> tc;
  while (tc--) {
    long long x;
    cin >> x;
    long long cnt=0;
    while (!isPrime(x,5)) {
      x--;
      cnt++;
    }
    cout << cnt << endl;
  }
}
