#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

struct Vertex
{
    vector<int> node;
};

pair<ll, bool> A[100005];
Vertex V[100005];
bool U[100005];

int main()
{
    ll N, M;
    cin >> N >> M;
    REP(i, N)
    {
        cin >> A[i].first;
        A[i].second = false;
        U[i] = false;
    }
    REP(i, M)
    {
        ll x, y;
        cin >> x >> y;
        V[x].node.push_back(y);
        V[y].node.push_back(x);
    }

    ll sum = 0;
    int fn = 0;
    REP(i, N)
    {
        if (U[i])
            continue;
        fn++;
        U[i] = true;
        ll min = i;
        queue<int> q;
        q.push(i);
        while (!q.empty())
        {
            int t = q.front();
            q.pop();
            REP(j, V[t].node.size())
            {
                int n = V[t].node[j];
                if (U[n])
                    continue;
                U[n] = true;
                q.push(n);
                if (A[n] < A[min])
                    min = n;
            }
        }
        A[min].second = true;
        sum += A[min].first;
    }
    if (fn == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    if (2 * (fn - 1) > N)
    {
        cout << "Impossible" << endl;
        return 0;
    }
    sort(A, A + N, [](pair<ll, bool> a, pair<ll, bool> b) { return a.first < b.first; });
    fn = 2 * (fn - 1) - fn;
    REP(i, N)
    {
        if (A[i].second)
            continue;
        if (fn-- <= 0)
            break;
        sum += A[i].first;
    }
    cout << sum << endl;
    return 0;
}