#ifndef __RHOMB_H__
#define __RHOMB_H__

#include "Polygon.h"

typedef struct Rhomb
{
  struct Rhomb_vtable
  {
    /* derived from Object */
    const char* (*type) ();
    struct Rhomb* (*clone) (const struct Rhomb *this);
    void (*destroy) (struct Rhomb *this);

    /* derived from Figure */
    void (*draw) (const struct Rhomb *this);
    double (*area) (const struct Rhomb *this);

    /* derived from Polygon */
    double (*max_diag) (const struct Rhomb *this);

    /* Rhomb virtual methods */
    int (*is_square) (const struct Rhomb *this);

  } *vtable;

  /* derived from Polygon */
  size_t npoints;

  struct point *points;

} Rhomb;

Rhomb* Rhomb_new (const struct point *points);

static inline const char* Rhomb_type (const Rhomb *this)
{
  return this->vtable->type ();
}

static inline Rhomb* Rhomb_clone (const Rhomb *this)
{
  return this->vtable->clone (this);
}

static inline void Rhomb_destroy (Rhomb *this)
{
  this->vtable->destroy (this);
}

static inline void Rhomb_draw (const Rhomb *this)
{
  this->vtable->draw (this);
}

static inline double Rhomb_area (const Rhomb *this)
{
  return this->vtable->area (this);
}

static inline double Rhomb_max_diag (const Rhomb *this)
{
  return this->vtable->max_diag (this);
}

static inline int Rhomb_is_square (const Rhomb *this)
{
  return this->vtable->is_square (this);
}

/* considered to be protected */
void Rhomb_constructor (Rhomb *this, const struct point *points);
void Rhomb_destructor (Rhomb *this);
void Rhomb_copy (Rhomb *dest, const Rhomb *src);

#endif // __RHOMB_H__
