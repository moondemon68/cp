#include <iostream>

using namespace std;

int main () {
    int hasilPerkalian, hasilPenjumlahan;
    cout << "Hasil perkalian PIN: ";
    cin >> hasilPerkalian;
    cout << "Hasil penjumlahan PIN: ";
    cin >> hasilPenjumlahan;
    bool found=false;   // variabel penanda
    for (int i=0;i<=9;i++) {
        for (int j=0;j<=9;j++) {
            for (int k=0;k<=9;k++) {
                for (int l=0;l<=9;l++) {
                    if (((i*j*k*l)==hasilPerkalian) && ((i+j+k+l)==hasilPenjumlahan) && (found==false)) {
                        cout << "PIN Tuan Yon adalah " << i << j << k << l << endl;
                        found=true; // menyatakan bahwa sebuah kombinasi telah ditemukan
                    }
                }
            }
        }
    }
    if (found==false) {
        cout << "Tidak ada kombinasi yang valid" << endl;
    }
    return 0;
}