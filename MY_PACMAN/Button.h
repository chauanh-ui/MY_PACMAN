#pragma once
#pragma once
#include "Texture.h"
class Button 
{
public:
	Button(std::string path, int _button_x, int _button_y, void (*callback)() = nullptr);
	~Button();

	// render texture len
	virtual void draw();

	//check vi tri chuot va update currentFrame
	// doan nay co the tham khao cua lazy foo
	virtual void update();
	virtual void handleEvents(SDL_Event& event);

	//virtual void clean();
private:
	// dung lam currentFrame
	LTexture buttonTexture;
	SDL_Rect clip;
	int button_x;
	int button_y;
	int button_w;
	int button_h;
	int currentFrame;
	enum button_state
	{
		MOUSE_OUT = 0,
		MOUSE_OVER = 1,
		CLICKED = 2
	};


	void (*m_callback)();
	bool m_bReleased;
};