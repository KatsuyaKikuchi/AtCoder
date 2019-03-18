#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int N, A, B;

bool check(int n)
{
    int s = 0;
    while (n > 0)
    {
        s += n % 10;
        n /= 10;
    }
    return s >= A && s <= B;
}

int main()
{
    cin >> N >> A >> B;

    int s = 0;
    REP(n, N + 1)
    {
        if (check(n))
            s+=n;
    }
    cout << s << endl;
    return 0;
}