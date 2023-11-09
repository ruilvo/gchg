/*
 * SPDX-License-Identifier: Apache-2.0
 *
 * Gregorian Calendar [Static] HTML [Page] Generator
 *
 * SPDX-FileCopyrightText: 2023 Rui Oliveira <ruimail24@gmail.com>
 */

#include "gchg/weeks.hpp"

#include "doctest/doctest.h"

using namespace gchg;

TEST_CASE("Check whether the mapping for disparate variation works")
{
    CHECK(impl::disparate_variation::month_to_number(Month::March) == 1);
    CHECK(impl::disparate_variation::month_to_number(Month::April) == 2);
    CHECK(impl::disparate_variation::month_to_number(Month::May) == 3);
    CHECK(impl::disparate_variation::month_to_number(Month::June) == 4);
    CHECK(impl::disparate_variation::month_to_number(Month::July) == 5);
    CHECK(impl::disparate_variation::month_to_number(Month::August) == 6);
    CHECK(impl::disparate_variation::month_to_number(Month::September) == 7);
    CHECK(impl::disparate_variation::month_to_number(Month::October) == 8);
    CHECK(impl::disparate_variation::month_to_number(Month::November) == 9);
    CHECK(impl::disparate_variation::month_to_number(Month::December) == 10);
    CHECK(impl::disparate_variation::month_to_number(Month::January) == 11);
    CHECK(impl::disparate_variation::month_to_number(Month::February) == 12);
}

TEST_CASE("Check days of the week")
{
    CHECK(weekday_from_date(2023, Month::October, 13) == Weekday::Friday);
    CHECK(weekday_from_date(2023, Month::October, 14) == Weekday::Saturday);
    CHECK(weekday_from_date(2023, Month::October, 15) == Weekday::Sunday);
    CHECK(weekday_from_date(2023, Month::October, 16) == Weekday::Monday);
    CHECK(weekday_from_date(2020, Month::February, 29) == Weekday::Saturday);
    CHECK(weekday_from_date(2020, Month::March, 1) == Weekday::Sunday);
    CHECK(weekday_from_date(2020, Month::May, 1) == Weekday::Friday);
}

TEST_CASE("Check week number from date")
{
    CHECK(week_number_from_date(2021, Month::January, 1) == 53);
    CHECK(week_number_from_date(2021, Month::December, 31) == 52);
    CHECK(week_number_from_date(2022, Month::January, 1) == 52);
    CHECK(week_number_from_date(2022, Month::January, 2) == 52);
    CHECK(week_number_from_date(2022, Month::January, 3) == 1);
}
