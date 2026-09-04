#pragma once

#include <cstdio>
#include <string_view>
#include <3ds/gdbhio_dev.h>

inline void gdbLogInit() {
#ifndef NDEBUG
    gdbHioDevInit();
    gdbHioDevRedirectStdStreams(false, false, true);
#endif
}

inline void gdbLog(const std::string_view msg) {
#ifndef NDEBUG
    fprintf(stderr, "%s", msg.data());
    fflush(stderr);
#endif
}

inline void gdbLogExit() {
#ifndef NDEBUG
    gdbHioDevExit();
#endif
}
