#include "noobargs.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
  cout << "Welcome to the CLI" << endl;

  NoobArgs args(argc, argv);
  args.refreshOptions();

  auto res = args.getStruct();

  cout << "Flags: " << args.joinStuff(res.flags) << endl;
  cout << "Options: " << args.joinStuff(res.options) << endl;

  return 0;
}
