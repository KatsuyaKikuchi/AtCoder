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
    int A, B, C, X;
    cin >> A >> B >> C >> X;
    int ans = 0;
    REP(a, A + 1)
    {
        REP(b, B + 1)
        {
            REP(c, C + 1)
            {
                if (500 * a + 100 * b + 50 * c == X)
                    ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}