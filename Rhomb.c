#include <stdio.h>
#include <string.h>
#include <math.h>

#include "Rhomb.h"

/* considered to be protected */
void Rhomb_constructor (Rhomb *this, const struct point *points)
{
  Polygon_constructor ((Polygon *) this, points, 4);
}

void Rhomb_destructor (Rhomb *this)
{
  Polygon_destructor ((Polygon *) this);
}

void Rhomb_copy (Rhomb *dest, const Rhomb *src)
{
  Polygon_copy ((Polygon *) dest, (Polygon *) src);
}

/* private */
static const char* __Rhomb_type ()
{
  return "Rhomb";
}

static Rhomb* __Rhomb_clone (const Rhomb *this)
{
  Rhomb *rhomb = malloc (sizeof (Rhomb));
  memset (rhomb, 0, sizeof (Rhomb));
  Rhomb_copy (rhomb, this);
  rhomb->vtable = this->vtable;
  return rhomb;
}

static void __Rhomb_destroy (Rhomb *this)
{
  Rhomb_destructor (this);
  free (this);
}

static void __Rhomb_draw (const Rhomb *this)
{
  __Polygon_draw ((Polygon *) this);
}

static double __Rhomb_area (const Rhomb *this)
{
  return __Polygon_area ((Polygon *) this);
}

static double __Rhomb_max_diag (const Rhomb *this)
{
  return __Polygon_max_diag ((Polygon *) this);
}

static int __Rhomb_is_square (const Rhomb *this)
{
  double diag1, diag2, tmp1, tmp2;
  
  tmp1 = this->points[0].x - this->points[2].x;
  tmp2 = this->points[0].y - this->points[2].y;
  diag1 = tmp1 * tmp1 + tmp2 * tmp2;

  tmp1 = this->points[1].x - this->points[3].x;
  tmp2 = this->points[1].y - this->points[3].y;
  diag2 = tmp1 * tmp1 + tmp2 * tmp2;

  return (fabs (diag1 - diag2) < 1e-12);
}

/* public */
Rhomb* Rhomb_new (const struct point *points)
{
  static struct Rhomb_vtable vtable = {
    __Rhomb_type,
    __Rhomb_clone,
    __Rhomb_destroy,
    __Rhomb_draw,
    __Rhomb_area,
    __Rhomb_max_diag,
    __Rhomb_is_square
  };

  Rhomb *rhomb = malloc (sizeof (Rhomb));
  memset (rhomb, 0, sizeof (Rhomb));
  Rhomb_constructor (rhomb, points);
  rhomb->vtable = &vtable;
  return rhomb;
}
