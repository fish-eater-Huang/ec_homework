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
    // Angle normalization(rad->[-PI,PI], deg->[-180,180])
    // 角度规范化(rad->[-PI,PI], deg->[-180,180])
    float radNormalizePI(const float& angle);
    float degNormalize180(const float& angle);
    // Voop limitation 循环限幅
    float loopLimit(float val, const float& min, const float& max);
}

#endif //EC_HOMEWORK_MATH_H
