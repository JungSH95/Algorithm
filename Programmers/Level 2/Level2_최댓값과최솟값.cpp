#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

string solution(string s) {
	string answer = "";
	vector<int> arr;

	string buf;
	stringstream ss(s);

	int imax;
	int imin;

	while (ss >> buf)
		arr.push_back(stoi(buf));

	imax = arr[0];
	imin = arr[0];

	for (int i = 1; i < arr.size(); i++)
	{
		imax = max(imax, arr[i]);
		imin = min(imin, arr[i]);
	}

	answer = to_string(imin) + ' ' + to_string(imax);

	return answer;
}