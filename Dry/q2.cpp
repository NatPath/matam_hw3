#include <vector>
#include <iterator>
#include <iostream>

class Car {
    public:
    Car()=default;
    virtual double getFuelConsumption(int speed) const=0;

};
class Batmobile : public Car {
    double consumption;
    public:
    explicit Batmobile(double consumption):Car(),consumption(consumption){};
    double getFuelConsumption(int speed) const override;
};

double Batmobile::getFuelConsumption(int speed) const{
    return speed*consumption;
}

class Road { 
    double length_r;
    int speed_r;
    public:
    Road(double length, int speed):length_r(length),speed_r(speed){};
    double length(){
        return length_r;        
    }
    int speed(){
        return speed_r;

    } 
};
double getPetrol(std::vector<Road> roads,const Car& car){
    double sum=0;
    for (Road i : roads){
        sum+=(i.length())/car.getFuelConsumption(i.speed());
    }
    return sum;
}



using namespace std;
int main(){
    vector<Road> roads;
    for (int i=0;i<100;i++){
        roads.push_back(Road(i,i));
    }
    Batmobile batwheels(1);
    double res =getPetrol(roads,batwheels);
    cout<<res<<endl;


}