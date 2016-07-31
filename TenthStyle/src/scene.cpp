//
//  scene.cpp
//  TenthStyle
//
//  Created by Charles Magahern on 9/13/14.
//  Copyright (c) 2014 zanneth. All rights reserved.
//

#include "scene.h"
#include "background.h"
#include "ship.h"

using namespace zge;

TenthStyleScene::TenthStyleScene(zge::ZRenderContextRef context) :
    _context(context),
    _bgnode(nullptr)
{}

void TenthStyleScene::on_enter()
{
    ZNodeRef background = TenthStyleBackground::create(_context);
    add_child(background);
    
    ZNodeRef ship = TenthStyleShip::create(_context);
    add_child(ship);
}
