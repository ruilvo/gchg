/*
 * SPDX-License-Identifier: Apache-2.0
 *
 * Gregorian Calendar [Static] HTML [Page] Generator
 *
 * SPDX-FileCopyrightText: 2023 Rui Oliveira <ruimail24@gmail.com>
 */

#include "gchg/years.hpp"

#include "doctest/doctest.h"

using namespace gchg;

TEST_CASE("Test interesting leap years")
{
    // Thanks https://kalender-365.de/leap-years.php
    CHECK(is_leap_year(1804) == true);
    CHECK(is_leap_year(1808) == true);
    CHECK(is_leap_year(1812) == true);
    CHECK(is_leap_year(1816) == true);
    CHECK(is_leap_year(1944) == true);
    CHECK(is_leap_year(1948) == true);
    CHECK(is_leap_year(1952) == true);
    CHECK(is_leap_year(1956) == true);
    CHECK(is_leap_year(1960) == true);
    CHECK(is_leap_year(1964) == true);
    CHECK(is_leap_year(1968) == true);
    CHECK(is_leap_year(1972) == true);
    CHECK(is_leap_year(1976) == true);
    CHECK(is_leap_year(1980) == true);
    CHECK(is_leap_year(1984) == true);
    CHECK(is_leap_year(1988) == true);
    CHECK(is_leap_year(1992) == true);
    CHECK(is_leap_year(1996) == true);
    CHECK(is_leap_year(2000) == true); // This is a special case
    CHECK(is_leap_year(2004) == true);
    CHECK(is_leap_year(2008) == true);
    CHECK(is_leap_year(2012) == true);
    CHECK(is_leap_year(2016) == true);
    CHECK(is_leap_year(2020) == true);
    CHECK(is_leap_year(2024) == true);
    CHECK(is_leap_year(2028) == true);
    CHECK(is_leap_year(2032) == true);
    CHECK(is_leap_year(2396) == true);
    CHECK(is_leap_year(2400) == true); // This is a special case
}

TEST_CASE("Test interesting non-leap years")
{
    CHECK(is_leap_year(1998) == false);
    CHECK(is_leap_year(1999) == false);
    CHECK(is_leap_year(2001) == false);
    CHECK(is_leap_year(1900) == false); // This is a special case
    CHECK(is_leap_year(2100) == false); // This is a special case
}

TEST_CASE("Test the number of weeks in some years")
{
    CHECK(weeks_in_year(2023) == 52);
    CHECK(weeks_in_year(2022) == 52);
    CHECK(weeks_in_year(2020) == 53);
}
