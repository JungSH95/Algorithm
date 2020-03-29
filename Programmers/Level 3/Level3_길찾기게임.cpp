#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
	int x, y;
	int num;
	Node* left;
	Node* right;
};

void preorder(Node* n, vector<int>& visit)
{
	if (n == nullptr)
		return;

	visit.push_back(n->num);
	preorder(n->left, visit);
	preorder(n->right, visit);
}

void postorder(Node* n, vector<int>& visit)
{
	if (n == nullptr)
		return;

	postorder(n->left, visit);
	postorder(n->right, visit);
	visit.push_back(n->num);

}

bool compare(vector<int> node1, vector<int> node2)
{
	// 깊이가 같다면 x값 오름차순
	if (node1.at(1) == node2.at(1))
		return node1.at(0) < node2.at(0);
	// 깊이는 내림 차순 (가장 큰 것이 루트)
	else
		return node1.at(1) > node2.at(1);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	vector<vector<int>> answer;

	// 각 노드 번호 추가
	for (int i = 0; i < nodeinfo.size(); i++)
		nodeinfo[i].push_back(i + 1);
	// y는 내림차순, x는 오름차순 정렬
	sort(nodeinfo.begin(), nodeinfo.end(), compare);

	// 트리 생성
	Node* root = new Node{ nodeinfo[0].at(0), nodeinfo[0].at(1),
		nodeinfo[0].at(2), nullptr, nullptr };

	for (int i = 1; i < nodeinfo.size(); i++)
	{
		Node* node = new Node{ nodeinfo[i].at(0), nodeinfo[i].at(1),
			nodeinfo[i].at(2), nullptr, nullptr };

		Node* temp = root;
		while (temp != nullptr)
		{
			// 자식 노드
			if (temp->y > node->y)
			{
				// 왼쪽
				if (temp->x > node->x)
				{
					if (temp->left != nullptr)
						temp = temp->left;
					else
					{
						temp->left = node;
						break;
					}
				}
				// 오른쪽
				else
				{
					if (temp->right != nullptr)
						temp = temp->right;
					else
					{
						temp->right = node;
						break;
					}
				}
			}
		}
	}

	vector<int> visit;
	preorder(root, visit);
	answer.push_back(visit);
	visit.clear();

	postorder(root, visit);
	answer.push_back(visit);

	return answer;
}

/*
단순한 문제 level3 라고 하기에는 쉬운것 같다.
*/