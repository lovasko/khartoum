#ifndef ZIAR_GEOM_VECTOR_H
#define ZIAR_GEOM_VECTOR_H

typedef struct vector {
  float vc_x; /** Axis X component. */
  float vc_y; /** Axis Y component. */
  float vc_z; /** Axis Z component. */
} vector;

/* General-purpose functions. */
void vector_init(vector* v, float x, float y, float z);
void vector_repeat(vector* v, float xyz);
void vector_copy(vector* dst, vector* src);

/* Arithmetic operations. */
void vector_add(vector* v, vector* u);
void vector_sub(vector* v, vector* u);
void vector_mul(vector* v, float s);
void vector_norm(vector* v);

/* Vector products. */
void vector_dot(float* d, vector* v, vector* u);
void vector_cross(vector* c, vector* v, vector* u);

#endif
