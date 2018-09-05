#include <unistd.h>
#include <iostream>
#include <fstream>
using namespace std;
int main(){
  system("cat /proc/cpuinfo |head -4|cat >output.txt");

      system("cat /proc/cpuinfo |grep -m 1 'cores'|cat >>output.txt");
ifstream in("output.txt");
if(!in) {
    cout << "Cannot open input file.\n";
    return 1;
  }
  char str [255];

 while(in) {
   in.getline(str,255);  // delim defaults to '\n'
   if(in) cout << str<< endl;

 }

 in.close();



  return 0;
}
