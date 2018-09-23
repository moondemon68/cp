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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int a[10];
    memset (a,0,sizeof(a));
    for (int i=0;i<s.size();i++) {
      if (s[i]=='2') a[2]++;
      if (s[i]=='3') {
        a[2]++;
        a[3]++;
      }
      if (s[i]=='4') {
        a[2]+=3;
        a[3]++;
      }
      if (s[i]=='5') {
        a[2]+=3;
        a[3]++;
        a[5]++;
      }
      if (s[i]=='6') {
        a[2]+=4;
        a[3]+=2;
        a[5]++;
      }
      if (s[i]=='7') {
        a[2]+=4;
        a[3]+=2;
        a[5]++;
        a[7]++;
      }
      if (s[i]=='8') {
        a[2]+=7;
        a[3]+=2;
        a[5]++;
        a[7]++;
      }
      if (s[i]=='9') {
        a[2]+=7;
        a[3]+=4;
        a[5]++;
        a[7]++;
      }
    }
    while (a[7]>=1&&a[5]>=1&&a[3]>=2&&a[2]>=4) {
      cout << 7;
      a[2]-=4;
      a[3]-=2;
      a[5]--;
      a[7]--;
    }
    while (a[5]>=1&&a[3]>=1&&a[2]>=3) {
      cout << 5;
      a[2]-=3;
      a[3]--;
      a[5]--;
    }
    while (a[3]>=1&&a[2]>=1) {
      cout << 3;
      a[2]--;
      a[3]--;
    }
    while (a[2]>=1) {
      cout << 2;
      a[2]--;
    }
    return 0;
}
