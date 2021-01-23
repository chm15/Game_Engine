//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Maintains a list of all classes that are registered. Useful for
//      networking functions and initializing component arrays automatically.
//
//=============================================================================

#ifndef CLASS_TABLE_H
#define CLASS_TABLE_H

#include <unordered_map>
#include <string>


class ClassTable {
public:
    ClassTable() {}
    void registerClass(std::string classString, int classID) {
        this->classStringToClassID.emplace(classString, classID);
    }

private:
    std::unordered_map<std::string, int> classStringToClassID;

};

#endif
