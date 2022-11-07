#include <argparse/argparse.hpp>
#include <iostream>
#include <tesseract/baseapi.h>
#include <string>
#include <fstream>
#include <cstdio>
#define PROGRAM_NAME "pdr"

int main(int argc, char* argv[]) {
  argparse::ArgumentParser args(PROGRAM_NAME);
  args.add_argument("infile").help("Input file");
  args.add_argument("outfile").help("Output file");
  try {
    args.parse_args(argc, argv);
  }
  catch (const std::runtime_error& err) {
    std::cerr << err.what() << std::endl;
    std::cerr << args;
    std::exit(1);
  }
  std::ifstream infile;
  infile.open(args.get<std::string>("infile"), std::ios::in | std::ios::binary);
  if (!infile.is_open()) {
    std::cerr << "No such file or directory: " << args.get<std::string>("infile") << std::endl;
    std::exit(1);
  }
  char b;
  while(infile.read(&b, 1)) {
    printf("%.2x", b & 0xff);
  }
  std::cout << std::endl;
  return 0;
}
