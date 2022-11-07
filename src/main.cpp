#include <argparse/argparse.h>
#include <iostream>

#define PROGRAM_NAME "pdr"

int main() {
  argparse::ArgumentParser args(PROGRAM_NAME);
  args.add_argument("infile").help("Input file");
  try {
    args.parse_args(argc, argv);
  }
  catch (const std::runtime_error& err) {
    std::cerr << err.what() << std::endl;
    std::cerr << program;
    std::exit(1);
  }
  
  return 0;
}
