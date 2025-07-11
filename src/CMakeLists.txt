add_subdirectory(data)
add_subdirectory(utils)

target_sources(keyper PRIVATE config.cc keyper.cc)
target_sources(exec PRIVATE main.cc)
