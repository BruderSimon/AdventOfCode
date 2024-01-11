#include <cstddef>
#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <algorithm>

int part1(std::string& line){
  bool red = true;
  bool blue = true;
  bool green = true;
  //line.erase(line.begin(), line.begin()+5);
  int gamestart = line.find(':');
  std::string id = line.substr(5, gamestart);
  line.erase(line.begin(), line.begin()+gamestart+1);
  std::cout <<  "Game ID: " << id << "\n " << line <<std::endl;
  line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());
  size_t count = std::count_if( line.begin(), line.end(), []( char c ){return c ==';';});
  for(int i = 0; i < count; i++){
    std::string grab = line;
    if(i < count-1)
       grab = line.substr(0, line.find(';'));
    std::cout << "Line: " << line <<std::endl;
    line = line.substr(grab.length()+1, line.length());
    //line.erase(0, grab.length());
    std::cout << "Grab " << i << ": " << std::endl;
    std::cout << grab << std::endl;
    
    std::size_t r = grab.find("red");
    if(r != std::string::npos){
      // std::cout << "Pos Red: " << r << " ";
      std::cout << "\033[1;31m Red:";
      std::size_t comma = grab.find(',');
      if(comma > r)
	std::cout << grab.substr(0, r-1) << "\033[0m ";
      else
	std::cout << grab.substr(comma+1, r-1) << "\033[0m ";
      //grab.erase(0, comma);
    }
    std::size_t b = grab.find("blue");
    if(b != std::string::npos){
      std::size_t comma = grab.find(',');
      std::cout << "\033[1;34m Blue:";
      if(comma > b)
	std::cout << grab.substr(0, b-1) << "\033[0m ";
      else
	std::cout << grab.substr(comma+1, b-1) << "\033[0m ";
      //grab.erase(0, comma);
    }
    std::size_t g = grab.find("green");
    if(g != std::string::npos){
      std::cout << "\033[1;32m Green:";
      std::size_t comma = grab.find(',');
      if(comma > g)
	std::cout << grab.substr(0, g-1) << "\033[0m " << std::endl;
      else
	std::cout << grab.substr(comma+1, g-1) << "\033[0m " << std::endl; 
      //grab = grab.substr(comma, grab.length());
    }
    //std::cout << std::stoi( line.substr(0, g-1)) << std::endl;
    //line = line.substr(line.find(';'), line.length());
    //if(std::stoi(line.substr(0, r-1))
  }
  
  if(red && blue && green)
    return std::stoi(id);
  else
    return 0;
}

int main(){  
  std::ifstream input_file("input_day2.txt");
  std::string line;
  int sum = 0;
  if(!input_file.is_open()){
    std::cerr << "Could not read file" << std::endl;
    return -1;
  }
  while (std::getline(input_file, line)) {
    sum += part1(line);
  }
  std::cout << "Part 1: " << sum << std::endl;
}
