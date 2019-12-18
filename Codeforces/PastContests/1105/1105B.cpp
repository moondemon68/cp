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
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ans=0;
    for (int i=0;i<26;i++) {
        char c=i+'a';
        int cnt=0,count=0;
        int x=s.size();
        for (int j=0;j<x;j++) {
            if (s[j]==c) {
                cnt++;
                if (cnt==k) {
                    cnt=0;
                    count++;
                }
            } else {
                cnt=0;
            }
        }
        ans=max(ans,count);
    }    
    cout << ans << endl;
    return 0;
}
