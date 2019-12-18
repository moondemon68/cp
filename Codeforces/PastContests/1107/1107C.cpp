#include <bits/stdc++.h>
#define LL long long

using namespace std;

int main () {
    int n,k;
    cin >> n >> k;
    LL a[n+5];
    memset (a,0,sizeof(a));
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    string s;
    cin >> s;
    s+='0';
    LL ans=0;
    for (int i=0;i<n;i++) {
        if (s[i]==s[i+1]) {
            priority_queue<LL> tmp;
            while (s[i]==s[i+1]) {
                tmp.push(a[i]);
                i++;
            }
            tmp.push(a[i]);
            int cnt=0;
            while (!tmp.empty()&&cnt<k) {
                cnt++;
                ans+=tmp.top();
                tmp.pop();
            }
        } else {
            ans+=a[i];
        }
    }
    cout << ans << endl;
    return 0;
}