#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>


std::unordered_set<std::string> get_neighbors(
    std::string& current, 
    std::unordered_set<std::string>& dictionary,
    std::vector<char>& alphabet
) {
    std::unordered_set<std::string> neighbors;

    for (int i = 0; i < current.size(); i++) {
        for (const char& letter : alphabet) {
            if (letter != current[i]) {
                std::string neighbor = current.substr(0, i) + letter + current.substr(i + 1, current.size());
                if (dictionary.count(neighbor)) {
                    neighbors.insert(neighbor);
                }
            }
        }
    }
    return neighbors;
}


int bfs(
    std::string& begin, 
    std::string& end, 
    std::unordered_set<std::string>& dictionary, 
    std::vector<char>& alphabet
) {
    std::queue<std::string> q;
    std::unordered_set<std::string> visited {begin};
    int num_steps {0};

    q.push(begin);
    while (!q.empty()) {
        int level_size = q.size();
        std::string& current = q.front();
        if (current == end) return num_steps;

        for (int i = 0; i < level_size; i++) {
            for (const std::string& n : get_neighbors(current, dictionary, alphabet)) {
                if (visited.count(n)) continue; 
                visited.insert(n);
                q.push(n);
            }
            q.pop();
        }
        num_steps++;
    }

    return -1;
}


int word_ladder(std::string& begin, std::string& end, std::vector<std::string>& word_list) {
    std::unordered_set<std::string> dictionary(word_list.begin(), word_list.end());
    std::vector<char> alphabet;
    for (int i = 0; i < 26; i++) {
        alphabet.emplace_back((char)(i + 'a'));
    }
    return bfs(begin, end, dictionary, alphabet);
}


int main() {
    std::string begin = "fool";
    std::string end = "sage";
    std::vector<std::string> word_list {"fool", "pool", "poll", "pole", "pale", "sale", "sage"};
    int result = word_ladder(begin, end, word_list);
    std::cout << "Result: " << result << std::endl;

    begin = "cold";
    end = "warm";
    word_list = {"cold", "gold", "cord", "card", "ward", "warm", "tard", "sold"};
    result = word_ladder(begin, end, word_list);
    std::cout << "Result: " << result << std::endl;
}

