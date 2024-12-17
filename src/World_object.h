#pragma once
#include "Transform.h"

class World_Object
{

  private:
  public:
    Transform transform;

    World_Object(Transform transform) : transform(transform)
    {
    }

    World_Object(double x, double y, double z) : transform(x, y, z)
    {
    }
};