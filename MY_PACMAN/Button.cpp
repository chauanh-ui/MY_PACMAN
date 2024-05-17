#include "Button.h"
#include <iostream>
Button::Button(std::string path, int _button_x, int _button_y, void (*callback)())
{
	buttonTexture.loadFromFile(path);
	button_x = _button_x;
	button_y = _button_y;
	button_w = buttonTexture.getWidth() / 3;
	button_h = buttonTexture.getHeight();
	std::cout << "button_w" << button_w << " button_h: " << button_h << std::endl;
	currentFrame = MOUSE_OUT; // start at frame 0
	clip.x = 0;
	clip.y = 0;
	clip.w = button_w;
	clip.h = button_h;
	std::cout << "clip_h: " << clip.h << std::endl;
	std::cout << "button()\n";
	m_callback = callback;
	std::cout << "Call back function:\n" << *m_callback << std::endl;
}
void Button::draw()
{
	/*SDL_Rect clip;
	clip.x = currentFrame * button_w;
	clip.y = 0;
	clip.w = button_w;
	clip.h = button_h;*/
	buttonTexture.render(button_x - OffsetX, button_y - OffsetY,0U, &clip);
} 
// x, y la vi tri cua chuot
void Button::update()
{
	/*Vector2D* pMousePos = TheInputHandler::Instance()
		->getMousePosition();
	if (pMousePos->getX() < (m_position.getX() + m_width)
		&& pMousePos->getX() > m_position.getX()
		&& pMousePos->getY() < (m_position.getY() + m_height)
		&& pMousePos->getY() > m_position.getY())
	{
		m_currentFrame = MOUSE_OVER;
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
		{
			m_currentFrame = CLICKED;
		}
	}
	else
	{
		m_currentFrame = MOUSE_OUT;
	}*/
	clip.x = currentFrame * button_w;
}
void Button::handleEvents(SDL_Event& event) {
	std::cout << "Button handle Event\n";
	int mouseX, mouseY;
	SDL_GetMouseState(&mouseX, &mouseY);
	if (mouseX >= button_x && mouseX <= button_x + button_w
		&& mouseY >= button_y && mouseY <= button_y + button_h) {
		if (event.type == SDL_MOUSEMOTION) {
			currentFrame = MOUSE_OVER;
		}
		else if (event.type == SDL_MOUSEBUTTONDOWN) {
			currentFrame = CLICKED;
			m_callback();
			m_bReleased = false;
		}
	}
	else {
		currentFrame = MOUSE_OUT;
	}
	//std::cout << "Button handle Event\n";
}

Button::~Button() {
	// Destructor implementation
	//delete buttonTexture;
	;
}
