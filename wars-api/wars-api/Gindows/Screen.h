#pragma once

namespace gindows {
    class Screen : public Object {
    public:
        int x, y, width, height;

        Screen(int* rect); // probably some csl struct
    };

    static Screen* currentScreen;
    static Screen* GetCurrentScreen();
    static void SetCurrentScreen(Screen* screen);
}
