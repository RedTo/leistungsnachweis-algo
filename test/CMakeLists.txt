#file(GLOB SRCS *.cpp)

file(GLOB SRCS *.cpp)

add_executable(algo-test ${SRCS})

target_link_libraries(algo-test gtest)

include_directories("..")

install(TARGETS algo-test DESTINATION bin)

add_test(NAME algotest COMMAND algo-test)