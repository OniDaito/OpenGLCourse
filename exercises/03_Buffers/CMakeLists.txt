##########################################################
# CMakeLists for the Third Exercise - Buffers

cmake_minimum_required (VERSION 2.8) 
project (03_Buffers) 

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
  add_executable (03_Buffers
    ${SOURCE_FILES} 
  )

  add_custom_command(TARGET 03_Buffers POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_CURRENT_BINARY_DIR}/../../$<CONFIGURATION>/OpenGLCourse.dll"
        $<TARGET_FILE_DIR:03_Buffers>)


elseif(_OPENGLCOURSE_OSX)
  OPENGLCOURSE_bundler()

else()

endif()


