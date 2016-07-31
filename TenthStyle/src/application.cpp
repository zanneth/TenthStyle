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
    _engine = ZEngine::create();
    _engine->initialize(get_main_runloop());
    _engine->set_application(this);
    
    // setup display
    bool run_windowed = false;
    for (const std::string &arg : get_arguments()) {
        if (arg == "--windowed") {
            run_windowed = true;
            break;
        }
    }
    
    ZDisplayMode disp_mode;
    disp_mode.windowed = run_windowed;
    disp_mode.width = 1024;
    disp_mode.height = 768;
    disp_mode.window_title = "10th Style";
    _engine->get_render_manager()->create_display(disp_mode);
    
    // setup scene
    zge::ZRenderContextRef ctx = _engine->get_render_manager()->get_context();
    ZSceneRef scene = TenthStyleScene::create(ctx);
    _engine->set_current_scene(scene);
}
