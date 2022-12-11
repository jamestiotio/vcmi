/*
 * CBattleFieldController.h, part of VCMI engine
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 *
 */
#pragma once

#include "../../lib/battle/BattleHex.h"
#include "../gui/CIntObject.h"

VCMI_LIB_NAMESPACE_BEGIN

class CStack;

VCMI_LIB_NAMESPACE_END

struct SDL_Surface;
struct Rect;
struct Point;

class ClickableHex;
class Canvas;
class IImage;
class BattleInterface;

class BattleFieldController : public CIntObject
{
	BattleInterface * owner;

	std::shared_ptr<IImage> background;
	std::shared_ptr<IImage> cellBorder;
	std::shared_ptr<IImage> cellShade;

	std::unique_ptr<Canvas> cellBorders;

	/// Canvas that contains background, hex grid (if enabled), absolute obstacles and movement range of active stack
	std::unique_ptr<Canvas> backgroundWithHexes;

	//BattleHex previouslyHoveredHex; //number of hex that was hovered by the cursor a while ago
	//BattleHex currentlyHoveredHex; //number of hex that is supposed to be hovered (for a while it may be inappropriately set, but will be renewed soon)
	BattleHex attackingHex; //hex from which the stack would perform attack with current cursor

	std::vector<BattleHex> occupyableHexes; //hexes available for active stack
	std::array<bool, GameConstants::BFIELD_SIZE> stackCountOutsideHexes; // hexes that when in front of a unit cause it's amount box to move back

	std::vector<std::shared_ptr<ClickableHex>> bfield; //11 lines, 17 hexes on each

	void showHighlightedHex(Canvas & to, BattleHex hex, bool darkBorder);

	std::set<BattleHex> getHighlightedHexesStackRange();
	std::set<BattleHex> getHighlightedHexesSpellRange();

	void showBackground(Canvas & canvas);
	void showBackgroundImage(Canvas & canvas);
	void showBackgroundImageWithHexes(Canvas & canvas);
	void showHighlightedHexes(Canvas & canvas);

public:
	BattleFieldController(BattleInterface * owner);

	void redrawBackgroundWithHexes();
	void renderBattlefield(Canvas & canvas);

	Rect hexPositionLocal(BattleHex hex) const;
	Rect hexPosition(BattleHex hex) const;
	bool isPixelInHex(Point const & position);

	BattleHex getHoveredHex();

	void setBattleCursor(BattleHex myNumber);
	BattleHex fromWhichHexAttack(BattleHex myNumber);
	bool isTileAttackable(const BattleHex & number) const;
	bool stackCountOutsideHex(const BattleHex & number) const;
};
