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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    scanf("%d",&tc);
    while (tc--) {
      int n;
      scanf("%d",&n);
      if (n==1) {
        printf("1\n");
        continue;
      }
      stack<int> a;
      for (int i=9;i>=2;i--) {
        while (n%i==0) {
          a.push(i);
          n/=i;
        }
      }
      if (n>1) {
        printf("-1\n");
        continue;
      }
      while (!a.empty()) {
        printf("%d",a.top());
        a.pop();
      }
      printf("\n");
    }
    return 0;
}
