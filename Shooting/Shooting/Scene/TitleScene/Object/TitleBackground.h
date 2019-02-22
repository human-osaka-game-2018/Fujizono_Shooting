#pragma once

#include "../../../GameLib/ObjectManager/Object2DBase.h"
#include "../../../GameLib/DirectX/DirectX.h"
#include "../../../GameLib/2DHelper/2DHelper.h"
#include "../../../GameLib/Texture/Texture.h"


/**
* @brief ƒ^ƒCƒgƒ‹‚Ì”wŒiŠÖŒW‚Ìˆ—‚ğ‚Ü‚Æ‚ß‚½ƒNƒ‰ƒX
*/
class TitleBackground : public Object2DBase
{
public:

	TitleBackground();
	~TitleBackground();

	/**
	* @brief ‰Šú‰»‚·‚éŠÖ”
	* @return ‰Šú‰»‚ªãè‚­‚Å‚«‚Ä‚¢‚È‚¢‚ÆFALSE
	*/
	bool Initialize();

	/**
	* @brief ‰ğ•ú‚·‚éŠÖ”
	*/
	void Finalize();

	/**
	* @brief ‘€ìŠÖ”
	*/
	void Update();

	/**
	* @brief •`‰æŠÖ”
	*/
	void Render();

private:

};

