#include <iostream>
#include "chapter2.cpp"
#include <vector>
#include <algorithm>
#include <numeric>
#include <cctype>
double average_score(const std::vector<int>& scores){
  return std::accumulate(scores.begin(), scores.end(), 0) / (double) scores.size();
}
bool is_not_space(char c){
  !isspace(c);
}
std::string trimLeft(std::string s){
  s.erase(s.begin(), std::find_if(s.begin(), s.end(), is_not_space));
}


int main(int, char**) {
  // chapter2
  std::vector<int> avg{1,2,3,4,5};

  std::cout << "Average " << average_score(avg) << "\n";

  std::string trim = "  spacesLeft";

  std::cout << "Trim Left " << trimLeft(trim) << "\n";
  

}


