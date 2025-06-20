#pragma once

#include "../page.hpp"

struct LoadGamePageData
{
   UIElement *textAku;

   std::string saveName;
};

Page *LoadGamePG_Create();
void LoadGamePG_Start(Page *page);
void LoadGamePG_Update(Page *page);
void LoadGamePG_Destroy(Page *page);