/*
 * SPDX-License-Identifier: Apache-2.0
 *
 * Gregorian Calendar [Static] HTML [Page] Generator
 *
 * SPDX-FileCopyrightText: 2023 Rui Oliveira <ruimail24@gmail.com>
 */

#include "gchg/table.hpp"

#include "gchg/months.hpp"
#include "gchg/weeks.hpp"

#include <cstddef>
#include <string>
#include <vector>

namespace gchg
{

GCHG_API std::vector<std::vector<std::string>> table_rows_for_month(unsigned int year, Month month)
{
    constexpr size_t row_size = static_cast<size_t>(Weekday::Count) + 1;

    // We will be returning a vector of vectors of strings.
    std::vector<std::vector<std::string>> rows;

    // First, we have to handle the first row, which is special.

    // We start by creating the first row.
    std::vector<std::string> first_row(row_size);

    // The first element of the first row is the week number of the first day of the month.
    const auto week_number_of_day_one = week_number_from_date(year, month, 1);
    first_row[0] = std::to_string(week_number_of_day_one);

    // The first row needs to be padded with empty cells to account for the weekday of the first day
    // of the month.
    //
    // We get the weekday of the first day of the month.
    const auto weekday_of_day_one = weekday_from_date(year, month, 1);

    // The ISO 8601 standard defines the first day of the week as Monday.
    // In our enum, Sunday is the first value, so we need to take that into account.
    // In the following math, if we get -1, we need to add 6 to get the correct index.
    int index_of_first_day =
        static_cast<int>(weekday_of_day_one) - static_cast<int>(Weekday::Monday);
    if (index_of_first_day == -1) // Sunday
    {
        index_of_first_day = row_size - 2; // -2 because we have a +1 down below
    }
    // But we must not forget that the first column is reserved for the week number.
    // So, we need to add 1 to the index.
    index_of_first_day += 1;

    // Now, we can fill the first row with empty cells up to the weekday of the first day of the
    // month.
    for (std::size_t i = 1; i < static_cast<std::size_t>(index_of_first_day); ++i)
    {
        first_row[i] = "";
    }

    // Now we can start filing...
    int current_day = 1;

    // First, with the actual first few days of the month.
    for (auto i = static_cast<std::size_t>(index_of_first_day); i < row_size; ++i)
    {
        first_row[i] = std::to_string(current_day);
        ++current_day;
    }

    // We don't need the row anymore, so we can move it to the vector.
    rows.emplace_back(std::move(first_row));

    // Then, the rest of the rows.
    const auto days_in_this_month = days_in_month(year, month);

    while (current_day <= static_cast<int>(days_in_this_month))
    {
        std::vector<std::string> row(row_size);

        // First column is the week number.
        const auto current_week_number = week_number_from_date(year, month, current_day);
        row[0] = std::to_string(current_week_number);

        for (std::size_t i = 1; i < row_size; ++i)
        {
            if (current_day <= static_cast<int>(days_in_this_month))
            {
                row[i] = std::to_string(current_day);
                ++current_day;
            }
            // We have reached the end of the month, but we still need to fill the row.
            else
            {
                row[i] = "";
            }
        }

        rows.emplace_back(std::move(row));
    }

    return rows;
}

GCHG_API std::string html_table_for_moth(unsigned int year, Month month)
{
    // First, we get the table rows.
    const auto rows = table_rows_for_month(year, month);

    // Then, we generate the HTML.
    std::string html = "<table>\n";

    // We put in a nice header with the name of the month
    html += "<thead>";
    html += "  <tr>\n";
    html += R"(    <th colspan="8" class="monthCell">)" + month_name(month) + "</th>\n";
    html += "  </tr>\n";
    // Also the labels for the weekdays.
    html += "  <tr>\n";
    html += "    <th class=\"firstCell\">Wk</th>\n";
    html += "    <th class=\"firstCell\">Mo</th>\n";
    html += "    <th class=\"firstCell\">Tu</th>\n";
    html += "    <th class=\"firstCell\">We</th>\n";
    html += "    <th class=\"firstCell\">Th</th>\n";
    html += "    <th class=\"firstCell\">Fr</th>\n";
    html += "    <th class=\"saCell\">Sa</th>\n";
    html += "    <th class=\"suCell\">Su</th>\n";
    html += "  </tr>\n";
    html += "</thead>\n";

    // Then, we generate the body.
    html += "<tbody>\n";

    for (const auto &row : rows)
    {
        html += "  <tr>\n";

        for (size_t i{0}; i < row.size(); ++i)
        {
            if (i == 0) // First column is the week number
            {
                html += "    <th class=\"firstCell\">" + row[i] + "</th>\n";
            }
            else if (i == row.size() - 2) // Second to last column is Saturday
            {
                html += "    <td class=\"saCell\">" + row[i] + "</td>\n";
            }
            else if (i == row.size() - 1) // Last column is Sunday
            {
                html += "    <td class=\"suCell\">" + row[i] + "</td>\n";
            }
            else
            {
                html += "    <td>" + row[i] + "</td>\n";
            }
        }

        html += "  </tr>\n";
    }

    html += "</tbody>\n";
    html += "</table>\n";

    return html;
}

} // namespace gchg
