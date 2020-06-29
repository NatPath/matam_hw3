#include <iostream>
using namespace std;
class A {
public:
    A() {}
    A(const A& a) { cout << "A copy ctor" << endl; }
    virtual ~A() { cout << "A dtor" << endl; }
    virtual void type() const { cout << "This is A" << endl; }
};
class B: public A {
    public:
    virtual ~B() { cout << "B dtor" << endl; }
    void type() const override { cout << "This is B" << endl; }
};
A f(A a) {
    a.type();
    return a;
}
const A& g(const A& a) {
    a.type();
    return a;
}
int main()
{
    A* pa = new B(); // will call constructor of B , which is the constructor of A by default
    cout << "applying function f:" << endl;
    f(*pa).type(); // will call f(*pa), regarding the content of pa as an A, slicing its "B" proprties.
    cout << "applying function g:" << endl;
    g(*pa).type();
    delete pa;
    return 0;
}
/**
 * 
 * Expected output:
 * applying function f:
 * A copy ctor
 * This is A
 * A copy ctor
 * This is A
 * A dtor
 * A dtor // why twice?
 * applying function g:
 * This is B
 * This is B
 * B dtor
 * A dtor
 * 
 * 
 * 
 * 
 * */