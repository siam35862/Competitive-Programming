#include <bits/stdc++.h>
using namespace std;

#define N 300005

vector<vector<int>> graph(N), revGraph(N);
vector<pair<int,int>> edges(N);
vector<int> cost(N);

vector<int> visited(N), order;
vector<int> roots(N);

vector<vector<pair<int,int>>> condensationGraph(N);
vector<vector<pair<int,int>>> rev_graph(N);

vector<int> visited2(N), visited3(N);
vector<int> toposort, rev_toposort;

int cn = 0;

// -------- First Pass (Finish Order) --------
void first_pass(int n)
{
    for(int i=1;i<=n;i++)
    {
        if(visited[i]) continue;

        stack<pair<int,int>> st;
        st.push({i,0});

        while(!st.empty())
        {
            auto &[u,idx] = st.top();

            if(!visited[u])
                visited[u] = 1;

            if(idx < (int)graph[u].size())
            {
                int v = graph[u][idx++];
                if(!visited[v])
                    st.push({v,0});
            }
            else
            {
                order.push_back(u);
                st.pop();
            }
        }
    }
}

// -------- Second Pass (Assign SCC) --------
void second_pass(int n)
{
    reverse(order.begin(), order.end());

    for(int u : order)
    {
        if(roots[u]) continue;

        cn++;
        stack<int> st;
        st.push(u);
        roots[u] = cn;

        while(!st.empty())
        {
            int node = st.top();
            st.pop();

            for(int v : revGraph[node])
            {
                if(!roots[v])
                {
                    roots[v] = cn;
                    st.push(v);
                }
            }
        }
    }
}

// -------- Toposort --------
void topo_iterative(int n)
{
    for(int i=1;i<=n;i++)
    {
        if(visited2[i]) continue;

        stack<pair<int,int>> st;
        st.push({i,0});

        while(!st.empty())
        {
            auto &[u,idx] = st.top();

            if(!visited2[u])
                visited2[u] = 1;

            if(idx < (int)condensationGraph[u].size())
            {
                int v = condensationGraph[u][idx++].first;
                if(!visited2[v])
                    st.push({v,0});
            }
            else
            {
                toposort.push_back(u);
                st.pop();
            }
        }
    }
}

// -------- Reverse Toposort --------
void topo_rev_iterative(int n)
{
    for(int i=1;i<=n;i++)
    {
        if(visited3[i]) continue;

        stack<pair<int,int>> st;
        st.push({i,0});

        while(!st.empty())
        {
            auto &[u,idx] = st.top();

            if(!visited3[u])
                visited3[u] = 1;

            if(idx < (int)rev_graph[u].size())
            {
                int v = rev_graph[u][idx++].first;
                if(!visited3[v])
                    st.push({v,0});
            }
            else
            {
                rev_toposort.push_back(u);
                st.pop();
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    int n,m;
    cin>>n>>m;

    // Reset
    cn = 0;
    order.clear();
    toposort.clear();
    rev_toposort.clear();

    for(int i=1;i<=n;i++)
    {
        graph[i].clear();
        revGraph[i].clear();
        visited[i]=0;
        roots[i]=0;
        visited2[i]=0;
        visited3[i]=0;
    }

    for(int i=0;i<m;i++)
    {
        cin>>edges[i].first>>edges[i].second>>cost[i];
        graph[edges[i].first].push_back(edges[i].second);
        revGraph[edges[i].second].push_back(edges[i].first);
    }

    // ---- Kosaraju ----
    first_pass(n);
    second_pass(n);

    vector<pair<int,int>> score(cn+1,{0,INT_MAX});
    vector<pair<int,int>> score2(cn+1,{0,INT_MAX});

    for(int i=1;i<=cn;i++)
    {
        condensationGraph[i].clear();
        rev_graph[i].clear();
    }

    for(int i=0;i<m;i++)
    {
        int u = roots[edges[i].first];
        int v = roots[edges[i].second];
        int w = cost[i];

        if(u==v)
        {
            score[u].first = max(score[u].first,w);
            score[u].second = min(score[u].second,w);
            score2[u] = score[u];
        }
        else
        {
            condensationGraph[u].push_back({v,w});
            rev_graph[v].push_back({u,w});
        }
    }

    topo_iterative(cn);
    topo_rev_iterative(cn);

    reverse(toposort.begin(),toposort.end());
    reverse(rev_toposort.begin(),rev_toposort.end());

    // Forward DP
    for(auto u: toposort)
        for(auto [v,w]: condensationGraph[u])
        {
            score[v].first = max(score[v].first, max(score[u].first,w));
            score[v].second = min(score[v].second, min(score[u].second,w));
        }

    // Reverse DP
    for(auto u: rev_toposort)
        for(auto [v,w]: rev_graph[u])
        {
            score2[v].first = max(score2[v].first, max(score2[u].first,w));
            score2[v].second = min(score2[v].second, min(score2[u].second,w));
        }

    int ans=0;
    for(int i=1;i<=cn;i++)
        if(score[i].second!=INT_MAX && score2[i].second!=INT_MAX)
        {
            ans=max(ans,score[i].first-score2[i].second);
            ans=max(ans,score2[i].first-score[i].second);
        }

    cout<<max(ans,0)<<"\n";
}