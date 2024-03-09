# NoobArgs

A Simple CLI argument parser for C++.
Easy to setup, customizable and with validation support on self-defined arguments.

## Parses

- `--arg` or `-a` (bool)
- `--arg value` or `-a value` (string)
- `--arg value1 ... valueN` or `-a value1 ... valueN` (vector<string>)

## Usage

```cpp
#include "noobargs.h"

int main(int argc, char* argv[]) {
    NoobArgs args(argc, argv);
    args.addArg("arg", "a", "Description of arg", NoobArgs::ArgType::BOOL);
    args.addArg("arg", "a", "Description of arg", NoobArgs::ArgType::STRING);
    args.addArg("arg", "a", "Description of arg", NoobArgs::ArgType::STRING_VECTOR);
    args.parse();
    if (args.getBool("arg")) {
        // Do something
    }
    if (args.getString("arg") == "value") {
        // Do something
    }
    for (const auto& value : args.getStringVector("arg")) {
        // Do something
    }
    return 0;
}
```

## License

The above code is licensed under the MIT License. Check [LICENSE](LICENSE) for more information.
