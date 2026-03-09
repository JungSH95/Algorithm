// 백준 너의 평점은 (https://www.acmicpc.net/problem/25206)

#include<iostream>
#include<queue>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int main() {

	string subject, grade = "";
	double total_gpa = 0;
	double gpa;
	double average_gpa = 0.0;

	// 전공평점 = 전공과목별(학점 * 과목평점)의 합 / 학점의총합
	for (int i = 0; i < 20; i++) {
		cin >> subject >> gpa >> grade;

		if (grade == "P")
			continue;

		total_gpa += gpa;

		if (grade == "A+")
			gpa *= 4.5;
		else if (grade == "A0")
			gpa *= 4.0;
		else if (grade == "B+")
			gpa *= 3.5;
		else if (grade == "B0")
			gpa *= 3.0;
		else if (grade == "C+")
			gpa *= 2.5;
		else if (grade == "C0")
			gpa *= 2.0;
		else if (grade == "D+")
			gpa *= 1.5;
		else if (grade == "D0")
			gpa *= 1.0;
		else 			
			gpa *= 0.0;

		average_gpa += gpa;
	}
	
	cout.precision(7);
	cout << (double)(average_gpa / total_gpa);

	return 0;
}

// 1차 시도 : 성공