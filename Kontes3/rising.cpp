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
    int n,a,b;
    cin >> n >> a >> b;
    if (n==2&&a==1&&b==1) {
      cout << -1 << endl;
      return 0;
    }
    cout << 1 << " ";
    int sum=1,mak=0;
    for (int i=1;i<=b;i++) {
      cout << sum+1 << " ";
      mak=sum+1;
      sum+=sum+1;
    }
    for (int i=1;i<=a;i++) {
      mak++;
      cout << mak << " ";
    }
    for (int i=1;i<n-a-b;i++) {
      cout << 1 << " ";
    }
    return 0;
}
