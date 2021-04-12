/***
  This file is adapted from a part of PulseAudio.

  Copyright 2004-2006 Lennart Poettering
  Copyright (C) 2020 UBports foundation
  Author: Ratchanan Srirattanamet

  PulseAudio is free software; you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published
  by the Free Software Foundation; either version 2.1 of the License,
  or (at your option) any later version.

  PulseAudio is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with PulseAudio; if not, see <http://www.gnu.org/licenses/>.
***/

/* These 2 files have its own header guard. */
#include <pulsecore/core.h>
#include <pulsecore/module.h>

/* Check if we're defining a module (usually defined via compiler flags) and 
   that pa__init has not been defined somewhere else (be it a modern module.h
   or other symdef file). This allows this file to not require an explicit
   header guard and be compatible with a modern PulseAudio. */
#if defined(PA_MODULE_NAME) && !defined(pa__init)

/* Jump through some double-indirection hoops to get PA_MODULE_NAME substituted before the concatenation */
#define _MACRO_CONCAT1(a, b) a ## b
#define _MACRO_CONCAT(a, b) _MACRO_CONCAT1(a, b)

#define pa__init _MACRO_CONCAT(PA_MODULE_NAME, _LTX_pa__init)
#define pa__done _MACRO_CONCAT(PA_MODULE_NAME, _LTX_pa__done)
#define pa__get_author _MACRO_CONCAT(PA_MODULE_NAME, _LTX_pa__get_author)
#define pa__get_description _MACRO_CONCAT(PA_MODULE_NAME, _LTX_pa__get_description)
#define pa__get_usage _MACRO_CONCAT(PA_MODULE_NAME, _LTX_pa__get_usage)
#define pa__get_version _MACRO_CONCAT(PA_MODULE_NAME, _LTX_pa__get_version)
#define pa__get_deprecated _MACRO_CONCAT(PA_MODULE_NAME, _LTX_pa__get_deprecated)
#define pa__load_once _MACRO_CONCAT(PA_MODULE_NAME, _LTX_pa__load_once)
#define pa__get_n_used _MACRO_CONCAT(PA_MODULE_NAME, _LTX_pa__get_n_used)

int pa__init(pa_module*m);
void pa__done(pa_module*m);
int pa__get_n_used(pa_module*m);

const char* pa__get_author(void);
const char* pa__get_description(void);
const char* pa__get_usage(void);
const char* pa__get_version(void);
const char* pa__get_deprecated(void);
bool pa__load_once(void);
#endif /* defined(PA_MODULE_NAME) && !defined(pa__init) */
