//
//  background.h
//  TenthStyle
//
//  Created by Charles Magahern on 9/20/14.
//  Copyright (c) 2014 zanneth. All rights reserved.
//

#pragma once

#include <zge/zge.h>

class TenthStyleBackground : public zge::ZSpriteNode {
public:
    TenthStyleBackground();
    ~TenthStyleBackground();
    
    void on_enter() override;
    
private:
    void _setup_camera();
};
