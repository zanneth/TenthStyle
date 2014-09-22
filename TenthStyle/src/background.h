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
    TenthStyleBackground();
    
private:
    void _setup_camera();
    void _setup_background();
};
