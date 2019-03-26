#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef pair<int, double> pid;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

struct Human
{
    pdd g;
    double t;
    double r;
};
double C[1005];
Human H[1005];

double dist(pdd a, pdd b)
{
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

int main()
{
    int N;
    cin >> N;
    REP(i, N)
    {
        cin >> H[i].g.first >> H[i].g.second >> H[i].t >> H[i].r;
        C[i] = INF;
    }
    C[0] = 0;
    priority_queue<pid, vector<pid>, function<bool(pid, pid)>> q([](pid a, pid b) { return a.second > b.second; });
    q.push(pid(0, 0));
    while (!q.empty())
    {
        pid t = q.top();
        q.pop();
        if (C[t.first] < t.second)
            continue;
        REP(i, N)
        {
            double cost = t.second + dist(H[i].g, H[t.first].g) / std::min(H[i].r, H[t.first].t);
            if (C[i] <= cost)
                continue;
            C[i] = cost;
            q.push(pid(i, cost));
        }
    }

    sort(C, C + N, [](double a, double b) { return a > b; });
    double max = 0;
    REP(i, N - 1)
    {
        max = std::max(max, C[i] + i);
    }
    cout << OF64 << max << endl;
    return 0;
}