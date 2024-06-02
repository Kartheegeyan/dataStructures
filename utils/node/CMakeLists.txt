add_library(dataStruct_utils STATIC
    src/node.cpp 
    src/dll_node.cpp 
    src/bst_node.cpp 
    src/hashTable_node.cpp
)
target_include_directories(dataStruct_utils PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)