// TC: O(V^2 E^(1/2))
// SC: O(V^2)
// E is the number of edges and V is the number of vertices in the graph
// Mahesh Reddy B N

#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int from, to, cap, flow, index;
	edge(int from, int to, int cap, int flow, int index):
		from(from), to(to), cap(cap), flow(flow), index(index) {}
};
struct PushRelabel
{
	int n;
	vector<vector<edge>> g;
	vector<long long> excess;
	vector<int> height, active, count;
	queue<int> Q;
	PushRelabel(int n):
		n(n), g(n), excess(n), height(n), active(n), count(2*n) {}
	void addEdge(int from, int to, int cap)
	{
		g[from].push_back(edge(from, to, cap, 0, g[to].size()));
		if(from==to)
			g[from].back().index++;
		g[to].push_back(edge(to, from, 0, 0, g[from].size()-1));
	}
	void enqueue(int v)
	{
		if(!active[v] && excess[v] > 0)
		{
			active[v]=true;
			Q.push(v);
		}
	}
	void push(edge &e)
	{
		int amt=(int)min(excess[e.from], (long long)e.cap - e.flow);
		if(height[e.from]<=height[e.to] || amt==0)
			return;
		e.flow += amt;
		g[e.to][e.index].flow -= amt;
		excess[e.to] += amt;
		excess[e.from] -= amt;
		enqueue(e.to);
	}
	void relabel(int v)
	{
		count[height[v]]--;
		int d=2*n;
		for(auto &it:g[v])
		{
			if(it.cap-it.flow>0)
				d=min(d, height[it.to]+1);
		}
		height[v]=d;
		count[height[v]]++;
		enqueue(v);
	}
	void gap(int k)
	{
		for(int v=0;v<n;v++)
		{
			if(height[v]<k)
				continue;
			count[height[v]]--;
			height[v]=max(height[v], n+1);
			count[height[v]]++;
			enqueue(v);
		}
	}
	void discharge(int v)
	{
		for(int i=0; excess[v]>0 && i<g[v].size(); i++)
			push(g[v][i]);
		if(excess[v]>0)
		{
			if(count[height[v]]==1)
				gap(height[v]);
			else
				relabel(v);
		}
	}
	long long max_flow(int source, int dest)
	{
		count[0] = n-1;
		count[n] = 1;
		height[source] = n;
		active[source] = active[dest] = 1;
		for(auto &it:g[source])
		{
			excess[source]+=it.cap;
			push(it);
		}
		while(!Q.empty())
		{
			int v=Q.front();
			Q.pop();
			active[v]=false;
			discharge(v);
		}
		long long max_flow=0;
		for(auto &e:g[source])
			max_flow+=e.flow;

		return max_flow;
	}
};
int main() {
    int n = 6; 
    PushRelabel pr(n);
    pr.addEdge(0, 1, 16);
    pr.addEdge(0, 2, 13);
    pr.addEdge(1, 2, 10);
    pr.addEdge(1, 3, 12);
    pr.addEdge(2, 1, 4);
    pr.addEdge(2, 4, 14);
    pr.addEdge(3, 2, 9);
    pr.addEdge(3, 5, 20);
    pr.addEdge(4, 3, 7);
    pr.addEdge(4, 5, 4);
    long long max_flow = pr.max_flow(0, 5);
    cout<<"Mahesh Reddy B N\nOutput : \n";
    cout<<"Maximum flow: "<<max_flow<<endl;
    return 0;
}


