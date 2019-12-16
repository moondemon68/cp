    #include <bits/stdc++.h>
    #define fi first
    #define se second
    #define pb push_back
    #define mp make_pair
    #define MOD 1000000007
    #define pii pair<int,int>
    #define LL long long
    using namespace std;
     
    int a[200005], n;
    pii p[200005];
     
     
     
    int main () {
        //clock_t start = clock();
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int tc;
        scanf("%d", &tc);
        while (tc--) {
            scanf("%d", &n);
            memset (a,0,n+5);
            int maxmonster = 0;
            for (int i=1;i<=n;i++) {
                scanf("%d", &a[i]);
                maxmonster = max(maxmonster, a[i]);
            }
            int m;
            scanf("%d", &m);
            int maxplayer = 0;
            for (int i=1;i<=m;i++) {
                scanf("%d%d", &p[i].fi, &p[i].se);
                
                maxplayer = max(maxplayer, p[i].fi);
            }
            if (maxplayer<maxmonster) {
                printf("-1\n");
                continue;
            }
            int k=1;
            int maxp[n+5];
            memset (maxp,0,sizeof(maxp));
            for (int i=1;i<=m;i++) {
                maxp[p[i].se] = max(maxp[p[i].se], p[i].fi);
            }
            for (int i=n-1;i>=1;i--) maxp[i] = max(maxp[i], maxp[i+1]);
            
            int px = 1;
            int ans=0;
            while (px <= n) {
                ans++;
                int cnt=0;
                int x=0;
                while (1>0) {
                    x=max(x, a[px+cnt]);
                    if (x > maxp[cnt+1]) break;
                    cnt++;
                }
                px += cnt;
            }
            printf("%d\n", ans);
        }
        //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
        return 0;
    }