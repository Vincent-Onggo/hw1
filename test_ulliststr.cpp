#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite
using namespace std;
#include <iostream>
int main(int argc, char* argv[]) {
    ULListStr list;
    list.push_back("A");
    list.push_back("B");
    list.push_back("C");






    list.pop_front();
    list.pop_back();
    list.pop_front();
    cout << list.get(0);



}
