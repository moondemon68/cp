#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<int,int>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    getline(cin,s);
    if (s[s.size()-1]=='?') {
        cout << "7";
    } else {
        bool y=1;
        string p="";
        for (int i=0;i<s.size();i++) {
            if (s[i]==' '||s[i]=='.'||s[i]=='!') {
                if (p=="Sussu") {
                    cout << "AI SUSSU!" << endl;
                    return 0;
                } 
                p="";
            } else {
                p+=s[i];
            }
        }
        cout << "O cara é bom!" << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}