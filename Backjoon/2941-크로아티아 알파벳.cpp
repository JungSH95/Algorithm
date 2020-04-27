#include<iostream>
#include<string>
using namespace std;

int main()
{
	int count = 0;
	string words = "";
	cin >> words;

	for (int i = 0; i < words.length(); i++)
	{
		char c = words[i];

		if (c == 'c' || c == 's' || c == 'z')
		{
			if (words[i + 1] == '=' || words[i + 1] == '-')
				i++;
		}
		else if (c == 'd')
		{
			if (words[i + 1] == 'z' && words[i + 2] == '=')
				i += 2;
			else if (words[i + 1] == '-')
				i++;
		}
		else if (c == 'l' || c == 'n')
		{
			if (words[i + 1] == 'j')
				i++;
		}

		count += 1;
	}

	cout << count;
	return 0;
}

/*
if 문을 사용하는 간단한 문제
*/