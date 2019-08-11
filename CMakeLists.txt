cmake_minimum_required (VERSION 2.6)

project (flecstest)

add_compile_definitions(FLECS_STATIC)

file(GLOB flecs_SRC "src/*.cpp")

include_directories("include" "$ENV{FLECS_ROOT}/include")
link_directories("$ENV{FLECS_ROOT}/lib")

add_executable(flecstest ${flecs_SRC})
target_link_libraries(flecstest "flecs_static")
