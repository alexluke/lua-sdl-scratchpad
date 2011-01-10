#include "graphics.h"

SDL_Surface* screen = NULL;

int graphics_init(lua_State* L) {
	SDL_Init(SDL_INIT_EVERYTHING);

	int width = luaL_checkint(L, 1);
	int height = luaL_checkint(L, 2);
	int bpp = luaL_checkint(L, 3);

	screen = SDL_SetVideoMode(width, height, bpp, SDL_SWSURFACE);

	return 0;
}

int graphics_loadImage(lua_State* L) {
	char* filename = luaL_checkstring(L, 1);
	SDL_Surface* loadedImage = NULL;
	SDL_Surface* optimizedImage = NULL;

	loadedImage = IMG_Load(filename);

	if (loadedImage != NULL) {
		optimizedImage = SDL_DisplayFormat(loadedImage);
		SDL_FreeSurface(loadedImage);
	}
	lua_pushnumber(L, (int)optimizedImage);
	return 1;
}

int graphics_drawImage(lua_State *L) {
	SDL_Surface* image = (SDL_Surface*)luaL_checkint(L, 1);
	SDL_BlitSurface(image, NULL, screen, NULL);
}

int graphics_show(lua_State* L) {
	SDL_Flip(screen); 
	return 0;
}

void graphics_register(lua_State* L) {
	luaL_Reg to_register[] = {
		{"init", graphics_init},
		{"loadImage", graphics_loadImage},
		{"drawImage", graphics_drawImage},
		{"show", graphics_show},
		{NULL, NULL}
	};

	luaL_register(L, "graphics", to_register);
}

