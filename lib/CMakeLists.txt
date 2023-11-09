# SPDX-License-Identifier: Apache-2.0
#
# Gregorian Calendar [Static] HTML [Page] Generator
#
# SPDX-FileCopyrightText: 2023 Rui Oliveira <ruimail24@gmail.com>

# It is not good CMake practice to define libraries as STATIC or SHARED directly.
# Rather, one should usually honor the BUILD_SHARED_LIBS variable and use the add_library() command
# without the TYPE argument. This allows the user to build both static and shared libraries with the
# same build files, by simply setting BUILD_SHARED_LIBS to true or false.
# HOWEVER, in this case, we want to build a static library, as its own application is with the
# accompanying executable, and this eases deployment.
add_library(gchg_lib STATIC)

set_target_properties(
  gchg_lib
  PROPERTIES DEFINE_SYMBOL "GCHG_EXPORTING" #
             VERSION "${PROJECT_VERSION}" #
             SOVERSION "${PROJECT_VERSION_MAJOR}")

# Export header
set(GCHG_EXPORT_HEADER_FILE "${GCHG_INCLUDE_DIR}/api.h")
generate_export_header(
  gchg_lib
  BASE_NAME
  "GCHG"
  EXPORT_MACRO_NAME
  "GCHG_API"
  EXPORT_FILE_NAME
  ${GCHG_EXPORT_HEADER_FILE})
target_sources(
  gchg_lib
  PUBLIC #
         FILE_SET HEADERS #
         BASE_DIRS ${CMAKE_CURRENT_BINARY_DIR}/include)
target_sources(
  gchg_lib #
  PUBLIC #
         FILE_SET HEADERS #
         FILES ${CMAKE_CURRENT_BINARY_DIR}/${GCHG_EXPORT_HEADER_FILE})

add_subdirectory(src)
add_subdirectory(include)
