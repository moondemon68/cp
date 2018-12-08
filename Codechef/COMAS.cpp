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
    cin >> tc;
    while (tc--) {
      int n;
      cin >> n;
      pii a[n+5];
      for (int i=1;i<=n;i++) {
        a[i].fi=0;
        a[i].se=i;
      }
      map<int,int> m;
      set<string> asked;
      while (1>0) {
        vector<int> ask;
        int cnt=0;
        for (int i=1;i<=n;i++) {
          if (a[i].fi==0) {
            ask.pb(i);
            cnt++;
          }
          if (cnt==5) break;
        }
        if (cnt<5) break;
        cout << "? ";
        string s="";
        for (int i=0;i<5;i++) {
          cout << ask[i] << " ";
          s+='0'+ask[i];
        }
        sort (s.begin(),s.end());
        asked.insert(s);
        cout << endl;
        int x,y;
        cin >> x >> y;
        a[x].fi++;
        a[y].fi+=2;
      }
      for (int i=1;i<=n;i++) m[i]=a[i].fi;
      sort (a+1,a+n+1);
      /*for (int i=1;i<=n;i++) {
        cout << a[i].fi << " " << a[i].se << endl;
      }*/
      int x,y,sum1=-1,sum2=-1,sum3=-1,sum4=-1;
      if (n%2==1) {
        cout << "? " << a[1].se << " " << a[2].se << " " << a[n].se << " " << a[n-1].se << " " << a[n-2].se << endl;
        cin >> x >> y;
        sum1=x+y;
        cout << "? " << a[1].se << " " << a[3].se << " " << a[n].se << " " << a[n-1].se << " " << a[n-2].se << endl;
        cin >> x >> y;
        sum2=x+y;
        cout << "? " << a[2].se << " " << a[3].se << " " << a[n].se << " " << a[n-1].se << " " << a[n-2].se << endl;
        cin >> x >> y;
        sum3=x+y;
        if (sum1==sum2) cout << "! " << a[1].se << endl;
        else if (sum1==sum3) cout << "! " << a[2].se << endl;
        else if (sum2==sum3) cout << "! " << a[3].se << endl;
      } else {
        cout << "? " << a[1].se << " " << a[2].se << " " << a[3].se << " " << a[4].se << " " << a[n].se << endl;
        cin >> x >> y;
        m[x]++;
        m[y]+=2;
        for (int i=1;i<=n;i++) {
          a[i].fi=m[i];
          a[i].se=i;
        }
        sort (a+1,a+n+1);
        cout << "? " << a[1].se << " " << a[2].se << " " << a[n].se << " " << a[n-1].se << " " << a[n-2].se << endl;
        cin >> x >> y;
        sum1=x+y;
        cout << "? " << a[1].se << " " << a[3].se << " " << a[n].se << " " << a[n-1].se << " " << a[n-2].se << endl;
        cin >> x >> y;
        sum2=x+y;
        cout << "? " << a[2].se << " " << a[3].se << " " << a[n].se << " " << a[n-1].se << " " << a[n-2].se << endl;
        cin >> x >> y;
        sum3=x+y;
        if (sum1==sum2) cout << "! " << a[1].se << endl;
        else if (sum1==sum3) cout << "! " << a[2].se << endl;
        else if (sum2==sum3) cout << "! " << a[3].se << endl;
      }
    }
    return 0;
}
