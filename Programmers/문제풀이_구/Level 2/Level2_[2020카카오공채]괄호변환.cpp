#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

void StringSplit(string p, string& u, string& v)
{
	int open = 0, close = 0;

	for (int i = 0; i < p.length(); i++)
	{
		if (p[i] == '(')
			open++;
		else
			close++;
		u += p[i];

		if (open == close)
		{
			v += p.substr(i + 1, p.length() - i);
			break;
		}
	}
}

bool StringCheck(string s)
{
	stack<char> st;
	for (int i = 0; i < s.length(); i++)
	{
		char c = s[i];
		if (c == '(')
			st.push(c);
		else
		{
			if (!st.empty())
				st.pop();
			else
				return false;
		}
	}

	return st.empty();
}

string Reverse(string s)
{
	string temp = "";

	for (int i = 1; i < s.length() - 1; i++)
		if (s[i] == '(')
			temp += ')';
		else
			temp += '(';

	return temp;
}

string solution(string p) {
	string answer = "";
	string u = "", v = "";

	if (StringCheck(p))
		return p;

	StringSplit(p, u, v);

	// 올바른 문자이면
	if (StringCheck(u))
		answer += (u + solution(v));
	else        //올바르지 않을경우
		answer += ('(' + solution(v) + ')' + Reverse(u));

	return answer;
}