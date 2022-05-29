#include "widgets.hpp"

#define IMGUI_DEFINE_MATH_OPERATORS
#include <ImGui/imgui_internal.h>

#define get_keycode_name(vk, name)\
switch (vk) {\
case VK_CONTROL: name = "control"; break;\
case VK_SHIFT: name = "shift"; break;\
case VK_LSHIFT: name = "shift"; break;\
case VK_MENU: name = "alt"; break;\
case VK_TAB: name = "tab"; break;\
case VK_CAPITAL: name = "caps lock"; break;\
case VK_ESCAPE: name = "esc"; break;\
case VK_SPACE: name = "space"; break;\
case VK_PAUSE: name = "pause"; break;\
case VK_LBUTTON: name = "mouse 1"; break;\
case VK_RBUTTON: name = "mouse 2"; break;\
case VK_MBUTTON: name = "mouse 3"; break;\
case VK_XBUTTON1: name = "mouse 4"; break;\
case VK_XBUTTON2: name = "mouse 5"; break;\
case VK_PRIOR: name = "page up"; break;\
case VK_NEXT: name = "page down"; break;\
case VK_END: name = "end"; break;\
case VK_HOME: name = "home"; break;\
case VK_LEFT: name = "left arrow"; break;\
case VK_UP: name = "up arrow"; break;\
case VK_RIGHT: name = "right arrow"; break;\
case VK_DOWN: name = "down arrow"; break;\
case VK_INSERT: name = "insert"; break;\
case VK_DELETE: name = "delete"; break;\
case VK_RETURN: name = "enter"; break;\
case 'A': name = "a"; break;\
case 'B': name = "b"; break;\
case 'C': name = "c"; break;\
case 'D': name = "d"; break;\
case 'E': name = "e"; break;\
case 'F': name = "f"; break;\
case 'G': name = "g"; break;\
case 'H': name = "h"; break;\
case 'I': name = "i"; break;\
case 'J': name = "j"; break;\
case 'K': name = "k"; break;\
case 'L': name = "l"; break;\
case 'M': name = "m"; break;\
case 'N': name = "n"; break;\
case 'O': name = "o"; break;\
case 'P': name = "p"; break;\
case 'Q': name = "q"; break;\
case 'R': name = "r"; break;\
case 'S': name = "s"; break;\
case 'T': name = "t"; break;\
case 'U': name = "u"; break;\
case 'V': name = "v"; break;\
case 'W': name = "w"; break;\
case 'X': name = "x"; break;\
case 'Y': name = "y"; break;\
case 'Z': name = "z"; break;\
case VK_NUMPAD0: name = "numpad 0"; break;\
case VK_NUMPAD1: name = "numpad 1"; break;\
case VK_NUMPAD2: name = "numpad 2"; break;\
case VK_NUMPAD3: name = "numpad 3"; break;\
case VK_NUMPAD4: name = "numpad 4"; break;\
case VK_NUMPAD5: name = "numpad 5"; break;\
case VK_NUMPAD6: name = "numpad 6"; break;\
case VK_NUMPAD7: name = "numpad 7"; break;\
case VK_NUMPAD8: name = "numpad 8"; break;\
case VK_NUMPAD9: name = "numpad 9"; break;\
case VK_F1: name = "f1"; break;\
case VK_F2: name = "f2"; break;\
case VK_F3: name = "f3"; break;\
case VK_F4: name = "f4"; break;\
case VK_F5: name = "f5"; break;\
case VK_F6: name = "f6"; break;\
case VK_F7: name = "f7"; break;\
case VK_F8: name = "f8"; break;\
case VK_F9: name = "f9"; break;\
case VK_F10: name = "f10"; break;\
case VK_F11: name = "f11"; break;\
case VK_F12: name = "f12"; break;\
default: name = "unknown";\

const char* const silahname[] = {
"AK",
"LR"
};

const char* const KeyNames[] = {
	"Unknown",
	"MOUSE-1",
	"MOUSE-2",
	"VK_CANCEL",
	"MOUSE-3",
	"MOUSE-4",
	"MOUSE-5",
	"Unknown",
	"VK_BACK",
	"tab",
	"Unknown",
	"Unknown",
	"VK_CLEAR",
	"VK_RETURN",
	"Unknown",
	"Unknown",
	"shift",
	"control",
	"alt",
	"pause",
	"capslock",
	"VK_KANA",
	"Unknown",
	"VK_JUNJA",
	"VK_FINAL",
	"VK_KANJI",
	"Unknown",
	"esc",
	"CONVERT",
	"NONCONVERT",
	"ACCEPT",
	"MODECHANGE",
	"space",
	"PRIOR",
	"NEXT",
	"END",
	"HOME",
	"LEFT",
	"UP",
	"RIGHT",
	"DOWN",
	"SELECT",
	"PRINT",
	"EXECUTE",
	"SNAPSHOT",
	"INSERT",
	"DELETE",
	"HELP",
	"0",
	"1",
	"2",
	"3",
	"4",
	"5",
	"6",
	"7",
	"8",
	"9",
	"Unknown",
	"Unknown",
	"Unknown",
	"Unknown",
	"Unknown",
	"Unknown",
	"Unknown",
	"a",
	"b",
	"c",
	"d",
	"e",
	"f",
	"g",
	"h",
	"ý",
	"k",
	"k",
	"l",
	"m",
	"n",
	"o",
	"p",
	"q",
	"r",
	"s",
	"t",
	"u",
	"v",
	"w",
	"x",
	"y",
	"z",
	"VK_LWIN",
	"VK_RWIN",
	"VK_APPS",
	"Unknown",
	"VK_SLEEP",
	"numpad 0",
	"numpad 1",
	"numpad 2",
	"numpad 3",
	"numpad 4",
	"numpad 5",
	"numpad 6",
	"numpad 7",
	"numpad 8",
	"numpad 9",
	"VK_MULTIPLY",
	"VK_ADD",
	"VK_SEPARATOR",
	"VK_SUBTRACT",
	"VK_DECIMAL",
	"VK_DIVIDE",
	"f1",
	"f2",
	"f3",
	"f4",
	"f5",
	"f6",
	"f7",
	"f8",
	"f9",
	"f10",
	"f11",
	"f12",
	"f13",
	"f14",
	"f15",
	"f16",
	"f17",
	"f18",
	"f19",
	"f20",
	"f21",
	"f22",
	"f23",
	"f24",
	"Unknown",
	"Unknown",
	"Unknown",
	"Unknown",
	"Unknown",
	"Unknown",
	"Unknown",
	"Unknown",
	"VK_NUMLOCK",
	"VK_SCROLL",
	"VK_OEM_NEC_EQUAL",
	"VK_OEM_FJ_MASSHOU",
	"VK_OEM_FJ_TOUROKU",
	"VK_OEM_FJ_LOYA",
	"VK_OEM_FJ_ROYA",
	"Unknown",
	"Unknown",
	"Unknown",
	"Unknown",
	"Unknown",
	"Unknown",
	"Unknown",
	"Unknown",
	"Unknown",
	"lshift",
	"VK_RSHIFT",
	"VK_LCONTROL",
	"VK_RCONTROL",
	"VK_LMENU",
	"VK_RMENU"
};


	bool Hotkey(const char* label, int* k, const ImVec2& size_arg)
	{
		ImGuiWindow* window = ImGui::GetCurrentWindow();
		if (window->SkipItems)
			return false;

		ImGuiContext& g = *GImGui;
		ImGuiIO& io = g.IO;
		const ImGuiStyle& style = g.Style;

		const ImGuiID id = window->GetID(label);
		const ImVec2 label_size = ImGui::CalcTextSize(label, NULL, true);
		ImVec2 size = ImGui::CalcItemSize(size_arg, ImGui::CalcItemWidth(), label_size.y + style.FramePadding.y * 2.0f);
		
		//const ImRect frame_bb(window->DC.CursorPos + ImVec2(label_size.x + style.ItemInnerSpacing.x, 0.0f), window->DC.CursorPos + size);
		const ImRect frame_bb(window->DC.CursorPos + ImVec2(0.0f, 0.0f), window->DC.CursorPos + size);
		const ImRect total_bb(window->DC.CursorPos, frame_bb.Max);

		ImGui::ItemSize(total_bb, style.FramePadding.y);
		if (!ImGui::ItemAdd(total_bb, id))
			return false;

		const bool focus_requested = ImGui::FocusableItemRegister(window, g.ActiveId == id);

		const bool hovered = ImGui::ItemHoverable(frame_bb, id);

		if (hovered) {
			ImGui::SetHoveredID(id);
			g.MouseCursor = ImGuiMouseCursor_TextInput;
		}

		const bool user_clicked = hovered && io.MouseClicked[0];

		if (focus_requested || user_clicked) {
			if (g.ActiveId != id) {
				// Start edition
				memset(io.MouseDown, 0, sizeof(io.MouseDown));
				memset(io.KeysDown, 0, sizeof(io.KeysDown));
				*k = 0;
			}
			ImGui::SetActiveID(id, window);
			ImGui::FocusWindow(window);
		}
		else if (io.MouseClicked[0]) {
			// Release focus when we click outside
			if (g.ActiveId == id)
				ImGui::ClearActiveID();
		}

		bool value_changed = false;
		int key = *k;

		if (g.ActiveId == id) {
			for (auto i = 0; i < 5; i++) {
				if (io.MouseDown[i]) {
					switch (i) {
					case 0:
						key = VK_LBUTTON;
						break;
					case 1:
						key = VK_RBUTTON;
						break;
					case 2:
						key = VK_MBUTTON;
						break;
					case 3:
						key = VK_XBUTTON1;
						break;
					case 4:
						key = VK_XBUTTON2;
						break;
					}
					value_changed = true;
					ImGui::ClearActiveID();
				}
			}
			if (!value_changed) {
				for (auto i = VK_BACK; i <= VK_RMENU; i++) {
					if (io.KeysDown[i]) {
						key = i;
						value_changed = true;
						ImGui::ClearActiveID();
					}
				}
			}

			if (ImGui::IsKeyPressedMap(ImGuiKey_Escape)) {
				*k = 0;
				ImGui::ClearActiveID();
			}
			else {
				*k = key;
			}
		}

		// Render
		// Select which buffer we are going to display. When ImGuiInputTextFlags_NoLiveEdit is Set 'buf' might still be the old value. We Set buf to NULL to prevent accidental usage from now on.

		char buf_display[64] = "key";

		ImGui::RenderFrame(frame_bb.Min, frame_bb.Max, ImGui::GetColorU32(ImVec4(0.20f, 0.25f, 0.30f, 1.0f)), true, style.FrameRounding);

		if (*k != 0 && g.ActiveId != id) {
			strcpy_s(buf_display, KeyNames[*k]);
		}
		else if (g.ActiveId == id) {
			strcpy_s(buf_display, "<key>");
		}

		const ImRect clip_rect(frame_bb.Min.x, frame_bb.Min.y, frame_bb.Min.x + size.x, frame_bb.Min.y + size.y); // Not using frame_bb.Max because we have adjusted size
		ImVec2 render_pos = frame_bb.Min + style.FramePadding;
		ImGui::RenderTextClipped(frame_bb.Min + style.FramePadding, frame_bb.Max - style.FramePadding, buf_display, NULL, NULL, { 0.f, 0.5f }, &clip_rect);
		//RenderTextClipped(frame_bb.Min + style.FramePadding, frame_bb.Max - style.FramePadding, buf_display, NULL, NULL, GetColorU32(ImGuiCol_Text), style.ButtonTextAlign, &clip_rect);
		//draw_window->DrawList->AddText(g.Font, g.FontSize, render_pos, GetColorU32(ImGuiCol_Text), buf_display, NULL, 0.0f, &clip_rect);

		if (label_size.x > 0)
			ImGui::RenderText(ImVec2(total_bb.Max.x + style.ItemInnerSpacing.x, frame_bb.Min.y + style.FramePadding.y), label);
			//ImGui::RenderText(ImVec2(total_bb.Min.x, frame_bb.Min.y + style.FramePadding.y), label);

		return value_changed;
	}
