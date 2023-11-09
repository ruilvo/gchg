# SPDX-License-Identifier: Apache-2.0
#
# Gregorian Calendar [Static] HTML [Page] Generator
#
# SPDX-FileCopyrightText: 2023 Rui Oliveira <ruimail24@gmail.com>

target_sources(
  gchg_lib
  PUBLIC FILE_SET
         HEADERS
         FILES
         test_api.hpp
         years.hpp
         weeks.hpp
         months.hpp
         days.hpp
         table.hpp
         html.hpp)
