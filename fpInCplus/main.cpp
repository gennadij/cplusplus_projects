#include <iostream>
#include "chapter2.cpp"
#include <vector>
#include <algorithm>
#include <numeric>

double average_score(const std::vector<int>& scores){
  return std::accumulate(scores.begin(), scores.end(), 0) / (double) scores.size();
}


int main(int, char**) {
  // chapter2
  std::vector<int> avg{1,2,3,4,5};

  std::cout << "Average " << average_score(avg) << "\n";

}


