#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

double average_score(const std::vector<int>& scores){
  return std::accumulate(scores.begin(), scores.end(), 0) / (double) scores.size();
}

std::string trim_left(std::string s){
  s.erase(s.begin(), find_if(s.begin(), s.end(), [](char ss){return ss != ' ';}));
  return s;
}

std::string trim_right(std::string s){
  s.erase(find_if(s.begin(), s.end(), [](char ss){return ss != ' ';}), s.end());
  return s;
}

std::string trim(std::string s){
  return trim_left(trim_right(s));
}

int main(int, char**) {
  // chapter2
  std::vector<int> avg{1,2,3,4,5};

  std::cout << "Average " << average_score(avg) << "\n";

  std::cout << "Trim left :" << trim_left("     TrimLeft") << "\n";

  std::cout << "Trim right :" << trim_left("TrimRight     ") << "\n";

  std::cout << "Trim :" << trim_left("      Trim     ") << "\n";
}


