add_executable(test_ids test_ids.cpp)
target_link_libraries(test_ids PRIVATE softadastra_core)
add_test(NAME test_ids COMMAND test_ids)

add_executable(test_errors test_errors.cpp)
target_link_libraries(test_errors PRIVATE softadastra_core)
add_test(NAME test_errors COMMAND test_errors)

add_executable(test_time test_time.cpp)
target_link_libraries(test_time PRIVATE softadastra_core)
add_test(NAME test_time COMMAND test_time)

add_executable(test_hash test_hash.cpp)
target_link_libraries(test_hash PRIVATE softadastra_core)
add_test(NAME test_hash COMMAND test_hash)
