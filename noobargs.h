#include <map>
#include <string>
#include <vector>

using namespace std;

enum ArgType { FLAG, STRING, INT, FLOAT, VECTOR };

class NoobArgs {
public:
  map<string, ArgType> reqArgs;

  NoobArgs(int argc, char **argv) : argc(argc - 1) {
    for (int i = 1; i < argc; i++) {
      string arg = argv[i];
      this->argv.push_back(arg);
    }
  }

  struct Args {
    vector<string> flags;
    map<string, string> options;
  };

  int getArgc() const { return argc; }
  vector<string> getArgv() const { return argv; }
  vector<string> getFlags() const { return flags; }
  map<string, string> getOptions() const { return options; }
  Args getStruct() const { return {flags, options}; }

  void addArg(string arg, ArgType type) { reqArgs[arg] = type; }

  string joinStuff(vector<string> &vec) {
    string result = "";
    for (int i = 0; i < vec.size(); i++) {
      result += vec[i] + " ";
    }
    return result;
  }

  string joinStuff(map<string, string> &map) {
    string result = "";
    for (auto const &x : map) {
      result += "--" + x.first + " " + x.second + " ";
    }
    return result;
  }

  void refreshOptions() {
    this->flags.clear();
    this->options.clear();

    for (int i = 0; i < this->argc; i++) {
      string arg = this->argv[i];
      if (arg.find("--") == 0) {
        if (i + 1 < this->argc) {
          string nextArg = this->argv[i + 1];
          if (nextArg.find("--") != 0) {
            while (nextArg.find("--") != 0) {
              this->options[stripDashes(arg)] += nextArg + " ";
              i++;
              if (i + 1 < this->argc) {
                nextArg = this->argv[i + 1];
              } else {
                break;
              }
            }
          } else {
            this->flags.push_back(stripDashes(arg));
          }
        } else {
          this->flags.push_back(stripDashes(arg));
        }
      }
    }
  }

  void parse() { 
    refreshOptions(); 
    for (auto const &x : reqArgs) {
      if (x.second == FLAG) {}
    }
  }

private:
  int argc;
  vector<string> argv;

  vector<string> flags;
  map<string, string> options;

  string stripDashes(string str) { return str.substr(2, str.length()); }
};
