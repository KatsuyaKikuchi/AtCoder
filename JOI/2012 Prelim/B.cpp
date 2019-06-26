#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[100005];

int main()
{
    ll N;
    cin >> N;
    memset(A, 0, sizeof(A));
    REP(i, N * (N - 1) / 2)
    {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        if (c > d)
        {
            A[a] += 3;
        }
        else if (c < d)
        {
            A[b] += 3;
        }
        else
        {
            A[a]++;
            A[b]++;
        }
    }
    vector<ll> B;
    REP(i, N)
    {
        B.push_back(A[i]);
    }
    sort(B.begin(), B.end(), [](ll a, ll b) { return a > b; });
    //B.erase(unique(B.begin(), B.end()), B.end());

    REP(i, N)
    {
        //cout << A[i] << endl;
        int n = find(B.begin(), B.end(), A[i]) - B.begin();
        cout << n + 1 << endl;
    }
    return 0;
}