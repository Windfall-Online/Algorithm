#include <iostream>
#include <vector>
using namespace std;



void CreateGraph_1()
{
	// 연결 리스트에서는 이랬음
	/*struct Node
	{
		Node* _prev;
		Node* _Next;
		int _data;
	};*/

	// 꼭 양옆으로 연결되어있는게 아님 
	// 하나의 정점에 여러개의 간선이 연결되어 있을 수 있음
	struct Vertex
	{
		vector<Vertex*> edges;
		// int data;
	};

	vector<Vertex> v;
	v.resize(6);

	v[0].edges.push_back(&v[1]);
	v[0].edges.push_back(&v[3]);
	v[1].edges.push_back(&v[0]);
	v[1].edges.push_back(&v[2]);
	v[1].edges.push_back(&v[3]);
	v[3].edges.push_back(&v[4]);
	v[5].edges.push_back(&v[4]);

	// Q) 0번 -> 3번 정점이 연결되어 있나요?
	bool connected = false;
	for (Vertex* edge : v[0].edges)
	{
		if (edge == &v[3])
		{
			connected = true;
			break;
		}
	}


}

void CreateGraph_2()
{
	struct Vertex
	{
		int _data;
	};

	vector<Vertex> v;
	v.resize(6);

	// 연결된 정점의 목록을 따로 관리
	// adjacent[n] n번째 정점과 연결된 정점 목록
	// ex) adjacent[0]의 값은 0번 정점과 연결된 정점 목록
	// 0번에서 1, 3번으로 가는것 
	// 4번같은경우는 간선이 오기만하지 나가는게없음
	vector<vector<int>> adjacent(6);
	adjacent[0] = { 1, 3 };
	adjacent[1] = { 0, 2, 3 };
	adjacent[3] = { 4 };
	adjacent[5] = { 4 };

	bool connected = false;
	for (int vertex : adjacent[0])
	{
		if (vertex == 3)
		{
			connected = true;
			break;
		}
	}

	//STL
	vector<int>& adj = adjacent[0];
	// adj.begin()부터 adj.end()까지 탐색하며 3을 찾는데 그 위치가 adj.end()가아니면 중간에
	// 뭐가 있다는 소리니까 찾은거
	bool connected2 = (find(adj.begin(), adj.end(), 3) != adj.end());


}

// 만약에 정점이 100개, 1000개가 있다면?
// 지하철 노선도 -> 서로 드문 드문 연결
// 어마어마하게 연결은 안돼있음
// 정점 갯수와 간선 갯수는 별개 문제임
// 양옆, 혹은 환승역이라면 좀더 많음
// CreateGraph_2()의 방법이 나쁜게 아님

// 페이스북 친구 -> 서로
// 각자 너무 친해서 100명이 서로 친하면
// 서로 빽빽하게 연결이 되어있음
// CreateGraph_2()와 같은방법으로하면 너무 노가다임
// 전부 다 연결시켜줘야함 
// 누가 누구랑 연결되어있나요? 라는 검색을 하게되면
// 일일히 다 찾아봐야함 100개면 100개를 다 검색해서 찾아야한다
// 너무 아쉬운 상황 성능적으로


void CreateGraph_3()
{
	struct Vertex
	{
		int _data;
	};

	vector<Vertex> v;
	v.resize(6);

	// 연결된 목록을 따로 관리
	// 연결 안되면 [X]
	// 6개기준 6 by 6의 이중배열을 관리
	// [X][X][X][X][X][X]
	// [X][X][X][X][X][X]
	// [X][X][X][X][X][X]
	// [X][X][X][X][X][X]
	// [X][X][X][X][X][X]
	// [X][X][X][X][X][X]

	// 여기서 연결된 곳을 O로 바꿔준다
	// [X][O][X][X][X][X]
	// [O][X][O][O][X][X]
	// [X][X][X][X][X][X]
	// [X][X][X][X][O][X]
	// [X][X][X][X][X][X]
	// [X][X][X][X][O][X]

	vector<vector<bool>> adjacent(6, vector<bool>(6, false));
	adjacent[0][1] = true;
	adjacent[0][3] = true;
	adjacent[1][0] = true;
	adjacent[1][2] = true;
	adjacent[1][3] = true;
	adjacent[3][4] = true;
	adjacent[5][4] = true;

	// adjacent의 [from][to]를 확인해서 연결여부 검사
	// 2차원 배열을 이용한 그래프 표현
	// 메모리 소모가 심하지만 빠른 접근 가능

	// 빽빽하지 않다면?? CreateGraph_2()의 방법을
	// 빽뺵하면 CreateGraph_3()의 방법을 추천
	// 메모리를 약간 포기하고 성능을 챙김

	// 0번이 3번이랑 연결되어있나요?
	bool connected = adjacent[0][3];

	// 가중치가있는 그래프는?
	// CreateGraph_2()의 방법에서는
	// 각 원소를 pair<int, int>()로 묶어서

	vector<vector<int>> adjacent2 =
	{
		// 음수 거리라는건 존재하지않으니까 -1을 연결되지 않았다 라는 표현으로 사용
		vector<int> {-1, 15, -1, 35, -1, -1},
		vector<int> {15, -1, +5, 10, -1, -1},
		vector<int> {-1, -1, -1, -1, -1, -1},
		vector<int> {-1, -1, -1, -1, +5, -1},
		vector<int> {-1, -1, -1, -1, -1, -1},
		vector<int> {-1, -1, -1, -1, +5, -1},
	};

	// [0][3]이 -1보다 크거나 -1아니면 연결되어있음
	// 가중치는? 그냥 이 숫자 그대로 갖다씀
	adjacent2[0][3]; 
}

int main()
{
	CreateGraph_1();
	CreateGraph_2();
}

