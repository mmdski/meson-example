#include <stdlib.h>

int main(void) {
  double *x = malloc(sizeof(double));
  free(x);
  return EXIT_SUCCESS;
}
