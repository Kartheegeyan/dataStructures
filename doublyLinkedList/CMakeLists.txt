add_library(dll_constructor STATIC src/doublyLinkedList.cpp)
target_include_directories(dll_constructor PUBLIC include)
target_link_libraries(dll_constructor PUBLIC dataStruct_utils)
