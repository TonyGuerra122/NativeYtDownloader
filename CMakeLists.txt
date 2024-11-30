cmake_minimum_required(VERSION 3.12)

project(NativeYtDownloader)

add_executable(
    NativeYtDownloader
    "src/main.cpp"
    "src/initialize.cpp"
    "src/process_builder.cpp"
    "src/yt_dlp.cpp"
)

set_target_properties(NativeYtDownloader PROPERTIES CXX_STANDARD 17)

set(FETCHCONTENT_QUIET OFF CACHE BOOL "Desabilita o modo quiet do FetchContent" FORCE)
include(FetchContent)

add_subdirectory(libs)

target_link_libraries(NativeYtDownloader PRIVATE boost)