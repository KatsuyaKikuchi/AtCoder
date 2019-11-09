#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(20)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

struct Cone
{
    double X;
    double H;
    double R;
};

double calc(Cone &c, double l, double r)
{
    if (c.X >= r || c.X + c.H <= l)
        return 0;
    double x0 = std::max(l, c.X);
    double x1 = std::min(r, c.X + c.H);

    double h0 = (c.H + c.X - x0);
    double h1 = (c.H + c.X - x1);

    double r0 = c.R * h0 / c.H;
    double r1 = c.R * h1 / c.H;

    double v0 = r0 * r0 * h0 * M_PI / 3.0;
    double v1 = r1 * r1 * h1 * M_PI / 3.0;
    return v0 - v1;
}

Cone C[105];
int main()
{
    ll N;
    cin >> N;
    ll Q;
    cin >> Q;
    REP(i, N)
    {
        cin >> C[i].X >> C[i].R >> C[i].H;
    }

    REP(q, Q)
    {
        double a, b;
        cin >> a >> b;
        double v = 0;
        REP(i, N)
        {
            v += calc(C[i], a, b);
        }
        cout << OF64 << v << endl;
    }
    return 0;
}