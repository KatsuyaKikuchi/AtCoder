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
    string S, T;
    cin >> S >> T;
    ll min = INF;
    if (S.length() == T.length())
    {
        ll n = S.length();
        REP(i, n)
        {
            bool f = true;
            REP(j, n)
            {
                if (S[(n - i + j) % n] == T[j])
                    continue;
                f = false;
            }
            if (f)
                min = std::min(min, i);
        }
    }

    if (min == INF)
        cout << -1 << endl;
    else
        cout << min << endl;
    return 0;
}