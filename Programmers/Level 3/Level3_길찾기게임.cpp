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
	// ���̰� ���ٸ� x�� ��������
	if (node1.at(1) == node2.at(1))
		return node1.at(0) < node2.at(0);
	// ���̴� ���� ���� (���� ū ���� ��Ʈ)
	else
		return node1.at(1) > node2.at(1);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	vector<vector<int>> answer;

	// �� ��� ��ȣ �߰�
	for (int i = 0; i < nodeinfo.size(); i++)
		nodeinfo[i].push_back(i + 1);
	// y�� ��������, x�� �������� ����
	sort(nodeinfo.begin(), nodeinfo.end(), compare);

	// Ʈ�� ����
	Node* root = new Node{ nodeinfo[0].at(0), nodeinfo[0].at(1),
		nodeinfo[0].at(2), nullptr, nullptr };

	for (int i = 1; i < nodeinfo.size(); i++)
	{
		Node* node = new Node{ nodeinfo[i].at(0), nodeinfo[i].at(1),
			nodeinfo[i].at(2), nullptr, nullptr };

		Node* temp = root;
		while (temp != nullptr)
		{
			// �ڽ� ���
			if (temp->y > node->y)
			{
				// ����
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
				// ������
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
�ܼ��� ���� level3 ��� �ϱ⿡�� ����� ����.
*/