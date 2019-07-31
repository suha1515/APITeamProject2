#pragma once

#ifndef __STRUCT_H__

typedef struct tagLineInfo
{
	float fStartX, fStartY;
	float fEndX, fEndY;
}LINE_INFO;

typedef struct tagInfo
{
	float fX = 0.f;
	float fY = 0.f;
	float fCX = 0.f;
	float fCY = 0.f;
}INFO;

typedef struct tagSpawn_Obstacle_Info
{
	int pos_X;
	int pos_Y;
	int spawn_Time;
	tagSpawn_Obstacle_Info(int x, int y, int time,  OBSTACLE_TYPE obsType,OBSTACLE_MOVETYPE moveType=OBSTACLE_MOVETYPE::STOP)
		:pos_X(x), pos_Y(y), spawn_Time(time),m_ObsType(obsType),m_MoveType(moveType)
	{}
	OBSTACLE_TYPE m_ObsType;
	OBSTACLE_MOVETYPE m_MoveType;

}SPAWN_OBSTACLE_INFO;

typedef struct tagSpawn_Item_Info
{
	int pos_X;
	int pos_Y;
	int spawn_Time;
	tagSpawn_Item_Info(int x, int y, int time, ITEM_TYPE itemType)
		:pos_X(x), pos_Y(y), spawn_Time(time), m_ItemType(itemType)
	{}
	ITEM_TYPE m_ItemType;

}SPAWN_ITEM_INFO;

typedef struct tagSpawn_Floor_Info
{
	int pos_X;
	int pos_Y;
	int spawn_Time;
	tagSpawn_Floor_Info(int x, int y, int time,  FLOOR_TYPE floorType)
		:pos_X(x), pos_Y(y), spawn_Time(time), m_FloorType(floorType)
	{}
	FLOOR_TYPE m_FloorType;

}SPAWN_FLOOR_INFO;

typedef struct tagSpawn_Jelly_Info
{
	int pos_X;
	int pos_Y;
	int spawn_Time;
	tagSpawn_Jelly_Info(int x, int y, int time, JELLY_TYPE jellyType)
		:pos_X(x), pos_Y(y), spawn_Time(time), m_JellyType(jellyType)
	{}
	JELLY_TYPE m_JellyType;

}SPAWN_JELLY_INFO;
#define __STRUCT_H__
#endif
