// SONIC ROBO BLAST 2
//-----------------------------------------------------------------------------
// Copyright (C) 2014-2016 by John "JTE" Muniz.
// Copyright (C) 2014-2024 by Sonic Team Junior.
//
// This program is free software distributed under the
// terms of the GNU General Public License, version 2.
// See the 'LICENSE' file for more details.
//-----------------------------------------------------------------------------
/// \file  lua_custombuild.c
/// \brief Currently only used for lua scripts to detect this build specifically

#include "doomdef.h"
#include "fastcmp.h"
#include "dehacked.h"
#include "deh_lua.h"
#include "lua_script.h"
#include "lua_libs.h"
#include "lua_custombuild.h"

boolean gks_complexlocaladdons = false;
INT32 GKS_PushGlobals(lua_State *L, const char *word)
{
    if (fastcmp(word,"gks_custombuild")) {
		lua_pushboolean(L, true);
		return 1;
    } else if (fastcmp(word, "gks_complexlocaladdons")) {
		lua_pushboolean(L, gks_complexlocaladdons);
		return 1;
	} else if (fastcmp(word, "gks_locallyloading")) {
        if (lua_locallyloading)
		    lua_pushboolean(L, true);
        else
            lua_pushboolean(L, false);
		return 1;
    } else if (fastcmp(word, "gks_lumpname")) {
		if (!lua_lumploading)
			lua_pushnil(L);
		else if (lua_lumpname[0])
			lua_pushstring(L, lua_lumpname);
		return 1;
	}
    return 0;
}
