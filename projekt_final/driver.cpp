#include <iostream>

int main() {
  std::string list[4];
  list[0]="aaa";
  list[1]="bbb";
  list[2]="ccc";
  std::string *listOfStops;
    for (int i=0; ; i++) {
      if (listOfStops[i] == "") {
	break;
      }
      std::cout << listOfStops[i] << " " << std::endl;
    }
  }
