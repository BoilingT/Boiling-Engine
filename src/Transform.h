#pragma once
#include <string>

class Transform
{
  private:
  public:
    double x, y, z;
    double rotx_, rot_y, rot_z;
    double scale_x, scale_y, scaler_z;

    Transform(double x, double y, double z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    Transform(Transform &transform)
    {
        this->x = transform.x;
        this->y = transform.y;
        this->z = transform.z;
    }

    void set(double x, double y, double z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    void set(Transform &transform)
    {
        this->x = transform.x;
        this->y = transform.y;
        this->z = transform.z;
    }

    std::string toString();
};