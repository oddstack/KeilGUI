//*******************************************************************
// IDrawable
//*******************************************************************

//-------------------------------------------------------------------

#include "GUIControls.h"

void GUIControls::update()
{
	touch.update();
	int t = touch.isTouched();

	int x = touch.getPosX();
	int y = touch.getPosY();
	
	Rect finger(x-10, y-10, 20, 20);
	
	if (wasTouching != t)
	{
		wasTouching = t;
		superView->onEvent(t ? GUIEvent::TouchDown : GUIEvent::TouchUp, finger);
	}
	else if (t)
	{
		superView->onEvent(GUIEvent::Touch, finger);
	}
}

//EOF
