#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

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

Vec2 G[15];

int main()
{
    Vec2 g;
    cin >> g.x >> g.y;
    ll N;
    cin >> N;
    REP(i, N)
    {
        cin >> G[i].x >> G[i].y;
    }

    double min = INF;
    REP(i, N)
    {
        Vec2 v0 = G[(i + 1) % N] - G[i];
        Vec2 v1 = g - G[i];
        double cos = v0.dot(v1) / (v0.length() * v1.length());
        double sin = sqrt(1 - pow(cos, 2));

        double h = v1.length() * sin;
        min = std::min(h, min);
    }
    cout << OF64 << min << endl;
    return 0;
}