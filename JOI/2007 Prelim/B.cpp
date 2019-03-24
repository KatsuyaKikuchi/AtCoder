#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int C[30];

int main()
{
    REP(i, 28)
    {
        cin >> C[i];
    }
    FOR(i, 31, 1)
    {
        bool e = false;
        REP(j, 28)
        {
            if (C[j] == i)
                e = true;
        }
        if (!e)
            cout << i << endl;
    }
    return 0;
}