#include "graphics.h"
#define LOAD_IMAGE_MAX 256

SDL_Surface *screen = NULL;
SDL_Surface *loadedImages[LOAD_IMAGE_MAX];

int graphics_init(lua_State *L) {
	SDL_Init(SDL_INIT_EVERYTHING);

	int width = luaL_checkint(L, 1);
	int height = luaL_checkint(L, 2);
	int bpp = luaL_checkint(L, 3);

	screen = SDL_SetVideoMode(width, height, bpp, SDL_SWSURFACE);

	memset(loadedImages, 0, sizeof(SDL_Surface*) * LOAD_IMAGE_MAX);

	return 0;
}

int graphics_loadImage(lua_State *L) {
	const char *filename = luaL_checkstring(L, 1);
	SDL_Surface *loadedImage = NULL;
	SDL_Surface *optimizedImage = NULL;
	int imageIndex;

	loadedImage = IMG_Load(filename);

	if (loadedImage != NULL) {
		optimizedImage = SDL_DisplayFormat(loadedImage);
		SDL_FreeSurface(loadedImage);

		for (imageIndex = 0; imageIndex < LOAD_IMAGE_MAX; imageIndex++) {
			if (loadedImages[imageIndex] == NULL) {
				loadedImages[imageIndex] = optimizedImage;
				break;
			}
		}
		assert(imageIndex < LOAD_IMAGE_MAX);
	}
	lua_pushinteger(L, imageIndex);
	return 1;
}

int graphics_drawImage(lua_State *L) {
	int imageIndex = luaL_checkint(L, 1);
	assert(imageIndex < LOAD_IMAGE_MAX);
	SDL_Surface *image = loadedImages[imageIndex];
	SDL_BlitSurface(image, NULL, screen, NULL);
	return 0;
}

int graphics_show(lua_State *L) {
	SDL_Flip(screen); 
	return 0;
}

void graphics_register(lua_State *L) {
	luaL_Reg to_register[] = {
		{"init", graphics_init},
		{"loadImage", graphics_loadImage},
		{"drawImage", graphics_drawImage},
		{"show", graphics_show},
		{NULL, NULL}
	};

	luaL_register(L, "graphics", to_register);
}

