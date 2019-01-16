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
    int n;
    cin >> n;
    int a[n+5],b[n+5];
    for (int i=1;i<=n;i++) {
        cin >> a[i];
    }    
    for (int i=1;i<=n;i++) {
        cin >> b[i];
    }
    for (int i=1;i<=n;i++) a[i]-=b[i];
    int x=0;
    for (int i=1;i<=n;i++) {
        x+=a[i];
    }
    priority_queue<int> kurang;
    priority_queue<int> lebih;
    if (x<0) cout << -1 << endl;
    else {
        for (int i=1;i<=n;i++) {
            if (a[i]<0) kurang.push(a[i]);
            else if (a[i]>0) lebih.push(a[i]);
        }
    }
    int ans=0;
    while (!kurang.empty()) {
        int bot=kurang.top();
        kurang.pop();
        int top=lebih.top();
        lebih.pop();
        cout << bot << top << endl;
        int need=-1*bot;
        bot+=need;
        top+=need;
        if (bot<0) kurang.push(bot);
        if (top>0) lebih.push(top);
        ans++;
    }
    cout << ans << endl;
    return 0;
}
