/*
 * SPDX-License-Identifier: Apache-2.0
 *
 * Gregorian Calendar [Static] HTML [Page] Generator
 *
 * SPDX-FileCopyrightText: 2023 Rui Oliveira <ruimail24@gmail.com>
 */

#include "gchg/html.hpp"

#include "cxxopts.hpp"

#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char *argv[])
try
{

    cxxopts::Options options("gchg", "Gregorian Calendar [Static] HTML [Page] Generator");

    // Arguments
    options.add_options() // -
        ("f,file-name", "File name of the output, including extension.",
         cxxopts::value<std::string>()) // -
        ("y,year", "Year (+-1) to generate the calendar for.", cxxopts::value<int>()) // -
        ("h,help", "Print usage");

    // Add the option to make file-name and year positional arguments.
    options.parse_positional({"file-name", "year"});
    options.positional_help("<file-name> <year>");
    options.show_positional_help();

    cxxopts::ParseResult arguments;

    try
    {
        arguments = options.parse(argc, argv);
    }
    catch (...)
    {
        std::cout << "Error parsing arguments.\n" << options.help() << "\n";
        return 1;
    }

    const auto help = options.help();

    if (arguments.count("help") != 0)
    {
        std::cout << help << "\n";
        return 0;
    }

    if (arguments.count("file-name") != 1)
    {
        std::cout << "A single file name is required.\n" << help << "\n";
        return 1;
    }

    if (arguments.count("year") != 1)
    {
        std::cout << "A single year is required.\n" << help << "\n";
        return 1;
    }

    const auto file_name = arguments["file-name"].as<std::string>();
    const auto year = arguments["year"].as<int>();

    std::cout << "File name: " << file_name << "\n";
    std::cout << "Year: " << year << "\n";

    std::cout << "Generating HTML...\n";
    std::string html = gchg::html_file(year);
    std::cout << "HTML generated.\n";

    std::cout << "Writing to file...\n";
    std::ofstream file(file_name);
    file << html;
    std::cout << "File written.\n";

    return 0;
}
catch (...)
{
    std::cout << "Unknown error.\n";
    return 1;
}
