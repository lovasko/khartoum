#include <math.h>

#include "cam/persp.h"

void
cam_persp_setup(persp* c, const float ratio)
{
  vector left;
  float width;
  float height;

  vector_cross(&left, &c->ps_for, &c->ps_up);
  vector_norm(&left);

  width = 1.0f / tanf(c->ps_fov / 2.0f);
  height = width / ratio;

  vector_copy(&c->ps_hst, &left);
  vector_mul(&c->ps_hst, -width);

  vector_copy(&c->ps_vst, &c->ps_up);
  vector_mul(&c->ps_vst, -height);
}

void
cam_persp_primary(ray* r, const persp* c, const float x, const float y)
{
  vector dir;
  vector xdir;
  vector ydir;

  vector_copy(&xdir, &c->ps_hst);
  vector_mul(&xdir, x);

  vector_copy(&ydir, &c->ps_vst);
  vector_mul(&ydir, y);

  vector_repeat(&dir, 0.0f);
  vector_add(&dir, &xdir);
  vector_add(&dir, &ydir);
  vector_add(&dir, &c->ps_for);
  vector_norm(&dir);

  vector_copy(&r->ry_ori, &c->ps_pos);
  vector_copy(&r->ry_dir, &dir);
}
