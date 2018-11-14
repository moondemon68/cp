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
    string type;
    map<string,int> m;
    string a[2005];
    for (int i=0;i<=2000;i++) {
      a[i]=".";
    }
    while (cin >> type) {
      if (type=="def") {
        string s;
        cin >> s;
        int x;
        cin >> x;
        if (m[s]!=0&&a[0]!=s) {
          a[m[s]]=".";
          m[s]=x+1000;
          a[x+1000]=s;
        } else {
          m[s]=x+1000;
          a[x+1000]=s;
        }
      } else if (type=="calc") {
        string s;
        char t;
        char pt='.';
        int ans=0;
        bool y=1;
        while (cin >> s >> t) {
          cout << s << " " << t << " ";
          //cout << m[s] << endl;
          if (m[s]==0&&a[0]!=s) y=0;
          if (pt=='.') {
            ans+=m[s]-1000;
          } else if (pt=='+') {
            ans+=m[s]-1000;
          } else {
            ans-=m[s]-1000;
          }
          if (t=='=') break;
          pt=t;
        }
        //cout << ans << endl;
        //if (ans>=0) cout << a[ans+1000] << endl;
        if (ans<-1000||ans>1000) ans=2001;
        if (!y||ans==2001) cout << "unknown";
        else if (a[ans+1000]==".") cout << "unknown";
        else cout << a[ans+1000];
        cout << endl;
      } else {
        for (int i=0;i<=2000;i++) {
          a[i]=".";
        }
        m.clear();
      }
    }
    return 0;
}
