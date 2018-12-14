#include <iostream>
#include <fstream>
#include "Sort.h"

using namespace std;

int main(int argc, char** argv)
{
  Sort s;
  string file;

  if(argc < 2) {
      cout << "Please Enter Valid File Input" << endl;
  }

  else if(argc >= 2) {
      file = argv[1];
  }
  s.mainSort(file);
}
