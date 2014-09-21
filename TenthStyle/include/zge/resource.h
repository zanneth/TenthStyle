/*
 * resource.h
 *
 * Author: Charles Magahern <charles@magahern.com>
 * Date Created: 05/08/2014
 */

#pragma once

#include <zge/foundation.h>

BEGIN_ZGE_NAMESPACE

class ZResource {
public:
    virtual ~ZResource();
    virtual std::string get_absolute_path() const = 0;
};

END_ZGE_NAMESPACE
