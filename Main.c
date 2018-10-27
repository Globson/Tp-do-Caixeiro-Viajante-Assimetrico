#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Libs/Interativo.h"
#include "Libs/Menu.h"
int main(int argc, char const *argv[]) {
  srand((unsigned)time(NULL));

  Interativo();
  return 0;
}
