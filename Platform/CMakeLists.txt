IF (CMAKE_SYSTEM_NAME MATCHES "Windows") 
    add_subdirectory(Windows)
ELSE ()
    add_subdirectory(Empty)
ENDIF()