//
// Created by 15795 on 2023/12/23.
//

#ifndef EC_HOMEWORK_MATH_H
#define EC_HOMEWORK_MATH_H
#include <stdint.h>

namespace math {

// Value limitation 限幅
    float limit(float val, const float &min, const float &max);

    float limitMin(float val, const float &min);

    float limitMax(float val, const float &max);

    float sign(const float &val);
}

#endif //EC_HOMEWORK_MATH_H
