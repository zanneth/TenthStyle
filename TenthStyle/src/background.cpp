//
//  background.cpp
//  TenthStyle
//
//  Created by Charles Magahern on 9/20/14.
//  Copyright (c) 2014 zanneth. All rights reserved.
//

#include "background.h"

using namespace zge;

TenthStyleBackground::TenthStyleBackground() : ZSpriteNode()
{
    ZResourceBundle *resbundle = ZResourceBundle::get_main_bundle();
    ZImageRef bgimg = std::make_shared<ZImage>(resbundle->get_path_for_resource("scrolling_bg.png"));
    ZSize2D bgimg_size = bgimg->get_size();
    float bgimg_aspect = bgimg_size.width / bgimg_size.height;
    ZTextureRef bgtexture = std::make_shared<ZTexture>(bgimg);
    
    set_texture(bgtexture);
    set_size({bgimg_aspect * 2.0f, 1.0});
    set_position(ZVector::zero);
    set_texture_rect({{0.0, 0.0}, {2.0, 1.0}});
    
    ZVector anim_end = {-bgimg_aspect, 0.0};
    ZTranslationActionRef anim_action = std::make_shared<ZTranslationAction>(ZVector::zero, anim_end);
    anim_action->set_repeat_count(ZAction::repeat_count_infinity);
    anim_action->set_duration(ZTimeInterval(20.0));
    add_action(anim_action);
}

TenthStyleBackground::~TenthStyleBackground()
{}

#pragma mark -

void TenthStyleBackground::on_enter()
{
    _setup_camera();
}

#pragma mark - Internal

void TenthStyleBackground::_setup_camera()
{
    ZRect viewport = ZEngine::instance()->get_viewport_rect();
    float aspect = viewport.size.width / viewport.size.height;
    
    ZOrthoCameraRef camera = std::make_shared<ZOrthoCamera>();
    camera->set_clipping_rect({0.0, 0.0, aspect, 1.0});
    set_camera(camera);
}