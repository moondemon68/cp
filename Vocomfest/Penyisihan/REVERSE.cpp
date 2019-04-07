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
    string s;
    cin >> s;
    string t="";
    for (int i=0;i<s.size();i++) {
        if (s[i]=='%'&&s[i+1]=='2'&&s[i+2]=='0') {
            t+=' ';
            i+=2;
        }
        else if (s[i]=='%'&&s[i+1]=='2'&&s[i+2]=='8') {
            t+='(';
            i+=2;
        }
        else if (s[i]=='%'&&s[i+1]=='2'&&s[i+2]=='9') {
            t+=')';
            i+=2;
        }
        else if (s[i]=='%'&&s[i+1]=='2'&&s[i+2]=='C') {
            t+=',';
            i+=2;
        }
        else if (s[i]=='%'&&s[i+1]=='2'&&s[i+2]=='2') {
            t+='"';
            i+=2;
        }
        else if (s[i]=='%'&&s[i+1]=='2'&&s[i+2]=='7') {
            t+='\'';
            i+=2;
        }
        else if (s[i]=='%'&&s[i+1]=='2'&&s[i+2]=='1') {
            t+='!';
            i+=2;
        }
        else if (s[i]=='%'&&s[i+1]=='3'&&s[i+2]=='F') {
            t+='?';
            i+=2;
        }
        else t+=s[i];
    } 
    //cout << t << endl;
    string tmp="";
    string g="";
    bool d[1005];
    for (int p=0;p<=1000;p++) {
        memset (d,0,sizeof(d));
        for (int i=0;i<t.size();i++) {
            if (d[i]) continue;
            if (t[i]=='(') {
                tmp="";
                tmp+='(';
                for (int j=i+1;j<t.size();j++) {
                    if (t[j]=='(') {
                        tmp="";
                        g+='(';
                        break;
                    } else if (t[j]==')') {
                        tmp+=')';
                        break;
                    }
                    else tmp+=t[j];
                }
                //if (tmp.size()>=1)  cout << tmp << endl;
                for (int j=0;j<tmp.size();j++) d[i+j]=1;
                for (int j=tmp.size()-2;j>=1;j--) g+=tmp[j];
            } 
            else g+=t[i];
        }
        t=g;
        g="";
        //cout << t << endl;
    }
    cout << t << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}