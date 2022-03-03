#pragma once

#include<SDL2/SDL.h>
#include"utilities.hpp"

class Spritesheet {
    public:
        Spritesheet(char const *path, int row, int column);
        ~Spritesheet();

        void select_sprite(int x, int y);
        void draw_selected_sprite(SDL_Surface *window_surface, SDL_Rect *position);
        void draw_winner(SDL_Surface *window_surface, char const *pathh);

    private:
        SDL_Rect m_clip;
        SDL_Surface *m_spritesheet_image;
        SDL_Surface *image_output;
};
