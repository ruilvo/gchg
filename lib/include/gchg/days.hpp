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

namespace gchg
{

GCHG_API unsigned int ordinal_day_from_date(unsigned int year, Month month, unsigned int day);

} // namespace gchg
