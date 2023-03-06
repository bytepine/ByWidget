// Fill out your copyright notice in the Description page of Project Settings.

#include "UnLuaEx.h"
#include "Components/ByListView.h"

static int32 UListView_SetListItems(lua_State* L)
{
	const int32 NumParams = lua_gettop(L);
	if (NumParams < 2)
		return luaL_error(L, "invalid parameters");

	UListView* ListView = static_cast<UListView*>(GetCppInstanceFast(L, 1));
	if (!ListView)
		return luaL_error(L, "listview is invalid");

	if (!lua_istable(L, 2))
		return luaL_error(L, "items is not table");
	
	TArray<UObject*> ArrayItems;

	lua_pushnil(L);
	while (lua_next(L, 2))
	{
		ULuaListItem* ItemObject = NewObject<ULuaListItem>(ListView);
		ArrayItems.Add(ItemObject);
		UnLua::PushUObject(L, ItemObject);
		if (lua_istable(L, -2))
			lua_insert(L, -2);
		else
			lua_newtable(L);
		lua_setfield(L, -2, "__item");
		lua_settop(L, 3);
	}
	ListView->SetListItems(ArrayItems);
	
	return 0;
}

static int32 UListView_GetItemObject(lua_State* L)
{
	const int32 NumParams = lua_gettop(L);
	if (NumParams < 2)
		return luaL_error(L, "invalid parameters");

	UListView* ListView = static_cast<UListView*>(GetCppInstanceFast(L, 1));
	if (!ListView)
		return luaL_error(L, "listview is invalid");

	if (!lua_istable(L, 2))
		return luaL_error(L, "items is not table");

	TArray<UObject*> ArrayItems = ListView->GetListItems();
	for(UObject* Item : ArrayItems)
	{
		UnLua::PushUObject(L, Item);
		lua_getfield(L, -1, "__item");
		if (lua_compare(L, -1, 2, LUA_OPEQ))
		{
			return 1;
		}
		lua_settop(L, 2);
	}
	return 0;
}

static const luaL_Reg UListViewLib[] =
{
	{ "SetListItems", UListView_SetListItems },
	{ "GetItemObject", UListView_GetItemObject },
	{ nullptr, nullptr }
};

BEGIN_EXPORT_REFLECTED_CLASS(UListView)
	ADD_LIB(UListViewLib)
END_EXPORT_CLASS()

IMPLEMENT_EXPORTED_CLASS(UListView)