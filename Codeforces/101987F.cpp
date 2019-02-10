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
    clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    getline(cin,s);
    for (int i=0;i<s.size();i++) {
        if (s[i]==' ') {
            s.erase(s.begin()+i);
            i--;
        }
    }
    int cnt=0,buka=0,var=0,tanda=0;
    for (int i=0;i<s.size();i++) {
        if (s[i]=='(') {
            cnt++;
            buka++;
        }
        if (s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='%') tanda++;
        if (s[i]>='a'&&s[i]<='z') var++;
        if (s[i]==')') cnt--;
        if (s[i]>='a'&&s[i]<='z'&&s[i+1]>='a'&&s[i+1]<='z') {
            cout << "error" << endl;
            return 0;
        }
        if (cnt<0||(i!=s.size()-1&&(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='%')&&(s[i+1]=='+'||s[i+1]=='-'||s[i+1]=='*'||s[i+1]=='/'||s[i+1]=='%'))) {
            cout << "error" << endl;
            return 0;
        }
    }
    if (cnt>0||tanda!=var-1) {
        cout << "error" << endl;
        return 0;
    }
    if (buka>var-2&&var>2) {
        cout << "improper" << endl;
        return 0;
    }
    if (buka<var-2&&var>2) {
        cout << "error" << endl;
        return 0;
    }
    cout << "proper" << endl;
    cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}