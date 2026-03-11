#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <sstream>
using namespace std;

bool spoilerCheck(string word, int pos, string message, vector<vector<int>> spoiler_ranges) {
    for (auto range : spoiler_ranges) {
        if (range[0] > pos)
            break;

        int left = pos - word.size();
        int right = pos - 1;

        if (left <= range[1] && right >= range[0])
            return true;
    }
    return false;
}

int solution(string message, vector<vector<int>> spoiler_ranges) {
    int answer = 0;

    string word = "";
    int checkSpoilerCur = 0;
    map<string, int> importantWord;

    for (int i = 0; i < message.size(); i++) {
        if (message[i] == ' ') {
            if (spoilerCheck(word, i, message, spoiler_ranges))
                importantWord[word] += 1;
            else
                importantWord[word] -= 1;

            word = "";
            continue;
        }

        word += message[i];
    }

    if (spoilerCheck(word, message.size() + 1, message, spoiler_ranges))
        importantWord[word] += 1;
    else
        importantWord[word] -= 1;

    for (auto word : importantWord) {
        if (word.second >= 1)
            answer += 1;
    }

    return answer;
}


string getRangeSpoilerText(string message, vector<int> range) {
    int leftPos = 0;
    int rightPos = 0;

    for (int i = range[0]; i >= 0; i--) {
        if (message[i] == ' ') {
            leftPos = i + 1;
            break;
        }
    }

    for (int i = range[1]; i < message.size(); i++) {
        if (message[i] == ' ') {
            rightPos = i - 1;
            break;
        }
    }

    return message.substr(leftPos, rightPos - leftPos + 1);
}

int solution_1(string message, vector<vector<int>> spoiler_ranges) {

    vector<string> not_spoiler_texts;
    vector<string> spoiler_texts;
    
    // 전체 단어 추출
    string word = "";
    for (int i = 0; i < message.size(); i++) {
        if (message[i] == ' ') {            
            if (!spoilerCheck(word, i, message, spoiler_ranges))
                not_spoiler_texts.push_back(word);
            else
                spoiler_texts.push_back(word);

            word = "";
            continue;
        }

        word += message[i];
    }

    if (!spoilerCheck(word, message.size(), message, spoiler_ranges))
        not_spoiler_texts.push_back(word);
    else
        spoiler_texts.push_back(word);

    //for (auto text : not_spoiler_texts)
    //    cout << text << endl;

    set<string> s;

    // 스포일러 단어 추출, 2차 시도 방법
    /*
    for (auto range : spoiler_ranges) {
        string spoiler_text = getRangeSpoilerText(message, range);
        vector<string> splitText;

        istringstream ss(spoiler_text);
        string buffer;
        while (getline(ss, buffer, ' '))
            splitText.push_back(buffer);

        for (auto text : splitText) {
            text.erase(remove(text.begin(), text.end(), ' '), text.end());
            if (!text.empty() && find(not_spoiler_texts.begin(), not_spoiler_texts.end(), text) == not_spoiler_texts.end())
                s.insert(text);
        }
    }
    */

    for (auto text : spoiler_texts) {
        if (find(not_spoiler_texts.begin(), not_spoiler_texts.end(), text) == not_spoiler_texts.end()) {
            s.insert(text);
        }
    }

    return s.size();
}

// 1차 시도 : 실패, 너무 많은 테스트 케이스에서 실패해서 방식을 수정해봄

// 2차 시도 : 테스트 케이스 22, 23, 75번 실패

// 3차 시도 : 성공, 너무 꼬아서 