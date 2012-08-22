#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
#include <assert.h>


void graphics_register(lua_State* L);

#endif
