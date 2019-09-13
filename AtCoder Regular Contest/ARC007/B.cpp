#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[105];

int main()
{
    ll N, M;
    cin >> N >> M;
    REP(i, N)
    {
        A[i + 1] = i + 1;
    }

    ll c = 0;
    REP(i, M)
    {
        ll d;
        cin >> d;
        REP(j, N)
        {
            if (A[j + 1] == d)
            {
                ll t = A[j + 1];
                A[j + 1] = c;
                c = t;
                break;
            }
        }
    }

    REP(i, N)
    {
        cout << A[i + 1] << endl;
    }
    return 0;
}