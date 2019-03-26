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
    ll N;
    cin >> N;
    ll sum = 0;
    for (ll i = 1; i * i < N; ++i)
    {
        if (N % i == 0)
        {
            sum += i;
            if (i > 1)
                sum += N / i;
        }
    }

    if (sum == N)
        cout << "Perfect" << endl;
    else if (sum > N)
        cout << "Abundant" << endl;
    else
        cout << "Deficient" << endl;
    return 0;
}