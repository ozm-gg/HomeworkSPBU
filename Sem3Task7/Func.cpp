#include "Func.h"
#include <map>
#include <set>
#include <queue>
#include <sstream>
#include <list>

std::vector<int> ProfessorsGame(std::vector<int> &input_vec, int k) {

    const int MOD = 1073741823; // MOD = 2^30 - 1

    std::deque<int> board(input_vec.begin(), input_vec.end());

    for (int i = 0; i < k; ++i) {
        int x = board.front();
        int y = board.back();

        if (x < y) {
            board.pop_front();
            board.push_back((x + y) & MOD);
        } else {
            board.pop_back();
            board.push_front((y - x) & MOD);
        }
    }

    return std::vector<int>(board.begin(), board.end());
}

std::vector<std::pair<std::string, std::vector<std::string>>>
VasyasDictionary(int N, const std::vector<std::string> &dictionary) {

    std::map<std::string, std::set<std::string>> latin_to_english;

    for (int i = 0; i < N; ++i) {
        std::istringstream stream(dictionary[i]);
        std::string english_word;
        std::getline(stream, english_word, ' ');

        std::string latin_translations;
        std::getline(stream, latin_translations);

        std::istringstream latin_stream(latin_translations);
        std::string latin_word;
        while (std::getline(latin_stream, latin_word, ',')) {
            latin_word.erase(0, latin_word.find_first_not_of(" -\t\n"));
            latin_word.erase(latin_word.find_last_not_of(" -\t\n") + 1);
            latin_to_english[latin_word].insert(english_word);
        }
    }

    std::vector<std::pair<std::string, std::vector<std::string>>> result;
    for (const auto &entry: latin_to_english) {
        std::vector<std::string> english_words(entry.second.begin(), entry.second.end());
        result.push_back({entry.first, english_words});
    }

    return result;
}

double calculateTime(std::string input_string) {
    struct Customer {
        std::string item;
        int amount;
        int last_known_quantity; // -1 means not set
        bool is_mark;

        Customer(std::string it = "", int amt = 0, bool mark = false) : item(it), amount(amt), last_known_quantity(-1),
                                                                        is_mark(mark) {}
    };

    int m;
    std::stringstream ss(input_string);
    ss >> m;
    std::map<std::string, int> inventory;
    for (int i = 0; i < m; i++) {
        int amt;
        std::string of_word, name;
        ss >> amt >> of_word >> name;
        inventory[name] = amt;
    }
    int n;
    ss >> n;
    std::list<Customer> queue;
    for (int i = 0; i < n; i++) {
        int amt;
        std::string of_word, name;
        ss >> amt >> of_word >> name;
        queue.emplace_back(name, amt, false);
    }

    queue.emplace_back("", 0, true);
    double time = 0.0;
    while (!queue.empty()) {
        auto it = queue.begin();
        if (it->is_mark) {
            return time;
        }
        Customer current = *it;
        queue.pop_front();
        if (current.last_known_quantity == -1) {
            if (inventory.find(current.item) == inventory.end() || inventory[current.item] == 0) {
                time += 1.0;
            } else {
                if (inventory[current.item] >= current.amount) {
                    inventory[current.item] -= current.amount;
                    time += 1.0;
                } else if (inventory[current.item] > 0 && inventory[current.item] < current.amount) {
                    current.last_known_quantity = inventory[current.item];
                    time += 1.0;
                    auto it2 = queue.begin();
                    it2++;
                    queue.insert(it2, current);
                }
            }
        } else {
            if (inventory.find(current.item) == inventory.end() || inventory[current.item] == 0) {
                time += 1.0;
            } else {
                int current_quantity = inventory[current.item];

                if (current_quantity == current.last_known_quantity) {
                    inventory[current.item] = 0;
                    time += 1.0;

                } else if (current_quantity > 0 && current_quantity < current.last_known_quantity) {

                    current.last_known_quantity = current_quantity;
                    time += 1.0;
                    auto it2 = queue.begin();
                    it2++;
                    queue.insert(it2, current);

                } else {
                    inventory[current.item] = 0;
                    time += 1.0;
                }
            }
        }
    }
}