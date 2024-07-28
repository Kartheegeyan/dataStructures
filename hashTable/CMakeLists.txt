add_library(hashTable STATIC src/hashTable.cpp)
target_include_directories(hashTable PUBLIC include)
target_link_libraries(hashTable PUBLIC dataStruct_utils)

# Coding problem 1: items in common
add_executable(iteminCommon src/itemInCommon.cpp)
# Coding problem 2: Find duplicates
add_executable(findDuplicates src/findDuplicates.cpp)