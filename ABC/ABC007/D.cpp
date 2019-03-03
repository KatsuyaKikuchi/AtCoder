#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

//! 10^n未満に含まれる禁止された数
ll K[20];

ll get(ll k)
{
    int i = 0;
    while (k > 1)
    {
        k /= 10;
        i++;
    }
    return K[i];
}
//! n以下に含まれる禁止された数
ll solve(ll n)
{
    ll m = 0;
    ll k = pow(10, 18);
    while (k > n)
        k /= 10;
    while (k > 0)
    {
        REP(i, 10)
        {
            if (n >= (i + 1) * k)
            {
                if (i == 4 || i == 9)
                {
                    m += k;
                }
                else
                {
                    m += get(k);
                }
                continue;
            }
            if (i == 4 || i == 9)
            {
                m += n % k + 1;
                k = 0;
            }
            n -= i * k;
            break;
        }
        k /= 10;
    }
    return m;
}

int main()
{
    ll A, B;
    cin >> A >> B;
    K[0] = 0;
    FOR(i, 20, 1)
    {
        K[i] = K[i - 1] * 8 + 2 * pow(10, i - 1);
    }
    cout << solve(B) - solve(A - 1) << endl;
    return 0;
}