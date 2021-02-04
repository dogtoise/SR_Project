#pragma once

struct RendererState
{
	int numVertices;
	int numIndices;
	int numDrawCalls;
	int numTriangles;
};

struct SceneStats
{
	int numObjects;

	int numMainViewCulledObjects;



};

struct EngineConfig
{
	bool bShowBoundingBoxes;
	bool bShowProfiler;
};