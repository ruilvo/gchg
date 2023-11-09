# SPDX-License-Identifier: Apache-2.0
#
# Gregorian Calendar [Static] HTML [Page] Generator
#
# SPDX-FileCopyrightText: 2023 Rui Oliveira <ruimail24@gmail.com>

if(NOT BUILD_TESTING)
  return()
endif()

add_executable(gchg_tests)

target_sources(gchg_tests PRIVATE main.cpp years.cpp weeks.cpp)
target_link_libraries(gchg_tests PRIVATE doctest::doctest gchg_lib)

doctest_discover_tests(gchg_tests)
