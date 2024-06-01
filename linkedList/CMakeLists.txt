add_library(ll_constructor src/linkedList_constructor.cpp)
target_include_directories(ll_constructor PUBLIC include)
target_link_libraries(ll_constructor PUBLIC dataStruct_utils)

# add_executable(middleNode src/findMiddleNode.cpp)
# add_executable(hasLoop src/hasloop.cpp)
# add_executable(kthNode src/kthNodefromEnd.cpp)

