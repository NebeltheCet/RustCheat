#pragma once

/* Defines */
#define WIN32_LEAN_AND_MEAN /* This removes all rarely used Windows.h Features to reduce size. */

/* Visual Studio Includes */
#include <Windows.h>
#include <iostream>
#include <string>

/* External Includes */
#include "SDK/Detours/detours.h"
#pragma comment(lib, "SDK/Detours/detours.lib")

#include "Hooks/Hooks.hpp"