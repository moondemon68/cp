#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    cin >> n;
    int a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    bool b[100005];
    memset (b,0,sizeof(b));
    for (int i=1;i<=n;i++) b[a[i]]=1;
    sort (a+1,a+n+1);
    for (int i=1;i<=n;i++) 
    return 0;
}