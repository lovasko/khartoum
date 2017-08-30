#ifndef ZIAR_GEOM_VECTOR_H
#define ZIAR_GEOM_VECTOR_H

/// 3-dimensional vector.
typedef struct vector {
  float vc_x; ///< Axis X component.
  float vc_y; ///< Axis Y component.
  float vc_z; ///< Axis Z component.
} vector;

/// Initialise components of a vector.
/// @param[out] v vector
/// @param[in]  x X axis component
/// @param[in]  y Y axis component
/// @param[in]  z Z axis component
void vector_init(vector* v, const float x, const float y, const float z);

/// Initialise all components of a vector with the same value.
/// @param[out] v   vector
/// @param[in]  xyz value used for all components
void vector_repeat(vector* v, const float xyz);

/// Copy contents of a vector to an another vector.
/// @param[out] dst destination
/// @param[in]  src source
void vector_copy(vector* restrict dst, const vector* restrict src);

/// Add a vector to another one.
/// @param[out] v base vector
/// @param[in]  u vector to add
void vector_add(vector* restrict v, const vector* restrict u);

/// Subtract a vector from another one.
/// @param[out] v base vector
/// @param[in]  u vector to subtract
void vector_sub(vector* restrict v, const vector* restrict u);

/// Multiply all vector components with a scalar.
/// @param[out] v vector
/// @param[in]  s scalar
void vector_mul(vector* v, const float s);

/// Normalise the vector.
/// @param[out] v vector
void vector_norm(vector* v);

/// Compute the "dot" product of two vectors.
/// @param[out] d dot product
/// @param[in]  v first vector
/// @param[in]  u second vector
void vector_dot(
        float*  restrict d,
  const vector* restrict v,
  const vector* restrict u);

/// Compute the "cross" product of two vectors.
/// @param[out] c cross product
/// @param[in]  v first vector
/// @param[in]  u second vector
void vector_cross(
        vector* restrict c,
  const vector* restrict v,
  const vector* restrict u);

#endif
