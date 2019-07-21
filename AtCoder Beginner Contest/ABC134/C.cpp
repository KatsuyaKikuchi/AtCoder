#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[200005];

int main()
{
    ll N;
    cin >> N;
    ll max = 0;
    ll n = 0;
    REP(i, N)
    {
        cin >> A[i];
        max = std::max(max, A[i]);
    }

    ll sm = 0;
    REP(i, N)
    {
        if (A[i] == max)
            n++;
        else
            sm = std::max(sm, A[i]);
    }

    REP(i, N)
    {
        if (A[i] != max)
            cout << max << endl;
        else
        {
            if (n == 1)
                cout << sm << endl;
            else
                cout << max << endl;
        }
    }
    return 0;
}