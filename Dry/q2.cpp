#include <vector>

class Car {
    public:
    Car()=default;
    virtual double getFuelConsumption(int speed) const=0;

};
class Batmobile :public Car {
    double consumption;
    public:
    Batmobile(int consumption):consumption(consumption){};
    double getFuelConsumption(int speed) const override;
};

double Car::getFuelConsumption(int speed) const{
    return speed;
}

double getPetrol(std::vector<Road> roads,const Car& car){
    double sum=0;
    for (Road i :roads){
        sum+=i.length()*car.getFuelConsumption(i.speed());
    }
    return sum;
}

class Road { 
    double length;
    int speed;
    public:
    Road(double length, int speed):length(length),speed(speed){};
    double length(){
        return length;        
    }
    int speed(){
        return speed;

    } 
};


using namespace std;
int main(){
    vector<Road> roads;
    for (int i=0;i<100;i++){
        roads.push_back(Road(i,i));

    }


}