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
    TenthStyleScene(zge::ZRenderContextRef context);
    void on_enter() override;
    
    ZGE_DEFINE_SREF_FUNCTIONS(TenthStyleScene);
    
private:
    zge::ZRenderContextRef _context;
    zge::ZSpriteNodeRef    _bgnode;
};

ZGE_DEFINE_SREF_TYPE(TenthStyleScene);
