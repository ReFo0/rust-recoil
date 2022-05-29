#include "basvurular.h"
#include "../anabolum.h"
#include "config/Features.h"
#include "config/graphics_api.hpp"
using namespace std;

static int yarrak1 = 0;
static int yarrak2 = 0;
static int sayfa = 1;
static bool xacc = false;
static bool upgrade = false;
static bool cross = false;
static bool panelinfo = false;
static bool bestaim = true;
static bool yacc = false;
static bool marks = false;

int bir;
int iki;
int selectedbgrade;
static const char* bgrade[] = { "Wood","Stone", "Metal","HighQuality" };

int codekey = 0;
int code1 = 0;
int code2 = 0;
int code3 = 0;
int code4 = 0;
int bhıpk = 0;
int legitmd = 0;
int splbind = 0;
bool legitmode1 = false;
bool hipfire1 = false;
bool lr33 = false;

int& Crouch_key = Config::Add("Crouch Key", "Movement Key Binds", Config::Type::INT, VK_CONTROL);
int& W_key = Config::Add("W key", "Movement Key Binds", Config::Type::INT, 0x57);
int& S_key = Config::Add("S key", "Movement Key Binds", Config::Type::INT, 0x53);
int& A_key = Config::Add("A key", "Movement Key Binds", Config::Type::INT, 0x41);
int& D_key = Config::Add("D key", "Movement Key Binds", Config::Type::INT, 0x44);
int& F1_key = Config::Add("F1 key", "F1", Config::Type::INT, 0x70);
int& F2_key = Config::Add("F1 key", "F1", Config::Type::INT, 0x71);
int& F3_key = Config::Add("F1 key", "F1", Config::Type::INT, 0x72);
int& F4_key = Config::Add("F1 key", "F1", Config::Type::INT, 0x73);
int& F5_key = Config::Add("F1 key", "F1", Config::Type::INT, 0x74);
int& F6_key = Config::Add("F1 key", "F1", Config::Type::INT, 0x75);
int& F7_key = Config::Add("F1 key", "F1", Config::Type::INT, 0x76);
int& F8_key = Config::Add("F1 key", "F1", Config::Type::INT, 0x77);
int& F9_key = Config::Add("F1 key", "F1", Config::Type::INT, 0x78);
int& F10_key = Config::Add("F1 key", "F1", Config::Type::INT, 0x79);
bool& Rage = Config::Add("Rage Mode", "          Pre-sets          ", Config::Type::BOOL, true);
bool& Good = Config::Add("Good Mode", "          Pre-sets          ", Config::Type::BOOL, false);
bool& Legit = Config::Add("Legit Mode", "          Pre-sets          ", Config::Type::BOOL, false);
bool& randomise_toggle = Config::Add("Randomise", "  Other          ", Config::Type::BOOL, false);
int& RANDX = Config::Add("RANDX", "             Misc          ", Config::Type::INT, 1);
int& TIME = Config::Add("SMOOTHING", "          Misc          ", Config::Type::INT, 0);
bool& ADS_Hide = Config::Add("CrosshairADS", "          Crosshair          ", Config::Type::BOOL, false);
int& aksa = Config::Add("AK", "Hotkey", Config::Type::INT, 0);
int& lr3 = Config::Add("LR", "Hotkey", Config::Type::INT, 0);
int& mp5k = Config::Add("MP5", "Hotkey", Config::Type::INT, 0);
int& boostk = Config::Add("Boost", "Hotkey", Config::Type::INT, 0);
int& csmgk = Config::Add("Custom", "Hotkey", Config::Type::INT, 0);
int& sark = Config::Add("Sar", "Hotkey", Config::Type::INT, 0);
int& revok = Config::Add("Revok", "Hotkey", Config::Type::INT, 0);
int& m249k = Config::Add("M249", "Hotkey", Config::Type::INT, 0);
int& m92k = Config::Add("M92", "Hotkey", Config::Type::INT, 0);
int& pythonk = Config::Add("Python", "Hotkey", Config::Type::INT, 0);
int& x8k = Config::Add("8X", "Hotkey", Config::Type::INT, 0);
int& simplek = Config::Add("Simple", "Hotkey", Config::Type::INT, 0);
int& tommyk = Config::Add("Thompson", "Hotkey", Config::Type::INT, 0);
int& x16k = Config::Add("16X", "Hotkey", Config::Type::INT, 0);
int& holok = Config::Add("Holo", "Hotkey", Config::Type::INT, 0);
int& silenk = Config::Add("Silencer", "Hotkey", Config::Type::INT, 0);
int& numreset = Config::Add("reset key", "Hotkey", Config::Type::INT, 0);





float Python_pen() {
	// CROUCHING NO KEY 
	if (Input::WhilePressed(Crouch_key) && bpython == true)
	{
		return 1;
	}
	// STANDING NO KEY 
	else return 2;
}
float m249_pen() {
	// CROUCHING S + MOVING 
	if (Input::WhilePressed(S_key) && Input::WhilePressed(Crouch_key) && bM249 == true)
	{
		return 1.75;
	}
	// STANDING S 
	if (Input::WhilePressed(S_key) && bM249 == true)
	{
		return 4.2;
	}
	// CROUCHING A + MOVING 
	if (Input::WhilePressed(A_key) && Input::WhilePressed(Crouch_key) && bM249 == true)
	{
		return 1.75;
	}
	// STANDING A 
	if (Input::WhilePressed(A_key) && bM249 == true)
	{
		return 4.2;
	}
	// CROUCHING D + MOVING 
	if (Input::WhilePressed(D_key) && Input::WhilePressed(Crouch_key) && bM249 == true)
	{
		return 1.75;
	}
	// STANDING D 
	if (Input::WhilePressed(D_key) && bM249 == true)
	{
		return 4.2;
	}
	// CROUCHING NO KEY 
	if (Input::WhilePressed(Crouch_key) && bM249 == true)
	{
		return 1;
	}
	// STANDING NO KEY 
	else return 2;
}
float Semi_pen() {
	// STANDING S + MOVING 
	if (Input::WhilePressed(S_key) && Input::WhilePressed(Crouch_key) && bSemi == true)
	{
		return 1.2f;
	}
	// STANDING S 
	if (Input::WhilePressed(S_key) && bSemi == true)
	{
		return 3;
	}
	// STANDING A + MOVING 
	if (Input::WhilePressed(A_key) && Input::WhilePressed(Crouch_key) && bSemi == true)
	{
		return 1.2f;
	}

	// STANDING A 
	if (Input::WhilePressed(A_key) && bSemi == true)
	{
		return 3;
	}
	// STANDING D + MOVING 
	if (Input::WhilePressed(D_key) && Input::WhilePressed(Crouch_key) && bSemi == true)
	{
		return 1.2f;
	}
	// STANDING D 
	if (Input::WhilePressed(D_key) && bSemi == true)
	{
		return 3;
	}
	// CROUCHING NO KEY 
	if (Input::WhilePressed(Crouch_key) && bSemi == true)
	{
		return 1;
	}
	// STANDING NO KEY 
	else return 2;
}


namespace CurrentWeapon {
	double x(float Bullet) {
		if (randomise_toggle == false) {
			if (bAK47 == true)
				return (Recoil_Ak47[Bullet].x * ScopeAttachment() * BarrelAttachment() / 4 / butunsens / XCONTROLL);
			else if (bLR300 == true)
				return (Recoil_Lr300[Bullet].x * ScopeAttachment() * BarrelAttachment() / 4 / butunsens / XCONTROLL);
			else if (bMP5 == true)
				return (Recoil_Mp5a4[Bullet].x * ScopeAttachment() * BarrelAttachment() / 4 / butunsens) / XCONTROLL;
			else if (bTHOMPSON == true)
				return (Recoil_Thompson_g[Bullet].x * ScopeAttachment() * BarrelAttachment() / 4 / butunsens / XCONTROLL);
			else if (bCSMG == true)
				return (Recoil_Custom_g[Bullet].x * ScopeAttachment() * BarrelAttachment() / 4 / butunsens / XCONTROLL);
			else if (bM249 == true)
				return (Recoil_M249[Bullet].x * ScopeAttachment() * BarrelAttachment() * m249_pen() / 4 / butunsens / XCONTROLL);
			else if (bSemi == true)
				return (Recoil_Semi_r[Bullet].x * ScopeAttachment() * BarrelAttachment() * Semi_pen() / 4 / butunsens / XCONTROLL);
			else if (bpython == true)
				return (Recoil_Python[Bullet].x * ScopeAttachment() * BarrelAttachment() * Python_pen() / 4 / butunsens / XCONTROLL);
			else if (bM92 == true)
				return (Recoil_M92[Bullet].x * ScopeAttachment() * BarrelAttachment() / 4 / butunsens / XCONTROLL);
			else
				return 0;
		}
		if (randomise_toggle == true) {
			if (bAK47 == true)
				return Recoil_Ak47[Bullet].x * ScopeAttachment() * BarrelAttachment() / 4 / butunsens / XCONTROLL / 1 + rand() % (RANDX + RANDX) + (-RANDX);
			else if (bLR300 == true)
				return Recoil_Lr300[Bullet].x * ScopeAttachment() * BarrelAttachment() / 4 / butunsens / XCONTROLL / 1 + rand() % (RANDX + RANDX) + (-RANDX);
			else if (bMP5 == true)
				return Recoil_Mp5a4[Bullet].x * ScopeAttachment() * BarrelAttachment() / 4 / butunsens / XCONTROLL / 1 + rand() % (RANDX + RANDX) + (-RANDX);
			else if (bTHOMPSON == true)
				return Recoil_Thompson_g[Bullet].x * ScopeAttachment() * BarrelAttachment() / 4 / butunsens / XCONTROLL / 1 + rand() % (RANDX + RANDX) + (-RANDX);
			else if (bCSMG == true)
				return Recoil_Custom_g[Bullet].x * ScopeAttachment() * BarrelAttachment() / 4 / butunsens / XCONTROLL / 1 + rand() % (RANDX + RANDX) + (-RANDX);
			else if (bM249 == true)
				return Recoil_M249[Bullet].x * ScopeAttachment() * BarrelAttachment() * m249_pen() / 4 / butunsens / XCONTROLL / 1 + rand() % (RANDX + RANDX) + (-RANDX);
			else if (bSemi == true)
				return Recoil_Semi_r[Bullet].x * ScopeAttachment() * BarrelAttachment() * Semi_pen() / 4 / butunsens / XCONTROLL / 1 + rand() % (RANDX + RANDX) + (-RANDX);
			else if (bpython == true)
				return Recoil_Python[Bullet].x * ScopeAttachment() * BarrelAttachment() * Python_pen() / 4 / butunsens / XCONTROLL / 1 + rand() % (RANDX + RANDX) + (-RANDX);
			else if (bM92 == true)
				return (Recoil_M92[Bullet].x * ScopeAttachment() * BarrelAttachment() / 4 / butunsens);
			else
				return 0;
		}
	}
	double y(float Bullet) {
		if (randomise_toggle == false) {
			if (bAK47 == true)
				return (Recoil_Ak47[Bullet].y * ScopeAttachment() * BarrelAttachment() / 4 / butunsens / YCONTROLL);
			else if (bLR300 == true)
				return (Recoil_Lr300[Bullet].y * ScopeAttachment() * BarrelAttachment() / 4 / butunsens / YCONTROLL);
			else if (bMP5 == true)
				return (Recoil_Mp5a4[Bullet].y * ScopeAttachment() * BarrelAttachment() / 4 / butunsens / YCONTROLL);
			else if (bTHOMPSON == true)
				return (Recoil_Thompson_g[Bullet].y * ScopeAttachment() * BarrelAttachment() / 4 / butunsens / YCONTROLL);
			else if (bCSMG == true)
				return (Recoil_Custom_g[Bullet].y * ScopeAttachment() * BarrelAttachment() / 4 / butunsens / YCONTROLL);
			else if (bM249 == true)
				return (Recoil_M249[Bullet].y * ScopeAttachment() * BarrelAttachment() * m249_pen() / 4 / butunsens / YCONTROLL);
			else if (bSemi == true)
				return (Recoil_Semi_r[Bullet].y * ScopeAttachment() * BarrelAttachment() * Semi_pen() / 4 / butunsens / YCONTROLL);
			else if (bpython == true)
				return (Recoil_Python[Bullet].y * ScopeAttachment() * BarrelAttachment() * Python_pen() / 4 / butunsens / YCONTROLL);
			else if (bM92 == true)
				return (Recoil_M92[Bullet].y * ScopeAttachment() * BarrelAttachment() / 4 / butunsens / YCONTROLL);
			else
				return 0;
		}
		if (randomise_toggle == true) {
			if (bAK47 == true)
				return Recoil_Ak47[Bullet].y * ScopeAttachment() * BarrelAttachment() / 4 / butunsens / YCONTROLL / 1 + rand() % (RANDX + RANDX) + (-RANDX);
			else if (bLR300 == true)
				return Recoil_Lr300[Bullet].y * ScopeAttachment() * BarrelAttachment() / 4 / butunsens / YCONTROLL / 1 + rand() % (RANDX + RANDX) + (-RANDX);
			else if (bMP5 == true)
				return Recoil_Mp5a4[Bullet].y * ScopeAttachment() * BarrelAttachment() / 4 / butunsens / YCONTROLL / 1 + rand() % (RANDX + RANDX) + (-RANDX);
			else if (bTHOMPSON == true)
				return Recoil_Thompson_g[Bullet].y * ScopeAttachment() * BarrelAttachment() / 4 / butunsens / YCONTROLL / 1 + rand() % (RANDX + RANDX) + (-RANDX);
			else if (bCSMG == true)
				return Recoil_Custom_g[Bullet].y * ScopeAttachment() * BarrelAttachment() / 4 / butunsens / YCONTROLL / 1 + rand() % (RANDX + RANDX) + (-RANDX);
			else if (bM249 == true)
				return Recoil_M249[Bullet].y * ScopeAttachment() * BarrelAttachment() * m249_pen() / 4 / butunsens / 1 / YCONTROLL + rand() % (RANDX + RANDX) + (-RANDX);
			else if (bSemi == true)
				return Recoil_Semi_r[Bullet].y * ScopeAttachment() * BarrelAttachment() * Semi_pen() / 4 / butunsens / 1 / YCONTROLL + rand() % (RANDX + RANDX) + (-RANDX);
			else if (bpython == true)
				return Recoil_Python[Bullet].y * ScopeAttachment() * BarrelAttachment() * Python_pen() / 4 / butunsens / 1 / YCONTROLL + rand() % (RANDX + RANDX) + (-RANDX);
			else if (bM92 == true)
				return (Recoil_M92[Bullet].y * ScopeAttachment() * BarrelAttachment() / 4 / butunsens);
			else
				return 0;
		}
	};
	double Delay() {
		if (bAK47 == true)
			return WeaponData::AK47.Delay;
		else if (bLR300 == true)
			return WeaponData::LR300.Delay;
		else if (bMP5 == true)
			return WeaponData::MP5.Delay;
		else if (bTHOMPSON == true)
			return WeaponData::THOMPSON.Delay;
		else if (bCSMG == true)
			return WeaponData::CUSTOM_SMG.Delay;
		else if (bM249 == true)
			return WeaponData::M249.Delay;
		else if (bSemi == true)
			return WeaponData::SEMI.Delay;
		else if (bpython == true)
			return WeaponData::python.Delay;
		else
			return 0;
	}
	double Control(float bullet) {
		if (bAK47 == true)
			return ControlTime_Ak47[bullet] + TIME;
		else if (bLR300 == true)
			return ControlTime_LR300[bullet] + TIME;
		else if (bMP5 == true)
			return ControlTime_Mp5a4[bullet] + TIME;
		else if (bTHOMPSON == true)
			return ControlTime_Thompson_g[bullet] + TIME;
		else if (bCSMG == true)
			return ControlTime_Custom_g[bullet] + TIME;
		else if (bM249 == true)
			return WeaponData::M249.Delay + TIME;
		else if (bSemi == true)
			return WeaponData::SEMI.Delay + TIME;
		else if (bpython == true)
			return WeaponData::python.Delay + TIME;
		else
			return 0;
	}
	float Bullet() {
		if (bAK47 == true)
			return Recoil_Ak47.size() - 1;
		else if (bLR300 == true)
			return Recoil_Lr300.size() - 1;
		else if (bMP5 == true)
			return Recoil_Mp5a4.size() - 1;
		else if (bTHOMPSON == true)
			return Recoil_Thompson_g.size() - 1;
		else if (bCSMG == true)
			return Recoil_Custom_g.size() - 1;
		else if (bM249 == true)
			return Recoil_M249.size() - 1;
		else if (bSemi == true)
			return Recoil_Semi_r.size() - 1;
		else if (bpython == true)
			return Recoil_Python.size() - 1;
		else if (bM92 == true)
			return Recoil_M92.size() - 1;
		else
			return 0;
	}
	bool WeaponActive() {
		if (bAK47 == true || bLR300 == true || bMP5 == true || bTHOMPSON == true || bCSMG == true || bSemi == true || bM249 == true || bRevo == true || bpython == true)
			return true;
		else
			return false;
	}
	void RecoilBreak(int count) {
		if (bSemi == true) {
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		}
		else if (bM249 == true) {
		}
		else if (NULL != true || NULL != true) {
			if (count == CurrentWeapon::Bullet()) {
				if (NULL == true) {
					Beep(0, 0);
					Beep(0, 0);
				}
				mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			}
		}
	}



};
std::string Weapon = "None", Scope = "None", autofire = "None", legitayar = "Disabled", Attachment = "None", hipfire = "None", fun = "None", Sounds = "Disabled";


void gizlee();

void gizlee() {
	::ShowWindow(::GetConsoleWindow(), SW_HIDE);
}

int main1() {
	gizlee();

	//CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Recoil, 0, 0, 0);

	while (true) {
			if (CurrentWeapon::WeaponActive() == true)
			{
				if (!bhıp) {
					for (int i = 0; i <= CurrentWeapon::Bullet() && GetAsyncKeyState(VK_LBUTTON) & 0x8000 && GetAsyncKeyState(VK_RBUTTON) & 0x8000; i++)
					{
						Smoothing((float)IsMuzzleBoost((float)CurrentWeapon::Delay()), (float)IsMuzzleBoost(CurrentWeapon::Control(i)), (float)CurrentWeapon::x(i), (float)CurrentWeapon::y(i));
						CurrentWeapon::RecoilBreak(i);
					}
				}
				else {
					for (int i = 0; i <= CurrentWeapon::Bullet() && GetAsyncKeyState(VK_LBUTTON) & 0x8000; i++)
					{
						Smoothing((float)IsMuzzleBoost((float)CurrentWeapon::Delay()), (float)IsMuzzleBoost(CurrentWeapon::Control(i)), (float)CurrentWeapon::x(i), (float)CurrentWeapon::y(i));
						CurrentWeapon::RecoilBreak(i);
					}
				}
				Sleep(1);
			}
		if (GetAsyncKeyState(aksa) != 0) {
			bAK47 = !bAK47;
			if (bAK47 == true) {
				Weapon = "AK47";
				bLR300 = false; bMP5 = false; bCSMG = false; bTHOMPSON = false; bSemi = false; bM249 = false;
			}
			else if (bAK47 == false) {
				Weapon = "None"; Scope = "None"; Attachment = "None";
				b8x = false; bHolo = false; bSimple = false; bSuppressor = false;
			}
			Sound(bAK47);

		}
		if (GetAsyncKeyState(lr3) != 0) {
			bLR300 = !bLR300;
			if (bLR300 == true) {
				Weapon = "LR300";
				bMP5 = false; bCSMG = false; bTHOMPSON = false; bSemi = false; bM249 = false; bAK47 = false;
			}
			else if (bLR300 == false) {
				Weapon = "None"; Scope = "None"; Attachment = "None";
				b8x = false; bHolo = false; bSimple = false; bSuppressor = false;
			}
			Sound(bLR300);

		}
		INPUT ip;
		ip.type = INPUT_KEYBOARD;
		ip.ki.wScan = 0;
		ip.ki.time = 0;
		ip.ki.dwExtraInfo = 0;
		if (auto_lock && (GetAsyncKeyState(codekey)))
		{
			// Press the first key
			ip.ki.wVk = code1;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			// Release the first key
			ip.ki.wVk = code1;
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(20);
			// Press the 2nd key
			ip.ki.wVk = code2;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			// Release the 2nd key
			ip.ki.wVk = code2;
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(20);
			// Press the 3rd key
			ip.ki.wVk = code3;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			// Release the 3rd key
			ip.ki.wVk = code3;
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(20);
			ip.ki.wVk = code4;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			// Release the 3rd key
			ip.ki.wVk = code4;
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(300);
		}
		if (upgrade)
		{
			if (upgrade && GetAsyncKeyState(0x46))
			{
				mouse_event(MOUSEEVENTF_RIGHTDOWN, 400, 400, 400, 400);
				Sleep(50);
				SetCursorPos(bir, iki);
				//mouse_event(MOUSEEVENTF_MOVE, -5, 0, 0, 0);
				Sleep(50);
				mouse_event(MOUSEEVENTF_LEFTDOWN, 400, 400, 400, 400);
				Sleep(50);
				mouse_event(MOUSEEVENTF_RIGHTUP, 400, 400, 400, 400);
				mouse_event(MOUSEEVENTF_LEFTUP, 400, 400, 400, 400);
				//mouse_event(MOUSEEVENTF_MOVE, 0, 0, 0, 0);C(düzenlendi)
			}
		}
		if (afk)
		{
			{
				keybd_event(' ', 0, 0, NULL);
				Sleep(20);
				keybd_event(' ', 0, KEYEVENTF_KEYUP, NULL);
				keybd_event(' ', 0, 0, NULL);
				Sleep(20);
				keybd_event(' ', 0, KEYEVENTF_KEYUP, NULL);

			}
		}

		if (al)
		{

			keybindi();
			if (GetAsyncKeyState(rpbind) & 0x8000)
			{
				if (al)
				{
					keybd_event('H', 5000, 500, 500);

					SetCursorPos(1300, 310);
					Sleep(20);

					SetCursorPos(1400, 310);
					Sleep(20);
					SetCursorPos(1500, 310);
					Sleep(20);
					SetCursorPos(1600, 310);
					Sleep(20);
					SetCursorPos(1700, 310);
					Sleep(20);
					SetCursorPos(1800, 310);
					Sleep(20);
					SetCursorPos(1300, 310);
					Sleep(20);

					SetCursorPos(1300, 410);
					Sleep(20);
					SetCursorPos(1400, 410);
					Sleep(20);
					SetCursorPos(1500, 410);
					Sleep(20);
					SetCursorPos(1600, 410);
					Sleep(20);
					SetCursorPos(1700, 410);
					Sleep(20);
					SetCursorPos(1800, 410);
					Sleep(20);
					SetCursorPos(1300, 510);
					Sleep(20);
					SetCursorPos(1400, 510);
					Sleep(20);
					SetCursorPos(1500, 510);
					Sleep(20);
					SetCursorPos(1600, 510);
					Sleep(20);
					SetCursorPos(1700, 510);
					Sleep(20);
					SetCursorPos(1800, 510);
					Sleep(20);
					SetCursorPos(1300, 610);
					Sleep(20);
					SetCursorPos(1400, 610);
					Sleep(20);
					SetCursorPos(1500, 610);
					Sleep(20);
					SetCursorPos(1600, 610);
					Sleep(20);
					SetCursorPos(1700, 610);
					Sleep(20);
					SetCursorPos(1800, 610);
				}


			}



		}
		if (ADS_Hide == true) {
			if (Input::WhilePressed(VK_RBUTTON))
			{
				cross = false;
			}
			else {
				cross = true;
			}
		}

		//else if (Input::WhilePressed(VK_LBUTTON) && Input::WhilePressed(VK_RBUTTON) && recoil == true)
		//{
			//return 1;
		//}


		keybindi();
		if (GetAsyncKeyState(rpbind) & 0x8000)
		{
			if (spl == true) {

				void mouse_move(); {



					SetCursorPos(826, 500);
					Sleep(100);

					// first slot
					mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
					Sleep(20);
					mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
					Sleep(50);
					SetCursorPos(1200, 500);
					Sleep(50);
					mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
					Sleep(30);
					SetCursorPos(1380, 700);
					Sleep(50);
					mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
					// first slot done

					Sleep(50);
					SetCursorPos(1200, 500);
					Sleep(50);
					mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
					Sleep(30);
					SetCursorPos(1450, 700);
					Sleep(50);
					mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

					Sleep(200);
					SetCursorPos(1150, 500);
					mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);

					mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
					Sleep(200);
					SetCursorPos(1200, 500);
					Sleep(200);
					mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
					Sleep(30);
					SetCursorPos(1615, 700);
					Sleep(50);
					mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);



				}


			}
			else {

			}

		}
		if (GetAsyncKeyState(mp5k) != 0) {
			bMP5 = !bMP5;
			if (bMP5 == true) {
				Weapon = "MP5";
				bLR300 = false; bCSMG = false; bTHOMPSON = false; bSemi = false; bM249 = false; bAK47 = false;
			}
			else if (bMP5 == false) {
				Weapon = "None"; Scope = "None"; Attachment = "None";
				b8x = false; bHolo = false; bSimple = false; bSuppressor = false;
			}
			Sound(bMP5);
		}
		if (GetAsyncKeyState(csmgk) != 0) {
			bCSMG = !bCSMG;
			if (bCSMG == true) {
				Weapon = "CustomSMG";
				bLR300 = false; bMP5 = false; bTHOMPSON = false; bSemi = false; bM249 = false; bAK47 = false;
			}
			else if (bCSMG == false) {
				Weapon = "None"; Scope = "None"; Attachment = "None";
				b8x = false; bHolo = false; bSimple = false; bSuppressor = false;
			}
			Sound(bCSMG);

		}
		if (GetAsyncKeyState(numreset) != 0)
		{
			bReload = false; bAK47 = false; bLR300 = false; bMP5 = false; bCSMG = false; bTHOMPSON = false; bSemi = false; bM249 = false;
			bRevo = false; bM92 = false; bpython = false; legitayar1 = false; legitayar2 = false;
			b16x = false; b8x = false; bhıp = false; bHolo = false; bSimple = false; bSuppressor = false; bMuzzleBoost = false;
			Weapon = "None"; Scope = "None"; Attachment = "None"; hipfire = "None"; autofire = "None"; legitayar = "None";
			Sound(bReload);

		}
		if (GetAsyncKeyState(tommyk) != 0) {
			bTHOMPSON = !bTHOMPSON;
			if (bTHOMPSON == true) {
				Weapon = "Thompson";
				bLR300 = false; bMP5 = false; bCSMG = false; bSemi = false; bM249 = false; bAK47 = false;
			}
			else if (bTHOMPSON == false) {
				Weapon = "None"; Scope = "None"; Attachment = "None";
				b8x = false; bHolo = false; bSimple = false; bSuppressor = false;
			}
			Sound(bTHOMPSON);

		}
		if (GetAsyncKeyState(sark) != 0) {
			bSemi = !bSemi;
			if (bSemi == true) {
				Weapon = "SAR Rifle";
				bLR300 = false; bMP5 = false; bCSMG = false; bTHOMPSON = false; bM249 = false; bAK47 = false;
			}
			else if (bSemi == false) {
				Weapon = "None"; Scope = "None"; Attachment = "None";
				b8x = false; bHolo = false; bSimple = false; bSuppressor = false;
			}
			Sound(bSemi);

		}
		if (GetAsyncKeyState(revok) != 0) {
			bRevo = !bRevo;
			if (bRevo == true) {
				Weapon = "Revo";
				bLR300 = false; bMP5 = false; bCSMG = false; bTHOMPSON = false; bM249 = false; bAK47 = false;
			}
			else if (bRevo == false) {
				Weapon = "None"; Scope = "None"; Attachment = "None";
				b8x = false; bHolo = false; bSimple = false; bSuppressor = false;
			}
			Sound(bRevo);

		}
		if (GetAsyncKeyState(m249k) != 0) {
			bM249 = !bM249;
			if (bM249 == true) {
				Weapon = "M249";
				bLR300 = false; bMP5 = false; bCSMG = false; bTHOMPSON = false; bSemi = false; bAK47 = false;
			}
			else if (bM249 == false) {
				Weapon = "None"; Scope = "None"; Attachment = "None";
				b8x = false; bHolo = false; bSimple = false; bSuppressor = false;
			}
			Sound(bM249);

		}
		if (GetAsyncKeyState(m92k) != 0) {
			bM92 = !bM92;
			if (bM92 == true) {
				Weapon = "M92";
				bLR300 = false; bMP5 = false; bCSMG = false; bTHOMPSON = false; bSemi = false; bAK47 = false;
			}
			else if (bM92 == false) {
				Weapon = "None"; Scope = "None"; Attachment = "None"; hipfire = "None";
				b8x = false; bHolo = false; bSimple = false; bSuppressor = false;
			}
			Sound(bM92);

		}
		if ((GetAsyncKeyState(legitmd) & 0x8000)) {
			legitayar1 = !legitayar1;
			switch (legitayar1) {
			case(true):
				legitayar = "Enabled"; legitayar2 = false;
				break;
			case(false):
				legitayar = "Disabled";
				break;
			}
			Sound(legitayar1);

		}
		if (GetAsyncKeyState(pythonk) != 0) {
			bpython = !bpython;
			if (bpython == true) {
				Weapon = "Python";
				bLR300 = false; bMP5 = false; bCSMG = false; bTHOMPSON = false; bSemi = false; bAK47 = false;
			}
			else if (bpython == false) {
				Weapon = "None"; Scope = "None"; Attachment = "None";
				b8x = false; bHolo = false; bSimple = false; bSuppressor = false;
			}
			Sound(bpython);

		}
		if (GetAsyncKeyState(x8k) != 0) {
			b8x = !b8x;
			switch (b8x) {
			case(true):
				Scope = "8x"; bHolo = false; bSimple = false; b16x = false;
				break;
			case(false):
				Scope = "None";
				break;
			}
			Sound(b8x);

		}
		if (GetAsyncKeyState(simplek) != 0) {
			bSimple = !bSimple;
			if (bSimple == true) {
				Scope = "Simple"; b8x = false; bHolo = false; b16x = false;
			}
			else if (bSimple == false)
				Scope = "None";
			Sound(bSimple);

		}
		if (GetAsyncKeyState(x16k) != 0) {
			b16x = !b16x;
			if (b16x == true) {
				Scope = "16x"; b8x = false; bSimple = false; bHolo = false;
			}
			else if (b16x == false)
				Scope = "None";
			Sound(b16x);

		}
		if (GetAsyncKeyState(holok) != 0) {
			bHolo = !bHolo;
			if (bHolo == true) {
				Scope = "Holo"; b8x = false; bSimple = false; b16x = false;
			}
			else if (bHolo == false)
				Scope = "None";
			Sound(bHolo);

		}
		if ((GetAsyncKeyState(silenk) & 0x8000)) {
			bSuppressor = !bSuppressor;
			if (bSuppressor == true) {
				Attachment = "Silencer"; bMuzzleBoost = false;
			}
			else if (bSuppressor == false)
				Attachment = "None";
			Sound(bSuppressor);

		}
		if ((GetAsyncKeyState(boostk) & 0x8000)) {
			bMuzzleBoost = !bMuzzleBoost;
			if (bMuzzleBoost == true) {
				Attachment = "Muzzle Boost"; bSuppressor = false;
			}
			else if (bMuzzleBoost == false)
				Attachment = "None";
			Sound(bMuzzleBoost);

		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
	return 0;
}
