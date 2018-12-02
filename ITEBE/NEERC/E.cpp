#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

void prt(char a,int l,int r) {
  for (int i=l;i<=r;i++) {
    cout << a << i << " ";
  }
}
void prtd(char a,int l,int r) {
  for (int i=l;i>=r;i--) {
    cout << a << i << " ";
  }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    if (n==2) {
      cout << "a1 a8 h8" << endl;
    }
    if (n==3) {
      cout << "a1 a7 a8 h8" << endl;
    }
    if (n==4) {
      cout << "a1 a6 a7 a8 h8" << endl;
    }
    if (n==5) {
      cout << "a1 a5 a6 a7 a8 h8" << endl;
    }
    if (n==6) {
      cout << "a1 a4 a5 a6 a7 a8 h8" << endl;
    }
    if (n==7) {
      cout << "a1 a3 a4 a5 a6 a7 a8 h8" << endl;
    }
    if (n==8) {
      cout << "a1 a2 a3 a4 a5 a6 a7 a8 h8" << endl;
    }
    if (n==9) {
      cout << "a1 b1 b2 b3 b4 b5 b6 b7 b8 h8" << endl;
    }
    if (n==10) {
      cout << "a1 b1 ";
      prt('c',1,8);
      cout << "h8";
    }
    if (n==11) {
      cout << "a1 b1 c1 ";
      prt('d',1,8);
      cout << "h8";
    }
    if (n==12) {
      cout << "a1 b1 c1 d1 ";
      prt('e',1,8);
      cout << "h8";
    }
    if (n==13) {
      cout << "a1 b1 c1 d1 e1 ";
      prt('f',1,8);
      cout << "h8";
    }
    if (n==14) {
      cout << "a1 b1 c1 d1 e1 f1 ";
      prt('g',1,8);
      cout << "h8";
    }
    if (n==15) {
      prt('a',1,8);
      prtd('b',8,5);
      prt('h',5,8);
    }
    if (n==16) {
      prt('a',1,8);
      prtd('b',8,5);
      cout << "g5 ";
      prt('h',5,8);
    }
    if (n==17) {
      prt('a',1,8);
      prtd('b',8,4);
      prt('h',4,8);
    }
    if (n==18) {
      prt('a',1,8);
      prtd('b',8,4);
      cout << "g4 ";
      prt('h',4,8);
    }
    if (n==19) {
      prt('a',1,8);
      prtd('b',8,3);
      prt('h',3,8);
    }
    if (n==20) {
      prt('a',1,8);
      prtd('b',8,3);
      cout << "g3 ";
      prt('h',3,8);
    }
    if (n==21) {
      prt('a',1,8);
      prtd('b',8,2);
      prt('h',2,8);
    }
    if (n==22) {
      prt('a',1,8);
      prtd('b',8,2);
      cout << "g2 ";
      prt('h',2,8);
    }
    if (n==23) {
      prt('a',1,8);
      prtd('b',8,1);
      prt('h',1,8);
    }
    if (n==24) {
      prt('a',1,8);
      prtd('b',8,1);
      cout << "g1 ";
      prt('h',1,8);
    }
    if (n==25) {
      prt('a',1,8);
      prtd('b',8,1);
      prt('c',1,8);
      cout << "g8 h8 ";
    }
    if (n==26) {
      prt('a',1,8);
      prtd('b',8,1);
      prt('c',1,8);
      cout << "f8 g8 h8 ";
    }
    if (n==27) {
      prt('a',1,8);
      prtd('b',8,1);
      prt('c',1,8);
      cout << "e8 f8 g8 h8 ";
    }
    if (n==28) {
      prt('a',1,8);
      prtd('b',8,1);
      prt('c',1,8);
      cout << "d8 e8 f8 g8 h8 ";
    }
    if (n==29) {
      prt('a',1,8);
      prtd('b',8,1);
      prt('c',1,8);
      prtd('d',8,5);
      cout << "h5 h8 ";
    }
    if (n==30) {
      prt('a',1,8);
      prtd('b',8,1);
      prt('c',1,8);
      prtd('d',8,5);
      cout << "g5 h5 h8 ";
    }
    if (n==31) {
      prt('a',1,8);
      prtd('b',8,1);
      prt('c',1,8);
      prtd('d',8,5);
      cout << "f5 g5 h5 h8 ";
    }
    if (n==32) {
      prt('a',1,8);
      prtd('b',8,1);
      prt('c',1,8);
      prtd('d',8,5);
      cout << "e5 f5 g5 h5 h8 ";
    }
    if (n==33) {
      prt('a',1,8);
      prtd('b',8,1);
      prt('c',1,8);
      prtd('d',8,1);
      prt('h',1,1);
      cout << "h8 ";
    }
    if (n==34) {
      prt('a',1,8);
      prtd('b',8,1);
      prt('c',1,8);
      prtd('d',8,1);
      prt('h',1,2);
      cout << "h8 ";
    }
    if (n==35) {
      prt('a',1,8);
      prtd('b',8,1);
      prt('c',1,8);
      prtd('d',8,1);
      prt('h',1,3);
      cout << "h8 ";
    }
    if (n==36) {
      prt('a',1,8);
      prtd('b',8,1);
      prt('c',1,8);
      prtd('d',8,1);
      prt('h',1,4);
      cout << "h8 ";
    }
    if (n==37) {
      prt('a',1,8);
      prtd('b',8,1);
      prt('c',1,8);
      prtd('d',8,1);
      prt('h',1,5);
      cout << "h8 ";
    }
    if (n==38) {
      prt('a',1,8);
      prtd('b',8,1);
      prt('c',1,8);
      prtd('d',8,1);
      prt('h',1,6);
      cout << "h8 ";
    }
    if (n==39) {
      prt('a',1,8);
      prtd('b',8,1);
      prt('c',1,8);
      prtd('d',8,1);
      prt('h',1,7);
      cout << "h8 ";
    }
    if (n==40) {
      prt('a',1,8);
      prtd('b',8,1);
      prt('c',1,8);
      prtd('d',8,1);
      prt('e',1,8);
      cout << "h8 ";
    }
    if (n==41) {
      prt('a',1,8);
      prtd('b',8,1);
      prt('c',1,8);
      prtd('d',8,1);
      prt('e',1,8);
      cout << "g8 h8 ";
    }
    if (n==42) {
      prt('a',1,8);
      prtd('b',8,1);
      prt('c',1,8);
      prtd('d',8,1);
      prt('e',1,8);
      cout << "f8 g8 h8 ";
    }
    if (n==43) {
      prt('a',1,8);
      prtd('b',8,1);
      prt('c',1,8);
      prtd('d',8,1);
      prt('e',1,8);
      prtd('f',8,7);
      cout << "h7 h8 ";
    }
    if (n==44) {
      prt('a',1,8);
      prtd('b',8,1);
      prt('c',1,8);
      prtd('d',8,1);
      prt('e',1,8);
      prtd('f',8,7);
      cout << "g7 h7 h8 ";
    }
    if (n==45) {
      prt('a',1,8);
      prtd('b',8,1);
      prt('c',1,8);
      prtd('d',8,1);
      prt('e',1,8);
      prtd('f',8,6);
      cout << "h6 h7 h8 ";
    }
    if (n==46) {
      prt('a',1,8);
      prtd('b',8,1);
      prt('c',1,8);
      prtd('d',8,1);
      prt('e',1,8);
      prtd('f',8,6);
      cout << "g6 h6 h7 h8 ";
    }
    if (n==47) {
      prt('a',1,8);
      prtd('b',8,1);
      prt('c',1,8);
      prtd('d',8,1);
      prt('e',1,8);
      prtd('f',8,5);
      cout << "h5 h6 h7 h8 ";
    }
    if (n==48) {
      prt('a',1,8);
      prtd('b',8,1);
      prt('c',1,8);
      prtd('d',8,1);
      prt('e',1,8);
      prtd('f',8,5);
      cout << "g5 h5 h6 h7 h8 ";
    }
    if (n==49) {
      prt('a',1,8);
      prtd('b',8,1);
      prt('c',1,8);
      prtd('d',8,1);
      prt('e',1,8);
      prtd('f',8,4);
      cout << "h4 h5 h6 h7 h8 ";
    }
    if (n==50) {
      prt('a',1,8);
      prtd('b',8,1);
      prt('c',1,8);
      prtd('d',8,1);
      prt('e',1,8);
      prtd('f',8,4);
      cout << "g4 h4 h5 h6 h7 h8 ";
    }
    if (n==51) {
      prt('a',1,8);
      prtd('b',8,1);
      prt('c',1,8);
      prtd('d',8,1);
      prt('e',1,8);
      prtd('f',8,3);
      cout << "h3 h4 h5 h6 h7 h8 ";
    }
    if (n==52) {
      prt('a',1,8);
      prtd('b',8,1);
      prt('c',1,8);
      prtd('d',8,1);
      prt('e',1,8);
      prtd('f',8,3);
      cout << "g3 h3 h4 h5 h6 h7 h8 ";
    }
    if (n==53) {
      prt('a',1,8);
      prtd('b',8,1);
      prt('c',1,8);
      prtd('d',8,1);
      prt('e',1,8);
      prtd('f',8,2);
      cout << "h2 h3 h4 h5 h6 h7 h8 ";
    }
    if (n==54) {
      prt('a',1,8);
      prtd('b',8,1);
      prt('c',1,8);
      prtd('d',8,1);
      prt('e',1,8);
      prtd('f',8,2);
      cout << "g2 h2 h3 h4 h5 h6 h7 h8 ";
    }
    if (n==55) {
      prt('a',1,8);
      prtd('b',8,1);
      prt('c',1,8);
      prtd('d',8,1);
      prt('e',1,8);
      prtd('f',8,1);
      cout << "h1 h2 h3 h4 h5 h6 h7 h8 ";
    }
    if (n==56) {
      prt('a',1,8);
      prtd('b',8,1);
      prt('c',1,8);
      prtd('d',8,1);
      prt('e',1,8);
      prtd('f',8,1);
      cout << "g1 h1 h2 h3 h4 h5 h6 h7 h8 ";
    }
    if (n==57) {
      prt('a',1,8);
      prtd('b',8,1);
      prt('c',1,8);
      prtd('d',8,1);
      prt('e',1,8);
      prtd('f',8,1);
      prt('g',1,5);
      cout << "h5 h6 g6 g8 h8 ";
    }
    if (n==58) {
      prt('a',1,8);
      prtd('b',8,1);
      prt('c',1,8);
      prtd('d',8,1);
      prt('e',1,8);
      prtd('f',8,1);
      prt('g',1,6);
      cout << "h6 h7 g7 g8 h8 ";
    }
    if (n==59) {
      prt('a',1,8);
      prtd('b',8,1);
      prt('c',1,8);
      prtd('d',8,1);
      prt('e',1,8);
      prtd('f',8,1);
      cout << "h1 g1 g2 h2 h3 g3 g4 h4 h5 g5 g8 h8 ";
    }
    if (n==60) {
      prt('a',1,8);
      prtd('b',8,1);
      prt('c',1,8);
      prtd('d',8,1);
      prt('e',1,8);
      prtd('f',8,1);
      cout << "h1 g1 g2 h2 h3 g3 g4 h4 h5 g5 g6 h6 h8 ";
    }
    if (n==61) {
      prt('a',1,8);
      prtd('b',8,1);
      prt('c',1,8);
      prtd('d',8,1);
      prt('e',1,8);
      prtd('f',8,1);
      cout << "h1 g1 g2 h2 h3 g3 g4 h4 h5 g5 g6 g7 h7 h8 ";
    }
    if (n==62) {
      prt('a',1,8);
      prtd('b',8,1);
      prt('c',1,8);
      prtd('d',8,1);
      prt('e',1,8);
      prtd('f',8,1);
      prt('g',1,7);
      prtd('h',7,1);
      cout << "h8 ";
    }
    if (n==63) {
      prt('a',1,8);
      prtd('b',8,1);
      prt('c',1,8);
      prtd('d',8,1);
      prt('e',1,8);
      prtd('f',8,1);
      cout << "h1 g1 g2 h2 h3 g3 g4 h4 h5 g5 g6 h6 h7 g7 g8 h8 ";
    }
    return 0;
}
