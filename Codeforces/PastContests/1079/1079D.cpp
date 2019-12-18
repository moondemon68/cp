#include <bits/stdc++.h>
#define x first
#define y second
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
    double a,b,c;
    cin >> a >> b >> c;
    if (a==0) a=MOD*MOD;
    if (b==0) b=MOD*MOD;
    double x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if ((x1>=x2&&y1<=y2)||(x1<=x2&&y1>=y2)) {
      double ans=abs(x1-x2)+abs(y1-y2);
      if (x1>=x2&&y1<=y2) {
        swap(x1,x2);
        swap(y1,y2);
      }
      pair<double,double> ins1,ins2,ins3,ins4;
      ins1=mp(x1,(-a*x1-c)/b);
      ins2=mp((-b*y1-c)/a,y1);
      ins3=mp(x2,(-a*x2-c)/b);
      ins4=mp((-b*y2-c)/a,y2);
      if (ins2.x>=x1&&ins2.x<=x2&&ins3.y>=y2&&ins3.y<=y1) {
        ans=min(ans,ins2.x-x1-y2+ins3.y+sqrt((ins3.x-ins2.x)*(ins3.x-ins2.x)+(ins3.y-ins2.y)*(ins3.y-ins2.y)));
      }
      if (ins1.y>=y2&&ins1.y<=y1&&ins3.y>=y2&&ins3.y<=y1) {
        ans=min(ans,-ins1.y+y1-y2+ins3.y+sqrt((ins3.x-ins1.x)*(ins3.x-ins1.x)+(ins3.y-ins1.y)*(ins3.y-ins1.y)));
      }
      if (ins2.x<=x2&&ins2.x>=x1&&ins4.x<=x2&&ins4.x>=x1) {
        ans=min(ans,ins2.x-x1+x2-ins4.x+sqrt((ins2.x-ins4.x)*(ins2.x-ins4.x)+(ins2.y-ins4.y)*(ins2.y-ins4.y)));
      }
      if (ins4.x>=x1&&ins4.x<=x2&&ins1.y>=y2&&ins1.y<=y1) {
        ans=min(ans,ins4.x-x1-y2+ins1.y+sqrt((ins4.x-ins1.x)*(ins4.x-ins1.x)+(ins4.y-ins1.y)*(ins4.y-ins1.y)));
      }
      cout << fixed << setprecision(10) << ans << endl;
      return 0;
    }

    if ((x1>=x2&&y1>=y2)||(x1<=x2&&y1<=y2)) {
      double ans=abs(x1-x2)+abs(y1-y2);
      if (x1<=x2&&y1<=y2) {
        swap(x1,x2);
        swap(y1,y2);
      }
      pair<double,double> ins1,ins2,ins3,ins4;
      ins3=mp(x1,(-a*x1-c)/b);
      ins2=mp((-b*y1-c)/a,y1);
      ins1=mp(x2,(-a*x2-c)/b);
      ins4=mp((-b*y2-c)/a,y2);
      if (ins2.x<=x1&&ins2.x>=x2&&ins1.y>=y2&&ins1.y<=y1) {
        ans=min(ans,-ins2.x+x1-y2+ins1.y+sqrt((ins1.x-ins2.x)*(ins1.x-ins2.x)+(ins1.y-ins2.y)*(ins1.y-ins2.y)));
        //cout << ans << endl;
      }
      if (ins3.y>=y2&&ins3.y<=y1&&ins1.y>=y2&&ins1.y<=y1) {
        ans=min(ans,-ins3.y+y1-y2+ins1.y+sqrt((ins3.x-ins1.x)*(ins3.x-ins1.x)+(ins3.y-ins1.y)*(ins3.y-ins1.y)));
        //cout << ans << endl;
      }
      if (ins4.x>=x2&&ins4.x<=x1&&ins2.x>=x2&&ins2.x<=x1) {
        ans=min(ans,ins4.x-x2+x1-ins2.x+sqrt((ins2.x-ins4.x)*(ins2.x-ins4.x)+(ins2.y-ins4.y)*(ins2.y-ins4.y)));
        //cout << ans << endl;
      }
      if (ins4.x<=x1&&ins4.x>=x2&&ins3.y>=y2&&ins3.y<=y1) {
        //cout << ins4.x << endl;
        //cout << ins3.y << endl;
        ans=min(ans,abs(ins4.x-x2)+abs(y1-ins3.y)+sqrt((ins4.x-ins3.x)*(ins4.x-ins3.x)+(ins4.y-ins3.y)*(ins4.y-ins3.y)));
        //cout << ans << endl;
      }
      cout << fixed << setprecision(10) << ans << endl;
      return 0;
    }

    return 0;
}
