#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[100005];

int main()
{
    int N;
    cin >> N;
    REP(i, N)
    {
        cin >> A[i];
    }
    int n = 0;
    ll p = 0;
    FOR(i, N, 1)
    {
        ll q = A[i] - A[i - 1];
        if (q > 0)
        {
            //! 増加
            if (p < 0)
            {
                n++;
                p = 0;
                continue;
            }
            p = q;
        }
        else if (q < 0)
        {
            //! 減少
            if (p > 0)
            {
                n++;
                p = 0;
                continue;
            }
            p = q;
        }
    }
    cout << n + 1 << endl;
    return 0;
}