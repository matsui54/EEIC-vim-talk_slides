#include <stdio.h>
#include <string.h>
#include <sys/mman.h>

int foo() { return 0; }

int main(int argc, char *argv[]) {
  // for printf
  for (size_t i = 10; i < 200; i++) {
    printf("%d\n", i);
  }
  return 0;
}
