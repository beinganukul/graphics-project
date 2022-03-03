#include"stick_figure.hpp"

int const SPRITESHEET_UP = 0;
int const SPRITESHEET_LEFT = 1;
int const SPRITESHEET_RIGHT = 2;
int const SPRITESHEET_DOWN = 3;

StickFigure:: StickFigure(): m_spritesheet("spritesheet.bmp", 4, 9){
    m_spritesheet.select_sprite(0, 0);
    m_position.x = 0;
    jhyappa = Mix_LoadWAV("jhyappa.wav");
    m_position.y = 0;
    m_position.w = 22;
    m_position.h = 43;

    m_x = 0.0;
    m_y = 0.0;
    m_direction = Direction::NONE;
    m_spritesheet_column = 0;
     
}

void StickFigure:: update(double delta_time) {
    switch(m_direction) {
        case Direction:: NONE:
            m_x += 0.0;
            m_y += 0.0;
            break;
        case Direction::UP:
            m_y = m_y -(500.0 *delta_time);
            m_spritesheet.select_sprite(m_spritesheet_column, SPRITESHEET_UP);
            break;
        case Direction::DOWN:
            m_y = m_y +(500.0 *delta_time);
            m_spritesheet.select_sprite(m_spritesheet_column, SPRITESHEET_DOWN);
            break;
        case Direction::LEFT:
            m_x = m_x -(500.0 *delta_time);
            m_spritesheet.select_sprite(m_spritesheet_column, SPRITESHEET_LEFT);
            break;
        case Direction::RIGHT:
            m_x = m_x +(500.0 *delta_time);
            m_spritesheet.select_sprite(m_spritesheet_column, SPRITESHEET_RIGHT);
            break;
    }
    if(detach == 0) {
        m_position.x = m_x; //m_x is character xposition
        m_position.y = m_y; //m_y is character yposition
        rxmi = m_x-11-25;
        rxma = m_x+11-25;
        rymi = m_y-11+25;
        ryma = m_y+11+25;
    }
    if((xmouse >= rxmi && xmouse <= rxma) && (ymouse >= rymi && ymouse <= ryma)) {
        m_position.x = xmouse; //xmouse is mouse x position
        m_position.y = ymouse; //yomouse is mouse y postion
        m_direction = Direction::NONE;
        flag = 2;
        detach = 1;
        if(playjhyappa == 1) {
            printf("This is working now");
            playajayajhyappa();
            playjhyappa = 0;
        }
    }
    if(m_x > 1280 || m_y > 720) {
        printf("Chor wins");
        flag = 1;
    }
    //printf("%d, %d\n", m_position.x, m_position.y);
    printf("%d, %d\n", xmouse, ymouse);

    m_spritesheet_column++;

    if(m_spritesheet_column > 8)
        m_spritesheet_column = 1;
}

void StickFigure:: playajayajhyappa() {
    Mix_PlayChannel(-2, jhyappa, -1);
}
void StickFigure:: draw(SDL_Surface *window_surface) {
    if(flag == 0) { // normal render
        m_spritesheet.draw_selected_sprite(window_surface, &m_position);
    }
    else if(flag == 1) { // chor wins
        m_spritesheet.draw_winner(window_surface, "chorwins.bmp");
    }
    else { // policewins
        m_spritesheet.draw_winner(window_surface, "policewins.bmp");
    }
    SDL_Delay(20);
}

void StickFigure:: handle_events(SDL_Event const &event) {
    SDL_GetMouseState(&xmouse, &ymouse);
    switch(event.type) {
        case SDL_KEYDOWN:
            Uint8 const *keys = SDL_GetKeyboardState(nullptr);

            if(keys[SDL_SCANCODE_W] == 1)
                m_direction = Direction::UP;
            else if(keys[SDL_SCANCODE_A] == 1)
                m_direction = Direction::LEFT;
            else if(keys[SDL_SCANCODE_D] == 1)
                m_direction = Direction::RIGHT;
            else if(keys[SDL_SCANCODE_S] == 1)
                m_direction = Direction::DOWN;
            else if(keys[SDL_SCANCODE_SPACE] == 1)
                m_direction = Direction::NONE;
            break;
    }
}
