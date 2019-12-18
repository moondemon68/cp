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
    string s;
    cin >> s;
    int x=s.size();
    for (int i=1;i<=5;i++) {
      for (int j=1;j<=20;j++) {
        if (i*j>=x) {
          cout << i << " " << j << endl;
          int cnt=0,rem=((i*j)%x);
          for (int k=1;k<=i;k++) {
            for (int l=1;l<=j;l++) {
              if (l==j&&rem>0) {
                cout << "*";
                rem--;
                continue;
              }
              cout << s[cnt];
              cnt++;
            }
            cout << endl;
          }
          return 0;
        }
      }
    }
    return 0;
}
