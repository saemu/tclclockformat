
add_library( compiler_settings INTERFACE )

target_compile_features( compiler_settings INTERFACE cxx_std_14 )

target_compile_options( compiler_settings INTERFACE
                        $<$<CXX_COMPILER_ID:MSVC>:/W4;/WX>
                        $<$<CXX_COMPILER_ID:GNU,Clang,AppleClang>:-Wall;-Wextra;-fstack-protector-all>
                        $<$<CXX_COMPILER_ID:GNU,Clang,AppleClang>:$<$<CONFIG:Debug>:-g;-O0;-fno-inline>>
                        )

option( ENABLE_COVERAGE "Enable coverage reporting for gcc/clang" OFF )

if( ENABLE_COVERAGE )
    target_compile_options( compiler_settings INTERFACE
                            $<$<CXX_COMPILER_ID:GNU,Clang,AppleClang>:--coverage> )
    target_link_libraries( compiler_settings INTERFACE
                           $<$<CXX_COMPILER_ID:GNU,Clang,AppleClang>:--coverage> )
endif()
