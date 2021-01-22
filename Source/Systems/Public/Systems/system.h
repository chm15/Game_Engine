//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: 
//
//=============================================================================

#pragma once


class System {
public:
    virtual void update() = 0;

    virtual ~System() = default;
};

