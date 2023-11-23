# Parent project does not export its library target, so this CML implicitly
# depends on being added from it, i.e. the testing is done only from the build
# tree and is not feasible from an install location

project(comp-4300-initTests LANGUAGES CXX)

# ---- Dependencies ----

find_package(Catch2 REQUIRED)
include(Catch)

# ---- Tests ----

add_executable(comp-4300-init_test source/comp-4300-init_test.cpp)
target_link_libraries(
    comp-4300-init_test PRIVATE
    comp-4300-init_lib
    Catch2::Catch2WithMain
)
target_compile_features(comp-4300-init_test PRIVATE cxx_std_20)

catch_discover_tests(comp-4300-init_test)

# ---- End-of-file commands ----

add_folders(Test)
