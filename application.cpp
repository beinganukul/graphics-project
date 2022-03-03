#include"application.hpp"


Application:: Application() {
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    chor = Mix_LoadMUS("chor.wav");
    jhyappa = Mix_LoadMUS("jhyappa.wav");
    aaryachor = Mix_LoadWAV("aaryachor.wav");
       m_window = SDL_CreateWindow("StickMan", SDL_WINDOWPOS_CENTERED, 
                                SDL_WINDOWPOS_CENTERED, 1280, 720, 0);
   
   if(!m_window) {
       std::cout << "Failed to create window" << std::endl;
       std::cout << "SDL2 Error:" << SDL_GetError() << std::endl;
       return;
   }

   m_window_surface = SDL_GetWindowSurface(m_window);

   if(!m_window_surface) {
       std::cout << "Failed to get window's surface" << std::endl;
       std::cout << "SDL2 Error:" << SDL_GetError() << std::endl;
       return;
   }
}

Application::~Application() {
    Mix_FreeMusic(chor);
    Mix_FreeMusic(jhyappa);
    SDL_FreeSurface(m_window_surface);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

void Application:: update(double delta_time) {
    m_stick_figure.update(delta_time);
}

void Application::draw() {
    SDL_FillRect(m_window_surface, NULL, SDL_MapRGB(m_window_surface->format, 255, 255, 255));
    m_stick_figure.draw(m_window_surface);
    SDL_UpdateWindowSurface(m_window);
}

void Application::loop() {
    Mix_PlayMusic(chor, -1);
    Mix_PlayChannel(-1, aaryachor, -1);
    bool keep_window_open = true;
    SDL_WarpMouseInWindow(m_window, 1279, 720);
    while(keep_window_open) {
        while(SDL_PollEvent(&m_window_event) > 0) {
            m_stick_figure.handle_events(m_window_event);
            switch(m_window_event.type) {
                case SDL_QUIT:
                    keep_window_open = false;
                    break;
            }
        }
        update(1.0/60.0);
        draw();
    }
}
