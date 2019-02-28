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
    int N, A, B;
    cin >> N >> A >> B;
    ll m = 0;
    REP(i, N)
    {
        string s;
        int d;
        cin >> s >> d;
        if (s == "East")
            m += std::min(std::max(d, A), B);
        else
            m -= std::min(B, std::max(A, d));
    }

    if (m < 0)
        cout << "West ";
    else if (m > 0)
        cout << "East ";
    cout << abs(m) << endl;
    return 0;
}