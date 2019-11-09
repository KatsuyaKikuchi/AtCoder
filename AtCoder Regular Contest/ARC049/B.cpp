#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(20)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll N;
pll P[1005];
ll C[1005];

bool check(double c)
{
    double XL = -INF, XU = INF;
    REP(i, N)
    {
        double xl = -c / C[i] + P[i].first;
        double xu = c / C[i] + P[i].first;
        XL = std::max(xl, XL);
        XU = std::min(xu, XU);
    }

    double YL = -INF, YU = INF;
    REP(i, N)
    {
        double yl = -c / C[i] + P[i].second;
        double yu = c / C[i] + P[i].second;
        YL = std::max(yl, YL);
        YU = std::min(yu, YU);
    }

    //  cout << YL << endl;
    // cout << YU << endl;
    return YL <= YU && XL <= XU;
}

int main()
{
    cin >> N;
    REP(i, N)
    {
        cin >> P[i].first >> P[i].second;
        cin >> C[i];
    }

    double ok = INF, ng = 0;
    REP(i, 100)
    {
        double mid = (ok + ng) * 0.5;
        if (check(mid))
            ok = mid;
        else
            ng = mid;
    }
    cout << OF64 << ok << endl;

    return 0;
}