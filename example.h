// -*- mode: c++; -*-

#include <string>
#include <functional>

int add(int i, int j);

struct Pair {
  Pair(int, int);
  //typedef int (*BinOpT)(int, int);
  using BinOpT = std::function<int(int, int)>;
  void SetOp(BinOpT op);
  int operator()() const;
  
private:  
  int first;
  int second;
  BinOpT op;
};

