//
//  application.h
//  TenthStyle
//
//  Created by Charles Magahern on 9/13/14.
//  Copyright (c) 2014 zanneth. All rights reserved.
//

#pragma once

#include <zge/zge.h>

class TenthStyleApplication : public zge::ZApplication {
public:
    using zge::ZApplication::ZApplication;
    void application_ready() override;
};
