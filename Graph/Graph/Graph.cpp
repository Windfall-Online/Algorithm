#include <iostream>
#include <vector>
using namespace std;



void CreateGraph_1()
{
	// ���� ����Ʈ������ �̷���
	/*struct Node
	{
		Node* _prev;
		Node* _Next;
		int _data;
	};*/

	// �� �翷���� ����Ǿ��ִ°� �ƴ� 
	// �ϳ��� ������ �������� ������ ����Ǿ� ���� �� ����
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

	// Q) 0�� -> 3�� ������ ����Ǿ� �ֳ���?
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

	// ����� ������ ����� ���� ����
	// adjacent[n] n��° ������ ����� ���� ���
	// ex) adjacent[0]�� ���� 0�� ������ ����� ���� ���
	// 0������ 1, 3������ ���°� 
	// 4���������� ������ ���⸸���� �����°Ծ���
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
	// adj.begin()���� adj.end()���� Ž���ϸ� 3�� ã�µ� �� ��ġ�� adj.end()���ƴϸ� �߰���
	// ���� �ִٴ� �Ҹ��ϱ� ã����
	bool connected2 = (find(adj.begin(), adj.end(), 3) != adj.end());


}

// ���࿡ ������ 100��, 1000���� �ִٸ�?
// ����ö �뼱�� -> ���� �幮 �幮 ����
// ���ϰ� ������ �ȵ�����
// ���� ������ ���� ������ ���� ������
// �翷, Ȥ�� ȯ�¿��̶�� ���� ����
// CreateGraph_2()�� ����� ���۰� �ƴ�

// ���̽��� ģ�� -> ����
// ���� �ʹ� ģ�ؼ� 100���� ���� ģ�ϸ�
// ���� �����ϰ� ������ �Ǿ�����
// CreateGraph_2()�� ������������ϸ� �ʹ� �밡����
// ���� �� ������������ 
// ���� ������ ����Ǿ��ֳ���? ��� �˻��� �ϰԵǸ�
// ������ �� ã�ƺ����� 100���� 100���� �� �˻��ؼ� ã�ƾ��Ѵ�
// �ʹ� �ƽ��� ��Ȳ ����������


void CreateGraph_3()
{
	struct Vertex
	{
		int _data;
	};

	vector<Vertex> v;
	v.resize(6);

	// ����� ����� ���� ����
	// ���� �ȵǸ� [X]
	// 6������ 6 by 6�� ���߹迭�� ����
	// [X][X][X][X][X][X]
	// [X][X][X][X][X][X]
	// [X][X][X][X][X][X]
	// [X][X][X][X][X][X]
	// [X][X][X][X][X][X]
	// [X][X][X][X][X][X]

	// ���⼭ ����� ���� O�� �ٲ��ش�
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

	// adjacent�� [from][to]�� Ȯ���ؼ� ���Ῡ�� �˻�
	// 2���� �迭�� �̿��� �׷��� ǥ��
	// �޸� �Ҹ� �������� ���� ���� ����

	// �������� �ʴٸ�?? CreateGraph_2()�� �����
	// �����ϸ� CreateGraph_3()�� ����� ��õ
	// �޸𸮸� �ణ �����ϰ� ������ ì��

	// 0���� 3���̶� ����Ǿ��ֳ���?
	bool connected = adjacent[0][3];

	// ����ġ���ִ� �׷�����?
	// CreateGraph_2()�� ���������
	// �� ���Ҹ� pair<int, int>()�� ���

	vector<vector<int>> adjacent2 =
	{
		// ���� �Ÿ���°� �������������ϱ� -1�� ������� �ʾҴ� ��� ǥ������ ���
		vector<int> {-1, 15, -1, 35, -1, -1},
		vector<int> {15, -1, +5, 10, -1, -1},
		vector<int> {-1, -1, -1, -1, -1, -1},
		vector<int> {-1, -1, -1, -1, +5, -1},
		vector<int> {-1, -1, -1, -1, -1, -1},
		vector<int> {-1, -1, -1, -1, +5, -1},
	};

	// [0][3]�� -1���� ũ�ų� -1�ƴϸ� ����Ǿ�����
	// ����ġ��? �׳� �� ���� �״�� ���پ�
	adjacent2[0][3]; 
}

int main()
{
	CreateGraph_1();
	CreateGraph_2();
}

