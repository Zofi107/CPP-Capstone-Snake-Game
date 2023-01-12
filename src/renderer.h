#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include <SDL2/SDL.h> 
#include <memory>
#include "snake.h"


class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void Render(Snake const snake, SDL_Point const &food);
  void UpdateWindowTitle(int score, int fps, float speed);

 private:
  struct sdl_deleter
  {
    void operator()(SDL_Window *p) const{
      SDL_DestroyWindow(p);
    }
    void operator()(SDL_Renderer *p) const{
      SDL_DestroyRenderer(p);
    }
  };
  
  std::unique_ptr<SDL_Window, sdl_deleter> _window;
  std::unique_ptr<SDL_Renderer, sdl_deleter> _renderer;
  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif