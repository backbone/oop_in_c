#ifndef __SQUARE_H__
#define __SQUARE_H__

#include "Figure.h"

typedef struct Square_data
{
  double a;

} Square_data;

struct Square;

typedef struct Square_interface
{
  Figure_interface;

  void (*resize) (struct Square *this, double a);
  double (*diag_length) (const struct Square *this);

} Square_interface;

void Square_constructor (struct Square *this, double a);
void Square_destructor (struct Square *this);
void Square_copy (struct Square *dest, const struct Square *src);
struct Square* Square_clone (const struct Square *this);
void Square_destroy (struct Square *this);
const char* Square_type (const struct Square *this);
void Square_draw (const struct Square *this);
double Square_area (const struct Square *this);
void Square_resize (struct Square *this, double a);
double Square_diag_length (const struct Square *this);

/* public */
typedef struct Square
{
  Square_interface *vtable;

  Square_data;

} Square;

Square* Square_new (double a);

#endif // __SQUARE_H__
