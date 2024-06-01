add_executable(tree_sample tree_sample.cpp)
target_link_libraries(tree_sample PRIVATE bst_constructor)

add_executable(dll_sample dll_sample.cpp)
target_link_libraries(dll_sample PUBLIC dll_constructor)

add_executable(linked_list_sample ll_sample.cpp)
target_link_libraries(linked_list_sample PUBLIC ll_constructor)

# add_executable(dll_sample dll_sample.cpp)
# target_link_libraries(dll_sample PUBLIC dll_constructor)