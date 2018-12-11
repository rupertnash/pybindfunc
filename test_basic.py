import example
import py.test

def test_cpp_add():
    p = example.Pair(3, 2)
    p.SetOp(example.add)
    assert p() == 5

def test_py_mult():
    def mult(a, b):
        return a*b
    
    p = example.Pair(3, 2)
    p.SetOp(mult)
    assert p() == 6

