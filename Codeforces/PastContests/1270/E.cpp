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

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<pii> a;
    for (int i=1;i<=n;i++) {
        int x,y;
        cin >> x >> y;
        x += 1e6;
        y += 1e6;
        a.pb(mp(x,y));
    }
    int p=0,q=0,r=0,s=0;
    // LL tot=-1;
    for (int i=0;i<a.size();i++) {
        if (a[i].fi%2==0&&a[i].se%2==0) p++; 
        if (a[i].fi%2==0&&a[i].se%2==1) q++;
        if (a[i].fi%2==1&&a[i].se%2==0) r++;
        if (a[i].fi%2==1&&a[i].se%2==1) s++;
    }
    //cout << p << q << r << s << endl;
    while (p==n||q==n||r==n||s==n) {
        p=0;
        q=0;
        r=0;
        s=0;
        for (int i=0;i<a.size();i++) {
            a[i].fi/=2;
            a[i].se/=2;
            if (a[i].fi%2==0&&a[i].se%2==0) p++; 
            if (a[i].fi%2==0&&a[i].se%2==1) q++;
            if (a[i].fi%2==1&&a[i].se%2==0) r++;
            if (a[i].fi%2==1&&a[i].se%2==1) s++;
        }
        //if (tot == 0) break;
    }
    // if (tot == 0) {
    //     cout << 1 << endl << 1 << endl;
    //     return 0;
    // }
    //cout << p << q << r << s << endl;
    vector<int> ans;
    for (int i=0;i<a.size();i++) {
        if ((a[i].fi%2==0&&a[i].se%2==0)||(a[i].fi%2==1&&a[i].se%2==1)) ans.pb(i+1);
    }
    if (ans.size() != n && ans.size() != 0) {
        cout << ans.size() << endl;
        for (int i=0;i<ans.size();i++)  cout << ans[i] << " ";
        cout << endl;
        return 0;
    } 
    ans.clear();
    for (int i=0;i<a.size();i++) {
        if (a[i].fi%2==0&&a[i].se%2==0) ans.pb(i+1);
    }
    if (ans.size() != n && ans.size() != 0) {
        cout << ans.size() << endl;
        for (int i=0;i<ans.size();i++)  cout << ans[i] << " ";
        cout << endl;
        return 0;
    } 
    ans.clear();
    for (int i=0;i<a.size();i++) {
        if (a[i].fi%2==1&&a[i].se%2==0) ans.pb(i+1);
    }
    if (ans.size() != n && ans.size() != 0) {
        cout << ans.size() << endl;
        for (int i=0;i<ans.size();i++)  cout << ans[i] << " ";
        cout << endl;
        return 0;
    } 
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}