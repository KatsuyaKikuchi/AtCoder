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
    ll s = N % 60;
    N /= 60;
    ll m = N % 60;
    ll h = N / 60;
    cout << std::setfill('0') << std::right << std::setw(2) << h << ":";
    cout << std::setfill('0') << std::right << std::setw(2) << m << ":";
    cout << std::setfill('0') << std::right << std::setw(2) << s << endl;
    return 0;
}