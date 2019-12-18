#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
<<<<<<< HEAD
#define INF 1234567890
=======
>>>>>>> e5fed947e7778530786e9456986925b468d895d6
#define pii pair<int,int>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin >> n >> k;
<<<<<<< HEAD
    pii a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i].fi >> a[i].se;
    int v[205];
=======
    pii a[2005];
    for (int i=1;i<=n;i++) cin >> a[i].fi >> a[i].se;
    int v[2005];
>>>>>>> e5fed947e7778530786e9456986925b468d895d6
    memset (v,0,sizeof(v));
    for (int i=1;i<=n;i++) {
        v[a[i].fi]++;
        v[a[i].se+1]--;
    }
<<<<<<< HEAD
    for (int i=1;i<=200;i++) {
        v[i]+=v[i-1];
    }
    for (int i=1;i<=20;i++) cout << v[i] <<  ' ';
    cout << endl;
    int ans=0;
    for (int i=200;i>=1;i++) {
        if (v[i]!=0) {
            int minx=INT_MIN,mini=-1;
            for (int j=1;j<=n;j++) {
                if (a[j].fi<minx && a[j].se>=i) {
                    minx = a[j].fi;
                    mini = j;
                }
            }
        }
    }
=======
    for (int i=1;i<=2000;i++) v[i]+=v[i-1];
    for (int i=1;i<=2000;i++) v[i]=max(0,v[i]-k);
    int pre[2005];
    pre[0]=0;
    for (int i=1;i<=2000;i++) pre[i]=pre[i-1]+v[i];
    if (pre[2000]==0) {
        cout << 0 << endl;
        return 0;
    }
    vector<int> ans;
    while (1) {
        int maxa=0,maxi=0;
        for (int i=1;i<=n;i++) {
            if (a[i].fi==-1) continue;
            if (pre[a[i].se]-pre[a[i].fi-1]>maxa) {
                maxa=pre[a[i].se]-pre[a[i].fi-1];
                maxi=i;
            }
        }
        for (int i=a[maxi].fi;i<=a[maxi].se;i++) {
            v[i]--;
            v[i]=max(0,v[i]);
        }
        ans.pb(maxi);
        pre[0]=0;
        for (int i=1;i<=2000;i++) pre[i]=pre[i-1]+v[i];
        a[maxi].fi=-1;
        if (pre[2000]==0) break;
    }
    cout << ans.size() << endl;
    for (int i=0;i<ans.size();i++) cout << ans[i] << " ";
    cout << endl;
>>>>>>> e5fed947e7778530786e9456986925b468d895d6
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}