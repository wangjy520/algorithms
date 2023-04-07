#include<bits/stdc++.h>
using namespace std;
constexpr int inf = 0x3f3f3f3f;

struct DSU {
    vector<int> p, r;
    DSU(int n) : p(n, 0), r(0) {iota(p.begin(), p.end(), 0);}
    int find(int x) {return x == p[x] ? x : (p[x] = find(p[x]));}
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if(r[x] < r[y])
            p[x] = y;
        else 
            p[y] = x;
        if(x != y && r[x] == r[y])
            r[x]++;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

int shorest_circle(vector<vector<pair<int, int>>>& edges) {
    int n = edges.size();
    vector<pair<int, int>> g;
    vector<vector<int>> dis(n, vector<int>(n, -1));
    for(int i = 0;i < n;i++) {
        for(auto& e : edges[i]) {
            g.push_back({i, e.first});
            dis[i][e.first] = e.second;
        }
    }
    int ans = inf;
    for(auto& p : g) {
        int s = p.first, t = p.second;
        vector<int> d(n, -1), v(n, 0);
        d[s] = 0;
        auto cmp = [&](int i, int j) -> bool {
            return d[i] > d[j];
        };
        priority_queue<int, vector<int>, decltype(cmp)> h(cmp);
        h.push(s);
        while(!h.empty()) {
            int i = h.top();
            h.pop();
            if(i == t)
                break;
            if(v[i])
                continue;
            v[i] = 1;
            for(auto& e : edges[i]) {
                int child = e.first, w = e.second;
                if(i == s && child == t)
                    continue;
                if(d[child] == -1 || d[child] > d[i] + w) {
                    d[child] = d[i] + w;
                    h.push(child);
                }
            }
        }
        if(d[t] != -1) {
            ans = min(ans, d[t] + dis[s][t]);
        }
    }
    return ans == inf ? 0 : ans;
}

int dijkstra(vector<vector<pair<int, int>>>& edges, int s, int t) {
    int n = edges.size();
    vector<int> d(n, inf), v(n, 0);
    d[s] = 0;
    v[s] = 1;
    auto cmp = [&](int i, int j) -> bool {
        return d[i] > d[j];
    };
    priority_queue<int, vector<int>, decltype(cmp)> h(cmp);
    h.push(s);
    while(!h.empty()) {
        int i = h.top();
        h.pop();
        if(i == t) {
            break;
        }
        for(auto& p : edges[i]) {
            int child = p.first, w = p.second;
            if(d[child] > d[i] + w) {
                h.push(child);
                d[child] = d[i] + w;
            }
        }
    }
    return d[t];
}


int spfa(vector<vector<pair<int, int>>>& edges, int s, int t) {
    int n = edges.size();
    vector<int> d(n, inf);
    queue<int> q;
    q.push(s);
    d[s] = 0;
    unordered_set<int> ss;
    ss.insert(s);
    while(!q.empty()) {
        int i = q.front();
        q.pop();
        ss.erase(i);
        for(auto& p : edges[i]) {
            int child = p.first, w = p.second;
            if(d[child] > d[i] + w) {
                d[child] = d[i] + w;
                if(ss.count(child) == 0) {
                    ss.insert(child);
                    q.push(child);
                }
            }
        }
    }
    return d[t];
}

bool is_bipartite_bfs(vector<vector<int>>& edges) {
    int n = edges.size();
    vector<int> v(n, 0);
    queue<int> q;
    v[0] = 1;
    q.push(0);
    while(!q.empty()) {
        int i = q.front();
        q.pop();
        for(auto& child : edges[i]) {
            if(v[child] == v[i])
                return false;
            if(v[child] == 0) {
                v[child] = -v[i];
                q.push(child);
            }
        }
    }
    return true;
}

bool is_bipartite_dsu(vector<vector<int>>& edges) {
    int n = edges.size();
    DSU dsu(n);
    for(int i = 0;i < n;i++) {
        for(auto& j : edges[i]) {
            if(dsu.same(i, j))
                return false;
            dsu.merge(edges[i][0], j);
        }
    }
    return true;
}