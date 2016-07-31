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
    TenthStyleShip(zge::ZRenderContextRef context);
    
    ZGE_DEFINE_SREF_FUNCTIONS(TenthStyleShip);
    
private:
    void _setup_camera();
    void _setup_lights();
    void _setup_models();
    
private:
    zge::ZRenderContextRef _context;
};

ZGE_DEFINE_SREF_TYPE(TenthStyleShip);
