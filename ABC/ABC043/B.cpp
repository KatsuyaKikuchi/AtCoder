#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

char A[20];

int main()
{
    string S;
    cin >> S;
    int index = 0;
    REP(i, S.length())
    {
        if (S[i] == 'B')

            index = std::max(0, index - 1);
        else
            A[index++] = S[i];
    }

    REP(i, index)
    {
        cout << A[i];
    }
    cout << endl;
    return 0;
}