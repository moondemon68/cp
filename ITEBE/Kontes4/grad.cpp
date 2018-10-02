#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

int a[5005];

int paint(int l,int r,int h) {
  if (l>r) return 0;
  int minh=a[l],mini=l;
  for (int i=l;i<=r;i++) {
    if (a[i]<minh) {
      minh=a[i];
      mini=i;
    }
  }
  return min(r-l+1,paint(l,mini-1,minh)+paint(mini+1,r,minh)+minh-h);
}

int main () {
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    cout << paint(1,n,0) << endl;
    return 0;
}
