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

//! グラハムスキャンによる凸包検索クラス
class ConvexFull
{
  public:
    ConvexFull() {}

    //! グラハムスキャンによる凸包検索関数。
    //! pll配列を受け取り、凸包になるような要素のindex配列を返却する。
    //! 返り値の配列は凸包となるような要素のindexが反時計回りで格納されている。
    //! 計算オーダーO(NlogN)
    vector<int> getConvexFullIndex(Vec2 *vecTbl, int N)
    {
        vector<GridInfo> G(N);
        for (int i = 0; i < N; ++i)
        {
            //! とりあえず扱いやすいよう変換
            G[i] = GridInfo(vecTbl[i], i);
        }
        std::sort(G.begin(), G.end(), [](GridInfo a, GridInfo b) { return a.x() == b.x() ? a.y() < b.y() : a.x() < b.x(); });
        vector<int> q(N * 2);
        int k = 0;
        for (int i = 0; i < N; ++i)
        {
            while (k > 1)
            {
                Vec2 v0 = G[i].v - G[q[k - 1]].v;
                Vec2 v1 = G[q[k - 1]].v - G[q[k - 2]].v;
                if (v1.det(v0) > 0)
                    break;
                k--;
            }
            q[k++] = i;
        }
        for (int i = N - 2, t = k; i >= 0; --i)
        {
            while (k > t)
            {
                Vec2 v0 = G[i].v - G[q[k - 1]].v;
                Vec2 v1 = G[q[k - 1]].v - G[q[k - 2]].v;
                if (v1.det(v0) > 0)
                    break;
                k--;
            }
            q[k++] = i;
        }
        q.resize(k - 1);
        REP(i, k - 1)
        {
            q[i] = G[q[i]].i;
        }
        return q;
    }

  private:
    struct GridInfo
    {
        GridInfo() {}
        GridInfo(Vec2 v, int i)
            : v(v), i(i) {}

        Vec2 v;
        int i;

        double x() const
        {
            return v.x;
        }
        double y() const
        {
            return v.y;
        }
    };
};