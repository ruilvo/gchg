/*
 * SPDX-License-Identifier: Apache-2.0
 *
 * Gregorian Calendar [Static] HTML [Page] Generator
 *
 * SPDX-FileCopyrightText: 2023 Rui Oliveira <ruimail24@gmail.com>
 */

#include "gchg/months.hpp"

#include "gchg/years.hpp"

#include <stdexcept>

namespace gchg
{

GCHG_API unsigned int days_in_month(unsigned int year, Month month)
{
    switch (month)
    {
    case Month::January:
        return 31;
    case Month::February:
        return is_leap_year(year) ? 29 : 28;
    case Month::March:
        return 31;
    case Month::April:
        return 30;
    case Month::May:
        return 31;
    case Month::June:
        return 30;
    case Month::July:
    case Month::August:
        return 31;
    case Month::September:
        return 30;
    case Month::October:
        return 31;
    case Month::November:
        return 30;
    case Month::December:
        return 31;
    default:
        throw std::invalid_argument("Invalid month");
    }
};

GCHG_API std::string month_name(Month month)
{
    // Makes you wish for smart enums, doesn't it?
    switch (month)
    {
    case Month::January:
        return "January";
    case Month::February:
        return "February";
    case Month::March:
        return "March";
    case Month::April:
        return "April";
    case Month::May:
        return "May";
    case Month::June:
        return "June";
    case Month::July:
        return "July";
    case Month::August:
        return "August";
    case Month::September:
        return "September";
    case Month::October:
        return "October";
    case Month::November:
        return "November";
    case Month::December:
        return "December";
    default:
        throw std::invalid_argument("Invalid month");
    }
};

} // namespace gchg
