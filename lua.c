#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

#include "graphics.h"

int main(int argc, char** argv) {
	lua_State *L = lua_open();
	luaL_openlibs(L);

	graphics_register(L);

	if (luaL_loadfile(L, "startup.lua") == 0)
		lua_call(L, 0, 0);
	else
		fprintf(stderr, "Unable to load startup.lua");

	lua_close(L);
	return 0;
}
