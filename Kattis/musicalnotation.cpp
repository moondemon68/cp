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
    map<char,int> m;
    m['G']=1;
    m['F']=2;
    m['E']=3;
    m['D']=4;
    m['C']=5;
    m['B']=6;
    m['A']=7;
    m['g']=8;
    m['f']=9;
    m['e']=10;
    m['d']=11;
    m['c']=12;
    m['b']=13;
    m['a']=14;
    char b[16];
    b[1]='G';
    b[2]='F';
    b[3]='E';
    b[4]='D';
    b[5]='C';
    b[6]='B';
    b[7]='A';
    b[8]='g';
    b[9]='f';
    b[10]='e';
    b[11]='d';
    b[12]='c';
    b[13]='b';
    b[14]='a';
    char a[16][1005];
    memset (a,' ',sizeof(a));
    int n;
    cin >> n;
    int cnt=0;
    for (int i=1;i<=n;i++) {
      string s;
      cin >> s;
      if (s.size()==1) {
        cnt++;
        int x=m[s[0]];
        for (int i=1;i<=14;i++) {
          if (i==x) a[i][cnt]='*'; else a[i][cnt]=' ';
        }
      } else {
        for (int j=1;j<=s[1]-'0';j++) {
          cnt++;
          int x=m[s[0]];
          for (int i=1;i<=14;i++) {
            if (i==x) a[i][cnt]='*'; else a[i][cnt]=' ';
          }
        }
      }
      if (i==n) continue;
      cnt++;
      for (int i=1;i<=14;i++) {
        a[i][cnt]=' ';
      }
    }
    for (int i=1;i<=14;i++) {
      cout << b[i] << ": ";
      for (int j=1;j<=cnt;j++) {
        if (a[i][j]!=' ') cout << a[i][j];
        else {
          if (i==11||i==12||i==13||i==9||i==7||i==5||i==3||i==1) cout << ' ';
          else cout << '-';
        }
      }
      cout << endl;
    }
    return 0;
}
