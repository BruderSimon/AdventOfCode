#include <fstream>
#include <iostream>
#include <string>
#include <cctype>

int main(){
  std::string line;
  std::ifstream input_file("input_day1.txt");
  int sum = 0;
  if(!input_file.is_open()){
    std::cerr << "Could not read file" << std::endl;
    return -1;
  }
  while (std::getline(input_file, line)) {
    std::cout << line << ": ";
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
	std::cout << last << " ";
	break;
      }else{
	last = first;
      }
    }
    
    std::string num = "";
    num += first;
    num += last;
    std::cout << num << std::endl;
    sum += std::stoi(num);
  }
  std::cout << "Sum: " << sum << std::endl; 
  return 0;
}
