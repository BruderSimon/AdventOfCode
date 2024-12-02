#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include <cctype>
#include <map>

int part1(std::string& line){
  std::string::iterator it;
  char first, last;
  for(it = line.begin(); it != line.end()+1; ++it){
    if(std::isdigit(*it)){
      first = *it;
      std::cout << first << " + ";
      break;
    }
  }
  for(it = line.end(); it !=line.begin()-1; --it){
    if(std::isdigit(*it)){
      last = *it;
      std::cout << last;
      break;
    }else{
      last = first;
    }
  }
  
  std::string num = "";
  num += first;
  num += last;
  std::cout << " = " << std::stoi(num) << std::endl;
  return std::stoi(num);
}

int part2(std::string& line){
  std::size_t start_pos = 0;
  std::string from[] ={ "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
  std::cout << line << " ->";
  for(int i = 0; i<9; i++){
    std::string to = std::to_string((i+1));
    start_pos = line.find(from[i], start_pos);
    if(start_pos !=std::string::npos){
      //Insert the Number in the middle
      line.insert(start_pos + (from[i].length()/2), to);
      i--;
      start_pos += from[i].length();
    }else{
      start_pos = 0;
    }
    //start_pos = 0;
  }
  std::cout << line << std::endl;
  return part1(line);
}

int main(){
  std::ifstream input_file("input_day1.txt");
  std::string line;
  int sum = 0;
  int sum1 = 0;
  if(!input_file.is_open()){
    std::cerr << "Could not read file" << std::endl;
    return -1;
  }
  while (std::getline(input_file, line)) {
    //sum += part1(line);
    sum1 += part2(line);
  }
  std::cout << "Part1: " << sum << std::endl; 
  std::cout << "Part2: " << sum1 << std::endl;
}
