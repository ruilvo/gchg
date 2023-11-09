/*
 * SPDX-License-Identifier: Apache-2.0
 *
 * Gregorian Calendar [Static] HTML [Page] Generator
 *
 * SPDX-FileCopyrightText: 2023 Rui Oliveira <ruimail24@gmail.com>
 */

#pragma once

#include "gchg/api.h"

#include <string>

namespace gchg
{

GCHG_API std::string html_for_year(unsigned int year);

GCHG_API std::string html_for_three_years(unsigned int year);

GCHG_API std::string html_file(unsigned int year);

} // namespace gchg
