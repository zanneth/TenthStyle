//
//  scene.cpp
//  TenthStyle
//
//  Created by Charles Magahern on 9/13/14.
//  Copyright (c) 2014 zanneth. All rights reserved.
//

#include "scene.h"
#include "background.h"

using namespace zge;

void TenthStyleScene::on_enter()
{
    ZNodeRef background = std::make_shared<TenthStyleBackground>();
    add_child(background);
}