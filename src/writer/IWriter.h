#pragma once

#include "shared_EXPORTS.h"

namespace geom
{

class SHARED_EXPORT IWriter
{
public:
    virtual void write() = 0;

};

}
