# SPDX-License-Identifier: Apache-2.0
#
# Gregorian Calendar [Static] HTML [Page] Generator
#
# SPDX-FileCopyrightText: 2023 Rui Oliveira <ruimail24@gmail.com>

# Cxxopts is a header-only, lightweight C++ command line option parser library.
# Cxxopts is MIT licensed.

FetchContent_Declare(
  cxxopts
  GIT_REPOSITORY https://github.com/jarro2783/cxxopts.git
  GIT_TAG "v3.1.1"
  FIND_PACKAGE_ARGS)

FetchContent_MakeAvailable(cxxopts)
