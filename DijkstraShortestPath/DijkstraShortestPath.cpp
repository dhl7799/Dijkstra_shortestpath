/*#include <iostream> 
#include <functional> 
#include <queue> 
#define m 100
#define INF 100001
using namespace std;

class Vertex {
	
	int u;
	int v;
	int w;
public:
	Vertex(int u1, int v1, int w1)
		:u(u1), v(v1), w(w1)
	{}

	bool operator > (const Vertex& v1) const
	{
		return w > v1.w;
	}

	int getu() const
	{
		return u;
	}

	int getv() const
	{
		return v;
	}

	int getw() const
	{
		return w;
	}
};

int main()
{
	int V = 0;
	int E = 0;
	int start = 0;
	printf("정점의 갯수를 입력하세요:");
	scanf("%d", &V);
	printf("\n");
	printf("간선의 갯수를 입력하세요:");
	scanf("%d", &E);
	printf("\n");
	printf("시작점을 입력하세요:");
	scanf("%d", &start);
	printf("\n");

	int* dist = new int[V];
	for (int i = 0; i < V; i++)
		dist[i] = INF;
	int **Matrix = new int*[m];
	for (int i = 0; i < m; i++)
		Matrix[i] = new int[m];

	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			Matrix[i][j] = INF;
	priority_queue < Vertex, vector<Vertex>, greater<Vertex>> vt;
	vt.push(Vertex(start, start, 0));
	Matrix[start - 1][start - 1] = 0;
	for (int i = 0; i < E; i++)
	{
		cout << "간선 " << i+1 << " 을/를 입력하세요" << endl;
		int u1 = 0;
		int v1 = 0;
		int w1 = 0;
		cin >> u1 >> v1 >> w1;
		if (u1 > V || v1 > V)
		{
			printf("Vertex는 %d번 까지 입니다\n",V);
			return 0;
		}
		vt.push(Vertex(u1, v1, w1));
		if (Matrix[u1-1][v1-1] > w1)
			Matrix[u1-1][v1-1] = w1;
		cout << endl;
	}



	while (!vt.empty()) {
		Vertex t = vt.top();
		vt.pop();
		printf("%d %d %d\n", t.getu(), t.getv(), t.getw());
	}
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++)
			printf("%d\t", Matrix[i][j]);
		printf("\n");
	}
	delete []Matrix;
	return 0;
}*/