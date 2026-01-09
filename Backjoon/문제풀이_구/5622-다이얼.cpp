#include <iostream>
#include <string>
using namespace std;

int main()
{
	string number;
	cin >> number;

	int time = 0;
	for (int i = 0; i < (int)number.length(); i++)
	{
		switch (number[i])
		{
		case 'A': case 'B': case 'C':
			time += 3;
			break;
		case 'D': case 'E': case 'F':
			time += 4;
			break;
		case 'G': case 'H': case 'I':
			time += 5;
			break;
		case 'J': case 'K': case 'L':
			time += 6;
			break;
		case 'M': case 'N': case 'O':
			time += 7;
			break;
		case 'P': case 'Q': case 'R': case 'S':
			time += 8;
			break;
		case 'T': case 'U': case 'V':
			time += 9;
			break;
		case 'W': case 'X': case 'Y': case 'Z':
			time += 10;
			break;
		}
	}
	cout << time;
	return 0;
}


/*
각 해당하는 문자의 숫자를 switch로 설정하여 풀었다.
abc : 3
def : 4
ghi : 5
jkl : 6
mno : 7
pqrs : 8
tuv : 9
wxyz : 10


-다른 사람의 경우 배열을 사용하여 문제를 해결
int times[] = { 3, 3, ---------, 10, 10 };
for(int i = 0; number[i] != '\0'; i++)
time += times[number[i] - 'A'];

배열을 각 숫자로 접근 'A' - 'A' : 0 이므로 ~ 'Z' - 'A' : 26

*/
