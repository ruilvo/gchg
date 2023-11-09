/*
 * SPDX-License-Identifier: Apache-2.0
 *
 * Gregorian Calendar [Static] HTML [Page] Generator
 *
 * SPDX-FileCopyrightText: 2023 Rui Oliveira <ruimail24@gmail.com>
 */

#pragma once

#include "gchg/api.h"
#include "gchg/months.hpp"

#include <string>
#include <vector>

namespace gchg
{

GCHG_API std::vector<std::vector<std::string>> table_rows_for_month(unsigned int year, Month month);

GCHG_API std::string html_table_for_moth(unsigned int year, Month month);

} // namespace gchg
