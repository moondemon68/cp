#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

bool fin(int a[]) {
  for (int i=1;i<=9;i++) {
    if (a[i]!=0) return 0;
  }
  return 1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--) {
      int a[10];
      for (int i=1;i<=3;i++) {
        string s;
        cin >> s;
        for (int j=1;j<=3;j++) {
          if (s[j-1]=='n') a[i*3+j-3]=0;
          else if (s[j-1]=='e') a[i*3+j-3]=1;
          else if (s[j-1]=='s') a[i*3+j-3]=2;
          else a[i*3+j-3]=3;
        }
      }
      //for (int i=1;i<=9;i++) {
      //  cout << a[i];
      //}
      //cout << endl;
      while (!fin(a)) {
        if (a[1]!=0) {
          if (a[7]==a[1]) {
            cout << 4;
            a[1]++; a[1]%=4;
            a[4]++; a[4]%=4;
            a[7]++; a[7]%=4;
          }
          if (a[3]!=a[1]) {
            cout << 1;
            a[1]++; a[1]%=4;
            a[2]++; a[2]%=4;
            a[4]++; a[4]%=4;
            a[5]++; a[5]%=4;
          } else {
            cout << 2;
            a[1]++; a[1]%=4;
            a[2]++; a[2]%=4;
            a[3]++; a[3]%=4;
          }
        }
        else if (a[2]!=0) {
          cout << 3;
          a[2]++; a[1]%=4;
          a[3]++; a[2]%=4;
          a[5]++; a[3]%=4;
          a[6]++; a[6]%=4;
        }
        else if (a[3]!=0) {
          cout << 6;
          a[3]++; a[3]%=4;
          a[6]++; a[6]%=4;
          a[9]++; a[9]%=4;
        } else if (a[4]!=0) {
          cout << 7;
          a[4]++; a[4]%=4;
          a[5]++; a[5]%=4;
          a[7]++; a[7]%=4;
          a[8]++; a[8]%=4;
        } else if (a[5]!=0) {
          cout << 9;
          a[5]++; a[5]%=4;
          a[6]++; a[6]%=4;
          a[8]++; a[8]%=4;
          a[9]++; a[9]%=4;
        } else if (a[7]!=0) {
          cout << 8;
          a[7]++; a[7]%=4;
          a[8]++; a[8]%=4;
          a[9]++; a[9]%=4;
        }
      }
      cout << endl;
    }
    return 0;
}
