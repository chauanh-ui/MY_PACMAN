#pragma once
#include "Texture.h"
class MenuButton : public LTexture
{
public:
	MenuButton();
	~MenuButton();

	// render texture len
	virtual void draw();

	//check vi tri chuot va update currentFrame
	// doan nay co the tham khao cua lazy foo
	virtual void update();

	//virtual void clean();
private:
	// dung lam currentFrame
	enum button_state
	{
		MOUSE_OUT = 0,
		MOUSE_OVER = 1,
		CLICKED = 2
	};
};