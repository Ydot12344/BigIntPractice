add_executable(TestTest test.cpp ../BigInt.cpp)

target_link_libraries(TestTest gtest gtest_main)

add_test(
        NAME TestTest
        COMMAND TestTest --gtest_output=xml:${CMAKE_BINARY_DIR}/test_result/TestTest.xml
)
