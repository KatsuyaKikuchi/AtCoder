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
bool U[100005];

int main()
{
    int N;
    cin >> N;
    ll xr = 0;
    REP(i, N)
    {
        cin >> A[i];
        xr ^= A[i];
    }

    int sum = 0;
    for (int i = 30; i >= 0; --i)
    {
        int n = ((xr >> i) & 1);
        if ((n + sum) % 2 == 0)
            continue;

        bool find = false;
        REP(j, N)
        {
            if (A[j] % (1 << i) == 0 && ((A[j] >> i) & 1 == 1) && !U[j])
            {
                U[j] = true;
                find = true;
                sum++;
                break;
            }
        }
        if (!find)
        {
            sum = -1;
            break;
        }
    }
    cout << sum << endl;
    return 0;
}