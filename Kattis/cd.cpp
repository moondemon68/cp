#include <bits/stdc++.h>

using namespace std;

int a[1000005],b[1000005];

int main () {
    int n,m;
    while (1>0) {
        cin >> n >> m;
        if (n==0&&m==0) return 0;
        memset (a,0,sizeof(a));
        memset (b,0,sizeof(b));
        for (int i=1;i<=n;i++) cin >> a[i];
        for (int i=1;i<=m;i++) cin >> b[i];
        int ans=0;
        int pa=1,pb=1;
        while (pa<=n&&pb<=m) {
            if (a[pa]==b[pb]) {
                ans++;
                pa++;
                pb++;
            } else if (a[pa]>b[pb]) pb++;
            else if (a[pa]<b[pb]) pa++;
        }
        cout << ans << endl;
    }
    return 0;
}
