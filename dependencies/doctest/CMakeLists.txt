# SPDX-License-Identifier: Apache-2.0
#
# Gregorian Calendar [Static] HTML [Page] Generator
#
# SPDX-FileCopyrightText: 2023 Rui Oliveira <ruimail24@gmail.com>

# Doctest is a header-only C++ testing framework that is used to test the library.
# It is downloaded from GitHub and built as part of the build process.
# It is only downloaded if testing is enabled.
# Doctest is MIT licensed.

# Doctest is only used for testing, so it is only downloaded if testing is enabled
if(BUILD_TESTING)

  FetchContent_Declare(
    doctest
    GIT_REPOSITORY https://github.com/doctest/doctest.git
    GIT_TAG "v2.4.11"
    FIND_PACKAGE_ARGS)

  # Disable IPO temporarily for doctest, otherwise it will produce a policy CMP0069 warning
  set(CMAKE_INTERPROCEDURAL_OPTIMIZATION FALSE)

  # Disable installation of doctest
  set(DOCTEST_NO_INSTALL ON)

  FetchContent_MakeAvailable(doctest)

  # This makes doctest_discover_tests available, but seems to be broken.
  include(${doctest_SOURCE_DIR}/scripts/cmake/doctest.cmake)

endif()
