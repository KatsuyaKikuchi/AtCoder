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
    if (N == 3)
    {
        cout << "2 5 63" << endl;
        return 0;
    }

    vector<int> v;
    //! 3の倍数を偶数個入れられるだけ入れる
    ll t = std::min((ll)5000, (N - 2) - (N - 2) % 2);
    REP(i, t)
    {
        v.push_back(3 + 6 * i);
    }
    REP(i, (N - t) / 2)
    {
        if (2 * (i + 1) != 15000)
            v.push_back(2 * (i + 1));
        v.push_back(30000 - 2 * (i + 1));
    }
    if (N > v.size())
    {
        v.push_back(30000);
    }
    REP(i, N)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}