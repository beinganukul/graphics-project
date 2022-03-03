#pragma once
#include<SDL2/SDL.h>
#include<SDL2/SDL_mixer.h>
#include<iostream>
#include<memory>
#include"stick_figure.hpp"
class Application {
    public:
        Application();
        ~Application();
        void loop();
        void update(double delta_time);
        void draw();
        Mix_Music *chor;
        Mix_Music *jhyappa;
        Mix_Chunk *aaryachor;
    private:
        StickFigure m_stick_figure;
    
        SDL_Window *m_window;
        SDL_Surface *m_window_surface;
        SDL_Event m_window_event;

};
