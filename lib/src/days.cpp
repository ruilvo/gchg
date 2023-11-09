/*
 * SPDX-License-Identifier: Apache-2.0
 *
 * Gregorian Calendar [Static] HTML [Page] Generator
 *
 * SPDX-FileCopyrightText: 2023 Rui Oliveira <ruimail24@gmail.com>
 */

#include "gchg/days.hpp"

namespace gchg
{

GCHG_API unsigned int ordinal_day_from_date(unsigned int year, Month month, unsigned int day)
{
    unsigned int ordinal_day = 0;

    for (Month current_month = Month::January; current_month < month;
         current_month = static_cast<Month>(static_cast<unsigned int>(current_month) + 1))
    {
        ordinal_day += days_in_month(year, current_month);
    }

    ordinal_day += day;

    return ordinal_day;
}

} // namespace gchg
