#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int main()
{
    ll N;
    cin >> N;
    vector<double> v;
    REP(i, N)
    {
        ll n;
        cin >> n;
        v.push_back(n);
    }

    REP(i, N - 1)
    {
        sort(v.begin(), v.end());
        double n = (v[0] + v[1]) * 0.5;
        vector<double> u;
        FOR(j, v.size(), 2)
        {
            u.push_back(v[j]);
        }
        u.push_back(n);
        v = u;
    }

    cout << OF64 << v[0] << endl;

    return 0;
}