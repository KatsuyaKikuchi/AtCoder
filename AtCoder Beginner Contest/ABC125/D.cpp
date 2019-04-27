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
    int m = 0;
    ll sum = 0;
    REP(i, N)
    {
        cin >> A[i];
        if (A[i] < 0)
            m++;
        A[i] = abs(A[i]);
        sum += A[i];
    }
    sort(A, A + N);
    if (m % 2 == 1)
        sum -= 2 * A[0];
    cout << sum << endl;
    return 0;
}