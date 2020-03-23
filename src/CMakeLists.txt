
set( SRCS
     main.cpp )

set( TARGET_NAME tclclockformat )
add_executable( ${TARGET_NAME} )
target_sources( ${TARGET_NAME} PRIVATE ${SRCS} )
target_link_libraries( ${TARGET_NAME} PRIVATE compiler_settings TCL::TCL )

file( INSTALL ${CMAKE_CURRENT_SOURCE_DIR}/library
      DESTINATION ${CMAKE_BINARY_DIR} )
