#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

const int UNIQUE_WORD_REWARD = 3;
const int DOUBLE_WORD_REWARD = 1;

int main() {
    int t;
    cin >> t;

    for (int testcase=0; testcase<t; testcase++) {
        int n;
        cin >> n;
        set<string> words[3];
        for (int player=0; player<3; player++) {
            for (int i=0; i<n; i++) {
                string word;
                cin >> word;
                words[player].insert(word);
            }
        }
        
        for (int player=0; player<3; player++) {
            int score = 0;

            // Ugh, this is how you iterate through sets? C++ is weird ngl
            for (set<string>::iterator iterator=words[player].begin(); iterator != words[player].end(); iterator++) {
                int a = (player+1)%3;
                int b = (player+2)%3;
                // The equivalent Python code was like four times as short and much more readable just saying
                if (words[a].find(*iterator) != words[a].end() && words[b].find(*iterator) != words[b].end()) {
                    continue;
                }
                score += (words[a].find(*iterator) != words[a].end() || words[b].find(*iterator) != words[b].end())? DOUBLE_WORD_REWARD : UNIQUE_WORD_REWARD;
            }
            cout << score << " ";
        }
        cout << endl;
    }
}