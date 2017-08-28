#ifndef ZIAR_SCENE_ARRAY_H
#define ZIAR_SCENE_ARRAY_H

#include "geom/ray.h"
#include "geom/isect.h"
#include "obj/object.h"

void scene_array_intersect(isect* i,
                           const object* objs,
                           const size_t nobjs,
                           const ray* r);

#endif
