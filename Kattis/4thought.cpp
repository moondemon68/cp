#include <bits/stdc++.h>

using namespace std;

int main () {
	int tc;
	cin >> tc;
	for (int t=1;t<=tc;t++) {
		int x;
		cin >> x;
		if (x==16)cout << "4 + 4 + 4 + 4 = 16";
		else if (x==8)cout << "4 + 4 + 4 - 4 = 8";
		else if (x==24)cout << "4 + 4 + 4 * 4 = 24";
		else if (x==9)cout << "4 + 4 + 4 / 4 = 9";
		
		//cout << "4 + 4 - 4 + 4 = 8";
		else if (x==0)cout << "4 + 4 - 4 - 4 = 0";
		else if (x==-8)cout << "4 + 4 - 4 * 4 = -8";
		else if (x==7)cout << "4 + 4 - 4 / 4 = 7";
		
		//cout << "4 + 4 * 4 + 4 = 24";
		//cout << "4 + 4 * 4 - 4 = 16";
		else if (x==68)cout << "4 + 4 * 4 * 4 = 68";
		//cout << "4 + 4 * 4 / 4 = 8";
		
		//cout << "4 + 4 / 4 + 4 = 9";
		else if (x==1)cout << "4 + 4 / 4 - 4 = 1";
		//cout << "4 + 4 / 4 * 4 = 8";
		//cout << "4 + 4 / 4 / 4 = 0";
		//
		//cout << "4 - 4 + 4 + 4 = 8";
		//cout << "4 - 4 + 4 - 4 = 0";
		//cout << "4 - 4 + 4 * 4 = 16";
		//cout << "4 - 4 + 4 / 4 = 1";
		
		//cout << "4 - 4 - 4 + 4 = 8";
		//cout << "4 - 4 - 4 - 4 = 0";
		else if (x==-16)cout << "4 - 4 - 4 * 4 = -16";
		else if (x==-1)cout << "4 - 4 - 4 / 4 = -1";
		
		//cout << "4 - 4 * 4 + 4 = 24";
		//cout << "4 - 4 * 4 - 4 = 16";
		else if (x==-60)cout << "4 - 4 * 4 * 4 = -60";
		//cout << "4 - 4 * 4 / 4 = 8";
		
		//cout << "4 - 4 / 4 + 4 = 9";
		//cout << "4 - 4 / 4 - 4 = 1";
		//cout << "4 - 4 / 4 * 4 = 8";
		else if (x==4)cout << "4 - 4 / 4 / 4 = 4";
		//
		//cout << "4 * 4 + 4 + 4 = 16";
		//cout << "4 * 4 + 4 - 4 = 8";
		else if (x==32)cout << "4 * 4 + 4 * 4 = 32";
		else if (x==17)cout << "4 * 4 + 4 / 4 = 17";
		
		//cout << "4 * 4 - 4 + 4 = 8";
		//cout << "4 * 4 - 4 - 4 = 0";
		//cout << "4 * 4 - 4 * 4 = -8";
		else if (x==15)cout << "4 * 4 - 4 / 4 = 15";
		
		//cout << "4 * 4 * 4 + 4 = 24";
		else if (x==60)cout << "4 * 4 * 4 - 4 = 60";
		else if (x==256)cout << "4 * 4 * 4 * 4 = 256";
		//cout << "4 * 4 * 4 / 4 = 8";
		
		//cout << "4 * 4 / 4 + 4 = 9";
		//cout << "4 * 4 / 4 - 4 = 1";
		//cout << "4 * 4 / 4 * 4 = 8";
		//cout << "4 * 4 / 4 / 4 = 0";
		//
		//cout << "4 / 4 + 4 + 4 = 16";
		//cout << "4 / 4 + 4 - 4 = 8";
		//cout << "4 / 4 + 4 * 4 = 24";
		else if (x==2)cout << "4 / 4 + 4 / 4 = 2";
		
		//cout << "4 / 4 - 4 + 4 = 8";
		else if (x==-7)cout << "4 / 4 - 4 - 4 = -7";
		else if (x==-15)cout << "4 / 4 - 4 * 4 = -15";
		//cout << "4 / 4 - 4 / 4 = 7";
		
		//cout << "4 / 4 * 4 + 4 = 24";
		//cout << "4 / 4 * 4 - 4 = 16";
		//cout << "4 / 4 * 4 * 4 = 68";
		//cout << "4 / 4 * 4 / 4 = 8";
		
		//cout << "4 / 4 / 4 + 4 = 9";
		else if (x==-4)cout << "4 / 4 / 4 - 4 = -4";
		//cout << "4 / 4 / 4 * 4 = 8";
		//cout << "4 / 4 / 4 / 4 = 0";
		else cout << "no solution";
		cout << endl;
	}
	return 0;
}