#pragma once
#include <SFML/Graphics.hpp>

namespace sizes
{
	//	Window sizes
	const int win_wd = 600;
	const int win_ht = 900;
	//	InfoBar sizes
	const int ib_frm_wd = 600;
	const int ib_frm_ht = 150;
	const int ib_x = 0;
	const int ib_y = 0;
	//	Bound sizes
	const int bnd_wd = 600;
	const int bnd_ht = 750;
	const int bnd_x = 0;
	const int bnd_y = ib_y + ib_frm_ht;
	//	Brick sizes
	const int brk_frm_wd = 75;
	const int brk_frm_ht = 32;
	const int brk_txtr_wd = 75;
	const int brk_txtr_ht = 64;
	//	Ball sizes
	const int bl_frm_wd = 26;
	const int bl_frm_ht = 26;
	const int bl_txtr_wd = 26;
	const int bl_txtr_ht = 26;
	const int bl_rds = 13;
	const int min_angle = 10;
	//	Paddle sizes
	const int pd_frm_wd = 180;
	const int pd_frm_ht = 25;
	const int pd_txtr_wd = 180;
	const int pd_txtr_ht = 50;
	//	Falling-Object sizes
	const int fo_frm_wd = 60;
	const int fo_frm_ht = 60;
	const int fo_txtr_wd = 60;
	const int fo_txtr_ht = 60;
	//	Font sizes
	const int font_size = 25;
	//	Miscellaneous
	const float d2r = acosf(-1) / 180;
}

namespace paths
{
	//	Background Path
	const std::string backrnd_path = "C:\\Users\\Naftali Lewenstein\\Desktop\\bbProject\\Graphics\\background.png";
	const std::string ball_path =    "C:\\Users\\Naftali Lewenstein\\Desktop\\bbProject\\Graphics\\ball.png";
	const std::string pad_path =     "C:\\Users\\Naftali Lewenstein\\Desktop\\bbProject\\Graphics\\paddle_new.png";
	const std::string br_path =      "C:\\Users\\Naftali Lewenstein\\Desktop\\bbProject\\Graphics\\br_txtr.png";
	const std::string fo_exp_path =  "C:\\Users\\Naftali Lewenstein\\Desktop\\bbProject\\Graphics\\expand.png";
	const std::string fo_srt_path =  "C:\\Users\\Naftali Lewenstein\\Desktop\\bbProject\\Graphics\\shorten.png";
	const std::string fo_rpd_path =  "C:\\Users\\Naftali Lewenstein\\Desktop\\bbProject\\Graphics\\rapid.png";
	const std::string fo_slw_path =  "C:\\Users\\Naftali Lewenstein\\Desktop\\bbProject\\Graphics\\slow.png";
	const std::string fo_tbl_path =  "C:\\Users\\Naftali Lewenstein\\Desktop\\bbProject\\Graphics\\twoballs.png";
	const std::string ib_path =      "C:\\Users\\Naftali Lewenstein\\Desktop\\bbProject\\Graphics\\infback.jpg";
	const std::string font_path =    "C:\\Users\\Naftali Lewenstein\\Desktop\\bbProject\\Fonts\\Montery.ttf";
	const std::string hit_snd_path = "C:\\Users\\Naftali Lewenstein\\Desktop\\bbProject\\Sounds\\brk_hit.wav";
}

namespace textures
{
	static sf::Texture backrnd_txtr;
	static sf::Texture ib_txtr;
	static sf::Texture br_txtr;
	static sf::Texture bl_txtr;
	static sf::Texture pd_txtr;
	static sf::Texture exp_txtr;
	static sf::Texture srt_txtr;
	static sf::Texture rpd_txtr;
	static sf::Texture slw_txtr;
	static sf::Texture tbl_txtr;
}

namespace fonts
{
	static sf::Font ib_font;
}

namespace values///
{
	const int brick_val = 15;
	const int fall_val = 10;
	const int tri_brick = 25;
	const int coin = 50;
	const int jackpot = 500;

}