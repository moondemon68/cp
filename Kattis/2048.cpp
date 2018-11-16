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
    int a[5][5];
    for (int i=1;i<=4;i++) {
      for (int j=1;j<=4;j++) {
        cin >> a[i][j];
      }
    }
    int x;
    cin >> x;
    if (x==0) {
      for (int i=1;i<=4;i++) {
        vector<int> v;
        for (int j=1;j<=4;j++) {
          if (a[i][j]!=0) v.pb(a[i][j]);
          a[i][j]=0;
        }
        v.pb(-1);
        int cnt=1;
        for (int j=0;j<v.size()-1;j++) {
          if (v[j]==v[j+1]) {
            a[i][cnt]=v[j]*2;
            j++;
          } else {
            a[i][cnt]=v[j];
          }
          cnt++;
        }
      }
    } else if (x==2) {
      for (int i=1;i<=4;i++) {
        vector<int> v;
        for (int j=4;j>=1;j--) {
          if (a[i][j]!=0) v.pb(a[i][j]);
          a[i][j]=0;
        }
        v.pb(-1);
        int cnt=4;
        for (int j=0;j<v.size()-1;j++) {
          if (v[j]==v[j+1]) {
            a[i][cnt]=v[j]*2;
            j++;
          } else {
            a[i][cnt]=v[j];
          }
          cnt--;
        }
      }
    }
    else if (x==1) {
      for (int i=1;i<=4;i++) {
        vector<int> v;
        for (int j=1;j<=4;j++) {
          if (a[j][i]!=0) v.pb(a[j][i]);
          a[j][i]=0;
        }
        v.pb(-1);
        int cnt=1;
        for (int j=0;j<v.size()-1;j++) {
          if (v[j]==v[j+1]) {
            a[cnt][i]=v[j]*2;
            j++;
          } else {
            a[cnt][i]=v[j];
          }
          cnt++;
        }
      }
    }
    else if (x==3) {
      for (int i=1;i<=4;i++) {
        vector<int> v;
        for (int j=4;j>=1;j--) {
          if (a[j][i]!=0) v.pb(a[j][i]);
          a[j][i]=0;
        }
        v.pb(-1);
        int cnt=4;
        for (int j=0;j<v.size()-1;j++) {
          if (v[j]==v[j+1]) {
            a[cnt][i]=v[j]*2;
            j++;
          } else {
            a[cnt][i]=v[j];
          }
          cnt--;
        }
      }
    }
    for (int i=1;i<=4;i++) {
      for (int j=1;j<=4;j++) {
        cout << a[i][j] << " ";
      }
      cout << endl;
    }
    return 0;
}
