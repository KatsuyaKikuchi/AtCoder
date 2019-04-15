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
    int sum = 0;
    for (int i = 1; i <= 100; ++i)
    {
        if (i % 3 == 0)
            continue;
        if (i % 5 == 0)
            continue;
        sum += i;
    }
    cout << sum << endl;
    return 0;
}