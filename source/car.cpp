#include <iostream>
#include <memory>
#include <string>
#include <utility>

struct CarPart{
    virtual int getPrice() const = 0;
};

struct Wheel: CarPart{
    int getPrice() const override = 0;
};

struct Motor: CarPart{
    int getPrice() const override = 0;
};

struct Body: CarPart{
    int getPrice() const override = 0;
};

// Trabi

struct TrabiWheel: Wheel{
    int getPrice() const override{
        return 30;
    }
};

struct TrabiMotor: Motor{
    int getPrice() const override{
        return 350;
    }
};

struct TrabiBody: Body{
    int getPrice() const override{
        return 550;
    }
};

// VW

struct VWWheel: Wheel{
    int getPrice() const override{
        return 100;
    }
};

struct VWMotor: Motor{
    int getPrice() const override{
        return 500;
    }
};

struct VWBody: Body{
    int getPrice() const override{
        return 850;
    }
};

// BMW

struct BMWWheel: Wheel{
    int getPrice() const override{
        return 300;
    }
};

struct BMWMotor: Motor{
    int getPrice() const override{
        return 850;
    }
};

struct BMWBody: Body{
    int getPrice() const override{
        return 1250;
    }
};

// Generic car
    
struct Car{
    Car(std::unique_ptr<Wheel> wh, std::unique_ptr<Motor> mo, std::unique_ptr<Body> bo): 
         myWheel(std::move(wh)), myMotor(std::move(mo)), myBody(std::move(bo)){}
         
    int getPrice(){
        return 4 * myWheel->getPrice() + myMotor->getPrice() + myBody->getPrice();
    }

private:
    std::unique_ptr<Wheel> myWheel;
    std::unique_ptr<Motor> myMotor;
    std::unique_ptr<Body> myBody;

};

int main(){
    
    std::cout << '\n';
    
    Car trabi(std::make_unique<TrabiWheel>(), std::make_unique<TrabiMotor>(), std::make_unique<TrabiBody>());
    std::cout << "Offer Trabi: " << trabi.getPrice() << '\n';
    
    Car vw(std::make_unique<VWWheel>(), std::make_unique<VWMotor>(), std::make_unique<VWBody>());
    std::cout << "Offer VW: " << vw.getPrice() << '\n';
    
    Car bmw(std::make_unique<BMWWheel>(), std::make_unique<BMWMotor>(), std::make_unique<BMWBody>());
    std::cout << "Offer BMW: " << bmw.getPrice() << '\n';
    
    Car fancy(std::make_unique<TrabiWheel>(), std::make_unique<VWMotor>(), std::make_unique<BMWBody>());
    std::cout << "Offer Fancy: " << fancy.getPrice() << '\n';
    
    std::cout << '\n';
    
}
    
