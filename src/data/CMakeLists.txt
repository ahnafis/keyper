add_subdirectory(models)
add_subdirectory(sources)

target_sources(keyper PRIVATE vault.cc)
