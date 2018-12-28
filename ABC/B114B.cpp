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
    string S;
    cin >> S;
    int min = 1000;
    REP(i, S.length() - 2)
    {
        int a = S[i] - '0';
        int b = S[i + 1] - '0';
        int c = S[i + 2] - '0';

        int s = a * 100 + b * 10 + c;
        min = std::min(min, abs(753 - s));
    }
    cout << min << endl;
    return 0;
}