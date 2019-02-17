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
    int N;
    cin >> N;
    string s = "No";
    REP(i, 30)
    {
        if (i * 4 > N)
            break;
        if ((N - (i * 4)) % 7 == 0)
            s = "Yes";
    }
    cout << s << endl;
    return 0;
}