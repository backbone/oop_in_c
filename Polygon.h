#ifndef __POLYGON_H__
#define __POLYGON_H__

#include <stdlib.h>

#include "Figure.h"

typedef struct Polygon
{
  struct Polygon_vtable
  {
    /* derived from Object */
    const char* (*type) ();
    struct Polygon* (*clone) (const struct Polygon *this);
    void (*destroy) (struct Polygon *this);

    /* derived from Figure */
    void (*draw) (const struct Polygon *this);
    double (*area) (const struct Polygon *this);

    /* Polygon virtual methods */
    double (*max_diag) (const struct Polygon *this);

  } *vtable;

  /* Polygon fields */
  size_t npoints;

  struct point
  {
    double x, y;
  
  } *points;

} Polygon;

Polygon* Polygon_new (const struct point *points, size_t npoints);

static inline const char* Polygon_type (const Polygon *this)
{
  return this->vtable->type ();
}

static inline Polygon* Polygon_clone (const Polygon *this)
{
  return this->vtable->clone (this);
}

static inline void Polygon_destroy (Polygon *this)
{
  this->vtable->destroy (this);
}

static inline void Polygon_draw (const Polygon *this)
{
  this->vtable->draw (this);
}

static inline double Polygon_area (const Polygon *this)
{
  return this->vtable->area (this);
}

static inline double Polygon_max_diag (const Polygon *this)
{
  return this->vtable->max_diag (this);
}

/* considered to be protected */
void Polygon_constructor (Polygon *this, const struct point *points, size_t npoints);
void Polygon_destructor (Polygon *this);
void Polygon_copy (Polygon *dest, const Polygon *src);
void __Polygon_draw (const Polygon *this);
double __Polygon_area (const Polygon *this);
double __Polygon_max_diag (const Polygon *this);

#endif // __POLYGON_H__
