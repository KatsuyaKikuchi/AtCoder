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
    ll H, W;
    cin >> W >> H;
    if (4 * H == 3 * W)
        cout << "4:3" << endl;
    else
        cout << "16:9" << endl;
    return 0;
}