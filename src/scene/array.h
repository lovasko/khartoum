#ifndef ZIAR_SCENE_ARRAY_H
#define ZIAR_SCENE_ARRAY_H

#include "geom/ray.h"
#include "geom/isect.h"
#include "obj/object.h"

void scene_array_intersect(object* objs, unsigned int nobjs, ray* r, isect* i);

#endif
