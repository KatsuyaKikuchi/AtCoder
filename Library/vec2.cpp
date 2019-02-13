//! 2次元ベクトルクラス
class Vec2
{
  public:
    Vec2()
        : x(0), y(0)
    {
    }
    Vec2(double x, double y)
        : x(x), y(y)
    {
    }

    double length()
    {
        return sqrt(x * x + y * y);
    }
    Vec2 normalize()
    {
        double l = length();
        return Vec2(x / l, y / l);
    }
    double dot(Vec2 v)
    {
        return x * v.x + y * v.y;
    }
    double det(Vec2 v)
    {
        return x * v.y - y * v.x;
    }
    Vec2 rotate(double theta)
    {
        return Vec2(cos(theta) * x - sin(theta) * y, sin(theta) * x + cos(theta) * y);
    }

    double x;
    double y;

    Vec2 operator+(const Vec2 &v)
    {
        return Vec2(v.x + this->x, v.y + this->y);
    }
    Vec2 operator-(const Vec2 &v)
    {
        return Vec2(this->x - v.x, this->y - v.y);
    }
    Vec2 operator*(const double &a)
    {
        return Vec2(a * this->x, a * this->y);
    }
    Vec2 operator/(const double &a)
    {
        return Vec2(this->x / a, this->y / a);
    }
};