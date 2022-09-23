#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include "chapter3/fonctionObject.h"
#include "data/People.h"

using std::string;
using std::vector;

double average_score(const std::vector<int>& scores){
  return std::accumulate(scores.begin(), scores.end(), 0) / (double) scores.size();
}
bool is_not_space(char c){
  return !isspace(c);
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
  
  std::cout <<"\n people4";
  
  std::for_each(
    people4.begin(), people4.end(), 
    [](const People& p){std::cout << " " << p.name << " ";});

  //=========================================================================

  vector<People> people5 = initReople();

  people5.erase(std::remove_if(people5.begin(), people5.end(), is_not_female), people5.end());

  std::cout <<"\n ====================================================== \n";

  std::for_each(
    people5.begin(), people5.end(), 
    [](const People& p){std::cout << " " << p.name << " ";});

  //=========================================================================

  vector<People> people6 = initReople();
  vector<People> people6Copy;

  std::copy_if(people6.begin(), people6.end(), std::back_inserter(people6Copy), is_not_female);

  people6Copy.resize(std::distance(people6Copy.begin(), people6Copy.end()));

  std::cout <<"\n ====================================================== \n";

  std::cout << "Size : "  << people6Copy.size(); 

  std::for_each(
    people6Copy.begin(), people6Copy.end(), 
    [](const People& p){std::cout << " " << p.name << " ";});

  //=========================================================================

  std::cout <<"\n ====================================================== \n";
  older_than older_than_42(42);
  older_than older_than_14(14);

  vector<People> people7 = initReople();

  std::cout << older_than_42(people1.at(0)) << "\n";
  std::cout << older_than_42(people1.at(5)) << "\n";
  std::cout << older_than_14(people1.at(0)) << "\n";
  std::cout << older_than_14(people1.at(5)) << "\n";

}


