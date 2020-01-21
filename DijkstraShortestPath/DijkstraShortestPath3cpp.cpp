#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include<functional>
using namespace std;
//https://www.acmicpc.net/problem/1753
#define INF 100001


class Node
{
private:
	int next;
	int weight;
public:
	Node(int n, int w)
		:next(n),weight(w)
	{

	}
	Node()
		:next(0),weight(INF)
	{

	}

	bool operator() (Node& n1) const
	{
		return weight > n1.weight;
	}

	int getnext() const {
		return next;
	}

	int getweight() const {
		return weight;
	}

	void setnext(int n) {
		next = n;
	}

	void setweight(int w) {
		weight = w;
	}
};

struct cmp {
	bool operator()(Node n1, Node n2) {
		return n1.getweight() > n2.getweight();
	}
};


int main()
{

	vector<Node> Map[20001];
	priority_queue<Node, vector<Node>,cmp> vt;


	int vertex=0, edge=0;
	int start=0;
	int u=0, v=0, w=0;
	

	scanf("%d", &vertex);
	scanf("%d", &edge);
	scanf("%d", &start);

	vertex++;


	vector<int> dijkstra(vertex, INF);
	for (int i = 0; i < edge; i++)
	{
		scanf("%d", &u);
		scanf("%d", &v);
		scanf("%d", &w);
		Map[u].push_back(Node(v,w));
	}

	int location=0;
	int _weight=0;
	int nextLocation=0;
	int nextWeight=0;

	dijkstra[start] = 0;

	vt.push(Node(start, 0));
	
	while (!vt.empty())
	{
		location = vt.top().getnext();
		_weight = vt.top().getweight();

		vt.pop();

		if (dijkstra[location] < _weight)
			continue;

		for (int i = 0; i < Map[location].size(); i++) {
			nextLocation = Map[location][i].getnext();
			nextWeight = _weight + Map[location][i].getweight();

			if (dijkstra[nextLocation] > nextWeight) {
				dijkstra[nextLocation] = nextWeight;
				vt.push(Node(nextLocation, nextWeight));
			}

		}
		
	}
	for (int i = 1; i < vertex; ++i) {
		dijkstra[i] == INF ? printf("INF\n") : printf("%d\n", dijkstra[i]);
	}
	
	return 0;
}