#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

int poww(int a,int b) {
  int ans=1;
  for (int i=1;i<=b;i++) ans*=a;
  return ans;
}

int main () {
    int n;
    cin >> n;
    /*
    for (int i=1;i<=1000;i++) {
      int ans1=0,ans2=0,ans3=0;
      for (int j=1;j<=i;j++) {
        for (int k=j+1;k<=i;k++) {
          if ((j+k)%1000==999) ans3++;
          else if ((j+k)%100==99) ans2++;
          else if ((j+k)%10==9) ans1++;
        }
      }
      if (ans3>0) cout << i << " " << ans3 << endl;
      else if (ans2>0) cout << i << " " << ans2 << endl;
      else cout << i << " " << ans1 << endl;
    }
    */

    if (n<5) {
      cout << n*(n-1)/2 << endl;
      return 0;
    }
    int num=5,p=1;
    for (int i=1;i<=9;i++) {
      if (n==num) {
        cout << 1 << endl;
        return 0;
      }
      if (n>num) p=i;
      num*=10;
    }
    int q=poww(10,p)-1;
    int ans=0;
    int x=poww(10,p);
    while (q<=(2*n-1)) {
        if (n>=q) ans+=q/2;
        else ans+=(n-q/2);
        //cout << ans << endl;
        q+=x;
    }
    cout << ans << endl;

    return 0;
}
