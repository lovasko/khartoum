#ifndef ZIAR_OBJ_TRIANGLE_H
#define ZIAR_OBJ_TRIANGLE_H

#include "geom/vector.h"
#include "geom/ray.h"

typedef struct triangle {
  vector tr_a; /** Point A. */
  vector tr_b; /** Point B. */
  vector tr_c; /** Point C. */
} triangle;

void triangle_intersect(triangle* x, ray* r, float* t);
void triangle_normal(triangle* x, vector* p, vector* n);

#endif
