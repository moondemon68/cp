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
      int ans[n+5];
      if (n%4==0) {
        int cnt=1;
        while (cnt+3<=n) {
          int r123,r124,r134,r234;
          cout << "1 " << cnt << " " << cnt+1 << " " << cnt+2 << endl;
          cin >> r123;
          cout << "1 " << cnt << " " << cnt+1 << " " << cnt+3 << endl;
          cin >> r124;
          cout << "1 " << cnt << " " << cnt+2 << " " << cnt+3 << endl;
          cin >> r134;
          cout << "1 " << cnt+1 << " " << cnt+2 << " " << cnt+3 << endl;
          cin >> r234;
          ans[cnt]=r123^r124^r134;
          ans[cnt+1]=r123^r124^r234;
          ans[cnt+2]=r123^r134^r234;
          ans[cnt+3]=r124^r134^r234;
          cnt+=4;
        }
      } else if (n%3==2) {
        int a[2*n+5];
        for (int i=1;i<=n-2;i++) {
          cout << "1 " << i << " " << i+1 << " " << i+2 << endl;
          cin >> a[i];
        }
        cout << "1 1 " << n-1 << " " << n << endl;
        cin >> a[n-1];
        cout << "1 1 " << 2 << " " << n << endl;
        cin >> a[n];
        for (int i=1;i<=n;i++) {
          a[n+i]=a[i];
        }
        memset (ans,0,sizeof(ans));
        int all=0;
        for (int i=1;i<=n;i++) all^=a[i];
        for (int i=1;i<=n;i++) {
          ans[i]=all;
          int x=i;
          for (int j=1;j<=(n+2)/3;j++) {
            ans[i]^=a[x];
            x+=3;
          }
        }
      } else if (n==10) {
        int a[2*n+5];
        for (int i=1;i<=n-2;i++) {
          cout << "1 " << i << " " << i+1 << " " << i+2 << endl;
          cin >> a[i];
        }
        cout << "1 1 " << n-1 << " " << n << endl;
        cin >> a[n-1];
        cout << "1 1 " << 2 << " " << n << endl;
        cin >> a[n];
        int all=0;
        for (int i=1;i<=n;i++) all^=a[i];
        for (int i=1;i<=n;i++) ans[i]=all;
        ans[1]^=a[2]^a[5]^a[8];
        ans[2]^=a[3]^a[6]^a[9];
        ans[3]^=a[4]^a[7]^a[10];
        ans[4]^=a[5]^a[8]^a[1];
        ans[5]^=a[6]^a[9]^a[2];
        ans[6]^=a[7]^a[10]^a[3];
        ans[7]^=a[8]^a[1]^a[4];
        ans[8]^=a[9]^a[2]^a[5];
        ans[9]^=a[10]^a[3]^a[6];
        ans[10]^=a[1]^a[4]^a[7];
      } else {
        memset (ans,0,sizeof(ans));
      	int cnt=1;
        while ((n-cnt+1)%3!=2) {
          int r123,r124,r134,r234;
          cout << "1 " << cnt << " " << cnt+1 << " " << cnt+2 << endl;
          cin >> r123;
          cout << "1 " << cnt << " " << cnt+1 << " " << cnt+3 << endl;
          cin >> r124;
          cout << "1 " << cnt << " " << cnt+2 << " " << cnt+3 << endl;
          cin >> r134;
          cout << "1 " << cnt+1 << " " << cnt+2 << " " << cnt+3 << endl;
          cin >> r234;
          ans[cnt]=r123^r124^r134;
          ans[cnt+1]=r123^r124^r234;
          ans[cnt+2]=r123^r134^r234;
          ans[cnt+3]=r124^r134^r234;
          cnt+=4;
        }
        vector<int> a;
        int x;
        for (int i=cnt;i<=n-2;i++) {
          cout << "1 " << i << " " << i+1 << " " << i+2 << endl;
          cin >> x;
          a.pb(x);
        }
        cout << "1 " << cnt << " " << n-1 << " " << n << endl;
        cin >> x;
        a.pb(x);
        cout << "1 " << cnt << " " << cnt+1 << " " << n << endl;
        cin >> x;
        a.pb(x);
        int p=a.size();
        for (int i=0;i<p;i++) {
          a.pb(a[i]);
        }
        int all=0;
        for (int i=0;i<p;i++) all^=a[i];
        for (int i=0;i<p;i++) {
          ans[cnt+i]=all;
          int x=i;
          for (int j=1;j<=(n-cnt+3)/3;j++) {
            ans[cnt+i]^=a[x];
            x+=3;
          }
        }
      }
      //OUTPUT
      cout << 2 << " ";
      for (int i=1;i<=n;i++) {
        cout << ans[i] << " ";
      }
      cout << endl;
      int verdict;
      cin >> verdict;
    }
    return 0;
}
