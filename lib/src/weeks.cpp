/*
 * SPDX-License-Identifier: Apache-2.0
 *
 * Gregorian Calendar [Static] HTML [Page] Generator
 *
 * SPDX-FileCopyrightText: 2023 Rui Oliveira <ruimail24@gmail.com>
 */

#include "gchg/weeks.hpp"

#include "gchg/days.hpp"
#include "gchg/years.hpp"

namespace gchg
{

namespace impl::disparate_variation
{

GCHG_TESTING_API unsigned int month_to_number(Month month)
{
    constexpr auto month_count = static_cast<unsigned int>(Month::Count);

    const unsigned int shift = month_count - 1;
    auto month_number = (static_cast<unsigned int>(month) + shift) % month_count;
    // Special case for February (caught in testing!)
    if (month_number == 0)
    {
        month_number = month_count;
    }
    return month_number;
}

} // namespace impl::disparate_variation

GCHG_API Weekday weekday_from_date(unsigned int year, Month month, unsigned int day)
{
    // Let's use
    // https://en.wikipedia.org/wiki/Determination_of_the_day_of_the_week#Disparate_variation
    // to compute the weekday
    const int effective_year = static_cast<int>(month <= Month::February ? year - 1 : year);
    const int century = effective_year / 100;
    const int year_of_century = effective_year % 100;
    const int shifted_month = static_cast<int>(impl::disparate_variation::month_to_number(month));

    const int parcel1 = static_cast<int>(day);
    const int parcel2 = static_cast<int>(2.6 * shifted_month - 0.2);
    const int parcel3 = year_of_century;
    const int parcel4 = year_of_century / 4;
    const int parcel5 = century / 4;
    const int parcel6 = 2 * century;

    const int parcel_sum = parcel1 + parcel2 + parcel3 + parcel4 + parcel5 - parcel6;

    const int days_in_week = static_cast<int>(Weekday::Count);

    // Modulo operator in C++ is not the same as in mathematics.
    // This supports negative numbers.
    const int day_of_week = (parcel_sum % days_in_week + days_in_week) % days_in_week;

    return static_cast<Weekday>(day_of_week);
}

GCHG_API unsigned int week_number_from_date(unsigned int year, Month month, unsigned int day)
{
    // Let's use
    // https://en.wikipedia.org/wiki/ISO_week_date#Calculating_the_week_number_from_an_ordinal_date
    // to compute the week number.
    const auto ordinal_day = ordinal_day_from_date(year, month, day);

    const auto weekday = weekday_from_date(year, month, day);

    // In the international standard ISO 8601, Monday is treated as the first day of the week, and
    // as day one.
    // Compared to our enum, we have to map Sunday to 7, instead of 0.
    const auto corrected_weekday_number =
        weekday == Weekday::Sunday ? 7U : static_cast<unsigned int>(weekday);

    const unsigned int week_number = (ordinal_day + 10U - corrected_weekday_number) / 7U;
    const unsigned int weeks_in_this_year = weeks_in_year(year);

    if (week_number < 1U)
    {
        // It's the last week of the previous year
        return weeks_in_year(year - 1);
    }
    if (week_number > weeks_in_this_year)
    {
        // It's the first week of the next year
        return 1U;
    }
    return week_number;
}

} // namespace gchg
