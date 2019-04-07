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
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    for (int t=1;t<=tc;t++) {
        string s;
        cin >> s;
        cout << "Case #" << t << ": ";
        int num=0;
        string g="";
        for (int i=0;i<s.size();i++) {
            if (s[i]=='#') {
                g+=' ';
                i++;
            }
            else if (s[i]=='/') {
                num/=2;
                num--;
                g+='A'+num;
                num=0;
            } else {
                if (s[i]=='-') num++;
                num*=2;
            }
        }
        cout << g << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}