#include <bits/stdc++.h>

using namespace std;

int j(int m) {
	if (m==2) return 28;
	if (m==1||m==3||m==5||m==7||m==8||m==10||m==12) return 31;
	return 30;
}

int main () {
	int d,m;
	cin >> d >> m;
	int hari=4;
	int h=1,b=1;
	while (h!=d||b!=m) {
		hari++;
		if (hari>7) hari=1;
		h++;
		if (h>j(b)) {
			h=1;
			b++;
		}
	}
	if (hari==1) cout << "Monday"; 
	if (hari==2) cout << "Tuesday";
	if (hari==3) cout << "Wednesday";
	if (hari==4) cout << "Thursday";
	if (hari==5) cout << "Friday";
	if (hari==6) cout << "Saturday";
	if (hari==7) cout << "Sunday";
	cout << endl;
	return 0;
}
