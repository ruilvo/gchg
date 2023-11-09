# SPDX-License-Identifier: Apache-2.0
#
# Gregorian Calendar [Static] HTML [Page] Generator
#
# SPDX-FileCopyrightText: 2023 Rui Oliveira <ruimail24@gmail.com>

add_executable(gchg_app)

target_sources(gchg_app PRIVATE main.cpp)

target_link_libraries(gchg_app PRIVATE gchg_lib cxxopts::cxxopts)
