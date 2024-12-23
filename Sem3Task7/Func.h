#include <vector>
#include <deque>
#include <string>
#ifndef SEM3TASK7_FUNC_H
#define SEM3TASK7_FUNC_H

std::vector<int> ProfessorsGame(std::vector<int>& input_vec, int k);
std::vector<std::pair<std::string, std::vector<std::string>>> VasyasDictionary(int N,
                                                                               const std::vector<std::string> &dictionary);
double calculateTime(std::string input_string);
#endif //SEM3TASK7_FUNC_H