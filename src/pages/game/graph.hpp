#pragma once

#include <vector>
#include <list>

#include "../../scenes/scene.hpp"

struct Scene;

struct Graph
{
    std::vector<Scene *> scenes;

    std::map<int, std::vector<int>> connections;
};



Graph* Graph_Create(std::vector<Scene *> scenes);

void Graph_AddConnection(Graph *graph, int fromScene, int toScene);

void Graph_Print(Graph *graph);