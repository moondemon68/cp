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
    string s;
    cin >> s;
    int ans=INT_MAX;
    string answer="";
    string t="RGB";    
    int cnt=0;
    for (int i=1;i<=n;i++) {
        if (s[i-1]!=t[(i-1)%3]) cnt++;
    }
    if (cnt<ans) {
        answer=t;
        ans=cnt;
    }

    t="GBR";
    cnt=0;
    for (int i=1;i<=n;i++) {
        if (s[i-1]!=t[(i-1)%3]) cnt++;
    }
    if (cnt<ans) {
        answer=t;
        ans=cnt;
    }
    t="BRG";
    cnt=0;
    for (int i=1;i<=n;i++) {
        if (s[i-1]!=t[(i-1)%3]) cnt++;
    }
    if (cnt<ans) {
        answer=t;
        ans=cnt;
    }
    t="BGR";
    cnt=0;
    for (int i=1;i<=n;i++) {
        if (s[i-1]!=t[(i-1)%3]) cnt++;
    }
    if (cnt<ans) {
        answer=t;
        ans=cnt;
    }
    t="GRB";
    cnt=0;
    for (int i=1;i<=n;i++) {
        if (s[i-1]!=t[(i-1)%3]) cnt++;
    }
    if (cnt<ans) {
        answer=t;
        ans=cnt;
    }
    t="RBG";
    cnt=0;
    for (int i=1;i<=n;i++) {
        if (s[i-1]!=t[(i-1)%3]) cnt++;
    }
    if (cnt<ans) {
        answer=t;
        ans=cnt;
    }
    cout << ans << endl;
    for (int i=0;i<n;i++) cout << answer[i%3];
    return 0;
}
