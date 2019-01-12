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
    int a = 0, b = 0, c = 0;
    REP(i, N)
    {
        int p;
        cin >> p;
        if (p <= A)
            a++;
        else if (p <= B)
            b++;
        else
            c++;
    }
    cout << std::min(a, std::min(b, c)) << endl;
    return 0;
}