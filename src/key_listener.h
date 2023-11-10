#pragma once

#include <SDL.h>
#include <vector>


/**
 * @brief Something that should react to a key press
 * 
 */
class KeyListener {
public:
    static void register_listener(KeyListener* listener);

    static void notify_listeners(SDL_Event &event);

    virtual void on_key_event(SDL_Event &event) = 0;

private:
    inline static std::vector<KeyListener*> key_listeners;
};
