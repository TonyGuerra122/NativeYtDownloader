FetchContent_Declare(
    boost
    GIT_REPOSITORY https://github.com/boostorg/boost.git
    GIT_TAG boost-1.83.0
)
FetchContent_MakeAvailable(boost)

FetchContent_GetProperties(boost SOURCE_DIR _boostSourceDir)

add_library(boost INTERFACE)
target_include_directories(boost INTERFACE ${_boostSourceDir})