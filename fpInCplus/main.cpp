#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using std::string;
using std::vector;

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

struct People {
  string name;
  string gender;
};

vector<People> initReople() {
  return vector<People> {
    People{"Marta", "female"}, 
    People{"Peter", "male"},
    People{"Sandra", "female"},
    People{"Lucy", "female"},
    People{"Mark", "male"},
    People{"Anton", "male"},
    People{"Luda", "female"},
    People{"Artiom", "male"},
    People{"Aljona", "female"}
    }; 
}

bool is_female(const People& p){
  return p.gender == "female";
}

bool is_not_female(const People& p){
  return p.gender != "female";
}

int main(int, char**) {
  // chapter2
  std::vector<int> avg{1,2,3,4,5};

  std::cout << "Average " << average_score(avg) << "\n";

  std::cout << "Trim left :" << trim_left("     TrimLeft") << "\n";

  std::cout << "Trim right :" << trim_left("TrimRight     ") << "\n";

  std::cout << "Trim :" << trim_left("      Trim     ") << "\n";

  // chapter 2.2.4
  //=========================================================================

  vector<People> people1 = initReople();
  
  auto isFemale = std::partition(people1.begin(), people1.end(), is_female);
  
  std::cout << "people1";
  
  std::for_each(
    people1.begin(), people1.end(), 
    [](const People& p){std::cout << " " << p.name << " ";});
  
  //=========================================================================

  vector<People> people2 = initReople();

  auto isNotFemale = std::partition(people2.begin(), people2.end(), is_not_female); 
  
  std::cout << "\n people2";
  
  std::for_each(
    people2.begin(), people2.end(), 
    [](const People& p){std::cout << " " << p.name << " ";});

  //=========================================================================

  vector<People> people3 = initReople();
  
  std::stable_partition(people3.begin(), people3.end(), is_female);

  std::cout << "\n people3";

  std::for_each(
    people3.begin(), people3.end(), 
    [](const People& p){std::cout << " " << p.name << " ";});

  //=========================================================================
  
  vector<People> people4 = initReople();

  std::stable_partition(people4.begin(), people4.end(), is_not_female);
  
  std::cout << "\n people4";
  
  std::for_each(
    people4.begin(), people4.end(), 
    [](const People& p){std::cout << " " << p.name << " ";});
}


