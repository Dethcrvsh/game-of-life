#include "graphics/graphics_handler.h"
#include <iostream>
#include <unistd.h>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

const int MAX_FPS = 30;

GraphicsHandler* graphics_handler;

void handle_events() {
    SDL_Event ev;

    while(SDL_PollEvent(&ev) != 0) {
        switch(ev.type) {
            case SDL_QUIT:
                exit(0);
        }
    }
}

void loop() {
    Uint64 start_time = SDL_GetPerformanceCounter();

    handle_events();

    graphics_handler->draw_frame();

    Uint64 end_time = SDL_GetPerformanceCounter();
    float elapsed_time_ms = (end_time - start_time) / (float) SDL_GetPerformanceFrequency() * 1000.0f;
    // Cap the FPS
    SDL_Delay(floor((1.0f / MAX_FPS) * 1000.0f - elapsed_time_ms));
}

int main() {
    graphics_handler = new GraphicsHandler();

    #ifdef __EMSCRIPTEN__
    emscripten_set_main_loop(loop, 0, 1);
    #else
    while(true) {
        loop();
    }
    #endif
}
