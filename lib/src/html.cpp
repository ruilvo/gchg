/*
 * SPDX-License-Identifier: Apache-2.0
 *
 * Gregorian Calendar [Static] HTML [Page] Generator
 *
 * SPDX-FileCopyrightText: 2023 Rui Oliveira <ruimail24@gmail.com>
 */

#include "gchg/html.hpp"

#include "gchg/table.hpp"

namespace gchg
{

GCHG_API std::string html_for_year(unsigned int year)
{
    std::string html;

    for (unsigned int i = 0; i < static_cast<unsigned int>(Month::Count); ++i)
    {
        html += html_table_for_moth(year, static_cast<Month>(i));
    }

    return html;
}

GCHG_API std::string html_for_three_years(unsigned int year)
{
    std::string html;

    // Add the year number as a header
    for (unsigned int current_year = year - 1; current_year <= year + 1; ++current_year)
    {
        html += "<h2>" + std::to_string(current_year) + "</h2>\n";
        html += html_for_year(current_year);
    }

    return html;
}

GCHG_API std::string html_file(unsigned int year)
{
    std::string html;

    html += "<!DOCTYPE html>\n";
    html += "<html lang=\"en\">\n";
    html += "<head>\n";
    html += "<title>Gregorian Calendar</title>"; // No \n here because the raw string has one
    html += R"---(
<style>
  .monthCell {
    background-color: #ccffcc;
  }
  .firstCell {
    background-color: #e6e6e6;
  }
  .saCell {
    background-color: #ffffcc;
  }
  .suCell {
    background-color: #ffcc99;
  }
  table {
    border-collapse: collapse;
    margin-bottom: 10px;
  }
  table th, table td {
    border: 1px solid black;
    text-align: center;
  }
</style>
)---";
    html += "</head>\n";
    html += "<body>\n";
    html += "<h1>Gregorian Calendar</h1>\n";
    html += html_for_three_years(year);
    html += "</body>\n";
    html += "</html>\n";

    return html;
}

} // namespace gchg
