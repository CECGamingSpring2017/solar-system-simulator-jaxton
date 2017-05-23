#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <iostream>
using namespace std;

const int WIDTH = 1200;
const int HEIGHT = 768;

enum MYKEYS {
	KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
};



struct Background
{
	float x;
	float y;

	float velX;
	float velY;

	int dirX;
	int dirY;

	int width;
	int height;

	ALLEGRO_BITMAP *image;
};

//declarations

void InitBackground(Background &back, float x, float y, float velx, float vely, int width, int height, int dirX, int dirY, ALLEGRO_BITMAP *image);
void UpdateBackground(Background &back);
void UpdateBackgroundUp(Background &back);
void UpdateBackgroundDown(Background &back);
void DrawBackground(Background &back);
void DrawBackgroundUp(Background &back);

int main(void)
{
	cout << "turdle" << endl;
	//variables
	bool done = false;
	bool render = false;

	//stamp your struct objects
	Background BG;
	Background FG;
	Background IronMaden;
	Background BoxHead;



	//allegro variables
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer;
	ALLEGRO_BITMAP *bgImage = NULL;
	ALLEGRO_BITMAP *fgImage = NULL;
	ALLEGRO_BITMAP *IronMadenpic = NULL;
	ALLEGRO_BITMAP *BoxHeadpic = NULL;

	float bouncer_x = 0;
	float bouncer_y = 0;
	bool key[4] = { false, false, false, false };
	bool redraw = true;
	bool doexit = false;

	al_init();
	al_install_keyboard();
	display = al_create_display(WIDTH, HEIGHT);

	//initalize add ons
	al_install_keyboard();
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();

	//load image
	//NOTE: when you do multiple backgrounds for parallax, make sure to use PNG's so the transperancy works correctly
	bgImage = al_load_bitmap("Halo.jpg");
	//fgImage = al_load_bitmap("sorsha.png");
	IronMadenpic = al_load_bitmap("IronMaden.jpg");
	BoxHeadpic = al_load_bitmap("BoxHead.png");
	cout << "dorkwood" << endl;
	//set transparency
	al_convert_mask_to_alpha(IronMadenpic, al_map_rgb(0, 0, 0));
	al_convert_mask_to_alpha(BoxHeadpic, al_map_rgb(255, 255, 255));
	 
	//we wrote this function; get the background ready to draw
	InitBackground(BG, 0, 0, 2, 0, 1440, 810, -1, 1, bgImage);
	//InitBackground(FG, 0, -800, 5, 3, 1440, 810, 1, 1, fgImage);
	InitBackground(IronMaden, 2000, 0, 20, 0, 1440, 810, -1, 1, IronMadenpic);
	InitBackground(BoxHead, 2000, 300, 5, 0, 1440, 810, -1, 1, BoxHeadpic);
	cout << "asdl;fkjasdf" << endl;

	//event queue to handle input in game loop
	event_queue = al_create_event_queue();
	timer = al_create_timer(1.0 / 60);
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_start_timer(timer);
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_display_event_source(display));

	//game loop
	while (!done)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			}
			if (key[KEY_UP]) {
				bouncer_y -= 4.0;
			}

			if (key[KEY_DOWN]) {
				bouncer_y += 4.0;
			}

			if (key[KEY_LEFT]) {
				bouncer_x -= 4.0;
			}

			if (key[KEY_RIGHT]) {
				bouncer_x += 4.0;

			}
			UpdateBackground(BG);
			//UpdateBackgroundUp(FG);
			UpdateBackground(IronMaden);
			UpdateBackground(BoxHead);
			render = true;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}



		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				key[KEY_UP] = true;
				break;

			case ALLEGRO_KEY_DOWN:
				key[KEY_DOWN] = true;
				break;

			case ALLEGRO_KEY_LEFT:
				key[KEY_LEFT] = true;
				break;

			case ALLEGRO_KEY_RIGHT:
				key[KEY_RIGHT] = true;
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				key[KEY_UP] = false;
				break;

			case ALLEGRO_KEY_DOWN:
				key[KEY_DOWN] = false;
				break;

			case ALLEGRO_KEY_LEFT:
				key[KEY_LEFT] = false;
				break;

			case ALLEGRO_KEY_RIGHT:
				key[KEY_RIGHT] = false;
				break;

			case ALLEGRO_KEY_ESCAPE:
				doexit = true;
				break;
			}
		}
		cout << "snowbonk" << endl;
		if (render && al_is_event_queue_empty(event_queue))
		{
			render = false;

			DrawBackground(BG);

			//DrawBackgroundUp(FG);
			DrawBackground(IronMaden);
			DrawBackground(BoxHead);
			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
		}
	}

	//these statements are actually pretty important, as they free up memory again. Try to destroy anything you create when done.
	al_destroy_bitmap(bgImage);
	al_destroy_event_queue(event_queue);
	al_destroy_display(display);

	return 0;
}

//function initalize background sets the location, speed, size, and picture for a background image
void InitBackground(Background &back, float x, float y, float velx, float vely, int width, int height, int dirX, int dirY, ALLEGRO_BITMAP *image)
{
	back.x = x;
	back.y = y;
	back.velX = velx;
	back.velY = vely;
	back.width = width;
	back.height = height;
	back.dirX = dirX;
	back.dirY = dirY;
	back.image = image;
}

//function update background moves the image across the screen
void UpdateBackground(Background &back)
{
	//to "move" the background, add its current position to its velocity times its direction
	back.x += back.velX * back.dirX;

	//if our position walks off the end of the image, reset the position to zero
	if (back.x + back.width <= 0)
		back.x = 0;
}

//up and down movement
void UpdateBackgroundUp(Background &back)
{
	//to "move" the background, add its current position to its velocity times its direction
	back.y += back.velY * back.dirY;

	//if our position walks off the end of the image, reset the position to zero
	if (back.y >= HEIGHT)
		back.y = 0;
}

void UpdateBackgroundDown(Background &back)
{
	//to "move" the background, add its current position to its velocity times its direction
	back.y += back.velY * back.dirY;

	//if our position walks off the end of the image, reset the position to zero
	if (back.y < 0)
		back.y = HEIGHT;
}

//function draw background draws the image to the screen, including a second looping one to stop gaps from occuring
void DrawBackground(Background &back)
{
	//draw it, yo
	al_draw_bitmap(back.image, back.x, back.y, 0);

	//this smooths out the wrapping action
	//if the position plus the width of the background is less than the screen width
	//(this happens when back.x gets really negative)
	//draw a SECOND background image so the front of it attaches to the back of the first image
	if (back.x + back.width < WIDTH)
		al_draw_bitmap(back.image, back.x + back.width, back.y, 0);
}

void DrawBackgroundUp(Background &back)
{
	//draw it, yo
	al_draw_bitmap(back.image, back.x, back.y, 0);

	//this smooths out the wrapping action
	//if the position plus the width of the background is less than the screen width
	//(this happens when back.x gets really negative)
	//draw a SECOND background image so the front of it attaches to the back of the first image
	if (back.y + back.height > HEIGHT)
		al_draw_bitmap(back.image, back.x, back.y - HEIGHT, 0);
}