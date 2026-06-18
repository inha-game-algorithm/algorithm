#include <string>
#include <vector>
#include <regex>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    // 탈락발음
    regex checkRepeat("ayaaya|yeye|woowoo|mama");
    regex speak("aya|ye|woo|ma");
    
    for (string word : babbling) {
        //탈락발음 검사
        if (regex_search(word, checkRepeat)) {
            continue;
        }
        
        //공백으로 넣고
        word = regex_replace(word, speak, " ");
        
        bool isEmpty = true;
        for (char c : word) {
            if (c != ' ') {
                isEmpty = false;
                break;
            }
        }
        
        // 공백 검사해서 ++
        if (isEmpty) {
            answer++;
        }
    }
    
    return answer;
}