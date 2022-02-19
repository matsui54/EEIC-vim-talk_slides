#include <stdio.h>
#include <string.h>

int foo() { return 0; }

int main(int argc, char *argv[]) {
  for (int j = 0; j < 10; j++) {
    printf("%d\n", j);
  }
  return 0;
}
