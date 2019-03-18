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
    int R;
    cin >> R;
    if (R < 1200)
        cout << "ABC" << endl;
    else if (R < 2800)
        cout << "ARC" << endl;
    else
        cout << "AGC" << endl;
    return 0;
}