#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	vector<int> arr;

	arr.push_back(0);
	arr.push_back(1);

	for (int i = 1; i <= n; i++)
		arr.push_back((arr[i - 1] + arr[i]) % 1234567);

	return arr[n];
}