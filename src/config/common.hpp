#pragma once
#ifndef COMMON_H
#define COMMON_H

#define WIN32_LEAN_AND_MEAN

#include <Windows.h>

#include <algorithm>
#include <array>
#include <filesystem>
#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <string_view>
#include <thread>
#include <vector>

#define DIRECTINPUT_VERSION 0X0800
#include <dinput.h>
#include <d3d9.h>
#include <DirectX9/Include/d3dX9teX.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dX9.lib")

#include <ImGui/imgui.h>
#include <ImGui/imgui_impl_dX9.h>
#include <ImGui/imgui_impl_win32.h>

using Callback = std::function<void()>;

namespace Utils {
    void Error(const std::string& s);

    bool EndsWith(const std::string& haystack, const std::string& needle);

    std::vector<std::string> GetFilesInDirectory(const char* directory);
    std::vector<std::string> SplitString(std::string str, const char* delimiter);
}

#endif // !COMMON_H
