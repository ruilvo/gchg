/*
 * SPDX-License-Identifier: Apache-2.0
 *
 * Gregorian Calendar [Static] HTML [Page] Generator
 *
 * SPDX-FileCopyrightText: 2023 Rui Oliveira <ruimail24@gmail.com>
 */

#pragma once

#include "gchg/api.h"

namespace gchg
{

GCHG_API bool is_leap_year(unsigned int year);

GCHG_API unsigned int weeks_in_year(unsigned int year);

} // namespace gchg
