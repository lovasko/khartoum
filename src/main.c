#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#include "cam/persp.h"
#include "geom/isect.h"
#include "geom/ray.h"
#include "geom/vector.h"
#include "obj/object.h"
#include "obj/plane.h"
#include "obj/sphere.h"
#include "proc/debug.h"
#include "scene/array.h"

/* Scene camera. */
static persp cam;

/* Scene objects. */
static object objs[4];
static sphere sps[3];
static plane pl;

static void
clamp(uint32_t* x, uint32_t lo, uint32_t hi)
{
  if (*x > hi) *x = hi;
  if (*x < lo) *x = lo;
}

static uint32_t
scale(float x, uint32_t s)
{
  uint32_t y;

  y = (uint32_t)(x * (float)s);
  clamp(&y, 0, s);
  return y;
}

static float
coord(long val, long max)
{
  return ((((float)val + 0.5f)/(float)max)*2.0f)-1.0f;
}

static void
init_camera(void)
{
  vector_init(&cam.ps_pos, 0.0f, 2.0f, 0.0f);
  vector_init(&cam.ps_up,  0.0f, 1.0f, 0.0f);
  vector_init(&cam.ps_for, 0.0f, 0.0f, 1.0f);
  cam.ps_fov = 3.1415f/2.0f;

  cam_persp_setup(&cam, 1.0f);
}

static void
init_scene(void)
{
  vector_init(&sps[0].sp_pos, 0.0f, 2.0f, 5.0f);
  sps[0].sp_rad = 2.0f;
  objs[0].ob_geo = &sps[0];
  objs[0].ob_mat = NULL;
  objs[0].ob_gt  = OBJ_SPHERE;
  objs[0].ob_mt  = 0;

  vector_init(&sps[1].sp_pos, 1.0f, 1.0f, 3.0f);
  sps[1].sp_rad = 1.0f;
  objs[1].ob_geo = &sps[1];
  objs[1].ob_mat = NULL;
  objs[1].ob_gt  = OBJ_SPHERE;
  objs[1].ob_mt  = 0;

  vector_init(&sps[2].sp_pos, -2.0f, 0.5f, 6.0f);
  sps[2].sp_rad = 0.5f;
  objs[2].ob_geo = &sps[2];
  objs[2].ob_mat = NULL;
  objs[2].ob_gt  = OBJ_SPHERE;
  objs[2].ob_mt  = 0;

  vector_init(&pl.pl_pos, 0.0f, 0.0f, 0.0f);
  vector_init(&pl.pl_nor, 0.0f, 1.0f, 0.0f);
  objs[3].ob_geo = &pl;
  objs[3].ob_mat = NULL;
  objs[3].ob_gt  = OBJ_PLANE;
  objs[3].ob_mt  = 0;
}

int
main(void)
{
  FILE* output;
  uint32_t x;
  uint32_t y;
  vector c;
  ray r;
  isect i;

  init_camera();
  init_scene();

  output = fopen("output.ppm", "w");
  if (output == NULL) {
    perror("fopen");
    exit(1);
  }

  fprintf(output, "P3\n%d\n%d\n255\n", 500, 500);

  for (y = 0; y < 500; y++) {
    for (x = 0; x < 500; x++) {
      cam_persp_primary(&cam, coord(x, 500), coord(y, 500), &r);
      scene_array_intersect(objs, 4, &r, &i);
      proc_debug_compute(&r, &i, &c);
      fprintf(output, "%u %u %u ",
             scale(c.vc_x, 255),
             scale(c.vc_y, 255),
             scale(c.vc_z, 255));
    }
    fprintf(output, "\n");
  }

  return EXIT_SUCCESS;
}
