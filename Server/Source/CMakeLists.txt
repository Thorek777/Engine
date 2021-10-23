project(main)
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED YES)

file(GLOB SOURCES
	*.cpp
	*.h
)

add_executable(main
	${SOURCES}
)

execute_process(COMMAND mysql_config --cflags OUTPUT_VARIABLE MYSQL_CFLAGS OUTPUT_STRIP_TRAILING_WHITESPACE)
execute_process(COMMAND mysql_config --libs OUTPUT_VARIABLE MYSQL_LIBS OUTPUT_STRIP_TRAILING_WHITESPACE)
target_compile_options(main PUBLIC ${MYSQL_CFLAGS})
target_link_libraries(main ${MYSQL_LIBS})
