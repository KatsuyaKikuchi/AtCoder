#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

struct Circle
{
    Circle(double x, double y, double r)
        : x(x), y(y), r(r)
    {
    }
    Circle() {}
    double x, y;
    double r;
};
struct Vertex
{
    int i;
    double cost;
};

Circle C[1005];
//! startから点iまでの最短距離
double L[1005];

double length(Circle c0, Circle c1)
{
    return std::max(sqrt(pow(c0.x - c1.x, 2) + pow(c0.y - c1.y, 2)) - c0.r - c1.r, (double)0);
}

int main()
{
    double x0, y0, x1, y1;
    int N;
    cin >> x0 >> y0 >> x1 >> y1;
    cin >> N;
    REP(i, N)
    {
        double x, y, r;
        cin >> x >> y >> r;
        C[i] = Circle(x, y, r);
        L[i] = INF;
    }
    C[N] = Circle(x1, y1, 0);
    L[N] = INF;

    priority_queue<Vertex, vector<Vertex>, function<bool(Vertex, Vertex)>> q([](Vertex a, Vertex b) { return a.cost > b.cost; });
    Circle c(x0, y0, 0);
    REP(i, N + 1)
    {
        double cost = length(c, C[i]);
        Vertex v;
        v.i = i;
        v.cost = cost;
        q.push(v);
    }

    while (!q.empty())
    {
        Vertex v = q.top();
        q.pop();
        if (L[v.i] <= v.cost)
            continue;
        L[v.i] = v.cost;
        REP(i, N + 1)
        {
            if (i == v.i)
                continue;
            double cost = v.cost + length(C[i], C[v.i]);
            if (cost >= L[i])
                continue;
            Vertex nv;
            nv.i = i;
            nv.cost = cost;
            q.push(nv);
        }
    }
    cout << OF64 << L[N] << endl;
    return 0;
}