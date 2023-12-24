//
// Created by 15795 on 2023/12/23.
//

#include "math.h"
#define PI					3.14159265358979f
// Value limitation
// 限幅
float math::limit(float val, const float& min, const float& max) {
    if (min > max)
        return val;
    else if (val < min)
        val = min;
    else if (val > max)
        val = max;
    return val;
}

// Value limitation
// 限幅
float math::limitMin(float val, const float& min) {
    if (val < min)
        val = min;
    return val;
}

// Value limitation
// 限幅
float math::limitMax(float val, const float& max) {
    if (val > max)
        val = max;
    return val;
}

// Get sign of value
// 符号
float math::sign(const float& val) {
    if (val > 0)
        return 1;
    else if (val < 0)
        return -1;
    return 0;
}

// Voop limitation
// 循环限幅
float math::loopLimit(float val, const float& min, const float& max) {
    if (min >= max)
        return val;
    if (val > max) {
        while (val > max)
            val -= (max - min);
    } else if (val < min) {
        while (val < min)
            val += (max - min);
    }
    return val;
}

float math::radNormalizePI(const float& angle) {
    return math::loopLimit(angle, -PI, PI);
}

float math::degNormalize180(const float& angle) {
    return math::loopLimit(angle, -180.f, 180.f);
}