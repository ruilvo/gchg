/*
 * SPDX-License-Identifier: Apache-2.0
 *
 * Gregorian Calendar [Static] HTML [Page] Generator
 *
 * SPDX-FileCopyrightText: 2023 Rui Oliveira <ruimail24@gmail.com>
 */

/*
 * For the sake of testing, we will make an API macro that exports the internal functions depending
 * on whether tests are enabled or not.
 */

#pragma once

#include "gchg/api.h"

#ifdef GCHG_TESTING
    #define GCHG_TESTING_API GCHG_API
#else
    #define GCHG_TESTING_API GCHG_NO_EXPORT
#endif
