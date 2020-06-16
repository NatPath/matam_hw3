#include <iostream>
using namespace std;

class B {
    private:
    int n;
    public:
    B(int x) : n(x) {}
    //option B: B operator +(B b) {//send actual object as an argument
    B operator +(B& b) {
        return B(n+b.n);
    }
    friend ostream& operator <<(ostream &out, const B& b) {
        //previous: out << "B: " << n;
        out << "B: " << b.n;//b.n instead of n
        return out;
    }
    //previous: bool operator <(const B& rhs) {
    bool operator <(const B& rhs) const{//added const
        return n < rhs.n;
    }
 };

 B smaller (const B& b1, const B& b2) {
    if(b1 < b2) // left arguement of operator should not be a const
        return b1;
    else
        return b2;
 }
int main() {
    B b1(1), b2(2), b3(3);
    //const B b4 = b1 + (b2 + b3);//can't send a reference of an object as an arguement with no "tangible" address
    //option A:
    const B b4 = (b1 + b2) + b3;
    //option B:
    //const B b4 = b1 + (b2 + b3);// same as the original line 
    cout << smaller(b1,b2) << endl;
    return 0;
}