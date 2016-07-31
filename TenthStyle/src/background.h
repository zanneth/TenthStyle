//
//  background.h
//  TenthStyle
//
//  Created by Charles Magahern on 9/20/14.
//  Copyright (c) 2014 zanneth. All rights reserved.
//

#pragma once

#include <zge/zge.h>

class TenthStyleBackground : public zge::ZNode {
public:
    TenthStyleBackground(zge::ZRenderContextRef context);
    
    ZGE_DEFINE_SREF_FUNCTIONS(TenthStyleBackground);
    
private:
    void _setup_camera();
    void _setup_background();
    
private:
    zge::ZRenderContextRef _context;
};

ZGE_DEFINE_SREF_TYPE(TenthStyleBackground);
