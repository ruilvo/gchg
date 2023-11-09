/*
 * SPDX-License-Identifier: Apache-2.0
 *
 * Gregorian Calendar [Static] HTML [Page] Generator
 *
 * SPDX-FileCopyrightText: 2023 Rui Oliveira <ruimail24@gmail.com>
 */

#include "gchg/years.hpp"

#include "gchg/days.hpp"
#include "gchg/weeks.hpp"

namespace gchg
{

GCHG_API bool is_leap_year(unsigned int year)
{
    // Only years that are divisible by 4 can be leap years
    if (year % 4 != 0)
    {
        return false;
    }
    // Years that are divisible by 100 are not leap years, with the exception of years that are
    // divisible by 400
    if (year % 100 == 0)
    {
        return (year % 400) == 0;
    }
    // All other years are leap years
    return true;
}

GCHG_API unsigned int weeks_in_year(unsigned int year)
{
    // According to
    // https://en.wikipedia.org/wiki/ISO_week_date
    // "53 week years occur on all years that have Thursday as the 1st of January and on leap years
    // that start on Wednesday the 1st."

    // Let's use
    // https://en.wikipedia.org/wiki/ISO_week_date#Weeks_per_year
    // to compute the number of weeks in a year.

    const auto current_year_ends_on_thursday =
        weekday_from_date(year, Month::December, 31) == Weekday::Thursday;
    const auto previous_year_ends_on_wednesday =
        weekday_from_date(year - 1, Month::December, 31) == Weekday::Wednesday;

    return 52U + static_cast<unsigned int>(current_year_ends_on_thursday ||
                                           previous_year_ends_on_wednesday);
}

} // namespace gchg
