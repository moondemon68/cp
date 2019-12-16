#include <bits/stdc++.h>
#define x first
#define y second
#define x1 first.first
#define y1 first.second
#define x2 second.first
#define y2 second.second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<int,int>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    pair<pii,pii> a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
    for (int i=1;i<=n;i++) {
        int dx=a[i].x1,dy=a[i].y1;
        a[i].x1-=dx;
        a[i].x2-=dx;
        a[i].y1-=dy;
        a[i].y2-=dy;
    }
    int ans=0;
    pii p[n+5];
    for (int i=1;i<=n;i++) {
        p[i].x = a[i].x2;
        p[i].y = a[i].y2;
        if (p[i].x > p[i].y) swap(p[i].x,p[i].y);
    }
    sort (p+1,p+n+1);
    reverse(p+1,p+n+1);
     //for (int i=1;i<=n;i++) cout << p[i].x << " " << p[i].y << endl;
     //cout << endl;
    for (int i=1;i<=n;i++) {
        for (int j=i+1;j<=n;j++) {
            if (p[j].y>p[i].y) {
                //cout << i << " " << j << endl;
                ans++;
            }
        }   
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}