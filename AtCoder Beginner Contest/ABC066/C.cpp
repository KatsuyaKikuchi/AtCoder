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
    int N;
    cin >> N;
    REP(i, N)
    {
        cin >> A[i];
    }
    if (N % 2 == 1)
    {
        for (int i = N - 1; i >= 0; i -= 2)
        {
            cout << A[i] << " ";
        }
        for (int i = 1; i < N; i += 2)
        {
            cout << A[i] << " ";
        }
    }
    else
    {
        for (int i = N - 1; i >= 0; i -= 2)
        {
            cout << A[i] << " ";
        }
        for (int i = 0; i < N; i += 2)
        {
            cout << A[i] << " ";
        }
    }
    cout << endl;

    return 0;
}