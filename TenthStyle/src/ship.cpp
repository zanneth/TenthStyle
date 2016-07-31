//
//  ship.cpp
//  TenthStyle
//
//  Created by Charles Magahern on 9/20/14.
//  Copyright (c) 2014 zanneth. All rights reserved.
//

#include "ship.h"
#include <cmath>

#define SHIPS_COUNT 10

using namespace zge;

TenthStyleShip::TenthStyleShip(zge::ZRenderContextRef context) :
    _context(context)
{
    _setup_camera();
    _setup_lights();
    _setup_models();
}

#pragma mark - Internal

void TenthStyleShip::_setup_camera()
{
    Z3DCameraRef camera = Z3DCamera::create();
    camera->set_position({-0.5, 0.0, 0.0});
    camera->set_look({-0.1, 0.0, -1.0});
    camera->set_viewport_rect(_context->get_viewport());
    set_camera(camera);
}

void TenthStyleShip::_setup_lights()
{
    ZLightRef light = ZLight::create();
    light->set_color(ZColor::white);
    light->set_position(ZVector::zero);
    add_child(light);
}

void TenthStyleShip::_setup_models()
{
    const ZResourceBundle *bundle = ZResourceBundle::get_main_bundle();
    std::string ship_model_path = bundle->get_path_for_resource("TenthStyle.3ds");
    ZModelRef ship_model = ZModel::create(ship_model_path);
    
    ZColor material_color(0.25, 0.25, 0.30, 1.0);
    ZColorMaterialRef material = ZColorMaterial::create();
    material->set_color(material_color);
    ship_model->add_material(material);
    
    const float ships_spacing = 12.0;
    ZNodeRef ships = ZNode::create();
    ships->set_position(ZVector::zero);
    
    for (unsigned i = 0; i < SHIPS_COUNT; ++i) {
        ZNodeRef ship = ZNode::create(ship_model);
        ship->set_position({0.0, (float)i * ships_spacing, 0.0});
        ships->add_child(ship);
    }
    
    ZMatrix rotation = ZMatrix::rotation(-M_PI_2, 1.0, 0.0, 0.0);
    ships->set_transform(rotation);
    
    ZNodeRef ships_container = ZNode::create();
    ships_container->set_position(ZVector::zero);
    ships_container->add_child(ships);
    
    ZRotationActionRef rot_action = ZRotationAction::create(2.0 * M_PI, ZVector{0.0, 0.0, 1.0});
    rot_action->set_duration(ZTimeInterval(15.0));
    rot_action->set_repeat_count(ZAction::repeat_count_infinity);
    ships_container->add_action(rot_action);
    
    ZVector tr_start = ZVector::zero;
    ZVector tr_end = {0.0, 0.0, ships_spacing};
    ZTranslationActionRef tr_action = ZTranslationAction::create(tr_start, tr_end);
    tr_action->set_duration(ZTimeInterval(3.0));
    tr_action->set_repeat_count(ZAction::repeat_count_infinity);
    ships_container->add_action(tr_action);
    
    add_child(ships_container);
}
