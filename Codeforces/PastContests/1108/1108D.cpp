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
    if (s[n-1]=='R') s+='G';
    if (s[n-1]=='G') s+='R';
    if (s[n-1]=='B') s+='R';
    int ans=0,cnt=0;
    string answer="";
    string tmp="";
    for (int i=0;i<n;i++) {
        if (s[i]!=s[i+1]) answer+=s[i];
        else {
            while (s[i]==s[i+1]) {
                tmp+=s[i];
                i++;
            }
            tmp+=s[i];
            if (tmp[0]=='R'&&s[i+1]=='G') {
                for (int j=0;j<tmp.size();j++) {
                    if (j%2==1) tmp[j]='B';
                }
            }
            if (tmp[0]=='R'&&s[i+1]=='B') {
                for (int j=0;j<tmp.size();j++) {
                    if (j%2==1) tmp[j]='G';
                }
            }
            if (tmp[0]=='G'&&s[i+1]=='B') {
                for (int j=0;j<tmp.size();j++) {
                    if (j%2==1) tmp[j]='R';
                }
            }
            if (tmp[0]=='G'&&s[i+1]=='R') {
                for (int j=0;j<tmp.size();j++) {
                    if (j%2==1) tmp[j]='B';
                }
            }
            if (tmp[0]=='B'&&s[i+1]=='R') {
                for (int j=0;j<tmp.size();j++) {
                    if (j%2==1) tmp[j]='G';
                }
            }
            if (tmp[0]=='B'&&s[i+1]=='G') {
                for (int j=0;j<tmp.size();j++) {
                    if (j%2==1) tmp[j]='R';
                }
            }
            answer+=tmp;
            tmp="";
        }
    }
    for (int i=1;i<=n;i++) {
        if (s[i-1]!=answer[i-1]) ans++;
    }
    cout << ans << endl;
    cout << answer << endl;
    return 0;
}
