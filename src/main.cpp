#include <3ds.h>
#include "common/logging.hpp"

int main() {
    gfxInitDefault();
    consoleInit(GFX_TOP, nullptr);
    gdbLogInit();

    // gdbLog output is found in "Debug" Window -> "connect_to_gdb" Tab -> "Console" Tab after running "DebugApp"
    gdbLog("Hello World from GDB!\n");
    printf("Hello World from your emulator!\nPress START to exit!\n");

    while (aptMainLoop()) {
        hidScanInput();

        if (const u32 keys = hidKeysDown(); keys & KEY_START) {
            break;
        }

        gfxFlushBuffers();
        gfxSwapBuffers();
        gspWaitForVBlank();
    }

    gfxExit();
    gdbLogExit();
    return 0;
}
