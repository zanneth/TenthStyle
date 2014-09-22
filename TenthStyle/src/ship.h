//
//  ship.h
//  TenthStyle
//
//  Created by Charles Magahern on 9/20/14.
//  Copyright (c) 2014 zanneth. All rights reserved.
//

#pragma once

#include <zge/zge.h>

class TenthStyleShip : public zge::ZNode {
public:
    TenthStyleShip();
    
private:
    void _setup_camera();
    void _setup_lights();
    void _setup_model();
    
private:
    zge::ZNodeRef _ship_node;
};
