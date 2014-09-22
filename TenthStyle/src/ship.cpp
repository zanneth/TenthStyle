//
//  ship.cpp
//  TenthStyle
//
//  Created by Charles Magahern on 9/20/14.
//  Copyright (c) 2014 zanneth. All rights reserved.
//

#include "ship.h"
#include <cmath>

using namespace zge;

TenthStyleShip::TenthStyleShip() : ZNode()
{
    _setup_camera();
    _setup_lights();
    _setup_model();
    
    // for debugging
    ZInputManagerRef input_manager = ZEngine::instance()->get_input_manager();
    ZCameraRef camera = get_camera();
    input_manager->add_responder([camera] (const ZEvent &event) {
        if (event.type == ZEventType::ZKEY_DOWN_EVENT) {
            
        }
    });
}

#pragma mark - Internal

void TenthStyleShip::_setup_camera()
{
    Z3DCameraRef camera = std::make_shared<Z3DCamera>();
    camera->set_position(ZVector::zero);
    camera->set_look({0.0, 0.0, -1.0});
    set_camera(camera);
}

void TenthStyleShip::_setup_lights()
{
    ZLightRef light = std::make_shared<ZLight>();
    light->set_color(ZColor::white);
    light->set_position({-5.0, 0.0, 0.0});
    add_child(light);
}

void TenthStyleShip::_setup_model()
{
    ZResourceBundle *bundle = ZResourceBundle::get_main_bundle();
    std::string ship_model_path = bundle->get_path_for_resource("TenthStyle.3ds");
    ZModelRef ship_model = std::make_shared<ZModel>(ship_model_path);
    
    ZColor material_color(0.26, 0.35, 0.38, 1.0);
    ZColorMaterialRef material = std::make_shared<ZColorMaterial>();
    material->set_color(material_color);
    ship_model->add_material(material);
    
    ZNodeRef ship = std::make_shared<ZNode>(ship_model);
    ship->set_position({0.0, 0.0, -50.0});
    add_child(ship);
    
    auto rotation = std::make_shared<ZRotationAction>(2.0 * M_PI, ZVector({1.0, 0.75, 0.5}));
    rotation->set_duration(ZTimeInterval(5.0));
    rotation->set_repeat_count(ZAction::repeat_count_infinity);
    ship->add_action(rotation);
    
    _ship_node = ship;
}
