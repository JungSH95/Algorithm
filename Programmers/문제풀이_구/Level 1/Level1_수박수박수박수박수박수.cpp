#include <string>
#include <vector>

using namespace std;

string solution(int n) {
	string answer = "";

	int a = n / 2;
	int b = n % 2;

	for (int i = 0; i < a; i++)
		answer += "¼ö¹Ú";
	if (b == 1)
		answer += "¼ö";

	return answer;
}