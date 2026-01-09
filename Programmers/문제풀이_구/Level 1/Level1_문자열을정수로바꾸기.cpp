#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

int solution(string s) {
	int answer = 0;
	return answer = atoi(s.c_str());
}

#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(string s) {
	int answer = 0;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '+' || s[i] == '-')
			continue;
		answer += (s[i] - '0') * pow(10, s.length() - i - 1);
	}

	if (s[0] == '-')
		answer = -answer;

	return answer;
}