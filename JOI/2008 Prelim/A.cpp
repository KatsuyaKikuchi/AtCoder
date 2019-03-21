#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int C[6] = {500, 100, 50, 10, 5, 1};

int main()
{
    int N;
    cin >> N;
    N = 1000 - N;
    int sum = 0;
    REP(i, 6)
    {
        sum += N / C[i];
        N %= C[i];
    }
    cout << sum << endl;
    return 0;
}