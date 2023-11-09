# SPDX-License-Identifier: Apache-2.0
#
# Gregorian Calendar [Static] HTML [Page] Generator
#
# SPDX-FileCopyrightText: 2022 Rui Oliveira <ruimail24@gmail.com>

include_guard(GLOBAL)

include(CheckIPOSupported)

if(NOT GCHG_USE_LTO)
  return()
endif()

check_ipo_supported(RESULT IPO_SUPPORTED OUTPUT LTO_ERROR)
if(IPO_SUPPORTED)
  message(STATUS "IPO / LTO enabled")
  set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)
else()
  message(STATUS "IPO / LTO not supported: ${LTO_ERROR}")
endif()
