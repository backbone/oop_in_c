#ifndef __OBJECT_H__
#define __OBJECT_H__

typedef struct Object_interface
{
  void* (*clone) (const void *this);
  void (*destroy) (void *this);

} Object_interface;

#endif // __OBJECT_H__
