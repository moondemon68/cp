#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

int main() {
    int n;
    cin >> n;
    pair<int,string> a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i].se >> a[i].fi;
    sort (a+1,a+n+1);
    a[n+1]=make_pair(-1,"x");
    for (int i=1;i<=n;i++) {
        int cnt=1;
        while (a[i].fi == a[i+1].fi) {
            cnt++;
            i++;
        } 
        for (int j=i-cnt+1;j<=i;j++) cout << a[j].se << " ";
        cout << i-cnt+1 << " " << i << "\n";
    }
    return 0;
}