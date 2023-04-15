set (CMAKE_CXX_STANDARD 11)
set (CMAKE_BUILD_TYPE Debug)

file(GLOB SOURCES_FILES "*.cpp")
file(GLOB HEADERS_FILES "*.h")

# exe
add_executable(LeaRN ${SOURCES_FILES} ${HEADERS_FILES})

