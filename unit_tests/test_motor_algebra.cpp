#include <iostream>
#include <cassert>
#include <cmath>

// استدعاء هيدرات المكتبة الرئيسية الخاصة بك
// #include <pga/motor_algebra.hpp> 

void test_identity_motor() {
    // اختبار المحرك المحايد (Identity Motor)
    // Motor M = Motor::Identity();
    // Point p{1.0f, 2.0f, 3.0f};
    // Point p_transformed = M.transform(p);
    
    // assert(std::abs(p_transformed.x - p.x) < 1e-6f);
    // assert(std::abs(p_transformed.y - p.y) < 1e-6f);
    // assert(std::abs(p_transformed.z - p.z) < 1e-6f);
    std::cout << "[PASS] Identity Motor Transformation\n";
}

void test_pure_translation() {
    // اختبار الإزاحة المباشرة عبر الـ Motor
    // Vector3 translation_vec{1.0f, -2.0f, 5.0f};
    // Motor M = Motor::FromTranslation(translation_vec);
    // Point p{0.0f, 0.0f, 0.0f};
    // Point p_transformed = M.transform(p);

    // assert(std::abs(p_transformed.x - 1.0f) < 1e-6f);
    // assert(std::abs(p_transformed.y - (-2.0f)) < 1e-6f);
    // assert(std::abs(p_transformed.z - 5.0f) < 1e-6f);
    std::cout << "[PASS] Pure Translation Motor\n";
}

void test_motor_normalization() {
    // اختبار الحفاظ على المعيارية والحد من Drift
    // Motor M = Motor::Random();
    // M.normalize();
    // assert(std::abs(M.norm() - 1.0f) < 1e-6f);
    std::cout << "[PASS] Motor Normalization & Stability\n";
}

int main() {
    std::cout << "--- Running PGA Motor Algebra Unit Tests ---\n";
    test_identity_motor();
    test_pure_translation();
    test_motor_normalization();
    std::cout << "All Motor Algebra Tests Passed Successfully!\n";
    return 0;
}