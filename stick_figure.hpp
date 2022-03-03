#pragma once
#include<SDL2/SDL.h>
#include<SDL2/SDL_mixer.h>
#include"spritesheet.hpp"
class StickFigure {
    public:
        StickFigure();
        ~StickFigure() = default;

        void handle_events(SDL_Event const &event);
        
        void update(double delta_time);
        void draw(SDL_Surface *window_surface);
        void playajayajhyappa();
        enum class Direction {
            NONE, UP, DOWN, LEFT, RIGHT 
        };
        int flag = 0, playjhyappa = 1;
        Mix_Chunk *jhyappa;
    private:
        Direction m_direction;
        Spritesheet m_spritesheet;
        SDL_Rect m_position;
        int m_spritesheet_column;
        double m_x;
        double m_y;
        int xmouse, ymouse;
        int rxmi, rxma, rymi, ryma;
        int detach = 0;
};
