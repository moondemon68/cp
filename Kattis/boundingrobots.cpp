#include <bits/stdc++.h>

using namespace std;

int main () {
	int r,c;
	while (cin >> r >> c) {
		if (r==0&&c==0) return 0;
		int ar=0,ac=0,tr=0,tc=0;
		int n;
		cin >> n;
		for (int i=1;i<=n;i++) {
			char x;
			int y;
			cin >> x >> y;
			if (x=='u') {
				tc+=y;
				ac+=y;
				if (ac>c-1) ac=c-1;
			} else if (x=='d') {
				tc-=y;
				ac-=y;
				if (ac<0) ac=0;
			} else if (x=='r') {
				tr+=y;
				ar+=y;
				if (ar>r-1) ar=r-1;
			} else if (x=='l') {
				tr-=y;
				ar-=y;
				if (ar<0) ar=0;
			}
		}
		cout << "Robot thinks " << tr << " " << tc << endl;
		cout << "Actually at " << ar << " " << ac << endl;
		cout << endl;
	}
}
