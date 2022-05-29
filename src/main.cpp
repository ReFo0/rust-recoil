
#include "config/Features.h"
#include "config/graphics_api.hpp"
#include "../src/config/config.hpp"
#include "../src/config/common.hpp"
#include "core/graphics_api.hpp"
#include "core/config.hpp"
#include "../script/script.h"
#include "widgets/widgets.hpp"
#include "../script/çizim.h"
#include "../þifreleme/xor.h"
#include "../anabolum.h"
#include <direct.h>
#include <vcruntime.h>
#include <urlmon.h>
#include <shellapi.h>
#include <windows.h>
#include <iostream>
#include <stdio.h>
#include "../ConsoleColor.h"
#include "../þifreleme/md5.h"
#include "../print.h"



using namespace std;

void stylemenu()
{
    ImVec4* colors = ImGui::GetStyle().Colors;
    ImGuiIO& io = ImGui::GetIO();
    //io.Fonts->AddFontFromMemoryCompressedTTF(Pixel_compressed_data, Pixel_compressed_size, 12.f, NULL, io.Fonts->GetGlyphRangesJapanese());
    colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
    colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
    colors[ImGuiCol_WindowBg] = ImVec4(0.10f, 0.10f, 0.10f, 1.00f);
    colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    colors[ImGuiCol_PopupBg] = ImVec4(0.19f, 0.19f, 0.19f, 0.92f);
    colors[ImGuiCol_Border] = ImVec4(0.19f, 0.19f, 0.19f, 0.29f);
    colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.24f);
    colors[ImGuiCol_FrameBg] = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
    colors[ImGuiCol_FrameBgHovered] = ImVec4(0.19f, 0.19f, 0.19f, 0.54f);
    colors[ImGuiCol_FrameBgActive] = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
    colors[ImGuiCol_TitleBg] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
    colors[ImGuiCol_TitleBgActive] = ImVec4(0.06f, 0.06f, 0.06f, 1.00f);
    colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
    colors[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
    colors[ImGuiCol_ScrollbarBg] = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
    colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.34f, 0.34f, 0.34f, 0.54f);
    colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.40f, 0.40f, 0.40f, 0.54f);
    colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.56f, 0.56f, 0.56f, 0.54f);
    colors[ImGuiCol_CheckMark] = ImVec4(0.33f, 0.67f, 0.86f, 1.00f);
    colors[ImGuiCol_SliderGrab] = ImVec4(0.34f, 0.34f, 0.34f, 0.54f);
    colors[ImGuiCol_SliderGrabActive] = ImVec4(0.56f, 0.56f, 0.56f, 0.54f);
    colors[ImGuiCol_Button] = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
    colors[ImGuiCol_ButtonHovered] = ImVec4(0.19f, 0.19f, 0.19f, 0.54f);
    colors[ImGuiCol_ButtonActive] = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
    colors[ImGuiCol_Header] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
    colors[ImGuiCol_HeaderHovered] = ImVec4(0.00f, 0.00f, 0.00f, 0.36f);
    colors[ImGuiCol_HeaderActive] = ImVec4(0.20f, 0.22f, 0.23f, 0.33f);
    colors[ImGuiCol_Separator] = ImVec4(0.28f, 0.28f, 0.28f, 0.29f);
    colors[ImGuiCol_SeparatorHovered] = ImVec4(0.44f, 0.44f, 0.44f, 0.29f);
    colors[ImGuiCol_SeparatorActive] = ImVec4(0.40f, 0.44f, 0.47f, 1.00f);
    colors[ImGuiCol_ResizeGrip] = ImVec4(0.28f, 0.28f, 0.28f, 0.29f);
    colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.44f, 0.44f, 0.44f, 0.29f);
    colors[ImGuiCol_ResizeGripActive] = ImVec4(0.40f, 0.44f, 0.47f, 1.00f);
    colors[ImGuiCol_Tab] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
    colors[ImGuiCol_TabHovered] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
    colors[ImGuiCol_TabActive] = ImVec4(0.20f, 0.20f, 0.20f, 0.36f);
    colors[ImGuiCol_TabUnfocused] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
    colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
    colors[ImGuiCol_PlotLines] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
    colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
    colors[ImGuiCol_PlotHistogram] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
    colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);

    colors[ImGuiCol_TextSelectedBg] = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
    colors[ImGuiCol_DragDropTarget] = ImVec4(0.33f, 0.67f, 0.86f, 1.00f);
    colors[ImGuiCol_NavHighlight] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
    colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 0.00f, 0.00f, 0.70f);
    colors[ImGuiCol_NavWindowingDimBg] = ImVec4(1.00f, 0.00f, 0.00f, 0.20f);
    colors[ImGuiCol_ModalWindowDimBg] = ImVec4(1.00f, 0.00f, 0.00f, 0.35f);

    ImGuiStyle& style = ImGui::GetStyle();
    style.WindowPadding = ImVec2(8.00f, 8.00f);
    style.FramePadding = ImVec2(5.00f, 2.00f);
    style.ItemSpacing = ImVec2(6.00f, 6.00f);
    style.ItemInnerSpacing = ImVec2(6.00f, 6.00f);
    style.TouchExtraPadding = ImVec2(0.00f, 0.00f);
    style.IndentSpacing = 25;
    style.ScrollbarSize = 15;
    style.GrabMinSize = 10;
    style.WindowBorderSize = 1;
    style.ChildBorderSize = 1;
    style.PopupBorderSize = 1;
    style.FrameBorderSize = 1;
    style.TabBorderSize = 1;
    style.WindowRounding = 7;
    style.ChildRounding = 4;
    style.FrameRounding = 3;
    style.PopupRounding = 4;
    style.ScrollbarRounding = 9;
    style.GrabRounding = 3;
    style.TabRounding = 4;
}

void auto_sensdec() {
    LONG   lResult;
    HKEY   hKey;
    LPBYTE folder = new BYTE[MAX_PATH];
    DWORD  dwSize = sizeof(folder);
    char   value[64];
    DWORD  value_length = 64;
    DWORD  dwType = REG_SZ;

    lResult = RegOpenKey(HKEY_LOCAL_MACHINE,
        TEXT("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\"
            "Uninstall\\Steam App 252490"), &hKey);

    RegQueryValueExA(hKey, std::string(_xor_("InstallLocation").c_str()).c_str(), NULL, &dwType,
        (LPBYTE)&value, &value_length);

    RegCloseKey(hKey);

    std::ifstream file;
    std::string line;
    int fileLine = 0;

    try {
        std::string client("\\cfg\\client.cfg");

        file.open(std::string(value) + client); // path to rust

        while (std::getline(file, line))
        {
            fileLine++;


            if (line.find("input.sensitivity") != std::string::npos) { // makes sure we read the correct line of the .cfg file

                std::string sensString = line;
                size_t pos = sensString.find(" ");

                sensString = sensString.substr(pos + 2);
                std::stringstream sensConv(sensString);

                sensConv >> butunsens;
            }
        }
    }
    catch (const std::exception e) {
    }
    file.close();
}


float UserSensivity;

bool g_open = true;
int g_menuKeyBind = VK_HOME;
struct ImageTex {
	std::string m_name;
	PDIRECT3DTEXTURE9 m_texture;
	int m_width;
	int m_height;
};

std::vector<ImageTex> g_crosshairs;
ImageTex* g_pActiveCrosshair = nullptr;



bool WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	return true;
}


void oyunici();

D3DCOLOR FLOAT4TOD3DCOLOR(float Col[])
{
    ImU32 col32_no_alpha = ImGui::ColorConvertFloat4ToU32(ImVec4(Col[0], Col[1], Col[2], Col[3]));
    float a = (col32_no_alpha >> 24) & 255;
    float r = (col32_no_alpha >> 16) & 255;
    float g = (col32_no_alpha >> 8) & 255;
    float b = col32_no_alpha & 255;
    return D3DCOLOR_ARGB((int)a, (int)r, (int)g, (int)b);
}

namespace Screen
{
    static int Width = GetSystemMetrics(SM_CXSCREEN);
    static int Height = GetSystemMetrics(SM_CYSCREEN);
}

namespace Color
{
    float CrosshairColors[] = { 255.f, 55.f, 55.f, 255.f };
}

__forceinline void DrawLine1(const ImVec2& from, const ImVec2& to, ImColor color/*ARGB*/);

__forceinline void DrawLine1(const ImVec2& from, const ImVec2& to, ImColor color/*ARGB*/)
{
    ImGui::GetBackgroundDrawList()->AddLine(from, to, color, 1.0f);
}


void Crosshair()
{
    float xs = Screen::Width / 2, ys = Screen::Height / 2;

    DrawLine1(ImVec2{ xs, ys - 5 }, ImVec2{ xs , ys + 6 }, FLOAT4TOD3DCOLOR(Color::CrosshairColors));
    DrawLine1(ImVec2{ xs - 5, ys }, ImVec2{ xs + 6, ys }, FLOAT4TOD3DCOLOR(Color::CrosshairColors));

}

static int xekran = 300, yekran = 370;





void RenderUI() {  
    if (cross) {

        Crosshair();
    }
    if (panelinfo) {
        oyunici();
    }
    ImGui::SetNextWindowSize(ImVec2(xekran, yekran), ImGuiCond_Once);
    if(g_open){
    POINT mPos;

    GetCursorPos(&mPos);
    ImGui::Begin(_xor_("rust script").c_str(), NULL, ImGuiWindowFlags_NoResize);
    { 
        auto pos = ImGui::GetWindowPos();
        auto size = ImGui::GetWindowSize();
        bool isHovering = mPos.x >= pos.x && mPos.y >= pos.y && mPos.x <= (pos.x + size.x) && mPos.y <= (pos.y + size.y);
        if (isHovering)
            GAPI::EnableInput();
        else if (!isHovering)
            GAPI::DisableInput();

            if (ImGui::Button(_xor_("Main").c_str(), ImVec2(60, 18))) {
                sayfa = 1;

            }
            ImGui::SameLine();
            if (ImGui::Button(_xor_("Helpers").c_str(), ImVec2(60, 18))) {
                sayfa = 2;

            }
            ImGui::SameLine();
            if (ImGui::Button(_xor_("Settings").c_str(), ImVec2(65, 18))) {
                sayfa = 3;

            }
            ImGui::SameLine();
            if (ImGui::Button(_xor_("Keybinds").c_str(), ImVec2(65, 18))) {
                sayfa = 4;

            }
            ImGui::Separator();
            if (sayfa == 1) {
                ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 5);
                ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 9);
                ImGui::SliderFloat(_xor_("Sensitivity").c_str(), &butunsens, 0.f, 1.f);
                ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 7);
                ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 5);
                ImGui::Text(_xor_("").c_str());
                ImGui::SameLine();
                ImGui::SetCursorPosX(ImGui::GetCursorPosX() - 13);
                Hotkey("Reset", &numreset, ImVec2(80, 24));
                ImGui::SameLine();
                ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 49);
                Hotkey("Menu key", &g_menuKeyBind, ImVec2(80, 24));
                ImGui::Separator();

                ImGui::TextColored(ImVec4(0.953f, 1.f, 0.451f, 1.00f), "Weapon: ");
                ImGui::SameLine(); ImGui::SetCursorPosX(ImGui::GetCursorPosX() - 10);
                ImGui::Text(Weapon.c_str());
                ImGui::TextColored(ImVec4(0.953f, 1.f, 0.451f, 1.00f), "Scope: ");
                ImGui::SameLine(); ImGui::SetCursorPosX(ImGui::GetCursorPosX() - 10);
                ImGui::Text(Scope.c_str());
                ImGui::TextColored(ImVec4(0.953f, 1.f, 0.451f, 1.00f), "Attachment: ");
                ImGui::SameLine(); ImGui::SetCursorPosX(ImGui::GetCursorPosX() - 10);
                ImGui::Text(Attachment.c_str());

                ImGui::Separator();
                ImGui::Text("            Control Amounts");
                ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 15);
                ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 2);
                ImGui::PushItemWidth(250);
                ImGui::SliderInt("Control X", &XCONTROLL, 1.0, 100.0);
                ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 1);
                ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 2);
                ImGui::PushItemWidth(250);
                ImGui::SliderInt("Control Y", &YCONTROLL, 1.0, 100.0);
                ImGui::PushItemWidth(250);
                ImGui::SliderInt("Smoothing", &TIME, 0, 50); 

            }


            if (sayfa == 2) {
                    ImGui::Checkbox("enable auto-codelock", &auto_lock);
                    if (auto_lock)
                    {
                        Hotkey("code key", &codekey, ImVec2(80, 24));
                        ("code key", &codekey, ImVec2(80, 24));
                        ImGui::Text("codelock combination");
                        ImGui::SetNextItemWidth(30);
                        Hotkey("", &code1);
                        ImGui::SetNextItemWidth(30);
                        ImGui::SameLine(50);
                        Hotkey(" ", &code2);
                        ImGui::SameLine(90);
                        ImGui::SetNextItemWidth(30);
                        Hotkey("  ", &code3);
                        ImGui::SameLine(130);
                        ImGui::SetNextItemWidth(30);
                        Hotkey("   ", &code4);
                    }
                    ImGui::Text("");
                    ImGui::Checkbox("anti afk", &afk);
                    ImGui::Text("");
                    ImGui::Checkbox("auto loot", &al);
                    if (al == true) {
                        ImGui::TextColored(ImVec4(1.00f, 1.00f, 1.00f, 1.00f), " auto loot key");
                        ImGui::Combo("Key", &selectedItemRP, itemRP, IM_ARRAYSIZE(itemRP));
                    }
                    ImGui::Text("");
                    ImGui::Checkbox("hide on ads", &ADS_Hide);
                    ImGui::Text("");
                    ImGui::Checkbox("furnace splitter", &spl);
                    if (spl == true) {
                        ImGui::TextColored(ImVec4(1.00f, 1.00f, 1.00f, 1.00f), " furnace splitter Key");
                        ImGui::Combo("Key", &selectedItemRP, itemRP, IM_ARRAYSIZE(itemRP));
                    }
                    ImGui::Text("");
                    ImGui::Checkbox("auto upgrade", &upgrade);
                    if (upgrade)
                    {
                        ImGui::Combo("##Upgrade Item", &selectedbgrade, bgrade, IM_ARRAYSIZE(bgrade));
                        if (selectedbgrade == 0) {
                            bir = 890;
                            iki = 15;
                        }
                        if (selectedbgrade == 1) {
                            bir = 1700;
                            iki = 690;
                        }
                        if (selectedbgrade == 2) {
                            bir = 1500;
                            iki = 790;
                        }
                        if (selectedbgrade == 3) {
                            bir = 1000;
                            iki = 800;

                        }
                    }

                    if (afk)
                    {
                        keybd_event(' ', 5000, 500, 500);
                    }





                    keybindi();
                    if (GetAsyncKeyState(rpbind) & 0x8000)
                    {
                        if (afk == true) {

                            {

                                keybd_event(0x57, NULL, KEYEVENTF_EXTENDEDKEY | 0, 0);
                                Sleep(500);
                                keybd_event(0x53, NULL, KEYEVENTF_EXTENDEDKEY | 0, 0);
                                Sleep(500);
                                keybd_event(0x57, NULL, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
                                Sleep(500);
                                keybd_event(0x53, NULL, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
                                Sleep(500);
                            }


                        }
                        else {

                        }

                    }


                    keybindi();
                    if (GetAsyncKeyState(rpbind) & 0x8000)
                    {
                        if (spl == true) {

                            void mouse_move(); {



                                SetCursorPos(826, 500);
                                Sleep(100);
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


                }
                

            }
            if (sayfa == 3) {
                
                ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 5);
                ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 5);
                ImGui::SliderFloat(_xor_("Sens").c_str(), &butunsens, 0.f, 1.f);
                ImGui::SameLine();
                ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 10);
                ImGui::SetCursorPosX(ImGui::GetCursorPosX() - 10);
                if (ImGui::Button(_xor_("detect").c_str()))
                {
                    auto_sensdec();
                }
                ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 5);
                ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 5);
                ImGui::Checkbox("enable hipfire", &bhýp);
                ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 5);
                ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 5);
                ImGui::Checkbox("info panel", &panelinfo);
                ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 5);
                ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 5);
                ImGui::Checkbox("crosshair", &cross);
                ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 5);
                ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 5);
                if (ImGui::TreeNodeEx(_xor_(" Colors").c_str())) {
                    ImGui::SetColorEditOptions(ImGuiColorEditFlags_Float | ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_NoInputs);
                    ImGui::ColorEdit4(_xor_(" Crosshairs Color").c_str(), Color::CrosshairColors);
                    ImGui::EndGroup();
                    ImGui::TreePop();
                }
                ImGui::Text("");
                ImGui::Separator();
                ImGui::Text("                 Mods");
                ImGui::Text("");
                ImGui::Checkbox("Rage  Pre-set", &Rage);
                if (Rage == true) {
                    Good = false;
                    Legit = false;
                    TIME = 0;
                    randomise_toggle = false;
                    XCONTROLL = 1;
                    YCONTROLL = 1;

                }
                if (Rage == false) {
                }
                ImGui::Checkbox("Good  Pre-set", &Good);
                if (Good == true) {
                    Rage = false;
                    Legit = false;
                    TIME = 3;
                    randomise_toggle = true;
                    XCONTROLL = 2;
                    YCONTROLL = 2;


                }
                if (Good == false) {
                }
                ImGui::Checkbox("Legit Pre-set", &Legit);
                if (Legit == true) {
                    Good = false;
                    Rage = false;
                    TIME = 3;
                    randomise_toggle = true;
                    XCONTROLL = 6;
                    YCONTROLL = 6;


                }
                if (Legit == false) {
                }

            }

            if (sayfa == 4) {

                ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 5);
                ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 5);
                Hotkey("AK", &aksa, ImVec2(60, 24));
                ImGui::SetCursorPosY(ImGui::GetCursorPosY() + -27);
                ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 170);
                Hotkey("LR-300", &lr3, ImVec2(60, 24));
                ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 5);
                ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 5);
                Hotkey("MP5", &mp5k, ImVec2(60, 24));
                ImGui::SetCursorPosY(ImGui::GetCursorPosY() + -27);
                ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 170);
                Hotkey("Tommy", &tommyk, ImVec2(60, 24));
                ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 5);
                ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 5);
                Hotkey("Custom", &csmgk, ImVec2(60, 24));
                ImGui::SetCursorPosY(ImGui::GetCursorPosY() + -27);
                ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 170);
                Hotkey("SAR", &sark, ImVec2(60, 24));
                ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 5);
                ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 5);
                Hotkey("M249", &m249k, ImVec2(60, 24));
                ImGui::SetCursorPosY(ImGui::GetCursorPosY() + -27);
                ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 170);
                Hotkey("M92", &m92k, ImVec2(60, 24));
                ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 5);
                ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 5);
                Hotkey("Revolver", &revok, ImVec2(60, 24));
                ImGui::SetCursorPosY(ImGui::GetCursorPosY() + -27);
                ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 170);
                Hotkey("Python", &pythonk, ImVec2(60, 24));
                ImGui::Separator();
                ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 5);
                ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 5);
                Hotkey("8X", &x8k, ImVec2(60, 24));
                ImGui::SetCursorPosY(ImGui::GetCursorPosY() + -27);
                ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 170);
                Hotkey("16X", &x16k, ImVec2(60, 24));
                ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 5);
                ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 5);
                Hotkey("Holo", &holok, ImVec2(60, 24));
                ImGui::SetCursorPosY(ImGui::GetCursorPosY() + -27);
                ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 170);
                Hotkey("Simple", &simplek, ImVec2(60, 24));
                ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 5);
                ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 5);
                Hotkey("Silencer", &silenk, ImVec2(60, 24));
                ImGui::SetCursorPosY(ImGui::GetCursorPosY() + -27);
                ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 170);
                Hotkey("Boost", &boostk, ImVec2(60, 24));
                ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 90);
                ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 14);
                if (ImGui::Button(_xor_("Save Settings").c_str())){
                    Config::Save();
                }
            }
    }
        ImGui::End();
}

void oyunici() {
    ImGuiWindowFlags ResizeFlags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollbar;
    ImGui::Begin("Weapon Info   ", NULL, ImGuiWindowFlags_NoResize);
    ImGui::SetNextWindowSize(ImVec2(450, 70), ImGuiCond_FirstUseEver);
    ImGui::TextColored(ImVec4(0.953f, 1.f, 0.451f, 1.00f), "Weapon: ");
    ImGui::SameLine(); ImGui::SetCursorPosX(ImGui::GetCursorPosX() - 10);
    ImGui::Text(Weapon.c_str());
    ImGui::SameLine();
    ImGui::TextColored(ImVec4(0.953f, 1.f, 0.451f, 1.00f), "Scope: ");
    ImGui::SameLine(); ImGui::SetCursorPosX(ImGui::GetCursorPosX() - 10);
    ImGui::Text(Scope.c_str());
    ImGui::SameLine();
    ImGui::TextColored(ImVec4(0.953f, 1.f, 0.451f, 1.00f), "Attachment: ");
    ImGui::SameLine(); ImGui::SetCursorPosX(ImGui::GetCursorPosX() - 10);
    ImGui::Text(Attachment.c_str());
}








auto main() -> int
{

    SetPriorityClass(GetCurrentProcess(), REALTIME_PRIORITY_CLASS);
    _mkdir(_xor_("C:\\script").c_str());
    _mkdir(_xor_("C:\\script\\crosshairs").c_str());
    std::thread(auto_sensdec).detach();
    Config::Load();
    GAPI::MakeWindow(md5("overlay"), md5("overlay"), WndProc, stylemenu, RenderUI, &g_open);
    return 1;


}


