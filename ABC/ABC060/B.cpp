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
    int A, B, C;
    cin >> A >> B >> C;
    int D = A % B;

    int E = D;
    do
    {
        if (E % B == C)
        {
            cout << "YES" << endl;
            return 0;
        }
        E = (E + D) % B;
    } while (E != D);
    cout << "NO" << endl;
    return 0;
}