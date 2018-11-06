#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

LL a[300005];
LL b[300005];
LL dpn[600005];
LL smpg[600005];
LL n;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (LL i=1;i<=n;i++) cin >> a[i];
    for (LL i=1;i<=n;i++) cin >> b[i];
    LL r=1,c=0,cnt=1;
    memset (dpn,0,sizeof(dpn));
    while (r<=n) {
      if (r%2==1&&c==1) {
        dpn[cnt]=a[r]*cnt+dpn[cnt-1];
        c++;
        c%=2;
      } else if (r%2==1&&c==0) {
        dpn[cnt]=b[r]*cnt+dpn[cnt-1];
        r++;
      } else if (r%2==0&&c==0) {
        dpn[cnt]=b[r]*cnt+dpn[cnt-1];
        c++;
      } else if (r%2==0&&c==1) {
        dpn[cnt]=a[r]*cnt+dpn[cnt-1];
        r++;
      }
      cnt++;
    }
    memset (smpg,0,sizeof(smpg));
    LL tot=0;
    cnt=1;
    r=2;
    while (r<=n) {
      smpg[cnt]=smpg[cnt-1]+a[r];
      tot+=a[r]*cnt;
      r++;
      cnt++;
    }
    r--;
    while (r>=1) {
      smpg[cnt]=smpg[cnt-1]+b[r];
      tot+=b[r]*cnt;
      r--;
      cnt++;
    }
    LL ans=dpn[2*n-1],trans=2*n-2,ra=2,rb=1,l=1;
    r=2*n-1;
    bool g=0;
    for (LL i=0;i<n-1;i++) {
      LL num=dpn[2*i]+tot;
      trans+=2;
      if (!g) {
        tot-=b[rb]*(2*n-1);
        rb++;
        tot-=b[rb]*(2*n-2);
        rb++;
        r-=2;
        tot=trans*(smpg[r]-smpg[l-1])-tot;
      } else {
        tot-=a[ra]*(2*n-1);
        ra++;
        tot-=a[ra]*(2*n-2);
        ra++;
        l+=2;
        tot=trans*(smpg[r]-smpg[l-1])-tot;
      }
      g=!g;
      ans=max(ans,num);
    }
    cout << ans << endl;
    return 0;
}
