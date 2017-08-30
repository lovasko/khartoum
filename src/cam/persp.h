#ifndef ZIAR_CAM_PERSP_H
#define ZIAR_CAM_PERSP_H

#include "geom/vector.h"
#include "geom/ray.h"


/// Perspective camera.
typedef struct persp {
  vector ps_up;  ///< Up direction.
  vector ps_fwd; ///< Forward direction.
  vector ps_pos; ///< Camera position.
  vector ps_hst; ///< Horizontal step.
  vector ps_vst; ///< Vertical step.
  float  ps_fov; ///< Field-of-view.
} persp;

/// Initialise the camera.
/// @param[out] c camera
/// @param[in]  r horizontal/vertical ratio
void cam_persp_setup(persp* c, const float r);

/// Primary ray casting from the camera.
/// @param[out] r primary ray
/// @param[in]  c camera
/// @param[in]  x image X coordinate (0.0 - 1.0)
/// @param[in]  y image Y coordinate (0.0 - 1.0)
void cam_persp_primary(
        ray*   restrict r,
  const persp* restrict c,
  const float           x,
  const float           y);

#endif
