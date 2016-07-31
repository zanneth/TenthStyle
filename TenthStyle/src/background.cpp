//
//  background.cpp
//  TenthStyle
//
//  Created by Charles Magahern on 9/20/14.
//  Copyright (c) 2014 zanneth. All rights reserved.
//

#include "background.h"

using namespace zge;

TenthStyleBackground::TenthStyleBackground(zge::ZRenderContextRef context) :
    _context(context)
{
    _setup_camera();
    _setup_background();
}

#pragma mark - Internal

void TenthStyleBackground::_setup_camera()
{
    ZRect viewport = _context->get_viewport();
    ZOrthoCameraRef camera = ZOrthoCamera::create();
    camera->set_clipping_rect({0.0, 0.0, viewport.size.width, viewport.size.height});
    set_camera(camera);
}

void TenthStyleBackground::_setup_background()
{
    const ZResourceBundle *resbundle = ZResourceBundle::get_main_bundle();
    ZImageRef bgimg = ZImage::create(resbundle->get_path_for_resource("scrolling_bg.png"));
    ZSize2D bgimg_size = bgimg->get_size();
    ZTextureRef bgtexture = _context->create_texture(bgimg);
    
    ZSpriteNodeRef bg_node = ZSpriteNode::create();
    bg_node->set_texture(bgtexture);
    bg_node->set_size({bgimg_size.width * 2.0f, bgimg_size.height});
    bg_node->set_position(ZVector::zero);
    bg_node->set_texture_rect({{0.0, 0.0}, {2.0, 1.0}});
    add_child(bg_node);
    
    ZVector anim_end = {-bgimg_size.width, 0.0};
    ZTranslationActionRef anim_action = ZTranslationAction::create(ZVector::zero, anim_end);
    anim_action->set_repeat_count(ZAction::repeat_count_infinity);
    anim_action->set_duration(ZTimeInterval(20.0));
    bg_node->add_action(anim_action);
}
