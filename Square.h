#ifndef __SQUARE_H__
#define __SQUARE_H__

#include "Figure.h"

typedef struct Square_data
{
  double a;

} Square_data;

typedef struct Square_interface
{
  Figure_interface;

  void (*resize) (void *this, double a);
  double (*diag_length) (void *this);

} Square_interface;

void Square_constructor (void *this);
void Square_destructor (void *this);
void Square_copy (void *to, void *from);
void* Square_clone (void *this);
void Square_destroy (void *this);
const char* Square_type (void *this);
void Square_draw (void *this);
double Square_area (void *this);
void Square_resize (void *this, double a);
double Square_diag_length (void *this);

/* public */
typedef struct Square
{
  Square_interface *vtable;

  Square_data;

} Square;

void* Square_new ();

#endif // __SQUARE_H__
