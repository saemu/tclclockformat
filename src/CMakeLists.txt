
set( SRCS
     main.cpp )

add_executable( tclclockformat )
target_sources( tclclockformat PRIVATE ${SRCS} )
target_link_libraries( tclclockformat PRIVATE compiler_settings TCL::TCL )
