#pragma once
#ifndef _S_DEBUG_H
#define _S_DEBUG_H

#include <android\log.h>

#define ERROR(...) ((void)__android_log_print(ANDROID_LOG_ERROR, "SMOKE_ENGINE", __VA_ARGS__))
#define INFO(...) ((void)__android_log_print(ANDROID_LOG_DEBUG,  "SMOKE_ENGINE", __VA_ARGS__))

#endif

