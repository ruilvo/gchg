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

enum class Month : unsigned int
{
    January,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December,

    // This is a special value that can be used to represent the number of months
    // in a year.
    Count
};

GCHG_API unsigned int days_in_month(unsigned int year, Month month);

GCHG_API std::string month_name(Month month);

} // namespace gchg
