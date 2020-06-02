#include <iostream>
#include <cstring>
#include <string>
using namespace std;

// N : 단어의 개수
int N, group_count = 0;
int alphabet_count[26];

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		memset(alphabet_count, 0, sizeof(alphabet_count));
		string s;
		cin >> s;

		char now_c = s[0];
		alphabet_count[(int)(now_c - 'a')] += 1;
		bool check = true;

		for (int j = 1; j < s.length(); j++)
		{
			// 이전 문자와 같다
			if (now_c == s[j])
				continue;
			else
			{
				// 문자가 다르면 해당 문자가 이미 사용한 적이 있는지 체크
				if (alphabet_count[(int)(s[j] - 'a')] != 0)
				{
					// 사용했다는 것이므로 그룹 단어가 아님.
					check = false;
					break;
				}
				else
				{
					// 사용한 적이 없음, 현재 사용중인 문자로 설정, 사용했다는 표시
					now_c = s[j];
					alphabet_count[(int)(now_c - 'a')] += 1;
				}
			}
		}

		if (check)
			group_count++;
	}

	cout << group_count;

	return 0;
}

/*
맨 처음에 벡터를 사용해서 사용한 문자에 대해서 있는지 찾아서 체크를 할까 했는데
3중 반복문이 되기때문에 다른 방법으로 배열을 사용해서 풀었다.

알파벳은 총 26개이므로 26 크기의 배열을 만들어주고, 'a' 문자를 빼서 해당 문자를
배열로서 접근하여 카운트를 시켜서 사용 유무를 체크해주었다.
*/
