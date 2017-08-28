#ifndef ZIAR_CAM_PERSP_H
#define ZIAR_CAM_PERSP_H

#include "geom/vector.h"
#include "geom/ray.h"

/* Perspective camera. */
typedef struct persp {
  vector ps_up;   /** Up direction.      */
  vector ps_fwd;  /** Forward direction. */
  vector ps_pos;  /** Camera position.   */
  vector ps_hst;  /** Horizontal step.   */
  vector ps_vst;  /** Vertical step.     */
  float  ps_fov;  /** Field-of-view.     */
} persp;

/* Initialise the camera. */
void cam_persp_setup(persp* c, const float ratio);

/* Primary ray casting from the camera. */
void cam_persp_primary(ray* r, const persp* c, const float x, const float y);

#endif
