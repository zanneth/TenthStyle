//
//  scene.h
//  TenthStyle
//
//  Created by Charles Magahern on 9/13/14.
//  Copyright (c) 2014 zanneth. All rights reserved.
//

#include <zge/zge.h>

class TenthStyleScene : public zge::ZScene {
public:
    void on_enter() override;
    
private:
    zge::ZSpriteNodeRef  _bgnode;
    zge::ZActionRef      _bg_anim_action;
};
