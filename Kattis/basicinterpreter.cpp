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
    string s;
    while (getline(cin,s)) {
        int num=0;
        string t="";
        int x=0;
        for (int i=0;i<s.size();i++) {
            if (s==' ') {
                x=i+1;
                break;
            } 
            else {
                num+=s[i]-'0';
                
            }
        }
    }    
    return 0;
}
