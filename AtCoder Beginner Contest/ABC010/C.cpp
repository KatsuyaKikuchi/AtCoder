#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

pll A[1005];
int main()
{
    pll s, g;
    ll T, V;
    cin >> s.first >> s.second;
    cin >> g.first >> g.second;
    cin >> T >> V;
    ll N;
    cin >> N;
    REP(i, N)
    {
        cin >> A[i].first >> A[i].second;
    }

    bool t = false;
    REP(i, N)
    {
        double a = sqrt(pow(s.first - A[i].first, 2) + pow(s.second - A[i].second, 2));
        double b = sqrt(pow(g.first - A[i].first, 2) + pow(g.second - A[i].second, 2));
        if ((a + b) / V <= T)
            t = true;
    }

    if (t)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}