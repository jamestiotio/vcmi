/*
 * CAltarArtifacts.h, part of VCMI engine
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 *
 */
#pragma once

#include "../CArtifactsOfHeroAltar.h"
#include "CMarketBase.h"

class CAltarArtifacts : public CExperienceAltar
{
public:
	CAltarArtifacts(const IMarket * market, const CGHeroInstance * hero);
	TExpType calcExpAltarForHero() override;
	void deselect() override;
	void makeDeal() override;
	void update() override;
	void sacrificeAll() override;
	void sacrificeBackpack();
	std::shared_ptr<CArtifactsOfHeroAltar> getAOHset() const;
	void putBackArtifacts();

private:
	ObjectInstanceID altarId;
	const CArtifactSet * altarArtifacts;
	std::shared_ptr<CButton> sacrificeBackpackButton;
	std::shared_ptr<CArtifactsOfHeroAltar> heroArts;
	std::map<std::shared_ptr<CTradeableItem>, const CArtifactInstance*> tradeSlotsMap;

	void updateAltarSlots();
	CMarketBase::MarketShowcasesParams getShowcasesParams() const override;
	void onSlotClickPressed(const std::shared_ptr<CTradeableItem> & altarSlot, std::shared_ptr<TradePanelBase> & curPanel) override;
	TExpType calcExpCost(ArtifactID id) const;
};
