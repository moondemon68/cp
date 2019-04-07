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
    LL s1,s2,s3,e1,e2,e3,s4,e4;
    pair<LL,LL> a[10];
    int sloc,eloc;
    for (int t=1;t<=tc;t++) {
        LL d,b,y,h,m,s;
        cin >> d >> b >> y >> h >> m >> s;
        s1=y*20*50*24*60*60+b*50*24*60*60+d*24*60*60+h*60*60+m*60+s;
        cin >> d >> b >> y >> h >> m >> s;
        e1=y*20*50*24*60*60+b*50*24*60*60+d*24*60*60+h*60*60+m*60+s;
        cin >> d >> b >> y >> h >> m >> s;
        s2=y*20*50*24*60*60+b*50*24*60*60+d*24*60*60+h*60*60+m*60+s;
        cin >> d >> b >> y >> h >> m >> s;
        e2=y*20*50*24*60*60+b*50*24*60*60+d*24*60*60+h*60*60+m*60+s;
        cin >> d >> b >> y >> h >> m >> s;
        s3=y*20*50*24*60*60+b*50*24*60*60+d*24*60*60+h*60*60+m*60+s;
        cin >> d >> b >> y >> h >> m >> s;
        e3=y*20*50*24*60*60+b*50*24*60*60+d*24*60*60+h*60*60+m*60+s;
        cin >> d >> b >> y >> h >> m >> s;
        s4=y*20*50*24*60*60+b*50*24*60*60+d*24*60*60+h*60*60+m*60+s;
        cin >> d >> b >> y >> h >> m >> s;
        e4=y*20*50*24*60*60+b*50*24*60*60+d*24*60*60+h*60*60+m*60+s;
        a[1].fi=s1;
        a[1].se=e1;
        a[2].fi=s2;
        a[2].se=e2;
        a[3].fi=s3;
        a[3].se=e3;
        a[0].fi=0;
        a[0].se=0;
        a[4].fi=12345678987654321;
        a[4].se=12345678987654321;
        sort (a,a+4);
        sloc=0;
        eloc=0;
        bool ans=0;
        /*
        cout << a[0].fi << " " << a[0].se << endl;
        cout << a[1].fi << " " << a[1].se << endl;
        cout << a[2].fi << " " << a[2].se << endl;
        cout << a[3].fi << " " << a[3].se << endl;
        cout << a[4].fi << " " << a[4].se << endl;
        */
        sloc=0;eloc=0;
        if (s4>a[1].fi) sloc=1;
        if (s4>a[1].se) sloc=2;
        if (s4>a[2].fi) sloc=3;
        if (s4>a[2].se) sloc=4;
        if (s4>a[3].fi) sloc=5;
        if (s4>a[3].se) sloc=6;

        if (e4>a[1].fi) eloc=1;
        if (e4>a[1].se) eloc=2;
        if (e4>a[2].fi) eloc=3;
        if (e4>a[2].se) eloc=4;
        if (e4>a[3].fi) eloc=5;
        if (e4>a[3].se) eloc=6;
        if (sloc==eloc) {
            if (sloc==0 || sloc==2 || sloc==4 || sloc==6) ans=1;
            else ans=0; 
        } else {
            ans=0;
        }
        //cout << sloc << "  " << eloc << endl;
        //cout << s4 << endl << e4 << endl;
        cout << "Case #" << t << ": ";
        if (ans) cout << "OK" << endl;
        else cout << "COLLIDE" << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
