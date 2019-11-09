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
    int N;
    cin >> N;
    FOR(i, N + 1, 1)
    {
        bool f = false;
        FOR(j, 7, 2)
        {
            if (i % j == 0)
            {
                cout << (char)('a' + j - 2);
                f = true;
            }
        }
        if (!f)
            cout << i;
        cout << endl;
    }
    return 0;
}