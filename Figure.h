#ifndef __FIGURE_H__
#define __FIGURE_H__

#include "Object.h"

struct Figure;

typedef struct Figure_interface
{
  Object_interface;

  const char* (*type) (const struct Figure *this);
  void (*draw) (const struct Figure *this);
  double (*area) (const struct Figure *this);

} Figure_interface;

typedef struct Figure
{
  Figure_interface *vtable;

} Figure;

#endif // __FIGURE_H__
