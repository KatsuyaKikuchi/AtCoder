#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int A[10005];

int main()
{
    int H, W, N;
    cin >> H >> W >> N;
    REP(i, N)
    {
        cin >> A[i];
    }
    vector<vector<int>> v(H);
    int index = 0;
    REP(i, H)
    {
        vector<int> t(W);
        REP(j, W)
        {
            if (A[index] == 0)
                index++;
            t[j] = index + 1;
            A[index]--;
        }
        if (i % 2 == 1)
            std::reverse(t.begin(), t.end());
        v[i] = t;
    }

    REP(i, H)
    {
        REP(j, W)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}