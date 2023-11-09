# SPDX-License-Identifier: Apache-2.0
#
# Gregorian Calendar [Static] HTML [Page] Generator
#
# SPDX-FileCopyrightText: 2023 Rui Oliveira <ruimail24@gmail.com>

target_sources(gchg_lib PUBLIC FILE_SET HEADERS BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(gchg)
