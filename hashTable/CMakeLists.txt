add_library(hashTable STATIC src/hashTable.cpp)
target_include_directories(hashTable PUBLIC include)
target_link_libraries(hashTable PUBLIC dataStruct_utils)