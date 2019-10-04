#include <bits/stdc++.h>

using namespace std;

// HEX/BIT VIEWER CR: JOJO
void hex(int num){
    char hex[5];
    sprintf(hex, "%x", num);
    puts(hex);
}

void bin(int n){
    int c, k;
    for (c = 31; c >= 0; c--){
    k = n >> c;
    if (k & 1) printf("1");
    else printf("0");
    }
    printf("\n");
}
// JOJO's ENDING

// x^y
int itomori(int x, int y) {
    int a = ~x&y;
    int b = x&~y;
    int c = ~a&~b;
    return ~c;
}

// INT_MIN
int tokyo() {
    return 1 << 31;
}

// tukar byte ke n dengan m
int musubi(int x, int n, int m) {
    int nMask = (0xFF << (n << 3));
    int mMask = (0xFF << (m << 3));
    int nByte = (nMask & x) >> (n << 3);
    int mByte = (mMask & x) >> (m << 3);
    int tmp = nByte;
    nByte = mByte;
    mByte = tmp;
    x = x & ~nMask;
    x = x & ~mMask;
    nByte = (nByte << (n << 3));
    mByte = (mByte << (m << 3));
    nByte = nByte & nMask;
    mByte = mByte & mMask;
    x = x | nByte;
    x = x | mByte;
    return x;
}

// rep bit dari x: setiap bit ganjil bernilai 1
int kuchikamizake(int x) {
    int ans = 0xAA;
    ans = ans << 8;
    ans = ans + 0xAA;
    ans = ans << 8;
    ans = ans + 0xAA;
    ans = ans << 8;
    ans = ans + 0xAA; // ans = 0xAAAAAAAA
    return !((x & ans)+~ans+1); // x&ans == ans
}

// absolute function
unsigned katawaredoki(unsigned uf) {
    unsigned neg = (uf>>31) & 0x1;
    if (neg && (uf != -2147483648)) return (~uf + 1);
    return uf; 
}

// balik urutan byte dari x
int tessie(int x) {
    int Mask0 = (0xFF);
    int Mask1 = (0xFF << 8);
    int Mask2 = (0xFF << 16);
    int Mask3 = (0xFF << 24);
    int a0 = x & Mask0;
    int a1 = x & Mask1;
    int a2 = x & Mask2;
    int a3 = x & Mask3;
    int ans = a0;
    ans = ans << 8;
    ans = ans + (a1 >> 8);
    ans = ans << 8;
    ans = ans + (a2 >> 16);
    ans = ans << 8;
    a3 = a3 >> 8;           // fucking arithmetic shift
    a3 = a3 & Mask2;        // bertahap deh
    ans = ans + (a3 >> 16); // toh jadi juga
    return ans;
}

// return x*3/4 - BLOM AC - case -2147483648 >> gatau jawabannya kebalik tandanya;
int sayaka (int x) {
    int p = x + (x << 1);
    int neg = (p >> 31);
    p = p + neg;
    p = p ^ neg;
    p = p >> 2;
    p = p + neg;
    p = p ^ neg;
    return p;
}

// return 1 if x != 0, 0 if x == 0
int koi(int x) {
    int neg = ~x + 1;   // -x
    int ans = x | neg;
    ans = ans >> 31;
    ans = ans & 1;
    return ans;
}

int a[]={4,333,16518380};
int b[]={5,142,39081531};
int tc=3;

int main () {
    for (int i=0;i<tc;i++) {
        if ((a[i]^b[i]) != itomori(a[i], b[i])) {
            printf("%d ^ %d = %d BUKAN %d\n", a[i], b[i], (a[i]^b[i]), itomori(a[i], b[i]));
        }
    }

    if ((INT_MIN) != tokyo()) {
        printf("INT_MIN = %d BUKAN %d\n", (INT_MIN), tokyo());
    }

    if (musubi(0xDEADBEEF, 1, 3) != 0xBEADDEEF) {
        //cout << musubi(0xDEADBEEF, 1, 3) << endl;
        cout << "salah" << endl;
    }
    if (musubi(0xDEADBEEF, 3, 1) != 0xBEADDEEF) {
        //cout << musubi(0xDEADBEEF, 1, 3) << endl;
        cout << "salah" << endl;
    }

    if (kuchikamizake(0xAAAAAAAA) != 1) {
        cout << kuchikamizake(0xAAAAAAAA) << endl;
    }
    if (kuchikamizake(0xFFFFFFFD) != 0) {
        cout << kuchikamizake(0xFFFFFFFD) << endl;
    }

    if (tessie(0x01020304) != 0x04030201) {
        cout << tessie(0x01020304) << endl;
    }
    if (tessie(0xf3253577) != 0x773525f3) {
        cout << tessie(0xf3253577) << endl;
    }

    if (sayaka(11) != 8) {
        cout << "salah1" << endl;
    }
    if (sayaka(-9) != -6) {
        cout << sayaka(-9) << endl;
        cout << "salah2" << endl;
    }
    if (sayaka(1073741824) != -268435456) {
        cout << "salah3" << endl;
    }
    if (sayaka(4) != 3) {
        cout << sayaka(4) << endl;
        cout << "salah4" << endl;
    }
    if (sayaka(-4) != -3) {
        cout << sayaka(-4) << endl;
        cout << "salah5" << endl;
    }

    while (1) {
        int x;
        cin >> x;
        cout << katawaredoki(x) << " " << abs(x) << endl;
    }

    // while (1) {
    //     int x;
    //     cin >> x;
    //     cout << koi(x) << " " << (x != 0) << endl;
    // }
    // for (int i=INT_MIN;i<=INT_MAX;i++) {
    //     if (koi(i) != (i != 0)) {
    //         cout << i << endl;
    //         cout << koi(i) << " " << (i != 0) << endl;
    //     }
    // }
    return 0;
}