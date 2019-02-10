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
    ifstream cin ("8.txt");
    ofstream cout ("E8.txt");
    int n,l,d;
    cin >> n >> l >> d;
    //l--;
    string s;
    cin >> s;
    for (int i=1;i<=10000;i++) s+='-';
    for (int i=1;i<=s.size();i++) {
        if (s[i+l-2]=='-') break;
        int ans=0;
        string t="";
        for (int j=i;j<i+l;j++) t+=s[j-1];
        vector<int> answer;
        for (int j=1;j<=s.size();j++) {
            if (s[j-1]=='-') break;
            if (s[j-1]==t[0]) {
                int x=0;
                for (int k=0;k<t.size();k++) {
                    if (s[j+k-1]!=t[k]) x++;
                }
                if (x<=d) {
                    ans++;
                    answer.pb(j);
                }
            }
        }
        //cout << ans << endl;
        if (ans>=n) {
            cout << t << endl;
            for (int j=0;j<=n;j++) {
                cout << answer[j] << " ";
                //cout << endl;
                //for(int k=0;k<(int)t.size();k++) cout << s[answer[j]+k-1];
                //cout << endl;
                for (int k=0;k<(int)t.size();k++) {
                    if(s[answer[j]+k-1]!=t[k]) cout << k+1 << " ";
                }
                cout << endl;
            }
            break;
        }
    }
    return 0;
}