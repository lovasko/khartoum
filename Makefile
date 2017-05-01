CC=clang
STANDARDS=-ansi -pedantic
WARNINGS=-Wall -Wextra -Weverything
CFLAGS=-g -O3 -fPIC -Isrc $(STANDARDS) $(WARNINGS)
LDFLAGS= 
EXECUTABLE=bin/run
OBJECTS=obj/cam_persp.o   \
        obj/geom_ray.o    \
        obj/geom_vector.o \
        obj/main.o        \
        obj/obj_object.o  \
        obj/obj_plane.o   \
        obj/obj_sphere.o  \
        obj/proc_debug.o  \
        obj/scene_array.o

all: bin/run

bin/run: $(OBJECTS)
	$(CC) -fPIC -o $(EXECUTABLE) $(OBJECTS) $(LDFLAGS)

clean:
	rm $(OBJECTS) $(EXECUTABLE)

obj/cam_persp.o: src/cam/persp.c
	$(CC) $(CFLAGS) -c src/cam/persp.c -o obj/cam_persp.o

obj/geom_ray.o: src/geom/ray.c
	$(CC) $(CFLAGS) -c src/geom/ray.c -o obj/geom_ray.o

obj/geom_vector.o: src/geom/vector.c
	$(CC) $(CFLAGS) -c src/geom/vector.c -o obj/geom_vector.o

obj/main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o obj/main.o

obj/obj_object.o: src/obj/object.c
	$(CC) $(CFLAGS) -c src/obj/object.c -o obj/obj_object.o

obj/obj_plane.o: src/obj/plane.c
	$(CC) $(CFLAGS) -c src/obj/plane.c -o obj/obj_plane.o

obj/obj_sphere.o: src/obj/sphere.c
	$(CC) $(CFLAGS) -c src/obj/sphere.c -o obj/obj_sphere.o

obj/proc_debug.o: src/proc/debug.c
	$(CC) $(CFLAGS) -c src/proc/debug.c -o obj/proc_debug.o

obj/scene_array.o: src/scene/array.c
	$(CC) $(CFLAGS) -c src/scene/array.c -o obj/scene_array.o
