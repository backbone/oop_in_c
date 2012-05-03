#ifndef __FIGURE_H__
#define __FIGURE_H__

#include "Object.h"

typedef struct Figure
{
  struct Figure_vtable
  {
    /* derived from Object */
    const char* (*type) ();
    struct Figure* (*clone) (const struct Figure *this);
    void (*destroy) (struct Figure *this);

    /* Figure virtual methods */
    void (*draw) (const struct Figure *this);
    double (*area) (const struct Figure *this);

  } *vtable;

} Figure;

static inline const char* Figure_type (const Figure *this)
{
  return this->vtable->type ();
}

static inline Figure* Figure_clone (const Figure *this)
{
  return this->vtable->clone (this);
}

static inline void Figure_destroy (Figure *this)
{
  this->vtable->destroy (this);
}

static inline void Figure_draw (const Figure *this)
{
  this->vtable->draw (this);
}

static inline double Figure_area (const Figure *this)
{
  return this->vtable->area (this);
}

/* considered to be protected */
void Figure_constructor (Figure *this);
void Figure_destructor (Figure *this);
void Figure_copy (Figure *dest, const Figure *src);

#endif // __FIGURE_H__
