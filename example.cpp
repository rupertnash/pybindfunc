#include "example.h"
#include <iostream>

int add(int i, int j) {
    return i + j;
}


Pair::Pair(int a, int b) : first(a), second(b), op(nullptr) {
}

void Pair::SetOp(BinOpT op_) {
  op = op_;
}

int Pair::operator()() const {
  return op(first, second);
}

void test() {
  Pair p{1, 3};
  p.SetOp(&add);
  int ans = p();
}
