//
//  application.cpp
//  TenthStyle
//
//  Created by Charles Magahern on 9/13/14.
//  Copyright (c) 2014 zanneth. All rights reserved.
//

#include "application.h"
#include "scene.h"

using namespace zge;

void TenthStyleApplication::application_ready()
{
    ZEngine *engine = ZEngine::instance();
    engine->initialize();
    
    // setup display
    ZDisplayMode disp_mode;
    disp_mode.windowed = true;
//    disp_mode.width = 540;
//    disp_mode.height = 960;
    disp_mode.width = 1280;
    disp_mode.height = 720;
    disp_mode.window_title = "10th Style";
    engine->get_display_manager()->create_display(disp_mode);
    
    // setup scene
    ZSceneRef scene = std::make_shared<TenthStyleScene>();
    engine->set_current_scene(scene);
}
