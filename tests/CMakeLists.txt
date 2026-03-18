add_executable(core_tests
    test_ids.cpp
    test_errors.cpp
    test_time.cpp
    test_hash.cpp
)

target_link_libraries(core_tests
    PRIVATE softadastra_core
)

add_test(NAME core_tests COMMAND core_tests)
