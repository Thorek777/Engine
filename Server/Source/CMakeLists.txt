project(main)
cmake_minimum_required(VERSION 3.10)

add_executable(main
  Main.cpp
  Auth.cpp
  Auth.hpp
  Command.cpp
  Command.hpp
  Item.cpp
  Item.hpp
  Log.cpp
  Log.hpp
  MySQL.cpp
  MySQL.hpp
  Network.cpp
  Network.hpp
  Player.cpp
  Player.hpp
)

execute_process(COMMAND mysql_config --cflags OUTPUT_VARIABLE MYSQL_CFLAGS OUTPUT_STRIP_TRAILING_WHITESPACE)
execute_process(COMMAND mysql_config --libs OUTPUT_VARIABLE MYSQL_LIBS OUTPUT_STRIP_TRAILING_WHITESPACE)
target_compile_options(main PUBLIC ${MYSQL_CFLAGS})
target_link_libraries(main ${MYSQL_LIBS})
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
