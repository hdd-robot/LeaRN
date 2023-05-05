set (CMAKE_CXX_STANDARD 11)
set (CMAKE_BUILD_TYPE Debug)
set (PROJECT_NAME LeaRN)

# Library target
add_library(matplotlib_cpp INTERFACE)
target_include_directories(matplotlib_cpp
  INTERFACE
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/examples>
  $<INSTALL_INTERFACE:include>
)
target_compile_features(matplotlib_cpp INTERFACE
  cxx_std_11
)
# TODO: Use `Development.Embed` component when requiring cmake >= 3.18
find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
target_link_libraries(matplotlib_cpp INTERFACE
  Python3::Python
  Python3::Module
)
find_package(Python3 COMPONENTS NumPy)
if(Python3_NumPy_FOUND)
  target_link_libraries(matplotlib_cpp INTERFACE
    Python3::NumPy
  )
else()
  target_compile_definitions(matplotlib_cpp INTERFACE WITHOUT_NUMPY)
endif()
install(
  TARGETS matplotlib_cpp
  EXPORT install_targets
)

# exe

file(GLOB SOURCES_FILES "*.cpp")
file(GLOB HEADERS_FILES "*.h")


add_executable(LeaRN ${SOURCES_FILES} ${HEADERS_FILES} )
target_link_libraries(LeaRN PRIVATE matplotlib_cpp)
