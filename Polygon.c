#include <stdio.h>
#include <string.h>
#include <math.h>

#include "Polygon.h"

/* considered to be protected */
void Polygon_constructor (Polygon *this, const struct point *points, size_t npoints)
{
  Figure_constructor ((Figure *) this);
  this->npoints = npoints;
  this->points = malloc (npoints * sizeof (struct point));
  memcpy (this->points, points, npoints * sizeof (struct point));
}

void Polygon_destructor (Polygon *this)
{
  free (this->points);
}

void Polygon_copy (Polygon *dest, const Polygon *src)
{
  free (dest->points);
  dest->npoints = src->npoints;
  dest->points = malloc (src->npoints * sizeof (struct point));
  memcpy (dest->points, src->points, src->npoints * sizeof (struct point));
}

/* private */
static const char* __Polygon_type ()
{
  return "Polygon";
}

static Polygon* __Polygon_clone (const Polygon *this)
{
  Polygon *poly = malloc (sizeof (Polygon));
  memset (poly, 0, sizeof (Polygon));
  Polygon_copy (poly, this);
  poly->vtable = this->vtable;
  return poly;
}

static void __Polygon_destroy (Polygon *this)
{
  Polygon_destructor (this);
  free (this);
}

void __Polygon_draw (const Polygon *this)
{
  size_t i = 0;

  for (i = 0; i < this->npoints; i++)
    {
      printf ("{%f;%f}, ", this->points[i].x, this->points[i].y);
    }
  printf ("{%f;%f}\n", this->points[0].x, this->points[0].y);
}

double __Polygon_area (const Polygon *this)
{
  double s = 0.0;
  size_t i = 0;

  for (i = 0; i < this->npoints; i++)
    {
      s += this->points[i].x * this->points[(i + 1) % this->npoints].y -
           this->points[(i + 1) % this->npoints].x * this->points[i].y;
    }

  return fabs (s) * 0.5;
  // Trapezium rule for convex and non-convex polygons
  // S=abs(сумма{(x[i+1]-x[i])*(y[i+1]+y[i])/2})
}

double __Polygon_max_diag (const Polygon *this)
{
  double diag = 0.0,
         tmp = 0.0,
         tmp1 = 0.0,
         tmp2 = 0.0;
  size_t i = 0, j = 0;

  for (i = 0; i < this->npoints - 2; i++)
    {
      for (j = i + 2; j < this->npoints; j++)
        {
          tmp1 = (this->points[i].x - this->points[j].x);
          tmp2 = (this->points[i].y - this->points[j].y);
          tmp = sqrt (tmp1 * tmp1 + tmp2 * tmp2);
          if (diag < tmp)
            {
              diag = tmp;
            }
        }
    }

  return diag;
}

/* public */
Polygon* Polygon_new (const struct point *points, size_t npoints)
{
  static struct Polygon_vtable vtable = {
    __Polygon_type,
    __Polygon_clone,
    __Polygon_destroy,
    __Polygon_draw,
    __Polygon_area,
    __Polygon_max_diag
  };

  Polygon *poly = malloc (sizeof (Polygon));
  memset (poly, 0, sizeof (Polygon));
  Polygon_constructor (poly, points, npoints);
  poly->vtable = &vtable;
  return poly;
}
