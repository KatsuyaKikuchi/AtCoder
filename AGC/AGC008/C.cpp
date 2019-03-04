#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[10];

int main()
{
    REP(i, 7)
    {
        cin >> A[i];
    }

    ll k = 0;
    k += A[1];
    ll i = A[0] - A[0] % 2;
    k += i;
    A[0] -= i;
    ll j = A[3] - A[3] % 2;
    k += j;
    A[3] -= j;
    ll l = A[4] - A[4] % 2;
    k += l;
    A[4] -= l;
    if (A[0] + A[3] + A[4] == 2)
    {
        if ((A[0] == 0 && i > 0) || (A[3] == 0 && j > 0) || (A[4] == 0 && l > 0))
            k += 1;
    }
    else if (A[0] + A[3] + A[4] == 3)
    {
        k += 3;
    }

    cout << k << endl;
    return 0;
}