#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

pair<double, double> w[1005];
int N, K;

bool check(double m)
{
    vector<double> v(N);
    REP(i, N)
    {
        double p = w[i].first * w[i].second - m * w[i].first;
        v[i] = p;
    }
    sort(v.begin(), v.end(), [](double a, double b) { return a > b; });
    double sum = 0;
    REP(i, K)
    {
        sum += v[i];
    }
    return sum >= 0.0;
}

int main()
{
    cin >> N >> K;
    REP(i, N)
    {
        cin >> w[i].first >> w[i].second;
    }

    double un = 0.0, tp = 101.0;
    REP(i, 50)
    {
        double mid = (un + tp) * 0.5;
        if (check(mid))
        {
            un = mid;
        }
        else
        {
            tp = mid;
        }
    }
    cout << OF64 << un << endl;
    return 0;
}