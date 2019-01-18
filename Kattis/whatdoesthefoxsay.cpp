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
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string s;
        set<string> haram;
        vector<string> words;
        while (getline(cin,s)) {
            if (s=="what does the fox say?") break;
        s+=' ';
        if (words.size()==0) {
            string tmp="";
            for (int i=0;i<s.size();i++) {
                if (s[i]!=' ') tmp+=s[i]; 
                else {
                    words.pb(tmp);
                    tmp="";
                }
            }
        } else {
            vector<string> parsed;
            string tmp="";
            for (int i=0;i<s.size();i++) {
                if (s[i]!=' ') tmp+=s[i]; 
                else {
                    parsed.pb(tmp);
                    tmp="";
                }
            }
            haram.insert(parsed[2]);
        }
    }
    for (int i=0;i<words.size();i++) {
        if (haram.count(words[i])==0) cout << words[i] << " ";
    }
    cout << endl;
    }    
    return 0;
}
