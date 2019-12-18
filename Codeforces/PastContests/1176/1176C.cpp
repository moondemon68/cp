#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push
#define mp make_pair
#define MOD 1000000007
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
    int v[n+5];
    for (int i=1;i<=n;i++) cin >> v[i];
    queue<int> a,b,c,d,e,f;
    for (int i=1;i<=n;i++) {
        if (v[i]==4) a.pb(i);
        else if (v[i]==8) b.pb(i);
        else if (v[i]==15) c.pb(i);
        else if (v[i]==16) d.pb(i);
        else if (v[i]==23) e.pb(i);
        else f.pb(i);
    }
    a.pb(-1);
    b.pb(-1);
    c.pb(-1);
    d.pb(-1);
    e.pb(-1);
    f.pb(-1);
    int ans=0;
    while (a.front()!=-1&&b.front()!=-1&&c.front()!=-1&&d.front()!=-1&&e.front()!=-1&&f.front()!=-1) {
        while (b.front()<a.front()&&b.front()!=-1) {
            b.pop();
            if (b.front()==-1) {
                cout << n-6*ans << endl;
                return 0;
            }
        }
        while (c.front()<b.front()&&c.front()!=-1) {
            c.pop();
            if (c.front()==-1) {
                cout << n-6*ans << endl;
                return 0;
            }
        }
        while (d.front()<c.front()&&d.front()!=-1) {
            d.pop();
            if (d.front()==-1) {
                cout << n-6*ans << endl;
                return 0;
            }
        }
        while (e.front()<d.front()&&e.front()!=-1) {
            e.pop();
            if (e.front()==-1) {
                cout << n-6*ans << endl;
                return 0;
            }
        }
        while (f.front()<e.front()&&f.front()!=-1) {
            f.pop();
            if (f.front()==-1) {
                cout << n-6*ans << endl;
                return 0;
            }
        }
        if (a.front()!=-1&&b.front()!=-1&&c.front()!=-1&&d.front()!=-1&&e.front()!=-1&&f.front()!=-1) {
            ans++;
            a.pop();
            b.pop();
            c.pop();
            d.pop();
            e.pop();
            f.pop();
        }
    }
    cout  << n-6*ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}