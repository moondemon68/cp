#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<int,int>
#define LL long long
using namespace std;

const int N = 1e6+5;
int n,k;
int t[4*N];

void update(int v, int s, int e, int pos,int val){
    //cerr << v << " " << s << " " << e << '\n';
    if(s == e){
        t[v] = val;
    }else{
        int m = (s+e)>>1;
        if(pos <= m){
            update(2*v,s,m,pos,val);
        }else{
            update(2*v+1,m+1,e,pos,val);
        }
        t[v] = t[2*v] + t[2*v+1];
    }
}

int query(int v, int s, int e, int l, int r){
    if(s > r || e < l){
        return 0;
    }
    if(l <= s && e <= r){
        return t[v];
    }
    int m = (s+e)>>1;
    return query(2*v,s,m,l,r) + query(2*v+1,m+1,e,l,r);
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--) {
        int n,k;
        cin >> n >> k;
        int cnt[k+5];
        memset(t,0,sizeof(t));
        memset (cnt,0,sizeof(cnt));
        int a[n+5];
        for (int i=1;i<=n;i++) {
            cin >> a[i];
            if (a[i]>k) a[i]=k+1;
        }
        for (int i=1;i<=k;i++) {
            cnt[a[i]]++;
        }
        for (int i=1;i<=k;i++) {
            if (cnt[i]==i) update(1,1,k,i,1);
        }
        //for (int i=1;i<=k;i++) cerr << cnt[i] << " ";
        int ans=query(1,1,k,1,k);
        //cerr << ans << " ";
        for (int i=k+1;i<=n;i++) {
            //cout << a[i-k] << a[i] << endl;
            cnt[a[i-k]]--;
            cnt[a[i]]++;
            if (cnt[a[i-k]]==a[i-k]) update(1,1,k,a[i-k],1); else update(1,1,k,a[i-k],0);
            if (cnt[a[i]]==a[i]) update(1,1,k,a[i],1); else update(1,1,k,a[i],0);
            //cerr << a[i-k] << a[i] << " ";
            //for(int j=1;j<=k;j++){
                //cerr << query(1,1,k,j,j) << " ";
            //}
            //cerr << '\n';
            ans+=query(1,1,k,1,k);
        }

        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}