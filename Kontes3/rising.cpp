#include <bits/stdc++.h>

using namespace std;

int main () {
    int n,a,b;
    cin >> n >> a >> b;
    if (n>1&&b==0&&a==n-1) {
      cout << -1 << endl;
      return 0;
    }

    cout << 1 << " ";
    int sum=1,mak=1,cnt=1;
    for (int i=1;i<=b;i++) {
      cout << sum+1 << " ";
      mak=sum+1;
      sum+=sum+1;
      cnt++;
    }
    if (sum==1&&cnt<n) {
      cout << 1 << " ";
      cnt++;
    }
    for (int i=1;i<=a;i++) {
      mak++;
      cout << mak << " ";
      cnt++;
    }
    while (cnt<n) {
      cout << 1 << " ";
      cnt++;
    }
    return 0;
}
