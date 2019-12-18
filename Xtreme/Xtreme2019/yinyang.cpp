#include <bits/stdc++.h>

using namespace std;

int check(string s) {
    for (int i=0;i<s.size()/2;i++) {
        if (s[i]!=s[s.size()/2+i]) return 0;
    }
    return 1;
}

int main() {
    srand(time(NULL));
    int n; cin >> n;
    if (n==1) cout << 'y';
    else if (n==2) cout << "Yy";
    else {
        int mini=INT_MAX;
        string s="";
        int run=1e7/n;
        while (1) {
            string p="";
            for (int i=1;i<=n;i++) {
                if (rand()%2==0) p+='y';
                else p+='Y';
            }
            set<string> v;
            for (int i=0;i<n;i++) {
                for (int j=i+1;j<n;j++) {
                    if ((j-i)%2==1) {
                        string t="";
                        for (int f=i;f<=j;f++) t+=p[f];
                        if (check(t)) v.insert(t);
                        
                    }
                }
            }
            //cout << p << " " << x << endl;
            if (v.size()<mini) {
                mini=v.size();
                s=p;
                cout << s << endl << mini << endl;
            }
        }
        cout << s << endl << mini << endl;
    }
    return 0;
}