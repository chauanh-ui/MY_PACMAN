#include "Button.h"
#include <iostream>
Button::Button(std::string path, int _button_x, int _button_y, void (*callback)())
{
	buttonTexture.loadFromFile(path);
	button_x = _button_x;
	button_y = _button_y;
	button_w = buttonTexture.getWidth() / 3;
	button_h = buttonTexture.getHeight();
	currentFrame = MOUSE_OUT; // start at frame 0
	clip.x = 0;
	clip.y = 0;
	clip.w = button_w;
	clip.h = button_h;
	m_callback = callback;
}
void Button::draw()
{
	
	buttonTexture.render(button_x - OffsetX, button_y - OffsetY,0U, &clip);
} 
void Button::update()
{
	
	clip.x = currentFrame * button_w;
}
void Button::handleEvents(SDL_Event& event) {
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
}

Button::~Button() {
	// Destructor implementation
	//delete buttonTexture;
	;
}
