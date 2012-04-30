#ifndef __FIGURE_H__
#define __FIGURE_H__

#include "Object.h"

struct Figure;

typedef struct Figure_interface
{
  Object_interface;

  const char* (*type) (struct Figure *this);
  void (*draw) (struct Figure *this);
  double (*area) (struct Figure *this);

} Figure_interface;

typedef struct Figure
{
  Figure_interface *vtable;

} Figure;

#endif // __FIGURE_H__
