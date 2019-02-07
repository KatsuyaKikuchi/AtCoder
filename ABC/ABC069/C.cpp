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
    int N;
    cin >> N;
    int x = 0, y = 0, z = 0;
    REP(i, N)
    {
        ll a;
        cin >> a;
        if (a % 4 == 0)
            x++;
        else if (a % 2 == 0)
            y++;
        else
            z++;
    }
    if (z + (y % 2) <= x + 1)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}