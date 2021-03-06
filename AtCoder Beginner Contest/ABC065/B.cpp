#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll a[100005];
bool u[100005];

int main()
{
    int N;
    cin >> N;
    REP(i, N)
    {
        cin >> a[i];
        a[i]--;
        u[i] = false;
    }

    int index = 0;
    int num = -1;
    for (int i = 0; !u[index]; ++i)
    {
        if (index == 1)
        {
            num = i;
            break;
        }
        u[index] = true;
        index = a[index];
    }
    cout << num << endl;
    return 0;
}