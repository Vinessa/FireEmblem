#include "stdafx.h"
#include "Grid.h"

Grid::Grid(){}
Grid::~Grid(){}

void Grid::init(int x/*18*/, int y/*18*/)
{
	paused = false;
	turn = 1;
	playable[1] = (Characters*)new HeavyMace();
	playable[2] = (Characters*)new Swordsman;
	playable[3] = (Characters*)new Axeman;
	playable[1]->init(vector2(9, 9), "HeavyMace");
	playable[2]->init(vector2(9, 12), "Swordsman");
	playable[3]->init(vector2(12, 9), "Axeman");

	unplayable[1] = (Characters*)new HeavyMace();
	unplayable[2] = (Characters*)new Swordsman;
	unplayable[3] = (Characters*)new Axeman;
	unplayable[1]->init(vector2(15, 15), "HeavyMace");
	unplayable[2]->init(vector2(15, 12), "Swordsman");
	unplayable[3]->init(vector2(12, 15), "Axeman");
	for (auto & element : unplayable)
		element.second->loadAsEnemy();
	unplayable[1]->turnOrder = 4;
	unplayable[2]->turnOrder = 5;
	unplayable[3]->turnOrder = 6;
	selectedNode = vector2(-1, -1);
	//sel.init();
	sel.load();
	xml.loadNodes(nodes, 1);
	/*for (auto & element : nodes)
		for (auto & elem : element)
			elem->init();*/

	//selWhite = new Selection(sel);
	selWhite.load(vector2(2,2),screen);
	selWhite.belowContent = nodes[2][2];

	card.load();
	card.sel = (Characters*)playable[1];
	card.selLand = (Land*)nodes[playable[1]->cord.x][playable[1]->cord.y];

	scr.load("splash.png");
	curr = STATE::SPLASH;
	keyState[' '] = false;

	HPickup* hPick = new HPickup();
	hPick->init(vector2(3, 3));
	HTrap* hTrap = new HTrap();
	hTrap->init(vector2(3, 5));
	items = vector<Items*>(2);
	items[0] = (Items*)hPick;
	items[1] = (Items*)hTrap;
}
void Grid::draw(vector2 screen)
{
	if (scr.show)
	{
		scr.draw();
		updateHalt++;
		for (auto & element : scr.buttons)
		{
			element.draw();
		}
		if (updateHalt >= 1500 && curr != MENU)
		{
			curr = MENU;
			scr = Screens();
			scr.load("menu.png");
			Button newPlay;
			Button newExit;
			newPlay.load("play.png");
			newPlay.minSize = vector2(screen.x / 4, 400);
			newPlay.maxSize = vector2(screen.x - (screen.x / 4), 500);
			newPlay.updatePos(screen);
			newPlay.minSize = vector2(screen.x / 4, 100);
			newPlay.maxSize = vector2(screen.x - (screen.x / 4), 200);
			scr.buttons.push_back(newPlay);
			newExit.load("exit.png");
			newExit.minSize = vector2(screen.x / 4, 100);
			newExit.maxSize = vector2(screen.x - (screen.x / 4), 200);
			newExit.updatePos(screen);
			newExit.minSize = vector2(screen.x / 4, 400);
			newExit.maxSize = vector2(screen.x - (screen.x / 4), 500);
			scr.buttons.push_back(newExit);
		}
		return;
	}
	for (int i = 0; i < 18; i++) {
		for (int ii = 0; ii < 18; ii++) {
			if ((int)playable.size() >= turn)
			{
				if (playable[turn]->calculateCost(nodes[i][ii], 4, vector2(i, ii)))
				{
					nodes[i][ii]->blueHighLight = true;
					nodes[i][ii]->redHighLight = false;
					nodes[i][ii]->normal = false; //Added by Vinessa for color blending
				}
				else if (playable[turn]->calculateAtLand(nodes[i][ii], 4, vector2(i, ii)))
				{
					nodes[i][ii]->blueHighLight = false;
					nodes[i][ii]->redHighLight = true;
					nodes[i][ii]->normal = false; //Added by Vinessa for color blending
				}
				else
				{
					nodes[i][ii]->blueHighLight = false;
					nodes[i][ii]->redHighLight = false;
					nodes[i][ii]->normal = true; //Added by Vinessa for color blending
				}
				nodes[i][ii]->draw(true);
			}
			else
				nodes[i][ii]->draw();

			//if (nodes[i][ii]->isBottom)
			//	nodes[i][ii] = test->belowContent;
		}
	}
	for (auto & element : playable)
		element.second->draw();

	for (auto & element : unplayable)
		element.second->draw();

	card.draw();
	for (auto & element : items)
	{
		element->draw();
	}
	int bob = 5;
	//selWhite.draw();
}

void Grid::update()
{
	if (curr == STATE::GAME)
		scr.show = false;
	if (scr.show)
		return;

	for (map<int, Characters*>::iterator it = playable.begin(); it != playable.end(); it++)
	{
		if (turn == it->second->turnOrder)
		{
			card.sel = (Characters*)it->second;
			card.selLand = (Land*)nodes[it->second->cord.x][it->second->cord.y];
			if (move && playable[turn]->calculateCost(nodes[selectedNode.x][selectedNode.y], 4, selectedNode))
			{
				for (map<int, Characters*>::iterator itt = playable.begin(); itt != playable.end(); itt++)
				{
					if (itt->second->cord == selectedNode)
					{
						move = false;
					}
				}
				if (move)
				{
					it->second->waiting = false;
					it->second->updatePos(selectedNode);
					turn++;
					move = false;
				}
				selectedNode = vector2(-1, -1);
			}
			else if (move)
				move = false;
		}
		if (selectedNode == it->second->cord)
		{
			selCharacter = (Characters*)it->second;
			card.opSel = (Characters*)selCharacter;
			card.opselLand = (Land*)nodes[it->second->cord.x][it->second->cord.y];
			card.showOpSel = true;
		}
		else if (selectedNode == vector2(-1, -1))
		{
			card.showOpSel = false;
			selCharacter = (Characters*)new Characters;
		}
		else
		{
			selCharacter = (Characters*)new Characters;
		}
		it->second->alive = it->second->health > 0;
		it->second->waiting = false;
		int itemTrackVal = 0;
		if (!items.empty())
			for (auto & element : items)
			{
			element->update(it->second->cord);
			if (element->alive)
			{
				element->effect(it->second);
				items.erase(items.begin() + itemTrackVal);
				break;
			}
			itemTrackVal++;
			}
	}
	//AI TIME

	for (auto & element : unplayable)
	{
		if (selectedNode == element.second->cord)
		{
			selCharacter = (Characters*)element.second;
			card.opSel = (Characters*)selCharacter;
			card.opselLand = (Land*)nodes[element.second->cord.x][element.second->cord.y];
			card.showOpSel = true;
		}
		else if (selectedNode == vector2(-1, -1))
		{
			card.showOpSel = false;
			selCharacter = (Characters*)new Characters;
		}
		else
		{
			selCharacter = (Characters*)new Characters;
		}
	}



	if (turn > playable.size() && updateHalt == 0)
	{
		for (map<int, Characters*>::iterator it = unplayable.begin(); it != unplayable.end(); it++)
		{
			if (turn == it->second->turnOrder)
			{
				card.sel = (Characters*)it->second;
				card.selLand = (Land*)nodes[it->second->cord.x][it->second->cord.y];
				if (move && unplayable[turn - unplayable.size()]->calculateCost(nodes[selectedNode.x][selectedNode.y], 4, selectedNode))
				{
					updateHalt = 0.1;
				}
				else if (move)
					move = false;
			}
			it->second->alive = it->second->health > 0;
			it->second->waiting = false;
			int itemTrackVal = 0;
			if (!items.empty())
				for (auto & element : items)
				{
				element->update(it->second->cord);
				if (element->alive)
				{
					element->effect(it->second);
					items.erase(items.begin() + itemTrackVal);
					break;
				}
				itemTrackVal++;
				}
		}
	}
	else if (turn > (int)playable.size() && updateHalt != 100)
	{
		updateHalt++;
		if (updateHalt >= 500)//The time between each AI movement
		{
			unplayable[turn - 3]->updatePos(selectedNode);
			turn++;
			updateHalt = 0;
			selectedNode = vector2(-1, -1);
			move = false;
		}
	}
	//End of the round
	if (turn > maxTurns)
	{
		for (auto & element : playable)
		{
			element.second->getAdj(unplayable);

			Attacks * attk = new Attacks();
			attk->ExecuteBattle(element.second);
		}
		for (auto & element : unplayable)
		{
			element.second->getAdj(playable);

			Attacks * attk = new Attacks();
			attk->ExecuteBattle(element.second);
		}

		//Reset the turn order
		turn = 1;
	}
}