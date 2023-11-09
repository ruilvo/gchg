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
#include "gchg/test_api.hpp"

namespace gchg
{

namespace impl::disparate_variation
{

/**
 * As required by the `get_weekday` algorithm, this maps March->1, .., February->12
 */
GCHG_TESTING_API unsigned int month_to_number(Month month);

} // namespace impl::disparate_variation

enum class Weekday
{
    Sunday,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,

    // This is a special value that can be used to represent the number of days in a week.
    Count
};

GCHG_API Weekday weekday_from_date(unsigned int year, Month month, unsigned int day);

GCHG_API unsigned int week_number_from_date(unsigned int year, Month month, unsigned int day);

} // namespace gchg
