#include <cstdio>
#include <string>

int N = 5;
int arr[5];

void gali(int x) {
  printf("%d_", x);
  if (x > 1) {
    gali(x / 4);
    gali(x / 2);
  }
  printf("%d_", -x);
}

int main() {
  gali(4);
}
