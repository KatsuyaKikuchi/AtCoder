#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

double getR(double a, double b, double c, double tana, double tanb, double S)
{
    double ok = 0, ng = a;
    REP(i, 50)
    {
        double r = (ok + ng) * 0.5;
        double n = r / tana, m = r / tanb;
        double h = 2 * S / a;
        double ts = b * r * 0.5 + c * r * 0.5 + (h - r) * r + r * 2 * r + n * r * 0.5 + m * r * 0.5;
        if (n + m + 2 * r > a || ts > S)
        {
            ng = r;
        }
        else
        {
            ok = r;
        }
    }
    return ok;
}

int main()
{
    pll A, B, C;
    cin >> A.first >> A.second;
    cin >> B.first >> B.second;
    cin >> C.first >> C.second;

    double AB = sqrt(pow(A.first - B.first, 2) + pow(A.second - B.second, 2));
    double BC = sqrt(pow(C.first - B.first, 2) + pow(C.second - B.second, 2));
    double CA = sqrt(pow(A.first - C.first, 2) + pow(A.second - C.second, 2));

    double s = 0.5 * (AB + BC + CA);
    double S = sqrt(s * (s - AB) * (s - BC) * (s - CA));

    double tanA = tan(asin(2 * S / (AB * CA)) * 0.5);
    double tanB = tan(asin(2 * S / (BC * AB)) * 0.5);
    double tanC = tan(asin(2 * S / (BC * CA)) * 0.5);

    double mr = 0;
    mr = std::max(mr, getR(AB, BC, CA, tanA, tanB, S));
    mr = std::max(mr, getR(BC, CA, AB, tanB, tanC, S));
    mr = std::max(mr, getR(CA, AB, BC, tanC, tanA, S));

    cout << OF64 << mr << endl;
    return 0;
}