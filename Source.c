#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <stdbool.h>

#define player_1 101
#define player_2 102
#define player_1_befor 103
#define player_2_befor 104
#define player_1_mamnoo_kardan 110
#define player_2_mamnoo_kardan 111
#define first_menu 0
#define board 1
#define flip 10
#define about_us 14
#define exit_game 15
#define win1 200
#define win2 300


typedef struct button {
	int x1, x2;
	int y1, y2;
}button;

typedef struct khoone {
	int x;
	int y;
}khoone;

void must_init(bool test, const char* description)
{
	if (test) return;

	printf("couldn't initialize %s\n", description);
	exit(1);
}

int check_mouse_position(button* btn, ALLEGRO_MOUSE_STATE* mouse) {
	if (mouse->x > btn->x1 && mouse->x <btn->x2 && mouse->y > btn->y1 && mouse->y < btn->y2) {
		return 1;
	}
	return 0;
}

int flipacoin() {
	srand(time(0));
		int a = rand() % 2 ;
		if (a == 0) return 2;
		else return a;
}

int tas_partab() {
	srand(time(0));
		int a = rand() % 6 - 3;
		if (a == 0) return 3;
		else return a;
}






int main()
{
	al_init();

	al_init_font_addon();
	al_init_ttf_addon();
	must_init(al_init(), "allegro");
	must_init(al_install_keyboard(), "keyboard");
	must_init(al_init_primitives_addon(), "primitives");
	al_install_keyboard();
	must_init(al_install_keyboard(), "keyboard");
	al_install_mouse();

	ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);
	must_init(timer, "timer");

	ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
	must_init(queue, "queue");
	ALLEGRO_MOUSE_STATE mouse;
	//mouse.

	al_set_new_display_flags(ALLEGRO_RESIZABLE);
	al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
	al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);
	al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);
	ALLEGRO_DISPLAY* disp = al_create_display(1200, 702);
	must_init(disp, "display");

	must_init(al_init_font_addon(), "font addon");

	ALLEGRO_FONT* font = al_create_builtin_font();
	must_init(font, "font");

	must_init(al_install_audio(), "audio");
	must_init(al_init_acodec_addon(), "audio codec");
	must_init(al_reserve_samples(16), "reserve sample");

	must_init(al_init_image_addon(), "image addon");
	ALLEGRO_BITMAP* pas = al_load_bitmap("pas.png");
	must_init(pas, "pas");
	ALLEGRO_BITMAP* map = al_load_bitmap("map4.png");
	must_init(map, "map3");
	ALLEGRO_BITMAP* c1 = al_load_bitmap("c1.png");
	must_init(c1, "c1");
	ALLEGRO_BITMAP* c2 = al_load_bitmap("c2.png");
	must_init(c2, "c2");
	ALLEGRO_BITMAP* c3 = al_load_bitmap("c3.png");
	must_init(c3, "c3");
	ALLEGRO_BITMAP* c4 = al_load_bitmap("c4.png");
	must_init(c4, "c4");
	ALLEGRO_BITMAP* c5 = al_load_bitmap("c5.png");
	must_init(c5, "c5");
	ALLEGRO_BITMAP* c6 = al_load_bitmap("c6.png");
	must_init(c6, "c6");
	ALLEGRO_BITMAP* c7 = al_load_bitmap("c7.png");
	must_init(c7, "c7");
	ALLEGRO_BITMAP* c8 = al_load_bitmap("c8.png");
	must_init(c8, "c8");
	ALLEGRO_BITMAP* tas1 = al_load_bitmap("1.png");
	must_init(tas1, "1");
	ALLEGRO_BITMAP* tas2 = al_load_bitmap("2.png");
	must_init(tas2, "2");
	ALLEGRO_BITMAP* tas3 = al_load_bitmap("3.png");
	must_init(tas3, "3");
	ALLEGRO_BITMAP* tas_1 = al_load_bitmap("-1.png");
	must_init(tas_1, "-1");
	ALLEGRO_BITMAP* tas_2 = al_load_bitmap("-2.png");
	must_init(tas_2, "-2");
	ALLEGRO_BITMAP* tas_3 = al_load_bitmap("-3.png");
	must_init(tas_3, "-3");
	ALLEGRO_BITMAP* rahro = al_load_bitmap("rahro.png");
	must_init(rahro, "rahro");
	ALLEGRO_BITMAP* shans = al_load_bitmap("shans.png");
	must_init(shans, "shans");
    
	ALLEGRO_BITMAP* close = al_load_bitmap("close door.png");
	must_init(close, "close door");
	ALLEGRO_BITMAP* zarib = al_load_bitmap("zarib.png");
	must_init(zarib, "zarib");
	ALLEGRO_BITMAP* mamnoo = al_load_bitmap("mamnoo.png");
	must_init(mamnoo, "mamnoo");
	ALLEGRO_BITMAP* againdice = al_load_bitmap("again dice.png");
	must_init(againdice, "again dice");

	ALLEGRO_BITMAP* menu = al_load_bitmap("menu.png");
	must_init(menu, "OP");

	ALLEGRO_BITMAP* win_1 = al_load_bitmap("win 1.png");
	must_init(win_1, "win 1");
	ALLEGRO_BITMAP* win_2 = al_load_bitmap("win 2.png");
	must_init(win_2, "win 2");

	ALLEGRO_BITMAP* menu_about = al_load_bitmap("about.png");
	must_init(menu_about, "menu");


	ALLEGRO_FONT* font1 = al_load_ttf_font("font1.ttf", 36, 0);
	must_init(font1, "font1");
	ALLEGRO_FONT* font2 = al_load_ttf_font("ZEROGIRL.ttf", 36, 0);
	must_init(font2, "ZEROGIRL");
	ALLEGRO_FONT* font3 = al_load_ttf_font("GapsS.ttf", 36, 0);
	must_init(font3, "GapsS");
	ALLEGRO_FONT* font_menu = al_load_ttf_font("davyrib.ttf", 90, 0);
	must_init(font_menu, "davyrib");
	ALLEGRO_FONT* font_menu1 = al_load_ttf_font("PAGANINI.ttf", 60, 0);
	must_init(font_menu1, "PAGANINI");
	ALLEGRO_FONT* font_menu2 = al_load_ttf_font("virgo.ttf", 36, 0);
	must_init(font_menu2, "virgo");
	ALLEGRO_FONT* font_game1 = al_load_ttf_font(
		"virgo.ttf", 30, 0);
	must_init(font_game1, "virgo");


	ALLEGRO_AUDIO_STREAM* music = al_load_audio_stream("pas.mp3", 10, 2048);
	must_init(music, "pas");
	ALLEGRO_AUDIO_STREAM* click = al_load_audio_stream("1.mp3", 2, 2048);
	must_init(click, "mouse_click_sfx");
	ALLEGRO_AUDIO_STREAM* winner = al_load_audio_stream("winner.mp3", 20, 2048);
	must_init(winner, "mouse_click_sfx");
	ALLEGRO_AUDIO_STREAM* winner1 = al_load_audio_stream("winner.mp3", 2, 2048);
	must_init(winner1, "mouse_click_sfx");
	//ALLEGRO_AUDIO_STREAM* click1 = al_load_audio_stream("1.mp3", 2, 2048);
	//must_init(click1, "mouse_click_sfx");


	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_display_event_source(disp));
	al_register_event_source(queue, al_get_timer_event_source(timer));

	FILE* startnewgame;
	//startnewgame = fopen("startnewgame", "wt");
	FILE* startpreviuosgame;


	bool done = false;
	bool redraw = true;
	ALLEGRO_EVENT event;
#pragma region mokhtasat noghat
	khoone k[81];
	k[0].x = 248;
	k[0].y = 612;
	k[1].x = 248 + (85 * 1);
	k[1].y = 612;
	k[2].x = 248 + (85 * 2);
	k[2].y = 612;
	k[3].x = 248 + (85 * 3);
	k[3].y = 612;
	k[4].x = 248 + (85 * 4);
	k[4].y = 612;
	k[5].x = 248 + (5 * 85);
	k[5].y = 612 - (0 * 64);
	k[6].x = 248 + (6 * 85);
	k[6].y = 612 - (0 * 64);
	k[7].x = 248 + (7 * 85);
	k[7].y = 612 - (0 * 64);
	k[8].x = 248 + (8 * 85);
	k[8].y = 612 - (0 * 64);
	/**/
	k[9].x = 248 + (8 * 85);
	k[9].y = 612 - (1 * 64);
	k[10].x = 248 + (7 * 85);
	k[10].y = 612 - (1 * 64);
	k[11].x = 248 + (6 * 85);
	k[11].y = 612 - (1 * 64);
	k[12].x = 248 + (5 * 85);
	k[12].y = 612 - (1 * 64);
	k[13].x = 248 + (4 * 85);
	k[13].y = 612 - (1 * 64);
	k[14].x = 248 + (3 * 85);
	k[14].y = 612 - (1 * 64);
	k[15].x = 248 + (2 * 85);
	k[15].y = 612 - (1 * 64);
	k[16].x = 248 + (1 * 85);
	k[16].y = 612 - (1 * 64);
	k[17].x = 248 + (0 * 85);
	k[17].y = 612 - (1 * 64);
	/**/
	k[18].x = 248 + (0 * 85);
	k[18].y = 612 - (2 * 64);
	k[19].x = 248 + (1 * 85);
	k[19].y = 612 - (2 * 64);
	k[20].x = 248 + (2 * 85);
	k[20].y = 612 - (2 * 64);
	k[21].x = 248 + (3 * 85);
	k[21].y = 612 - (2 * 64);
	k[22].x = 248 + (4 * 85);
	k[22].y = 612 - (2 * 64);
	k[23].x = 248 + (5 * 85);
	k[23].y = 612 - (2 * 64);
	k[24].x = 248 + (6 * 85);
	k[24].y = 612 - (2 * 64);
	k[25].x = 248 + (7 * 85);
	k[25].y = 612 - (2 * 64);
	k[26].x = 248 + (8 * 85);
	k[26].y = 612 - (2 * 64);
	/**/
	k[27].x = 248 + (8 * 85);
	k[27].y = 612 - (3 * 64);
	k[28].x = 248 + (7 * 85);
	k[28].y = 612 - (3 * 64);
	k[29].x = 248 + (6 * 85);
	k[29].y = 612 - (3 * 64);
	k[30].x = 248 + (5 * 85);
	k[30].y = 612 - (3 * 64);
	k[31].x = 248 + (4 * 85);
	k[31].y = 612 - (3 * 64);
	k[32].x = 248 + (3 * 85);
	k[32].y = 612 - (3 * 64);
	k[33].x = 248 + (2 * 85);
	k[33].y = 612 - (3 * 64);
	k[34].x = 248 + (1 * 85);
	k[34].y = 612 - (3 * 64);
	k[35].x = 248 + (0 * 85);
	k[35].y = 612 - (3 * 64);
	/**/
	k[36].x = 248 + (0 * 85);
	k[36].y = 612 - (4 * 64);
	k[37].x = 248 + (1 * 85);
	k[37].y = 612 - (4 * 64);
	k[38].x = 248 + (2 * 85);
	k[38].y = 612 - (4 * 64);
	k[39].x = 248 + (3 * 85);
	k[39].y = 612 - (4 * 64);
	k[40].x = 248 + (4 * 85);
	k[40].y = 612 - (4 * 64);
	k[41].x = 248 + (5 * 85);
	k[41].y = 612 - (4 * 64);
	k[42].x = 248 + (6 * 85);
	k[42].y = 612 - (4 * 64);
	k[43].x = 248 + (7 * 85);
	k[43].y = 612 - (4 * 64);
	k[44].x = 248 + (8 * 85);
	k[44].y = 612 - (4 * 64);
	k[45].x = 248 + (8 * 85);
	k[45].y = 612 - (5 * 64);
	k[46].x = 248 + (7 * 85);
	k[46].y = 612 - (5 * 64);
	k[47].x = 248 + (6 * 85);
	k[47].y = 612 - (5 * 64);
	k[48].x = 248 + (5 * 85);
	k[48].y = 612 - (5 * 64);
	k[49].x = 248 + (4 * 85);
	k[49].y = 612 - (5 * 64);
	k[50].x = 248 + (3 * 85);
	k[50].y = 612 - (5 * 64);
	k[51].x = 248 + (2 * 85);
	k[51].y = 612 - (5 * 64);
	k[52].x = 248 + (1 * 85);
	k[52].y = 612 - (5 * 64);
	k[53].x = 248 + (0 * 85);
	k[53].y = 612 - (5 * 64);
	k[54].x = 248 + (0 * 85);
	k[54].y = 612 - (6 * 64);
	k[55].x = 248 + (1 * 85);
	k[55].y = 612 - (6 * 64);
	k[56].x = 248 + (2 * 85);
	k[56].y = 612 - (6 * 64);
	k[57].x = 248 + (3 * 85);
	k[57].y = 612 - (6 * 64);
	k[58].x = 248 + (4 * 85);
	k[58].y = 612 - (6 * 64);
	k[59].x = 248 + (5 * 85);
	k[59].y = 612 - (6 * 64);
	k[60].x = 248 + (6 * 85);
	k[60].y = 612 - (6 * 64);
	k[61].x = 248 + (7 * 85);
	k[61].y = 612 - (6 * 64);
	k[62].x = 248 + (8 * 85);
	k[62].y = 612 - (6 * 64);
	k[63].x = 248 + (8 * 85);
	k[63].y = 612 - (7 * 64);
	k[64].x = 248 + (7 * 85);
	k[64].y = 612 - (7 * 64);
	k[65].x = 248 + (6 * 85);
	k[65].y = 612 - (7 * 64);
	k[66].x = 248 + (5 * 85);
	k[66].y = 612 - (7 * 64);
	k[67].x = 248 + (4 * 85);
	k[67].y = 612 - (7 * 64);
	k[68].x = 248 + (3 * 85);
	k[68].y = 612 - (7 * 64);
	k[69].x = 248 + (2 * 85);
	k[69].y = 612 - (7 * 64);
	k[70].x = 248 + (1 * 85);
	k[70].y = 612 - (7 * 64);
	k[71].x = 248 + (0 * 85);
	k[71].y = 612 - (7 * 64);
	k[72].x = 248 + (0 * 85);
	k[72].y = 612 - (8 * 64);
	k[73].x = 248 + (1 * 85);
	k[73].y = 612 - (8 * 64);
	k[74].x = 248 + (2 * 85);
	k[74].y = 612 - (8 * 64);
	k[75].x = 248 + (3 * 85);
	k[75].y = 612 - (8 * 64);
	k[76].x = 248 + (4 * 85);
	k[76].y = 612 - (8 * 64);
	k[77].x = 248 + (5 * 85);
	k[77].y = 612 - (8 * 64);
	k[78].x = 248 + (6 * 85);
	k[78].y = 612 - (8 * 64);
	k[79].x = 248 + (7 * 85);
	k[79].y = 612 - (8 * 64);
	k[80].x = 248 + (8 * 85);
	k[80].y = 612 - (8 * 64);
#pragma endregion


	al_start_timer(timer);
#pragma region buttons
	button tas;
	tas.x1 = 0;
	tas.x2 = 100;
	tas.y1 = 450;
	tas.y2 = 560;

	button start;
	start.x1 = 410;
	start.x2 = 860;
	start.y1 = 250;
	start.y2 = 295;

	button saves;
	saves.x1 = 350;
	saves.x2 = 940;
	saves.y1 = 300;
	saves.y2 = 345;

	button rules_of_game;
	rules_of_game.x1 = 445;
	rules_of_game.x2 = 845;
	rules_of_game.y1 = 350;
	rules_of_game.y2 = 395;

	button about;
	about.x1 = 500;
	about.x2 = 760;
	about.y1 = 410;
	about.y2 = 460;

	button exit;
	exit.x1 = 10;
	exit.x2 = 110;
	exit.y1 = 650;
	exit.y2 = 700;

	button savegame;
	savegame.x1 = 10;
	savegame.x2 = 110;
	savegame.y1 = 650;
	savegame.y2 = 700;

	button pl_pi1;
	pl_pi1.x1 = 145;
	pl_pi1.x2 = 175;
	pl_pi1.y1 = 490;
	pl_pi1.y2 = 530;

	button pl_pi2;
	pl_pi2.x1 = 145;
	pl_pi2.x2 = 180;
	pl_pi2.y1 = 540;
	pl_pi2.y2 = 580;

	button close1;
	close1.x1 = 10;
	close1.x2 = 80;
	close1.y1 = 130;
	close1.y2 = 210;

	button zarib1;
	zarib1.x1 = 10;
	zarib1.x2 = 110;
	zarib1.y1 = 225;
	zarib1.y2 = 280;

	button mamnoo1;
	mamnoo1.x1 = 10;
	mamnoo1.x2 = 61;
	mamnoo1.y1 = 300;
	mamnoo1.y2 = 350;

	button againdice1;
	againdice1.x1 = 10;
	againdice1.x2 = 67;
	againdice1.y1 = 360;
	againdice1.y2 = 410;

	button close2;
	close2.x1 = 1120;
	close2.x2 = 1190;
	close2.y1 = 130;
	close2.y2 = 210;

	button zarib2;
	zarib2.x1 = 1090;
	zarib2.x2 = 1190;
	zarib2.y1 = 225;
	zarib2.y2 = 280;

	button mamnoo2;
	mamnoo2.x1 = 1139;
	mamnoo2.x2 = 1190;
	mamnoo2.y1 = 300;
	mamnoo2.y2 = 350;

	button againdice2;
	againdice2.x1 = 1133;
	againdice2.x2 = 1190;
	againdice2.y1 = 360;
	againdice2.y2 = 410;

	button exitgame;
	exitgame.x1 = 1100;
	exitgame.x2 = 1200;
	exitgame.y1 = 650;
	exitgame.y2 = 702;

	button first;
	first.x1 = 525;
	first.x2 = 662;
	first.y1 = 650;
	first.y2 = 702;


#pragma endregion


#pragma region chance switch
	int sw_k3;
	int sw_k15;
	int sw_k24;
	int sw_k35;

	int sw_k46;
	int sw_k57;
	int sw_k70;
	int sw_k77;
#pragma endregion



	int sw = 0;
#pragma region switch of coridores
	int sw1 = 0;
	int sw2 = 0;
	int sw3 = 0;
	int sw4 = 0;
#pragma endregion

#pragma region counts
	int count_close1;
	int count_zarib1;
	int count_mamnoo1;
	int count_againdice1;
	int count_close2;
	int count_zarib2;
	int count_mamnoo2;
	int count_againdice2;
#pragma endregion

#pragma region stsrt switchs
	int sw_asli_1;
	int sw_asli_2;
	int sw_asli_3;
	int sw_asli_4;

	int sw_komaki_1;
	int sw_komaki_2;
	int sw_komaki_3;
	int sw_komaki_4;
#pragma endregion


	//printf("%d", flipacoin());
	
	bool swbtndown = false;
	//int x = 675;
	//int y = 550;
	//int p=0;
	int i;
	int j;
	int p1_1;
	int p1_2;
	int p2_1;
	int p2_2;
	while (1)
	{
		al_wait_for_event(queue, &event);

		switch (event.type)
		{
		case ALLEGRO_EVENT_TIMER:
			// game logic goes here.

			redraw = true;
			break;

		case ALLEGRO_EVENT_KEY_DOWN:
			if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
				return 0;
                if(event.keyboard.keycode != ALLEGRO_KEY_ESCAPE)
                    break;

		case ALLEGRO_EVENT_DISPLAY_CLOSE:

			done = true;
			break;


		}

		if (done)
			break;
		//s
		if (redraw && al_is_event_queue_empty(queue))
		{
			switch (sw) {
			case first_menu:
				al_draw_bitmap(menu, -170, 0, 0);
				al_draw_text(font_menu, al_map_rgb(238, 53, 124), 450, 0, 0, "welcome");
				al_draw_text(font_menu, al_map_rgb(238, 53, 124), 690, 65, 30, "to");
				al_draw_text(font_menu, al_map_rgb(238, 53, 124), 740, 130, 30, "game");

				al_draw_text(font_menu1, al_map_rgb(149, 11, 65), 410, 250, 0, "start new game");
				al_draw_text(font_menu1, al_map_rgb(149, 11, 65), 350, 300, 0, "start previous game");
				al_draw_text(font_menu1, al_map_rgb(149, 11, 65), 445, 350, 0, "rules of game");
				al_draw_text(font_menu1, al_map_rgb(149, 11, 65), 500, 410, 0, "about us :)");
				al_draw_text(font_menu1, al_map_rgb(149, 11, 65), 10, 650, 0, "exit");
				al_get_mouse_state(&mouse);
				/*---dokme start----*/
				if (check_mouse_position(&start, &mouse)) {
					al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
					if (!swbtndown) 
						if (al_mouse_button_down(&mouse, 1))
					{
						swbtndown = true;
						startnewgame = fopen("startnewgame.txt", "rt");
						if (!startnewgame) {
							printf("cant open new game");
							return 0;
						}
						int a;
						fscanf_s(startnewgame, "%d", &a);
						p1_1 = (((a - 29) / 3) + 100) / 6521;
						fscanf_s(startnewgame, "%d", &a);
						p1_2 = (((a - 29) / 3) + 100) / 6521;
						fscanf_s(startnewgame, "%d", &a);
						count_close1 = (((a - 29) / 3) + 100) / 6521;
						fscanf_s(startnewgame, "%d", &a);
						count_zarib1 = (((a - 29) / 3) + 100) / 6521;
						fscanf_s(startnewgame, "%d", &a);
						count_mamnoo1 = (((a - 29) / 3) + 100) / 6521;
						fscanf_s(startnewgame, "%d", &a);
						count_againdice1 = (((a - 29) / 3) + 100) / 6521;
						fscanf_s(startnewgame, "%d", &a);
						p2_1 = (((a - 29) / 3) + 100) / 6521;
						fscanf_s(startnewgame, "%d", &a);
						p2_2 = (((a - 29) / 3) + 100) / 6521;
						fscanf_s(startnewgame, "%d", &a);
						count_close2 = (((a - 29) / 3) + 100) / 6521;
						fscanf_s(startnewgame, "%d", &a);
						count_zarib2 = (((a - 29) / 3) + 100) / 6521;
						fscanf_s(startnewgame, "%d", &a);
						count_mamnoo2 = (((a - 29) / 3) + 100) / 6521;
						fscanf_s(startnewgame, "%d", &a);
						count_againdice2 = (((a - 29) / 3) + 100) / 6521;
						fscanf_s(startnewgame, "%d", &a);
						sw_k3 = (((a - 29) / 3) + 100) / 6521;
						fscanf_s(startnewgame, "%d", &a);
						sw_k15 = (((a - 29) / 3) + 100) / 6521;
						fscanf_s(startnewgame, "%d", &a);
						sw_k24 = (((a - 29) / 3) + 100) / 6521;
						fscanf_s(startnewgame, "%d", &a);
						sw_k35 = (((a - 29) / 3) + 100) / 6521;
						fscanf_s(startnewgame, "%d", &a);
						sw_k46 = (((a - 29) / 3) + 100) / 6521;
						fscanf_s(startnewgame, "%d", &a);
						sw_k57 = (((a - 29) / 3) + 100) / 6521;
						fscanf_s(startnewgame, "%d", &a);
						sw_k70 = (((a - 29) / 3) + 100) / 6521;
						fscanf_s(startnewgame, "%d", &a);
						sw_k77 = (((a - 29) / 3) + 100) / 6521;
						fscanf_s(startnewgame, "%d", &a);
						sw_asli_1 = (((a - 29) / 3) + 100) / 6521;
						fscanf_s(startnewgame, "%d", &a);
						sw_asli_2 = (((a - 29) / 3) + 100) / 6521;
						fscanf_s(startnewgame, "%d", &a);
						sw_asli_3 = (((a - 29) / 3) + 100) / 6521;
						fscanf_s(startnewgame, "%d", &a);
						sw_asli_4 = (((a - 29) / 3) + 100) / 6521;
						fclose(startnewgame);
						int F = flipacoin();
						printf("\ncoin : %d", F);
						if (F == 1) sw = player_1_befor;
						if (F == 2) sw = player_2_befor;

						ALLEGRO_AUDIO_STREAM* click1 = al_load_audio_stream("1.mp3", 2, 2048);
						must_init(click1, "mouse_click_sfx");
						al_set_audio_stream_playmode(click1, _ALLEGRO_PLAYMODE_STREAM_LOOP_ONCE);
						al_attach_audio_stream_to_mixer(click1, al_get_default_mixer());
						
						al_set_audio_stream_playmode(music, ALLEGRO_PLAYMODE_LOOP);
						al_attach_audio_stream_to_mixer(music, al_get_default_mixer());
					}
					if (!al_mouse_button_down(&mouse, 1))  swbtndown = false;
				}
				else al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);

				/*-------------------*/

				/*----dokme saves----*/
			al_get_mouse_state(&mouse);
				if (check_mouse_position(&saves, &mouse)) {
					al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
					if (!swbtndown) if (al_mouse_button_down(&mouse, 1))
					{
						swbtndown = true;
						startpreviuosgame = fopen("startpreviuosgame.txt", "rt");
						if (!startpreviuosgame) {
							printf("cant open previous game");
							return 0;
						}
						int a;
						fscanf_s(startpreviuosgame, "%d", &a);
						p1_1 = (((a - 29) / 3) + 100) / 6521;
						fscanf_s(startpreviuosgame, "%d", &a);
						p1_2 = (((a - 29) / 3) + 100) / 6521;
						fscanf_s(startpreviuosgame, "%d", &a);
						count_close1 = (((a - 29) / 3) + 100) / 6521;
						fscanf_s(startpreviuosgame, "%d", &a);
						count_zarib1 = (((a - 29) / 3) + 100) / 6521;
						fscanf_s(startpreviuosgame, "%d", &a);
						count_mamnoo1 = (((a - 29) / 3) + 100) / 6521;
						fscanf_s(startpreviuosgame, "%d", &a);
						count_againdice1 = (((a - 29) / 3) + 100) / 6521;
						fscanf_s(startpreviuosgame, "%d", &a);
						p2_1 = (((a - 29) / 3) + 100) / 6521;
						fscanf_s(startpreviuosgame, "%d", &a);
						p2_2 = (((a - 29) / 3) + 100) / 6521;
						fscanf_s(startpreviuosgame, "%d", &a);
						count_close2 = (((a - 29) / 3) + 100) / 6521;
						fscanf_s(startpreviuosgame, "%d", &a);
						count_zarib2 = (((a - 29) / 3) + 100) / 6521;
						fscanf_s(startpreviuosgame, "%d", &a);
						count_mamnoo2 = (((a - 29) / 3) + 100) / 6521;
						fscanf_s(startpreviuosgame, "%d", &a);
						count_againdice2 = (((a - 29) / 3) + 100) / 6521;
						fscanf_s(startpreviuosgame, "%d", &a);
						sw_k3 = (((a - 29) / 3) + 100) / 6521;
						fscanf_s(startpreviuosgame, "%d", &a);
						sw_k15 = (((a - 29) / 3) + 100) / 6521;
						fscanf_s(startpreviuosgame, "%d", &a);
						sw_k24 = (((a - 29) / 3) + 100) / 6521;
						fscanf_s(startpreviuosgame, "%d", &a);
						sw_k35 = (((a - 29) / 3) + 100) / 6521;
						fscanf_s(startpreviuosgame, "%d", &a);
						sw_k46 = (((a - 29) / 3) + 100) / 6521;
						fscanf_s(startpreviuosgame, "%d", &a);
						sw_k57 = (((a - 29) / 3) + 100) / 6521;
						fscanf_s(startpreviuosgame, "%d", &a);
						sw_k70 = (((a - 29) / 3) + 100) / 6521;
						fscanf_s(startpreviuosgame, "%d", &a);
						sw_k77 = (((a - 29) / 3) + 100) / 6521;
						fscanf_s(startpreviuosgame, "%d", &a);
						sw_asli_1 = (((a - 29) / 3) + 100) / 6521;
						fscanf_s(startpreviuosgame, "%d", &a);
						sw_asli_2 = (((a - 29) / 3) + 100) / 6521;
						fscanf_s(startpreviuosgame, "%d", &a);
						sw_asli_3 = (((a - 29) / 3) + 100) / 6521;
						fscanf_s(startpreviuosgame, "%d", &a);
						sw_asli_4 = (((a - 29) / 3) + 100) / 6521;
						fscanf_s(startpreviuosgame, "%d", &a);
						i = (((a - 29) / 3) + 100) / 6521;
						fscanf_s(startpreviuosgame, "%d", &a);
						sw = (((a - 29) / 3) + 100) / 6521;
						fscanf_s(startpreviuosgame, "%d", &a);
						sw_komaki_1 = (((a - 29) / 3) + 100) / 6521;
						fscanf_s(startpreviuosgame, "%d", &a);
						sw_komaki_2 = (((a - 29) / 3) + 100) / 6521;
						fscanf_s(startpreviuosgame, "%d", &a);
						sw_komaki_3 = (((a - 29) / 3) + 100) / 6521;
						fscanf_s(startpreviuosgame, "%d", &a);
						sw_komaki_4 = (((a - 29) / 3) + 100) / 6521;
						fclose(startpreviuosgame);
						//sw = player_1_befor;

						ALLEGRO_AUDIO_STREAM* click1 = al_load_audio_stream("1.mp3", 2, 2048);
						must_init(click1, "mouse_click_sfx");
						al_set_audio_stream_playmode(click1, _ALLEGRO_PLAYMODE_STREAM_LOOP_ONCE);
						al_attach_audio_stream_to_mixer(click1, al_get_default_mixer());
						al_set_audio_stream_playmode(music, ALLEGRO_PLAYMODE_LOOP);
						al_attach_audio_stream_to_mixer(music, al_get_default_mixer());
					}
					if (!al_mouse_button_down(&mouse, 1))  swbtndown = false;
				}
				else al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
				/*-------------------*/

				/*dokme rules of game*/
				al_get_mouse_state(&mouse);
				if (check_mouse_position(&rules_of_game, &mouse)) {
					al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
					if (!swbtndown) if (al_mouse_button_down(&mouse, 1))
					{
						swbtndown = true;
						sw = flip;

						ALLEGRO_AUDIO_STREAM* click1 = al_load_audio_stream("1.mp3", 2, 2048);
						must_init(click1, "mouse_click_sfx");
						al_set_audio_stream_playmode(click1, _ALLEGRO_PLAYMODE_STREAM_LOOP_ONCE);
						al_attach_audio_stream_to_mixer(click1, al_get_default_mixer());
						al_set_audio_stream_playmode(music, ALLEGRO_PLAYMODE_LOOP);
						al_attach_audio_stream_to_mixer(music, al_get_default_mixer());
					}
					if (!al_mouse_button_down(&mouse, 1))  swbtndown = false;
				}
				else al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
				/*-------------------*/
				/*dokme about*/
				al_get_mouse_state(&mouse);
				if (check_mouse_position(&about, &mouse)) {
					al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
					if (!swbtndown) if (al_mouse_button_down(&mouse, 1))
					{
						swbtndown = true;
						sw = about_us;

						ALLEGRO_AUDIO_STREAM* click1 = al_load_audio_stream("1.mp3", 2, 2048);
						must_init(click1, "mouse_click_sfx");
						al_set_audio_stream_playmode(click1, _ALLEGRO_PLAYMODE_STREAM_LOOP_ONCE);
						al_attach_audio_stream_to_mixer(click1, al_get_default_mixer());
					}
					if (!al_mouse_button_down(&mouse, 1))  swbtndown = false;
				}
				else al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
				/**/
				/**/
				al_get_mouse_state(&mouse);
				if (check_mouse_position(&exit, &mouse)) {
					al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
					if (!swbtndown) if (al_mouse_button_down(&mouse, 1))
					{
						swbtndown = true;
						sw = exit_game;
						
						al_set_audio_stream_playmode(click, ALLEGRO_PLAYMODE_LOOP_ONCE);
						al_attach_audio_stream_to_mixer(click, al_get_default_mixer());
					}
					if (!al_mouse_button_down(&mouse, 1))  swbtndown = false;
				}
				else al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
				
				break;

			case about_us :
				al_clear_to_color(al_map_rgb(0, 0, 0));
				al_draw_bitmap(menu_about, 0, 0, 0);
				al_get_mouse_state(&mouse);
				if (check_mouse_position(&exitgame, &mouse)) {
					al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
					if (!swbtndown) if (al_mouse_button_down(&mouse, 1))
					{
						swbtndown = true;
						sw = first_menu;

						ALLEGRO_AUDIO_STREAM* click1 = al_load_audio_stream("1.mp3", 2, 2048);
						must_init(click1, "mouse_click_sfx");
						al_set_audio_stream_playmode(click1, _ALLEGRO_PLAYMODE_STREAM_LOOP_ONCE);
						al_attach_audio_stream_to_mixer(click1, al_get_default_mixer());
						//al_destroy_audio_stream(click1);
					}
					if (!al_mouse_button_down(&mouse, 1))  swbtndown = false;
				}
				else al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
				al_draw_text(font_menu1, al_map_rgb(149, 11, 65), 1100, 650, 0, "exit");
				break;

			case exit_game:
				return 0;
				break;


























			case player_1_befor:
				lable1:
				al_clear_to_color(al_map_rgb(0, 0, 0));
				sw1 = 0;
				sw2 = 0;
				sw3 = 0;
				sw4 = 0;
				j = 0;
				sw_komaki_1 = 1;
				sw_komaki_2 = 1;
				al_get_mouse_state(&mouse);
				if (check_mouse_position(&tas, &mouse)) {
					al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
					if (!swbtndown) if (al_mouse_button_down(&mouse, 1))
					{
						swbtndown = true;
						i = tas_partab();
						//sw = player_1;
						printf("\ntasssssssssss : %d", i);
						sw = player_1;
						/*if (i == 3) {
							sw_asli_1 = 1;
							sw_asli_2 = 1;
						}*/
						ALLEGRO_AUDIO_STREAM* dicerolling = al_load_audio_stream("dice.mp3", 2, 2048);
						must_init(dicerolling, "mouse_click_sfx");
						al_set_audio_stream_playmode(dicerolling, _ALLEGRO_PLAYMODE_STREAM_LOOP_ONCE);
						al_attach_audio_stream_to_mixer(dicerolling, al_get_default_mixer());
					}
					if (!al_mouse_button_down(&mouse, 1))  swbtndown = false;
				}
				else al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
				al_get_mouse_state(&mouse);
				if (check_mouse_position(&exitgame, &mouse)) {
					al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
					if (!swbtndown) if (al_mouse_button_down(&mouse, 1))
					{
						swbtndown = true;
						sw = exit_game;


						ALLEGRO_AUDIO_STREAM* click1 = al_load_audio_stream("1.mp3", 2, 2048);
						must_init(click1, "mouse_click_sfx");
						al_set_audio_stream_playmode(click1, _ALLEGRO_PLAYMODE_STREAM_LOOP_ONCE);
						al_attach_audio_stream_to_mixer(click1, al_get_default_mixer());
					}
					if (!al_mouse_button_down(&mouse, 1))  swbtndown = false;
				}
				else al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);

				al_get_mouse_state(&mouse);
				if (check_mouse_position(&first, &mouse)) {
					al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
					if (!swbtndown) if (al_mouse_button_down(&mouse, 1))
					{
						swbtndown = true;
						sw = first_menu;


						ALLEGRO_AUDIO_STREAM* click1 = al_load_audio_stream("1.mp3", 2, 2048);
						must_init(click1, "mouse_click_sfx");
						al_set_audio_stream_playmode(click1, _ALLEGRO_PLAYMODE_STREAM_LOOP_ONCE);
						al_attach_audio_stream_to_mixer(click1, al_get_default_mixer());
					}
					if (!al_mouse_button_down(&mouse, 1))  swbtndown = false;
				}
				else al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);

				al_draw_bitmap(pas, 0, 0, 0);
				al_draw_text(font1, al_map_rgb(34, 139, 34), 270, 0, 0, "MEET IN THE MIDDLE");
				al_draw_bitmap(map, 210, 75, 0);

				al_draw_text(font_menu1, al_map_rgb(102, 51, 153), 525, 650, 0, "menu");

				al_draw_text(font_menu1, al_map_rgb(102, 51, 153), 1100, 650, 0, "exit");
				al_draw_text(font3, al_map_rgb(165, 42, 42), 0, 0, 0, "turn player 1");
				al_draw_filled_circle(k[p1_1].x, k[p1_1].y, 20, al_map_rgb_f(1, 0, 0), 5);
				al_draw_circle(k[p1_2].x, k[p1_2].y, 20, al_map_rgb_f(1, 0, 0), 5);
				al_draw_filled_circle(k[p2_1].x, k[p2_1].y, 20, al_map_rgb_f(0, 0, 1), 5);
				al_draw_circle(k[p2_2].x, k[p2_2].y, 20, al_map_rgb_f(0, 0, 1), 5);

				al_draw_rectangle(150, 150, 180, 190, al_map_rgb(165, 42, 42), 5);
				al_draw_rectangle(150, 235, 180, 275, al_map_rgb(165, 42, 42), 5);
				al_draw_rectangle(150, 305, 180, 345, al_map_rgb(165, 42, 42), 5);
				al_draw_rectangle(150, 370, 180, 410, al_map_rgb(165, 42, 42), 5);
				al_draw_rectangle(1000, 150, 1030, 190, al_map_rgb(23, 77, 239), 5);
				al_draw_rectangle(1000, 235, 1030, 275, al_map_rgb(23, 77, 239), 5);
				al_draw_rectangle(1000, 305, 1030, 345, al_map_rgb(23, 77, 239), 5);
				al_draw_rectangle(1000, 370, 1030, 410, al_map_rgb(23, 77, 239), 5);
				if (count_close1 == 0) al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 155, 100, "0");
				if (count_zarib1 == 0)al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 240, 100, "0");
				if (count_mamnoo1 == 0)al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 310, 100, "0");
				if (count_againdice1 == 0)al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 375, 100, "0");
				if (count_close1 == 1) al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 155, 100, "1");
				if (count_zarib1 == 1)al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 240, 100, "1");
				if (count_mamnoo1 == 1)al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 310, 100, "1");
				if (count_againdice1 == 1)al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 375, 100, "1");
				if (count_close1 == 2) al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 155, 100, "2");
				if (count_zarib1 == 2)al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 240, 100, "2");
				if (count_mamnoo1 == 2)al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 310, 100, "2");
				if (count_againdice1 == 2)al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 375, 100, "2");

				if (count_close2 == 0) al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 155, 100, "0");
				if (count_zarib2 == 0)al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 240, 100, "0");
				if (count_mamnoo2 == 0)al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 310, 100, "0");
				if (count_againdice2 == 0)al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 375, 100, "0");
				if (count_close2 == 1) al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 155, 100, "1");
				if (count_zarib2 == 1)al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 240, 100, "1");
				if (count_mamnoo2 == 1)al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 310, 100, "1");
				if (count_againdice2 == 1)al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 375, 100, "1");
				if (count_close2 == 2) al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 155, 100, "2");
				if (count_zarib2 == 2)al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 240, 100, "2");
				if (count_mamnoo2 == 2)al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 310, 100, "2");
				if (count_againdice2 == 2)al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 375, 100, "2");


				al_draw_text(font3, al_map_rgb(165, 42, 42), 0, 450, 0, "click");
				al_draw_text(font3, al_map_rgb(165, 42, 42), 0, 490, 0, "to roll");
				al_draw_text(font3, al_map_rgb(165, 42, 42), 0, 530, 0, "the dice");

				/*al_draw_bitmap(tas1, 1050, 525, 0);
				al_draw_bitmap(tas2, 1050, 525, 0);
				al_draw_bitmap(tas3, 1050, 525, 0);
				al_draw_bitmap(tas_1, 1050, 525, 0);
				al_draw_bitmap(tas_2, 1050, 525, 0);
				al_draw_bitmap(tas_3, 1050, 525, 0);*/



				al_draw_text(font2, al_map_rgb(255, 0, 0), 10, 60, 100, "player 1");
				al_draw_text(font2, al_map_rgb(0, 0, 255), 1010, 60, 100, "player 2");

				al_draw_bitmap(close, 10, 130, 0);
				al_draw_bitmap(zarib, 10, 225, 0);
				al_draw_bitmap(mamnoo, 10, 300, 0);
				al_draw_bitmap(againdice, 10, 360, 0);
				al_draw_bitmap(close, 1120, 130, 0);
				al_draw_bitmap(zarib, 1090, 225, 0);
				al_draw_bitmap(mamnoo, 1139, 300, 0);
				al_draw_bitmap(againdice, 1133, 360, 0);
				break;

































			case player_2_befor:
				lable2:
				al_clear_to_color(al_map_rgb(0, 0, 0));
				sw1 = 0;
				sw2 = 0;
				sw3 = 0;
				sw4 = 0;
				j = 0;
				sw_komaki_3 = 1;
				sw_komaki_4 = 1;
				al_get_mouse_state(&mouse);
				if (check_mouse_position(&tas, &mouse)) {
					al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
					if (!swbtndown) if (al_mouse_button_down(&mouse, 1))
					{
						swbtndown = true;
					    i = tas_partab();
						printf("\ntasssssssssss : %d", i);
						ALLEGRO_AUDIO_STREAM* dicerolling = al_load_audio_stream("dice.mp3", 2, 2048);
						must_init(dicerolling, "mouse_click_sfx");
						al_set_audio_stream_playmode(dicerolling, _ALLEGRO_PLAYMODE_STREAM_LOOP_ONCE);
						al_attach_audio_stream_to_mixer(dicerolling, al_get_default_mixer());

						sw = player_2;
					}
					if (!al_mouse_button_down(&mouse, 1))  swbtndown = false;
				}
				else al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
				al_get_mouse_state(&mouse);
				if (check_mouse_position(&exitgame, &mouse)) {
					al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
					if (!swbtndown) if (al_mouse_button_down(&mouse, 1))
					{
						swbtndown = true;
						sw = exit_game;


						ALLEGRO_AUDIO_STREAM* click1 = al_load_audio_stream("1.mp3", 2, 2048);
						must_init(click1, "mouse_click_sfx");
						al_set_audio_stream_playmode(click1, _ALLEGRO_PLAYMODE_STREAM_LOOP_ONCE);
						al_attach_audio_stream_to_mixer(click1, al_get_default_mixer());
					}
					if (!al_mouse_button_down(&mouse, 1))  swbtndown = false;
				}
				else al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);

				al_get_mouse_state(&mouse);
				if (check_mouse_position(&first, &mouse)) {
					al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
					if (!swbtndown) if (al_mouse_button_down(&mouse, 1))
					{
						swbtndown = true;
						sw = first_menu;


						ALLEGRO_AUDIO_STREAM* click1 = al_load_audio_stream("1.mp3", 2, 2048);
						must_init(click1, "mouse_click_sfx");
						al_set_audio_stream_playmode(click1, _ALLEGRO_PLAYMODE_STREAM_LOOP_ONCE);
						al_attach_audio_stream_to_mixer(click1, al_get_default_mixer());
					}
					if (!al_mouse_button_down(&mouse, 1))  swbtndown = false;
				}
				else al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);

				al_draw_bitmap(pas, 0, 0, 0);
				al_draw_text(font1, al_map_rgb(34, 139, 34), 270, 0, 0, "MEET IN THE MIDDLE");
				al_draw_bitmap(map, 210, 75, 0);

				al_draw_text(font_menu1, al_map_rgb(102, 51, 153), 525, 650, 0, "menu");
				al_draw_text(font_menu1, al_map_rgb(102, 51, 153), 1100, 650, 0, "exit");
				al_draw_text(font3, al_map_rgb(23, 77, 239), 1000, 0, 0, "turn player 2");
				al_draw_filled_circle(k[p1_1].x, k[p1_1].y, 20, al_map_rgb_f(1, 0, 0), 5);
				al_draw_circle(k[p1_2].x, k[p1_2].y, 20, al_map_rgb_f(1, 0, 0), 5);
				al_draw_filled_circle(k[p2_1].x, k[p2_1].y, 20, al_map_rgb_f(0, 0, 1), 5);
				al_draw_circle(k[p2_2].x, k[p2_2].y, 20, al_map_rgb_f(0, 0, 1), 5);
				al_draw_rectangle(150, 150, 180, 190, al_map_rgb(165, 42, 42), 5);
				al_draw_rectangle(150, 235, 180, 275, al_map_rgb(165, 42, 42), 5);
				al_draw_rectangle(150, 305, 180, 345, al_map_rgb(165, 42, 42), 5);
				al_draw_rectangle(150, 370, 180, 410, al_map_rgb(165, 42, 42), 5);
				al_draw_rectangle(1000, 150, 1030, 190, al_map_rgb(23, 77, 239), 5);
				al_draw_rectangle(1000, 235, 1030, 275, al_map_rgb(23, 77, 239), 5);
				al_draw_rectangle(1000, 305, 1030, 345, al_map_rgb(23, 77, 239), 5);
				al_draw_rectangle(1000, 370, 1030, 410, al_map_rgb(23, 77, 239), 5);
				if (count_close1 == 0) al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 155, 100, "0");
				if (count_zarib1 == 0)al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 240, 100, "0");
				if (count_mamnoo1 == 0)al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 310, 100, "0");
				if (count_againdice1 == 0)al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 375, 100, "0");
				if (count_close1 == 1) al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 155, 100, "1");
				if (count_zarib1 == 1)al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 240, 100, "1");
				if (count_mamnoo1 == 1)al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 310, 100, "1");
				if (count_againdice1 == 1)al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 375, 100, "1");
				if (count_close1 == 2) al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 155, 100, "2");
				if (count_zarib1 == 2)al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 240, 100, "2");
				if (count_mamnoo1 == 2)al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 310, 100, "2");
				if (count_againdice1 == 2)al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 375, 100, "2");

				if (count_close2 == 0) al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 155, 100, "0");
				if (count_zarib2 == 0)al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 240, 100, "0");
				if (count_mamnoo2 == 0)al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 310, 100, "0");
				if (count_againdice2 == 0)al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 375, 100, "0");
				if (count_close2 == 1) al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 155, 100, "1");
				if (count_zarib2 == 1)al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 240, 100, "1");
				if (count_mamnoo2 == 1)al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 310, 100, "1");
				if (count_againdice2 == 1)al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 375, 100, "1");
				if (count_close2 == 2) al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 155, 100, "2");
				if (count_zarib2 == 2)al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 240, 100, "2");
				if (count_mamnoo2 == 2)al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 310, 100, "2");
				if (count_againdice2 == 2)al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 375, 100, "2");

				al_draw_text(font3, al_map_rgb(23, 77, 239), 0, 450, 0, "click");
				al_draw_text(font3, al_map_rgb(23, 77, 239), 0, 490, 0, "to roll");
				al_draw_text(font3, al_map_rgb(23, 77, 239), 0, 530, 0, "the dice");
				
				/*al_draw_bitmap(tas1, 1050, 525, 0);
				al_draw_bitmap(tas2, 1050, 525, 0);
				al_draw_bitmap(tas3, 1050, 525, 0);
				al_draw_bitmap(tas_1, 1050, 525, 0);
				al_draw_bitmap(tas_2, 1050, 525, 0);
				al_draw_bitmap(tas_3, 1050, 525, 0);*/



				al_draw_text(font2, al_map_rgb(255, 0, 0), 10, 60, 100, "player 1");
				al_draw_text(font2, al_map_rgb(0, 0, 255), 1010, 60, 100, "player 2");

				al_draw_bitmap(close, 10, 130, 0);
				al_draw_bitmap(zarib, 10, 225, 0);
				al_draw_bitmap(mamnoo, 10, 300, 0);
				al_draw_bitmap(againdice, 10, 360, 0);
				al_draw_bitmap(close, 1120, 130, 0);
				al_draw_bitmap(zarib, 1090, 225, 0);
				al_draw_bitmap(mamnoo, 1139, 300, 0);
				al_draw_bitmap(againdice, 1133, 360, 0);
				break;


































			case player_1:
				//al_get_keyboard_state();
				//j = 1;
				al_clear_to_color(al_map_rgb(0, 0, 0));

				/*dastoorate close door*/
				al_get_mouse_state(&mouse);
				if (check_mouse_position(&close1, &mouse)) {
					al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
					if (!swbtndown) if (al_mouse_button_down(&mouse, 1))
					{
						swbtndown = true;
						if (count_close1 > 0) {
							sw1 = 1;
							sw2 = 1;
							sw3 = 1;
							sw4 = 1;
							count_close1--;
						}
						ALLEGRO_AUDIO_STREAM* click1 = al_load_audio_stream("1.mp3", 2, 2048);
						must_init(click1, "mouse_click_sfx");
						al_set_audio_stream_playmode(click1, _ALLEGRO_PLAYMODE_STREAM_LOOP_ONCE);
						al_attach_audio_stream_to_mixer(click1, al_get_default_mixer());
					}
					if (!al_mouse_button_down(&mouse, 1))  swbtndown = false;
				}
				else al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
				/*-----------------------*/
				/*dastoorate  zarib*/
				al_get_mouse_state(&mouse);
				if (check_mouse_position(&zarib1, &mouse)) {
					al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
					if (!swbtndown) if (al_mouse_button_down(&mouse, 1))
					{
						swbtndown = true;
						if (count_zarib1 > 0) {
							i *= 2;
							count_zarib1--;
						}
						ALLEGRO_AUDIO_STREAM* click1 = al_load_audio_stream("1.mp3", 2, 2048);
						must_init(click1, "mouse_click_sfx");
						al_set_audio_stream_playmode(click1, _ALLEGRO_PLAYMODE_STREAM_LOOP_ONCE);
						al_attach_audio_stream_to_mixer(click1, al_get_default_mixer());

					}
					if (!al_mouse_button_down(&mouse, 1))  swbtndown = false;
				}
				else al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
				/*-----------------*/
				/*dastoorate again dice*/
				al_get_mouse_state(&mouse);
				if (check_mouse_position(&againdice1, &mouse)) {
					al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
					if (!swbtndown) if (al_mouse_button_down(&mouse, 1))
					{
						swbtndown = true;
						ALLEGRO_AUDIO_STREAM* click1 = al_load_audio_stream("1.mp3", 2, 2048);
						must_init(click1, "mouse_click_sfx");
						al_set_audio_stream_playmode(click1, _ALLEGRO_PLAYMODE_STREAM_LOOP_ONCE);
						al_attach_audio_stream_to_mixer(click1, al_get_default_mixer());
						if (count_againdice1 > 0) {
							sw = player_1_befor;
							count_againdice1--;
							goto lable1;
						}

					}
					if (!al_mouse_button_down(&mouse, 1))  swbtndown = false;
				}
				else al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
				/*---------------------*/
                /*dastoorat mahdoodiat*/
				al_get_mouse_state(&mouse);
				if (check_mouse_position(&mamnoo2, &mouse)) {
					al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
					if (!swbtndown) if (al_mouse_button_down(&mouse, 1))
					{
						swbtndown = true;
						if (count_mamnoo2 > 0) {
							sw = player_1_mamnoo_kardan;
							count_mamnoo2--;
						}
						ALLEGRO_AUDIO_STREAM* click1 = al_load_audio_stream("1.mp3", 2, 2048);
						must_init(click1, "mouse_click_sfx");
						al_set_audio_stream_playmode(click1, _ALLEGRO_PLAYMODE_STREAM_LOOP_ONCE);
						al_attach_audio_stream_to_mixer(click1, al_get_default_mixer());
					}
					if (!al_mouse_button_down(&mouse, 1))  swbtndown = false;
				}
				else al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
				/*---------------------*/
				/**/
				al_get_mouse_state(&mouse);
				if (check_mouse_position(&savegame, &mouse)) {
					al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
					if (!swbtndown) if (al_mouse_button_down(&mouse, 1))
					{
						swbtndown = true;
						startpreviuosgame = fopen("startpreviuosgame.txt", "wb");
						if (!startpreviuosgame) {
							printf("cant open previous game");
							return 0;
						}
						fprintf(startpreviuosgame, "%d\n", (((p1_1 * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((p1_2 * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((count_close1 * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((count_zarib1 * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((count_mamnoo1 * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((count_againdice1 * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((p2_1 * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((p2_2 * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((count_close2 * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((count_zarib2 * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((count_mamnoo2 * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((count_againdice2 * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((sw_k3 * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((sw_k15 * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((sw_k24 * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((sw_k35 * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((sw_k46 * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((sw_k57 * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((sw_k70 * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((sw_k77 * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((sw_asli_1 * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((sw_asli_2 * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((sw_asli_3 * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((sw_asli_4 * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((i * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((sw * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((sw_komaki_1 * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((sw_komaki_2 * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((sw_komaki_3 * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((sw_komaki_4 * 6521) - 100) * 3) + 29);
						fclose(startpreviuosgame);
						ALLEGRO_AUDIO_STREAM* click1 = al_load_audio_stream("1.mp3", 2, 2048);
						must_init(click1, "mouse_click_sfx");
						al_set_audio_stream_playmode(click1, _ALLEGRO_PLAYMODE_STREAM_LOOP_ONCE);
						al_attach_audio_stream_to_mixer(click1, al_get_default_mixer());

					}
					if (!al_mouse_button_down(&mouse, 1))  swbtndown = false;
				}
				else al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
				/**/
				/**/
				al_get_mouse_state(&mouse);
				if (check_mouse_position(&exitgame, &mouse)) {
					al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
					if (!swbtndown) if (al_mouse_button_down(&mouse, 1))
					{
						swbtndown = true;
						sw = exit_game;
						ALLEGRO_AUDIO_STREAM* click1 = al_load_audio_stream("1.mp3", 2, 2048);
						must_init(click1, "mouse_click_sfx");
						al_set_audio_stream_playmode(click1, _ALLEGRO_PLAYMODE_STREAM_LOOP_ONCE);
						al_attach_audio_stream_to_mixer(click1, al_get_default_mixer());


						al_set_audio_stream_playmode(music, ALLEGRO_PLAYMODE_LOOP);
						al_attach_audio_stream_to_mixer(music, al_get_default_mixer());
					}
					if (!al_mouse_button_down(&mouse, 1))  swbtndown = false;
				}
				else al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
				/**/
				/**/
				al_get_mouse_state(&mouse);
				if (check_mouse_position(&first, &mouse)) {
					al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
					if (!swbtndown) if (al_mouse_button_down(&mouse, 1))
					{
						swbtndown = true;
						sw = first_menu;


						ALLEGRO_AUDIO_STREAM* click1 = al_load_audio_stream("1.mp3", 2, 2048);
						must_init(click1, "mouse_click_sfx");
						al_set_audio_stream_playmode(click1, _ALLEGRO_PLAYMODE_STREAM_LOOP_ONCE);
						al_attach_audio_stream_to_mixer(click1, al_get_default_mixer());
					}
					if (!al_mouse_button_down(&mouse, 1))  swbtndown = false;
				}
				else al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
				/**/

				al_get_mouse_state(&mouse);
				if (check_mouse_position(&pl_pi1, &mouse)) {
					al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
					if (!swbtndown) if (al_mouse_button_down(&mouse, 1))
					{
						swbtndown = true;
						if (i == 3) sw_asli_1 = 1;
						if (sw_asli_1 == 1) {


						printf("\nfirst position of p1_1 : %d", p1_1);
						printf("\ntas : %d", i);

						if (sw_komaki_1 == 1) {



							if (p1_1 + i > 0) {
								p1_1 += (i);
								printf("\nsecond position of p1_1 : %d", p1_1);

								if (p1_1 == 5 && sw1 == 0) {
									p1_1 = 38;
									sw1 = 1;
								}
								if (p1_1 == 38 && sw1 == 0) {
									p1_1 = 5;
									sw1 = 1;
								}
								if (p1_1 == 21 && sw2 == 0) {
									p1_1 = 65;
									sw2 = 1;
								}
								if (p1_1 == 65 && sw2 == 0) {
									p1_1 = 21;
									sw2 = 1;
								}
								if (p1_1 == 25 && sw3 == 0) {
									p1_1 = 58;
									sw3 = 1;
								}
								if (p1_1 == 58 && sw3 == 0) {
									p1_1 = 25;
									sw3 = 1;
								}
								if (p1_1 == 42 && sw4 == 0) {
									p1_1 = 75;
									sw4 = 1;
								}
								if (p1_1 == 75 && sw4 == 0) {
									p1_1 = 42;
									sw4 = 1;
								}

								/*payan*/
								if (p1_1 == 40) {
									sw_asli_1 = 0;
								}

								if (p1_1 == 40 && p1_2 == 40) {
									printf("skgjghskjghskljghlsjg");
									al_destroy_audio_stream(music);
									sw = win1;
									goto lable4;
								}
								/*-----*/

								/*barkhord ha*/
								if (p1_1 == p2_1) {
									p2_1 = 80;
								}
								if (p1_1 == p2_2) {
									p2_2 = 80;
								}
								/*-----------*/

								/*khoone haye shanse 3 & 77*/ /*close door*/
								if (p1_1 == 3 && sw_k3 == 0) {
									count_close1++;
									sw_k3 = 1;
								}

								if (p1_1 == 77 && sw_k77 == 0) {
									count_close1++;
									sw_k77 = 1;
								}
								/*-----------------------------------------*/

								/*khoone haye shans 35 & 46*/ /*zarib*/
								if (p1_1 == 35 && sw_k15 == 0) {
									count_zarib1++;
									sw_k15 = 1;
								}

								if (p1_1 == 46 && sw_k46 == 0) {
									count_zarib1++;
									sw_k46 = 1;
								}
								/*-----------------------------------*/
								/*khoone haye shans 24 & 57*/ /*tas mojadad*/
								if (p1_1 == 24 && sw_k24 == 0) {
									count_againdice1++;
									sw_k24 = 1;
								}

								if (p1_1 == 57 && sw_k57 == 0) {
									count_againdice1++;
									sw_k57 = 1;
								}
								/*-----------------------------------------*/
								/*khoone haye shans 15 & 70*/ /*mahdoodiat*/
								if (p1_1 == 15 && sw_k15 == 0) {
									count_mamnoo1++;
									sw_k15 = 1;
								}

								if (p1_1 == 70 && sw_k70 == 0) {
									count_mamnoo1++;
									sw_k70 = 1;
								}
								/*-----------------------------------------*/
							}
							else {
								p1_1 = 0;
								printf("\nsecond position of p1_1 : %d", p1_1);
							}
							sw = player_2_befor;
						}
					}
					else {
						sw = player_2_befor;
						}
						ALLEGRO_AUDIO_STREAM* click1 = al_load_audio_stream("1.mp3", 2, 2048);
						must_init(click1, "mouse_click_sfx");
						al_set_audio_stream_playmode(click1, _ALLEGRO_PLAYMODE_STREAM_LOOP_ONCE);
						al_attach_audio_stream_to_mixer(click1, al_get_default_mixer());
					}
					if (!al_mouse_button_down(&mouse, 1))  swbtndown = false;
				}
				else al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);

				al_get_mouse_state(&mouse);
				if (check_mouse_position(&pl_pi2, &mouse)) {
					al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
					if (!swbtndown) if (al_mouse_button_down(&mouse, 1))
					{
						swbtndown = true;
						printf("\nfirst position of p1_2 : %d", p1_2);
						printf("\ntas : %d", i);
						if (i == 3)sw_asli_2 = 1;

						if (sw_asli_2 == 1) {



							if (sw_komaki_2 == 1) {


								if (p1_2 + i > 0) {
									p1_2 += (i);
									printf("\nsecond position of p1_2 : %d", p1_2);
									if (p1_2 == 5 && sw1 == 0) {
										p1_2 = 38;
										sw1 = 1;
									}
									if (p1_2 == 38 && sw1 == 0) {
										p1_2 = 5;
										sw1 = 1;
									}
									if (p1_2 == 21 && sw2 == 0) {
										p1_2 = 65;
										sw2 = 1;
									}
									if (p1_2 == 65 && sw2 == 0) {
										p1_2 = 21;
										sw2 = 1;
									}
									if (p1_2 == 25 && sw3 == 0) {
										p1_2 = 58;
										sw3 = 1;
									}
									if (p1_2 == 58 && sw3 == 0) {
										p1_2 = 25;
										sw3 = 1;
									}
									if (p1_2 == 42 && sw4 == 0) {
										p1_2 = 75;
										sw4 = 1;
									}
									if (p1_2 == 75 && sw4 == 0) {
										p1_2 = 42;
										sw4 = 1;
									}


									/*payan*/
									if (p1_2 == 40) {
										sw_asli_2 = 0;
									}

									if (p1_1 == 40 && p1_2 == 40) {
										printf("skgjghskjghskljghlsjg");
										al_destroy_audio_stream(music);
										sw = win1;
										goto lable4;
									}
									/*-----*/

									/*barkhord ha*/
									if (p1_2 == p2_1) {
										p2_1 = 80;
									}
									if (p1_2 == p2_2) {
										p2_2 = 80;
									}
									/*-----------*/

									/*khoone haye shanse 3 & 77*/ /*close door*/
									if (p1_2 == 3 && sw_k3 == 0) {
										count_close1++;
										sw_k3 = 1;
									}

									if (p1_2 == 77 && sw_k77 == 0) {
										count_close1++;
										sw_k77 = 1;
									}
									/*-----------------------------------------*/


									/*-----------------------------------------*/
									/*khoone haye shans 35 & 46*/ /*zarib*/
									if (p1_2 == 35 && sw_k15 == 0) {
										count_zarib1++;
										sw_k15 = 1;
									}

									if (p1_2 == 46 && sw_k46 == 0) {
										count_zarib1++;
										sw_k46 = 1;
									}
									/*-----------------------------------*/
									/*khoone haye shans 24 & 57*/ /*tas mojadad*/
									if (p1_2 == 24 && sw_k24 == 0) {
										count_againdice1++;
										sw_k24 = 1;
									}

									if (p1_2 == 57 && sw_k57 == 0) {
										count_againdice1++;
										sw_k57 = 1;
									}
									/*-----------------------------------------*/
									/*khoone haye shans 15 & 70*/ /*mahdoodiat*/
									if (p1_2 == 15 && sw_k15 == 0) {
										count_mamnoo1++;
										sw_k15 = 1;
									}

									if (p1_2 == 70 && sw_k70 == 0) {
										count_mamnoo1++;
										sw_k70 = 1;
									}
									/*-----------------------------------------*/
								}
								else {
									p1_2 = 0;
									printf("\nsecond position of p1_1 : %d", p1_2);
								}
								sw = player_2_befor;
							}
						}
						else {
							sw = player_2_befor;
						}
						ALLEGRO_AUDIO_STREAM* click1 = al_load_audio_stream("1.mp3", 2, 2048);
						must_init(click1, "mouse_click_sfx");
						al_set_audio_stream_playmode(click1, _ALLEGRO_PLAYMODE_STREAM_LOOP_ONCE);
						al_attach_audio_stream_to_mixer(click1, al_get_default_mixer());
					}
					if (!al_mouse_button_down(&mouse, 1))  swbtndown = false;
				}
				else al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);

				al_draw_bitmap(pas, 0, 0, 0);
				al_draw_text(font1, al_map_rgb(34, 139, 34), 270, 0, 0, "MEET IN THE MIDDLE");
				al_draw_bitmap(map, 210, 75, 0);

				al_draw_text(font_menu1, al_map_rgb(102, 51, 153), 525, 650, 0, "menu");
				al_draw_text(font_menu1, al_map_rgb(102, 51, 153), 1100, 650, 0, "exit");
				al_draw_text(font3, al_map_rgb(165, 42, 42), 0, 0, 0, "turn player 1");
				al_draw_filled_circle(k[p1_1].x, k[p1_1].y, 20, al_map_rgb_f(1, 0, 0), 5);
				al_draw_circle(k[p1_2].x, k[p1_2].y, 20, al_map_rgb_f(1, 0, 0), 5);
				al_draw_filled_circle(k[p2_1].x, k[p2_1].y, 20, al_map_rgb_f(0, 0, 1), 5);
				al_draw_circle(k[p2_2].x, k[p2_2].y, 20, al_map_rgb_f(0, 0, 1), 5);
				//al_draw_filled_circle(110, 150, 20, al_map_rgba_f(0, 0, 0.5, 1));
				al_draw_text(font_menu2, al_map_rgb(165, 42, 42), 0, 450, 0, "choose");
				al_draw_text(font_menu2, al_map_rgb(165, 42, 42), 0, 490, 0, "your");
				al_draw_text(font_menu2, al_map_rgb(165, 42, 42), 0, 540, 0, "piece");
				al_draw_text(font_menu2, al_map_rgb(165, 42, 42), 150, 490, 0, "1");
				al_draw_text(font_menu2, al_map_rgb(165, 42, 42), 150, 540, 0, "2");
				al_draw_text(font_menu2, al_map_rgb(102, 51, 153), 0, 665, 0, "save");
				al_draw_rectangle(145, 490, 175, 530, al_map_rgb(165, 42, 42), 5);
				al_draw_rectangle(145, 540, 180, 580, al_map_rgb(165, 42, 42), 5);

				al_draw_rectangle(150, 150, 180, 190, al_map_rgb(165, 42, 42), 5);
				al_draw_rectangle(150, 235, 180, 275, al_map_rgb(165, 42, 42), 5);
				al_draw_rectangle(150, 305, 180, 345, al_map_rgb(165, 42, 42), 5);
				al_draw_rectangle(150, 370, 180, 410, al_map_rgb(165, 42, 42), 5);
				al_draw_rectangle(1000, 150, 1030, 190, al_map_rgb(23, 77, 239), 5);
				al_draw_rectangle(1000, 235, 1030, 275, al_map_rgb(23, 77, 239), 5);
				al_draw_rectangle(1000, 305, 1030, 345, al_map_rgb(23, 77, 239), 5);
				al_draw_rectangle(1000, 370, 1030, 410, al_map_rgb(23, 77, 239), 5);
				if (count_close1 == 0) al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 155, 100, "0");
				if (count_zarib1 == 0)al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 240, 100, "0");
				if (count_mamnoo1 == 0)al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 310, 100, "0");
				if (count_againdice1 == 0)al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 375, 100, "0");
				if (count_close1 == 1) al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 155, 100, "1");
				if (count_zarib1 == 1)al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 240, 100, "1");
				if (count_mamnoo1 == 1)al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 310, 100, "1");
				if (count_againdice1 == 1)al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 375, 100, "1");
				if (count_close1 == 2) al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 155, 100, "2");
				if (count_zarib1 == 2)al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 240, 100, "2");
				if (count_mamnoo1 == 2)al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 310, 100, "2");
				if (count_againdice1 == 2)al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 375, 100, "2");

				if (count_close2 == 0) al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 155, 100, "0");
				if (count_zarib2 == 0)al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 240, 100, "0");
				if (count_mamnoo2 == 0)al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 310, 100, "0");
				if (count_againdice2 == 0)al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 375, 100, "0");
				if (count_close2 == 1) al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 155, 100, "1");
				if (count_zarib2 == 1)al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 240, 100, "1");
				if (count_mamnoo2 == 1)al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 310, 100, "1");
				if (count_againdice2 == 1)al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 375, 100, "1");
				if (count_close2 == 2) al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 155, 100, "2");
				if (count_zarib2 == 2)al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 240, 100, "2");
				if (count_mamnoo2 == 2)al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 310, 100, "2");
				if (count_againdice2 == 2)al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 375, 100, "2");
				
				if (i == 1)al_draw_bitmap(tas1, 1050, 525, 0);
				if (i == 2) al_draw_bitmap(tas2, 1050, 525, 0);
				if (i == 3)al_draw_bitmap(tas3, 1050, 525, 0);
				if (i == -1)al_draw_bitmap(tas_1, 1050, 525, 0);
				if (i == -2)al_draw_bitmap(tas_2, 1050, 525, 0);
				if (i == -3)al_draw_bitmap(tas_3, 1050, 525, 0);

				/*if (j != 0) {
					if (j == 1)al_draw_bitmap(tas1, 1050, 440, 0);
					if (j == 2) al_draw_bitmap(tas2, 1050, 440, 0);
					if (j == 3)al_draw_bitmap(tas3, 1050, 440, 0);
					if (j == -1)al_draw_bitmap(tas_1, 1050, 440, 0);
					if (j == -2)al_draw_bitmap(tas_2, 1050, 440, 0);
					if (j == -3)al_draw_bitmap(tas_3, 1050, 440, 0);
				}*/

				al_draw_text(font2, al_map_rgb(255, 0, 0), 10, 60, 100, "player 1");
				al_draw_text(font2, al_map_rgb(0, 0, 255), 1010, 60, 100, "player 2");

				al_draw_bitmap(close, 10, 130, 0);
				al_draw_bitmap(zarib, 10, 225, 0);
				al_draw_bitmap(mamnoo, 10, 300, 0);
				al_draw_bitmap(againdice, 10, 360, 0);
				al_draw_bitmap(close, 1120, 130, 0);
				al_draw_bitmap(zarib, 1090, 225, 0);
				al_draw_bitmap(mamnoo, 1139, 300, 0);
				al_draw_bitmap(againdice, 1133, 360, 0);
				break;
				//salam






























			case player_2:
				al_clear_to_color(al_map_rgb(0, 0, 0));
				//j = 1;
				/*dastoorate close door*/
				al_get_mouse_state(&mouse);
				if (check_mouse_position(&close2, &mouse)) {
					al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
					if (!swbtndown) if (al_mouse_button_down(&mouse, 1))
					{
						swbtndown = true;
						if (count_close2 > 0) {
							sw1 = 1;
							sw2 = 1;
							sw3 = 1;
							sw4 = 1;
							count_close2--;
						}
						ALLEGRO_AUDIO_STREAM* click1 = al_load_audio_stream("1.mp3", 2, 2048);
						must_init(click1, "mouse_click_sfx");
						al_set_audio_stream_playmode(click1, _ALLEGRO_PLAYMODE_STREAM_LOOP_ONCE);
						al_attach_audio_stream_to_mixer(click1, al_get_default_mixer());
					}
					if (!al_mouse_button_down(&mouse, 1))  swbtndown = false;
				}
				else al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
				/*---------------------*/
			    /*dastoorate  zarib*/
				al_get_mouse_state(&mouse);
				if (check_mouse_position(&zarib2, &mouse)) {
					al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
					if (!swbtndown) if (al_mouse_button_down(&mouse, 1))
					{
						swbtndown = true;
						if (count_zarib2 > 0) {
							i *= 2;
							count_zarib2--;
						}
						ALLEGRO_AUDIO_STREAM* click1 = al_load_audio_stream("1.mp3", 2, 2048);
						must_init(click1, "mouse_click_sfx");
						al_set_audio_stream_playmode(click1, _ALLEGRO_PLAYMODE_STREAM_LOOP_ONCE);
						al_attach_audio_stream_to_mixer(click1, al_get_default_mixer());
					}
					if (!al_mouse_button_down(&mouse, 1))  swbtndown = false;
				}
				else al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
				/*-----------------*/
				/*dastoorate again dice*/
				al_get_mouse_state(&mouse);
				if (check_mouse_position(&againdice2, &mouse)) {
					al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
					if (!swbtndown) if (al_mouse_button_down(&mouse, 1))
					{
						swbtndown = true;
						ALLEGRO_AUDIO_STREAM* click1 = al_load_audio_stream("1.mp3", 2, 2048);
						must_init(click1, "mouse_click_sfx");
						al_set_audio_stream_playmode(click1, _ALLEGRO_PLAYMODE_STREAM_LOOP_ONCE);
						al_attach_audio_stream_to_mixer(click1, al_get_default_mixer());
						if (count_againdice2 > 0) {
							sw = player_2_befor;
							count_againdice2--;
							goto lable2;
						}

					}
					if (!al_mouse_button_down(&mouse, 1))  swbtndown = false;
				}
				else al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
				/*---------------------*/
				/*dastoorat mahdoodiat*/
				al_get_mouse_state(&mouse);
				if (check_mouse_position(&mamnoo1, &mouse)) {
					al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
					if (!swbtndown) if (al_mouse_button_down(&mouse, 1))
					{
						swbtndown = true;
						if (count_mamnoo1 > 0) {
							sw = player_2_mamnoo_kardan;
							count_mamnoo1--;
						}
						ALLEGRO_AUDIO_STREAM* click1 = al_load_audio_stream("1.mp3", 2, 2048);
						must_init(click1, "mouse_click_sfx");
						al_set_audio_stream_playmode(click1, _ALLEGRO_PLAYMODE_STREAM_LOOP_ONCE);
						al_attach_audio_stream_to_mixer(click1, al_get_default_mixer());
					}
					if (!al_mouse_button_down(&mouse, 1))  swbtndown = false;
				}
				else al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
				/*---------------------*/
				/**/
				al_get_mouse_state(&mouse);
				if (check_mouse_position(&savegame, &mouse)) {
					al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
					if (!swbtndown) if (al_mouse_button_down(&mouse, 1))
					{
						swbtndown = true;
						startpreviuosgame = fopen("startpreviuosgame.txt", "wb");
						if (!startpreviuosgame) {
							printf("cant open previous game");
							return 0;
						}
						fprintf(startpreviuosgame, "%d\n", (((p1_1 * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((p1_2 * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((count_close1 * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((count_zarib1 * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((count_mamnoo1 * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((count_againdice1 * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((p2_1 * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((p2_2 * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((count_close2 * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((count_zarib2 * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((count_mamnoo2 * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((count_againdice2 * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((sw_k3 * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((sw_k15 * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((sw_k24 * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((sw_k35 * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((sw_k46 * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((sw_k57 * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((sw_k70 * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((sw_k77 * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((sw_asli_1 * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((sw_asli_2 * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((sw_asli_3 * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((sw_asli_4 * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((i * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((sw * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((sw_komaki_1 * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((sw_komaki_2 * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((sw_komaki_3 * 6521) - 100) * 3) + 29);
						fprintf(startpreviuosgame, "%d\n", (((sw_komaki_4 * 6521) - 100) * 3) + 29);
						fclose(startpreviuosgame);
						ALLEGRO_AUDIO_STREAM* click1 = al_load_audio_stream("1.mp3", 2, 2048);
						must_init(click1, "mouse_click_sfx");
						al_set_audio_stream_playmode(click1, _ALLEGRO_PLAYMODE_STREAM_LOOP_ONCE);
						al_attach_audio_stream_to_mixer(click1, al_get_default_mixer());

					}
					if (!al_mouse_button_down(&mouse, 1))  swbtndown = false;
				}
				else al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
				/**/
				/**/
				al_get_mouse_state(&mouse);
				if (check_mouse_position(&exitgame, &mouse)) {
					al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
					if (!swbtndown) if (al_mouse_button_down(&mouse, 1))
					{
						swbtndown = true;
						sw = exit_game;
						ALLEGRO_AUDIO_STREAM* click1 = al_load_audio_stream("1.mp3", 2, 2048);
						must_init(click1, "mouse_click_sfx");
						al_set_audio_stream_playmode(click1, _ALLEGRO_PLAYMODE_STREAM_LOOP_ONCE);
						al_attach_audio_stream_to_mixer(click1, al_get_default_mixer());

						al_set_audio_stream_playmode(music, ALLEGRO_PLAYMODE_LOOP);
						al_attach_audio_stream_to_mixer(music, al_get_default_mixer());
					}
					if (!al_mouse_button_down(&mouse, 1))  swbtndown = false;
				}
				else al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
				/**/
				/**/
				al_get_mouse_state(&mouse);
				if (check_mouse_position(&first, &mouse)) {
					al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
					if (!swbtndown) if (al_mouse_button_down(&mouse, 1))
					{
						swbtndown = true;
						sw = first_menu;
						ALLEGRO_AUDIO_STREAM* click1 = al_load_audio_stream("1.mp3", 2, 2048);
						must_init(click1, "mouse_click_sfx");
						al_set_audio_stream_playmode(click1, _ALLEGRO_PLAYMODE_STREAM_LOOP_ONCE);
						al_attach_audio_stream_to_mixer(click1, al_get_default_mixer());

						al_set_audio_stream_playmode(music, ALLEGRO_PLAYMODE_LOOP);
						al_attach_audio_stream_to_mixer(music, al_get_default_mixer());
					}
					if (!al_mouse_button_down(&mouse, 1))  swbtndown = false;
				}
				else al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
				/**/

				al_draw_bitmap(pas, 0, 0, 0);
				al_draw_text(font1, al_map_rgb(34, 139, 34), 270, 0, 0, "MEET IN THE MIDDLE");
				al_draw_bitmap(map, 210, 75, 0);


				al_draw_text(font3, al_map_rgb(23, 77, 239), 1000, 0, 0, "turn player 2");

				al_get_mouse_state(&mouse);
				if (check_mouse_position(&pl_pi1, &mouse)) {
					al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
					if (!swbtndown) if (al_mouse_button_down(&mouse, 1))
					{
						swbtndown = true;
						printf("\nfirst position of p2_1 : %d", p2_1);
						printf("\ntas : %d", i);

						if (i == -3) sw_asli_3 = 1;
						if (sw_asli_3 == 1) {


							if (sw_komaki_3 == 1) {


								if (p2_1 + i < 80) {
									p2_1 += (i);
									printf("\nsecond position of p2_1 : %d", p2_1);
									if (p2_1 == 5 && sw1 == 0) {
										p2_1 = 38;
										sw1 = 1;
									}
									if (p2_1 == 38 && sw1 == 0) {
										p2_1 = 5;
										sw1 = 1;
									}
									if (p2_1 == 21 && sw2 == 0) {
										p2_1 = 65;
										sw2 = 1;
									}
									if (p2_1 == 65 && sw2 == 0) {
										p2_1 = 21;
										sw2 = 1;
									}
									if (p2_1 == 25 && sw3 == 0) {
										p2_1 = 58;
										sw3 = 1;
									}
									if (p2_1 == 58 && sw3 == 0) {
										p2_1 = 25;
										sw3 = 1;
									}
									if (p2_1 == 42 && sw4 == 0) {
										p2_1 = 75;
										sw4 = 1;
									}
									if (p2_1 == 75 && sw4 == 0) {
										p2_1 = 42;
										sw4 = 1;
									}

									/*payan*/
									if (p2_1 == 40) {
										sw_asli_3 = 0;
									}

									if (p2_1 == 40 && p2_1 == 40) {
										printf("skgjghskjghskljghlsjg");
										al_destroy_audio_stream(music);
										sw = win2;
										goto lable3;

									}
									/*-----*/

									/*barkhord ha*/
									if (p2_1 == p1_1) {
										p1_1 = 0;
									}
									if (p2_1 == p1_2) {
										p1_2 = 0;
									}
									/*-----------*/

									/*khone haye shanse 3 & 77*//*close door*/
									if (p2_1 == 3 && sw_k3 == 0) {
										count_close2++;
										sw_k3 = 1;
									}

									if (p2_1 == 77 && sw_k77 == 0) {
										count_close2++;
										sw_k77 = 1;
									}
									/*--------------------------------------*/
									/*khoone haye shans 35 & 46*/ /*zarib*/
									if (p2_1 == 35 && sw_k15 == 0) {
										count_zarib2++;
										sw_k15 = 1;
									}

									if (p2_1 == 46 && sw_k46 == 0) {
										count_zarib2++;
										sw_k46 = 1;
									}
									/*-----------------------------------*/
									/*khoone haye shans 24 & 57*/ /*tas mojadad*/
									if (p2_1 == 24 && sw_k24 == 0) {
										count_againdice2++;
										sw_k24 = 1;
									}

									if (p2_1 == 57 && sw_k57 == 0) {
										count_againdice2++;
										sw_k57 = 1;
									}
									/*-----------------------------------------*/
									/*khoone haye shans 15 & 70*/ /*mahdoodiat*/
									if (p2_1 == 15 && sw_k15 == 0) {
										count_mamnoo2++;
										sw_k15 = 1;
									}

									if (p2_1 == 70 && sw_k70 == 0) {
										count_mamnoo2++;
										sw_k70 = 1;
									}
									/*-----------------------------------------*/

								}
								else {
									p2_1 = 80;
									printf("\nsecond position of p1_1 : %d", p2_1);
								}
								sw = player_1_befor;
							}
						}
						else
						{
							sw = player_1_befor;
						}
						ALLEGRO_AUDIO_STREAM* click1 = al_load_audio_stream("1.mp3", 2, 2048);
						must_init(click1, "mouse_click_sfx");
						al_set_audio_stream_playmode(click1, _ALLEGRO_PLAYMODE_STREAM_LOOP_ONCE);
						al_attach_audio_stream_to_mixer(click1, al_get_default_mixer());
					}
					if (!al_mouse_button_down(&mouse, 1))  swbtndown = false;
				}
				else al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);

				al_get_mouse_state(&mouse);
				if (check_mouse_position(&pl_pi2, &mouse)) {
					al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
					if (!swbtndown) if (al_mouse_button_down(&mouse, 1))
					{
						swbtndown = true;
						printf("\nfirst position of p2_2 : %d", p2_2);
						printf("\ntas : %d", i);

						if (i == -3) sw_asli_4 = 1;


						if (sw_asli_4 == 1) {


							if (sw_komaki_4 == 1) {


								if (p2_2 + i  < 80) {
									p2_2 += (i);
									printf("\nsecond position of p2_2 : %d", p2_2);
									if (p2_2 == 5 && sw1 == 0) {
										p2_2 = 38;
										sw1 = 1;
									}
									if (p2_2 == 38 && sw1 == 0) {
										p2_2 = 5;
										sw1 = 1;
									}
									if (p2_2 == 21 && sw2 == 0) {
										p2_2 = 65;
										sw2 = 1;
									}
									if (p2_2 == 65 && sw2 == 0) {
										p2_2 = 21;
										sw2 = 1;
									}
									if (p2_2 == 25 && sw3 == 0) {
										p2_2 = 58;
										sw3 = 1;
									}
									if (p2_2 == 58 && sw3 == 0) {
										p2_2 = 25;
										sw3 = 1;
									}
									if (p2_2 == 42 && sw4 == 0) {
										p2_2 = 75;
										sw4 = 1;
									}
									if (p2_2 == 75 && sw4 == 0) {
										p2_2 = 42;
										sw4 = 1;
									}

									/*payan*/
									if (p2_2 == 40) {
										sw_asli_4 = 0;
									}

									if (p2_2 == 40 && p2_2 == 40) {
										printf("skgjghskjghskljghlsjg");
										al_destroy_audio_stream(music);
										sw = win2;
										goto lable3;
									}
									/*-----*/

									/*barkhord ha*/
									if (p2_2 == p1_1) {
										p1_1 = 0;
									}
									if (p2_2 == p1_2) {
										p1_2 = 0;
									}
									/*-----------*/

									/*khone haye shanse 3 & 77*/ /*close door*/
									if (p2_2 == 3 && sw_k3 == 0) {
										count_close2++;
										sw_k3 = 1;
									}

									if (p2_2 == 77 && sw_k77 == 0) {
										count_close2++;
										sw_k77 = 1;
									}
									/*---------------------------------------*/
									/*khoone haye shans 35 & 46*/ /*zarib*/
									if (p2_2 == 35 && sw_k15 == 0) {
										count_zarib2++;
										sw_k15 = 1;
									}

									if (p2_2 == 46 && sw_k46 == 0) {
										count_zarib2++;
										sw_k46 = 1;
									}
									/*-----------------------------------*/
									/*khoone haye shans 24 & 57*/ /*tas mojadad*/
									if (p2_2 == 24 && sw_k24 == 0) {
										count_againdice2++;
										sw_k24 = 1;
									}

									if (p2_2 == 57 && sw_k57 == 0) {
										count_againdice2++;
										sw_k57 = 1;
									}
									/*-----------------------------------------*/
									/*khoone haye shans 15 & 70*/ /*mahdoodiat*/
									if (p2_2 == 15 && sw_k15 == 0) {
										count_mamnoo2++;
										sw_k15 = 1;
									}

									if (p2_2 == 70 && sw_k70 == 0) {
										count_mamnoo2++;
										sw_k70 = 1;
									}
									/*-----------------------------------------*/

								}
								else {
									p2_2 = 80;
									printf("\nsecond position of p1_1 : %d", p2_2);
								}
								sw = player_1_befor;
							}
						}
						else
						{
							sw = player_1_befor;
						}
						ALLEGRO_AUDIO_STREAM* click1 = al_load_audio_stream("1.mp3", 2, 2048);
						must_init(click1, "mouse_click_sfx");
						al_set_audio_stream_playmode(click1, _ALLEGRO_PLAYMODE_STREAM_LOOP_ONCE);
						al_attach_audio_stream_to_mixer(click1, al_get_default_mixer());
					}
					if (!al_mouse_button_down(&mouse, 1))  swbtndown = false;
				}
				else al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);


				al_draw_filled_circle(k[p1_1].x, k[p1_1].y, 20, al_map_rgb_f(1, 0, 0), 5);
				al_draw_circle(k[p1_2].x, k[p1_2].y, 20, al_map_rgb_f(1, 0, 0), 5);
				al_draw_filled_circle(k[p2_1].x, k[p2_1].y, 20, al_map_rgb_f(0, 0, 1), 5);
				al_draw_circle(k[p2_2].x, k[p2_2].y, 20, al_map_rgb_f(0, 0, 1), 5);
				//al_draw_filled_circle(110, 150, 20, al_map_rgba_f(0, 0, 0.5, 1));




				al_draw_text(font_menu2, al_map_rgb(23, 77, 239), 0, 450, 0, "choose");
				al_draw_text(font_menu2, al_map_rgb(23, 77, 239), 0, 490, 0, "your");
				al_draw_text(font_menu2, al_map_rgb(23, 77, 239), 0, 540, 0, "piece");
				al_draw_text(font_menu2, al_map_rgb(23, 77, 239), 150, 490, 0, "1");
				al_draw_text(font_menu2, al_map_rgb(23, 77, 239), 150, 540, 0, "2");
				al_draw_text(font_menu2, al_map_rgb(102, 51, 153), 0, 665, 0, "save");
				al_draw_rectangle(145, 490, 175, 530, al_map_rgb(23, 77, 239), 5);
				al_draw_rectangle(145, 540, 180, 580, al_map_rgb(123, 77, 239), 5);

				if (i == 1)al_draw_bitmap(tas1, 1050, 525, 0);
				if (i == 2) al_draw_bitmap(tas2, 1050, 525, 0);
				if (i == 3)al_draw_bitmap(tas3, 1050, 525, 0);
				if (i == -1)al_draw_bitmap(tas_1, 1050, 525, 0);
				if (i == -2)al_draw_bitmap(tas_2, 1050, 525, 0);
				if (i == -3)al_draw_bitmap(tas_3, 1050, 525, 0);

				/*if (j != 0) {
					if (j == 1)al_draw_bitmap(tas1, 1050, 440, 0);
					if (j == 2) al_draw_bitmap(tas2, 1050, 440, 0);
					if (j == 3)al_draw_bitmap(tas3, 1050, 440, 0);
					if (j == -1)al_draw_bitmap(tas_1, 1050, 440, 0);
					if (j == -2)al_draw_bitmap(tas_2, 1050, 440, 0);
					if (j == -3)al_draw_bitmap(tas_3, 1050, 440, 0);
				}*/

				al_draw_rectangle(150, 150, 180, 190, al_map_rgb(165, 42, 42), 5);
				al_draw_rectangle(150, 235, 180, 275, al_map_rgb(165, 42, 42), 5);
				al_draw_rectangle(150, 305, 180, 345, al_map_rgb(165, 42, 42), 5);
				al_draw_rectangle(150, 370, 180, 410, al_map_rgb(165, 42, 42), 5);
				al_draw_rectangle(1000, 150, 1030, 190, al_map_rgb(23, 77, 239), 5);
				al_draw_rectangle(1000, 235, 1030, 275, al_map_rgb(23, 77, 239), 5);
				al_draw_rectangle(1000, 305, 1030, 345, al_map_rgb(23, 77, 239), 5);
				al_draw_rectangle(1000, 370, 1030, 410, al_map_rgb(23, 77, 239), 5);
				if (count_close1 == 0) al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 155, 100, "0");
				if (count_zarib1 == 0)al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 240, 100, "0");
				if (count_mamnoo1 == 0)al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 310, 100, "0");
				if (count_againdice1 == 0)al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 375, 100, "0");
				if (count_close1 == 1) al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 155, 100, "1");
				if (count_zarib1 == 1)al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 240, 100, "1");
				if (count_mamnoo1 == 1)al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 310, 100, "1");
				if (count_againdice1 == 1)al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 375, 100, "1");
				if (count_close1 == 2) al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 155, 100, "2");
				if (count_zarib1 == 2)al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 240, 100, "2");
				if (count_mamnoo1 == 2)al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 310, 100, "2");
				if (count_againdice1 == 2)al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 375, 100, "2");

				if (count_close2 == 0) al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 155, 100, "0");
				if (count_zarib2 == 0)al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 240, 100, "0");
				if (count_mamnoo2 == 0)al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 310, 100, "0");
				if (count_againdice2 == 0)al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 375, 100, "0");
				if (count_close2 == 1) al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 155, 100, "1");
				if (count_zarib2 == 1)al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 240, 100, "1");
				if (count_mamnoo2 == 1)al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 310, 100, "1");
				if (count_againdice2 == 1)al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 375, 100, "1");
				if (count_close2 == 2) al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 155, 100, "2");
				if (count_zarib2 == 2)al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 240, 100, "2");
				if (count_mamnoo2 == 2)al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 310, 100, "2");
				if (count_againdice2 == 2)al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 375, 100, "2");

				al_draw_text(font_menu1, al_map_rgb(102, 51, 153), 525, 650, 0, "menu");
				al_draw_text(font_menu1, al_map_rgb(102, 51, 153), 1100, 650, 0, "exit");
				al_draw_text(font2, al_map_rgb(255, 0, 0), 10, 60, 100, "player 1");
				al_draw_text(font2, al_map_rgb(0, 0, 255), 1010, 60, 100, "player 2");

				al_draw_bitmap(close, 10, 130, 0);
				al_draw_bitmap(zarib, 10, 225, 0);
				al_draw_bitmap(mamnoo, 10, 300, 0);
				al_draw_bitmap(againdice, 10, 360, 0);
				al_draw_bitmap(close, 1120, 130, 0);
				al_draw_bitmap(zarib, 1090, 225, 0);
				al_draw_bitmap(mamnoo, 1139, 300, 0);
				al_draw_bitmap(againdice, 1133, 360, 0);
				break;







































            case player_1_mamnoo_kardan:
				al_clear_to_color(al_map_rgb(0, 0, 0));

				al_get_mouse_state(&mouse);
				if (check_mouse_position(&pl_pi1, &mouse)) {
					al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
					if (!swbtndown) if (al_mouse_button_down(&mouse, 1))
					{
						swbtndown = true;
						sw_komaki_1 = 0;
						sw = player_1;
						ALLEGRO_AUDIO_STREAM* click1 = al_load_audio_stream("1.mp3", 2, 2048);
						must_init(click1, "mouse_click_sfx");
						al_set_audio_stream_playmode(click1, _ALLEGRO_PLAYMODE_STREAM_LOOP_ONCE);
						al_attach_audio_stream_to_mixer(click1, al_get_default_mixer());
					}
					if (!al_mouse_button_down(&mouse, 1))  swbtndown = false;
				}
				else al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);

				al_get_mouse_state(&mouse);
				if (check_mouse_position(&pl_pi2, &mouse)) {
					al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
					if (!swbtndown) if (al_mouse_button_down(&mouse, 1))
					{
						swbtndown = true;
						sw_komaki_2 = 0;
						sw = player_1;
						ALLEGRO_AUDIO_STREAM* click1 = al_load_audio_stream("1.mp3", 2, 2048);
						must_init(click1, "mouse_click_sfx");
						al_set_audio_stream_playmode(click1, _ALLEGRO_PLAYMODE_STREAM_LOOP_ONCE);
						al_attach_audio_stream_to_mixer(click1, al_get_default_mixer());
					}
					if (!al_mouse_button_down(&mouse, 1))  swbtndown = false;
				}
				else al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);


				al_draw_bitmap(pas, 0, 0, 0);
				al_draw_text(font1, al_map_rgb(34, 139, 34), 270, 0, 0, "MEET IN THE MIDDLE");
				al_draw_bitmap(map, 210, 75, 0);


				al_draw_text(font3, al_map_rgb(23, 77, 239), 1000, 0, 0, "turn player 2");
				al_draw_filled_circle(k[p1_1].x, k[p1_1].y, 20, al_map_rgb_f(1, 0, 0), 5);
				al_draw_circle(k[p1_2].x, k[p1_2].y, 20, al_map_rgb_f(1, 0, 0), 5);
				al_draw_filled_circle(k[p2_1].x, k[p2_1].y, 20, al_map_rgb_f(0, 0, 1), 5);
				al_draw_circle(k[p2_2].x, k[p2_2].y, 20, al_map_rgb_f(0, 0, 1), 5);
				al_draw_rectangle(150, 150, 180, 190, al_map_rgb(165, 42, 42), 5);
				al_draw_rectangle(150, 235, 180, 275, al_map_rgb(165, 42, 42), 5);
				al_draw_rectangle(150, 305, 180, 345, al_map_rgb(165, 42, 42), 5);
				al_draw_rectangle(150, 370, 180, 410, al_map_rgb(165, 42, 42), 5);
				al_draw_rectangle(1000, 150, 1030, 190, al_map_rgb(23, 77, 239), 5);
				al_draw_rectangle(1000, 235, 1030, 275, al_map_rgb(23, 77, 239), 5);
				al_draw_rectangle(1000, 305, 1030, 345, al_map_rgb(23, 77, 239), 5);
				al_draw_rectangle(1000, 370, 1030, 410, al_map_rgb(23, 77, 239), 5);
				if (count_close1 == 0) al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 155, 100, "0");
				if (count_zarib1 == 0)al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 240, 100, "0");
				if (count_mamnoo1 == 0)al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 310, 100, "0");
				if (count_againdice1 == 0)al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 375, 100, "0");
				if (count_close1 == 1) al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 155, 100, "1");
				if (count_zarib1 == 1)al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 240, 100, "1");
				if (count_mamnoo1 == 1)al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 310, 100, "1");
				if (count_againdice1 == 1)al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 375, 100, "1");
				if (count_close1 == 2) al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 155, 100, "2");
				if (count_zarib1 == 2)al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 240, 100, "2");
				if (count_mamnoo1 == 2)al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 310, 100, "2");
				if (count_againdice1 == 2)al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 375, 100, "2");

				if (count_close2 == 0) al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 155, 100, "0");
				if (count_zarib2 == 0)al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 240, 100, "0");
				if (count_mamnoo2 == 0)al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 310, 100, "0");
				if (count_againdice2 == 0)al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 375, 100, "0");
				if (count_close2 == 1) al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 155, 100, "1");
				if (count_zarib2 == 1)al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 240, 100, "1");
				if (count_mamnoo2 == 1)al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 310, 100, "1");
				if (count_againdice2 == 1)al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 375, 100, "1");
				if (count_close2 == 2) al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 155, 100, "2");
				if (count_zarib2 == 2)al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 240, 100, "2");
				if (count_mamnoo2 == 2)al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 310, 100, "2");
				if (count_againdice2 == 2)al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 375, 100, "2");

				al_draw_text(font_menu2, al_map_rgb(23, 77, 239), 0, 450, 0, "which ");
				al_draw_text(font_menu2, al_map_rgb(23, 77, 239), 0, 490, 0, "one");
				al_draw_text(font_menu2, al_map_rgb(23, 77, 239), 0, 540, 0, "limit");
				al_draw_text(font_menu2, al_map_rgb(165, 42, 42), 150, 490, 0, "1");
				al_draw_text(font_menu2, al_map_rgb(165, 42, 42), 150, 540, 0, "2");
				al_draw_rectangle(145, 490, 175, 530, al_map_rgb(165, 42, 42), 5);
				al_draw_rectangle(145, 540, 180, 580, al_map_rgb(165, 42, 42), 5);


				/*al_draw_bitmap(tas1, 1050, 525, 0);
				al_draw_bitmap(tas2, 1050, 525, 0);
				al_draw_bitmap(tas3, 1050, 525, 0);
				al_draw_bitmap(tas_1, 1050, 525, 0);
				al_draw_bitmap(tas_2, 1050, 525, 0);
				al_draw_bitmap(tas_3, 1050, 525, 0);*/



				al_draw_text(font2, al_map_rgb(255, 0, 0), 10, 60, 100, "player 1");
				al_draw_text(font2, al_map_rgb(0, 0, 255), 1010, 60, 100, "player 2");

				al_draw_bitmap(close, 10, 130, 0);
				al_draw_bitmap(zarib, 10, 225, 0);
				al_draw_bitmap(mamnoo, 10, 300, 0);
				al_draw_bitmap(againdice, 10, 360, 0);
				al_draw_bitmap(close, 1120, 130, 0);
				al_draw_bitmap(zarib, 1090, 225, 0);
				al_draw_bitmap(mamnoo, 1139, 300, 0);
				al_draw_bitmap(againdice, 1133, 360, 0);
				break;






































			case player_2_mamnoo_kardan:
				al_clear_to_color(al_map_rgb(0, 0, 0));

				al_get_mouse_state(&mouse);
				if (check_mouse_position(&pl_pi1, &mouse)) {
					al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
					if (!swbtndown) if (al_mouse_button_down(&mouse, 1))
					{
						swbtndown = true;
						sw_komaki_3 = 0;
						sw = player_2;
						ALLEGRO_AUDIO_STREAM* click1 = al_load_audio_stream("1.mp3", 2, 2048);
						must_init(click1, "mouse_click_sfx");
						al_set_audio_stream_playmode(click1, _ALLEGRO_PLAYMODE_STREAM_LOOP_ONCE);
						al_attach_audio_stream_to_mixer(click1, al_get_default_mixer());
					}
					if (!al_mouse_button_down(&mouse, 1))  swbtndown = false;
				}
				else al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);

				al_get_mouse_state(&mouse);
				if (check_mouse_position(&pl_pi2, &mouse)) {
					al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
					if (!swbtndown) if (al_mouse_button_down(&mouse, 1))
					{
						swbtndown = true;
						sw_komaki_4 = 0;
						sw = player_2;
						ALLEGRO_AUDIO_STREAM* click1 = al_load_audio_stream("1.mp3", 2, 2048);
						must_init(click1, "mouse_click_sfx");
						al_set_audio_stream_playmode(click1, _ALLEGRO_PLAYMODE_STREAM_LOOP_ONCE);
						al_attach_audio_stream_to_mixer(click1, al_get_default_mixer());
					}
					if (!al_mouse_button_down(&mouse, 1))  swbtndown = false;
				}
				else al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);

				al_draw_bitmap(pas, 0, 0, 0);
				al_draw_text(font1, al_map_rgb(34, 139, 34), 270, 0, 0, "MEET IN THE MIDDLE");
				al_draw_bitmap(map, 210, 75, 0);


				al_draw_text(font3, al_map_rgb(23, 77, 239), 1000, 0, 0, "turn player 2");
				al_draw_filled_circle(k[p1_1].x, k[p1_1].y, 20, al_map_rgb_f(1, 0, 0), 5);
				al_draw_circle(k[p1_2].x, k[p1_2].y, 20, al_map_rgb_f(1, 0, 0), 5);
				al_draw_filled_circle(k[p2_1].x, k[p2_1].y, 20, al_map_rgb_f(0, 0, 1), 5);
				al_draw_circle(k[p2_2].x, k[p2_2].y, 20, al_map_rgb_f(0, 0, 1), 5);
				al_draw_rectangle(150, 150, 180, 190, al_map_rgb(165, 42, 42), 5);
				al_draw_rectangle(150, 235, 180, 275, al_map_rgb(165, 42, 42), 5);
				al_draw_rectangle(150, 305, 180, 345, al_map_rgb(165, 42, 42), 5);
				al_draw_rectangle(150, 370, 180, 410, al_map_rgb(165, 42, 42), 5);
				al_draw_rectangle(1000, 150, 1030, 190, al_map_rgb(23, 77, 239), 5);
				al_draw_rectangle(1000, 235, 1030, 275, al_map_rgb(23, 77, 239), 5);
				al_draw_rectangle(1000, 305, 1030, 345, al_map_rgb(23, 77, 239), 5);
				al_draw_rectangle(1000, 370, 1030, 410, al_map_rgb(23, 77, 239), 5);
				if (count_close1 == 0) al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 155, 100, "0");
				if (count_zarib1 == 0)al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 240, 100, "0");
				if (count_mamnoo1 == 0)al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 310, 100, "0");
				if (count_againdice1 == 0)al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 375, 100, "0");
				if (count_close1 == 1) al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 155, 100, "1");
				if (count_zarib1 == 1)al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 240, 100, "1");
				if (count_mamnoo1 == 1)al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 310, 100, "1");
				if (count_againdice1 == 1)al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 375, 100, "1");
				if (count_close1 == 2) al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 155, 100, "2");
				if (count_zarib1 == 2)al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 240, 100, "2");
				if (count_mamnoo1 == 2)al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 310, 100, "2");
				if (count_againdice1 == 2)al_draw_text(font_game1, al_map_rgb(165, 42, 42), 152, 375, 100, "2");

				if (count_close2 == 0) al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 155, 100, "0");
				if (count_zarib2 == 0)al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 240, 100, "0");
				if (count_mamnoo2 == 0)al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 310, 100, "0");
				if (count_againdice2 == 0)al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 375, 100, "0");
				if (count_close2 == 1) al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 155, 100, "1");
				if (count_zarib2 == 1)al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 240, 100, "1");
				if (count_mamnoo2 == 1)al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 310, 100, "1");
				if (count_againdice2 == 1)al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 375, 100, "1");
				if (count_close2 == 2) al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 155, 100, "2");
				if (count_zarib2 == 2)al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 240, 100, "2");
				if (count_mamnoo2 == 2)al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 310, 100, "2");
				if (count_againdice2 == 2)al_draw_text(font_game1, al_map_rgb(23, 77, 239), 1002, 375, 100, "2");

				al_draw_text(font_menu2, al_map_rgb(65, 42, 42), 0, 450, 0, "which ");
				al_draw_text(font_menu2, al_map_rgb(65, 42, 42), 0, 490, 0, "one");
				al_draw_text(font_menu2, al_map_rgb(65, 42, 42), 0, 540, 0, "limit");
				al_draw_text(font_menu2, al_map_rgb(23, 77, 239), 150, 490, 0, "1");
				al_draw_text(font_menu2, al_map_rgb(23, 77, 239), 150, 540, 0, "2");
				al_draw_rectangle(145, 490, 175, 530, al_map_rgb(23, 77, 239), 5);
				al_draw_rectangle(145, 540, 180, 580, al_map_rgb(23, 77, 239), 5);


				/*al_draw_bitmap(tas1, 1050, 525, 0);
				al_draw_bitmap(tas2, 1050, 525, 0);
				al_draw_bitmap(tas3, 1050, 525, 0);
				al_draw_bitmap(tas_1, 1050, 525, 0);
				al_draw_bitmap(tas_2, 1050, 525, 0);
				al_draw_bitmap(tas_3, 1050, 525, 0);*/



				al_draw_text(font2, al_map_rgb(255, 0, 0), 10, 60, 100, "player 1");
				al_draw_text(font2, al_map_rgb(0, 0, 255), 1010, 60, 100, "player 2");

				al_draw_bitmap(close, 10, 130, 0);
				al_draw_bitmap(zarib, 10, 225, 0);
				al_draw_bitmap(mamnoo, 10, 300, 0);
				al_draw_bitmap(againdice, 10, 360, 0);
				al_draw_bitmap(close, 1120, 130, 0);
				al_draw_bitmap(zarib, 1090, 225, 0);
				al_draw_bitmap(mamnoo, 1139, 300, 0);
				al_draw_bitmap(againdice, 1133, 360, 0);
				break;

		    case win2:
				lable3:
				al_clear_to_color(al_map_rgb(0, 0, 0));
				//al_destroy_audio_stream(music);

				al_set_audio_stream_playmode(winner, _ALLEGRO_PLAYMODE_STREAM_LOOP_ONCE);
				al_attach_audio_stream_to_mixer(winner, al_get_default_mixer());
				/**/
				al_get_mouse_state(&mouse);
				if (check_mouse_position(&exitgame, &mouse)) {
					al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
					if (!swbtndown) if (al_mouse_button_down(&mouse, 1))
					{
						swbtndown = true;
						sw = exit_game;


						ALLEGRO_AUDIO_STREAM* click1 = al_load_audio_stream("1.mp3", 2, 2048);
						must_init(click1, "mouse_click_sfx");
						al_set_audio_stream_playmode(click1, _ALLEGRO_PLAYMODE_STREAM_LOOP_ONCE);
						al_attach_audio_stream_to_mixer(click1, al_get_default_mixer());
					}
					if (!al_mouse_button_down(&mouse, 1))  swbtndown = false;
				}
				else al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
				/**/

				al_draw_bitmap(win_2, -25, 0, 0);

				al_draw_text(font_menu1, al_map_rgb(102, 51, 153), 1100, 650, 0, "exit");

				break;
            case win1:
				lable4:
				al_clear_to_color(al_map_rgb(0, 0, 0));
				//al_destroy_audio_stream(music);


				al_set_audio_stream_playmode(winner1, _ALLEGRO_PLAYMODE_STREAM_LOOP_ONCE);
				al_attach_audio_stream_to_mixer(winner1, al_get_default_mixer());
				/**/
				al_get_mouse_state(&mouse);
				if (check_mouse_position(&exitgame, &mouse)) {
					al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
					if (!swbtndown) if (al_mouse_button_down(&mouse, 1))
					{
						swbtndown = true;
						sw = exit_game;


						ALLEGRO_AUDIO_STREAM* click1 = al_load_audio_stream("1.mp3", 2, 2048);
						must_init(click1, "mouse_click_sfx");
						al_set_audio_stream_playmode(click1, _ALLEGRO_PLAYMODE_STREAM_LOOP_ONCE);
						al_attach_audio_stream_to_mixer(click1, al_get_default_mixer());
					}
					if (!al_mouse_button_down(&mouse, 1))  swbtndown = false;
				}
				else al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
				/**/

				al_draw_bitmap(win_1, -25, 0, 0);
				al_draw_text(font_menu1, al_map_rgb(102, 51, 153), 1100, 650, 0, "exit");
				break;
			}


			int sw = 0;







			al_flip_display();



			redraw = false;
		}
	}

	al_destroy_bitmap(pas);
	al_destroy_bitmap(map);
	al_destroy_bitmap(tas1);
	al_destroy_bitmap(tas2);
	al_destroy_bitmap(tas3);
	al_destroy_bitmap(tas_1);
	al_destroy_bitmap(tas_2);
	al_destroy_bitmap(tas_3);
	al_destroy_bitmap(c1);
	al_destroy_bitmap(c2);
	al_destroy_bitmap(c3);
	al_destroy_bitmap(c4);
	al_destroy_bitmap(c5);
	al_destroy_bitmap(c6);
	al_destroy_bitmap(c7);
	al_destroy_bitmap(c8);
	al_destroy_bitmap(close);
	al_destroy_bitmap(zarib);
	al_destroy_bitmap(mamnoo);
	al_destroy_bitmap(againdice);
	al_destroy_bitmap(menu);
	al_destroy_bitmap(win_1);
	al_destroy_bitmap(win_2);
	al_destroy_bitmap(menu_about);


	al_destroy_bitmap(rahro);
	al_destroy_bitmap(shans);
	al_destroy_audio_stream(music);
	al_destroy_audio_stream(click);
	al_destroy_audio_stream(winner);
	al_destroy_audio_stream(winner1);
	//al_destroy_mouse_cursor(mouse);
	al_destroy_font(font1);
	al_destroy_font(font);
	al_destroy_font(font2);
	al_destroy_font(font3);
	al_destroy_font(font_menu);
	al_destroy_font(font_menu1);
	al_destroy_font(font_menu2);
	al_destroy_font(font_game1);
	al_destroy_display(disp);
	al_destroy_timer(timer);
	al_destroy_event_queue(queue);

	return 0;
}