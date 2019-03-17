//
//  animals.h
//  hellocpp
//
//  Created by mike oshea on 3/16/19.
//  Copyright © 2019 Future Trends. All rights reserved.
//

#ifndef animal_h
#define animal_h

#include <iostream>

class Animal {
protected:
    std::string sound;
public:
    static int animals_created;
    Animal(std::string sound = "animal sounds") : sound(sound) {
        ++animals_created;
    }
    virtual void says();
};

int Animal::animals_created(0);

void Animal::says() {
    std::cout << "Animal says: " << sound << std::endl;
}

class Dog : public Animal {
public:
    Dog(std::string sound = "woof") : Animal(sound) { }
    void says() override {
        std::cout << "Dog says: " << sound << std::endl;
    }
};

class BigDog : public Dog {
public:
    BigDog(std::string sound = "WOOF") : Dog(sound) { }
    void says() override {
        std::cout << "Big Dog says: " << sound << std::endl;
    }
};

#endif /* animals_h */
