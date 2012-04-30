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
  double (*diag_length) (struct Square *this);

} Square_interface;

void Square_constructor (struct Square *this, double a);
void Square_destructor (struct Square *this);
void Square_copy (struct Square *to, struct Square *from);
struct Square* Square_clone (struct Square *this);
void Square_destroy (struct Square *this);
const char* Square_type (struct Square *this);
void Square_draw (struct Square *this);
double Square_area (struct Square *this);
void Square_resize (struct Square *this, double a);
double Square_diag_length (struct Square *this);

/* public */
typedef struct Square
{
  Square_interface *vtable;

  Square_data;

} Square;

struct Square* Square_new (double a);

#endif // __SQUARE_H__
