#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

int solution(string s) {
    int answer = 0;

    for (int i = 0; i < s.size(); i++) {
        s += s[0];
        s.erase(0, 1);

        stack<char> st;
        for (auto c : s) {
            if (st.empty())
                st.push(c);
            else {
                if (st.top() == '(' && c == ')')
                    st.pop();
                else if (st.top() == '{' && c == '}')
                    st.pop();
                else if (st.top() == '[' && c == ']')
                    st.pop();
                else
                    st.push(c);
            }
        }

        if (st.empty())
            answer += 1;
    }

    return answer;
}

// 1차 시도 : 성공