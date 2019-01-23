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
    while (cin >> s) {
        if (s=="end"||s=="mistake") return 0;
        int l=1,h=2;
        char xory='y',onetwo;
        xory='y';
        while (xory=='y') {
            cout << "? " << l << " " << h << endl;
            cin >> xory;
            if (l==1&&h==2) onetwo=xory;
            if (xory=='y') {
                l*=2;
                h*=2;
            } else {
                break;
            }
        }
        while ((h-l)>1) {
            int x=1;
            int newl=l,newh=newl+x;
            xory='y';
            while (xory=='y') {
                cout << "? " << newl << " " << newh << endl;
                cin >> xory;
                if (xory=='y') {
                    newl=newh;
                    x*=2;
                    newh+=x;
                } else {
                    l=newl;
                    h=newh;
                }
            }
        }
        char twothree;
        if (h==2) {
            cout << "? 2 3" << endl;
            cin >> twothree;
            if (onetwo=='x'&&twothree=='x') {
                cout << "! 1" << endl;
                continue;
            }
        }
        cout << "! " << h << endl;
    }    
    return 0;
}
