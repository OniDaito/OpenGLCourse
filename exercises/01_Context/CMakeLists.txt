##########################################################
# CMakeLists for the First exercise - Basic Contexts

cmake_minimum_required (VERSION 2.8) 
project (01_Context) 

set(SOURCE_FILES 
	app.cpp
)

include_directories(
  ${OPENGLCOURSE_INCLUDES}
  ${INCLUDES_SEARCH_PATHS}
  ${INCLUDES}
)

link_libraries( OpenGLCourse
${Boost_LIBRARIES} )

if (_OPENGLCOURSE_WIN32)
  SET(CMAKE_CXX_FLAGS "/MT /EHsc")
  add_executable (01_Context
    ${SOURCE_FILES} 
  )

add_custom_command(TARGET 01_Context POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_CURRENT_BINARY_DIR}/../../$<CONFIGURATION>/OpenGLCourse.dll"
        $<TARGET_FILE_DIR:01_Context>)


elseif(_OPENGLCOURSE_OSX)
  OPENGLCOURSE_bundler()

else()


endif()


