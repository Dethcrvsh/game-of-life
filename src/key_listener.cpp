#include "key_listener.h"
#include <iostream>


void KeyListener::register_listener(KeyListener* listener) {
    key_listeners.push_back(listener);

}

void KeyListener::notify_listeners(SDL_Event &event) {
    for (KeyListener* listener : key_listeners) {
        listener->on_key_event(event);
    }
}