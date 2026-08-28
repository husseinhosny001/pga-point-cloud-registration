cmake_minimum_required(VERSION 3.18)

add_executable(pga_mwe_demo main.cpp)

# ربط المجلد المصدري للهيدرات Header-only
target_include_directories(pga_mwe_demo PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)

# تفعيل التحسينات العتادية للمثال
if(MSVC)
    target_compile_options(pga_mwe_demo PRIVATE /O2 /arch:AVX2)
else()
    target_compile_options(pga_mwe_demo PRIVATE -O3 -mavx2 -fopenmp)
endif()