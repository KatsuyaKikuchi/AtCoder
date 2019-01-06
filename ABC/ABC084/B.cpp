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
    int A, B;
    cin >> A >> B;
    string S;
    cin >> S;
    string a = "Yes";
    REP(i, A)
    {
        if (S[i] - '0' >= 0 && S[i] - '0' <= 9)
            continue;
        a = "No";
    }
    REP(i, B)
    {
        if (S[i + A + 1] - '0' >= 0 && S[i + A + 1] - '0' <= 9)
            continue;
        a = "No";
    }
    if (S[A] != '-')
        a = "No";
    cout << a << endl;
    return 0;
}