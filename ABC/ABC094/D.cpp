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
    sort(A, A + N);
    ll a = A[N - 1];
    ll b = A[0];
    REP(i, N - 1)
    {
        if (a % 2 == 0)
        {
            if (abs(a / 2 - b) > abs(a / 2 - A[i]))
                b = A[i];
        }
        else
        {
            if (std::min(abs(a / 2 - b), abs(a / 2 - b + 1)) > std::min(abs(a / 2 - A[i]), abs(a / 2 - A[i] + 1)))
                b = A[i];
        }
    }

    cout << a << " " << b << endl;
    return 0;
}