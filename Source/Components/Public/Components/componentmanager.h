//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: 
//
//=============================================================================

#pragma once

#include <memory>
#include <unordered_map>
#include <Entities/entity.h>
#include "componentarray.h"

class ComponentManager {
public:

    template<typename T>
    void registerComponent() {
        // Any component that is registered should have already been
        // registered with the Engine's ClassTable. Maybe assert this.


        // TODO: Catch error here. Component must be registered with the class
        // table first.
        int classID = T::classID;


        this->componentArrays.insert(
                {classID, std::make_shared<ComponentArray<T>>()}
                );
    };

    void addComponent(Entity entity, int classID) {
        // Use the component's classID (assigned by the classtable.
        // The classID will be used in a map between classID's and
        // component arrays.
    }

    void removeComponent(Entity entity, int classID) {
        // use the component's classID to remove the component from the
        // corresponding component array.
    }

public:
    ComponentManager() = default;

    // Maps from classID to ComponentArray
    std::unordered_map<int, std::shared_ptr<BaseComponentArray> > componentArrays;


    // Helper function for getting component array.
    //std::shared_ptr<ComponentArray> getComponentArray(int classID) {};

};



/*

==================== EXAMPLE ========================

#include <memory>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>


class Cls1 {
    void print(std::string str) {
        std::cout << "Cls1: " << str << std::endl;
        return;
    }
};


class Cls2 {
    void print(std::string str) {
        std::cout << "Cls2: " << str << std::endl;
        return;
    }
};


class BaseClsArray {};


template<typename T>
class ClsArray : public BaseClsArray {
public:
    T getCls(int index) {
        return this->classes[index];
    }

    void addCls() {
        this->classes.emplace();
    }

public:
    ClsArray() = default;

    ClsArray(int totalInit) {
        for (int i=0;i<totalInit;i++) {
            this->classes.emplace_back();
        }
    }

private:
    std::vector<T> classes;
};

int main() {

    std::unordered_map<int, std::shared_ptr<BaseClsArray> > clsArrays{};

    clsArrays.insert({1, std::make_shared<ClsArray<Cls1>>(3)});
    //clsArrays.insert({2, std::make_shared< ClsArray<Cls2> >(3) });
    
    //std::shared_ptr<BaseClsArray> shrd = std::static_pointer_cast<BaseClsArray>(std::make_shared<ClsArray<Cls1>>(3));


    //clsArrays[1].getCls[1].print("YUP");

    return 0;
}

*/
