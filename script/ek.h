#pragma once

#include <Windows.h>
#include <iostream>
#include <intrin.h>
#include <chrono>
#include <thread>
#include <string>
#include <vector>
#include "recoil.h"

#include <mmsystem.h>
#include <winbase.h>
#include <tchar.h>

#pragma comment(lib, "winmm.lib")




double BarrelAttachment();
void little_sleep(std::chrono::milliseconds us);
void ms_sleep(int milliseconds);
void pQuerySleep(int ms);
void Sound(bool type);
bool Recoil();
int IsMuzzleBoost(float Delay);
double ScopeAttachment();

void Smoothing(double delay, double control_time, int x, int y);
bool legitayar1 = false;
bool legitayar2 = false;
bool auto_lock = false;
bool recoil = true;
static bool afk = false;
static bool acl = false;
static bool au = false;
static bool al = false;
static bool spl = false;



bool bReload, bAK47, bLR300, bMP5, bCSMG, bpython, bm39, bM92, bSemi, bRevo, bfun, bTHOMPSON, bM249, bSound, b8x, b16x, bHolo, bSimple, bSuppressor, bhýp, bMuzzleBoost = false;
float butunsens;

float XCONTROL = 1;
float YKontrol = 1;



namespace Input
{
	bool WhilePressed(int virtual_key)
	{
		if (GetAsyncKeyState(virtual_key) & 0x8000) return true;
		return false;
	}
	bool IsPressed(int virtual_key)
	{
		if (GetKeyState(virtual_key) & 0x8000) return true;
		return false;
	}
	bool lonePressed(int virtual_key)
	{
		if (GetKeyState(virtual_key) & 0x8000) return true;
		return true;
	}
}

void Smoothing(float delay, float control_time, int x, int y) {
	int x_ = 0, y_ = 0, t_ = 0;
	for (int i = 1; i <= (float)control_time; ++i) {
		float xI = i * x / (float)control_time;
		float yI = i * y / (float)control_time;
		float tI = i * (float)control_time / (float)control_time;
		mouse_event(1, (float)xI - (float)x_, (float)yI - (float)y_, 0, 0);
		pQuerySleep((float)tI - (float)t_);
		x_ = xI; y_ = yI; t_ = tI;
	}
	pQuerySleep((float)delay - (float)control_time);
}

int IsMuzzleBoost(float Delay)
{
	if (bMuzzleBoost == true)
	{
		float difference = Delay * 0.0f;
		Delay = Delay - difference;
		return (float)Delay + 0;
	}
	else
		return (float)Delay;
}



double BarrelAttachment() {
	if (bSuppressor == true && recoil == true) {
		if (bM249 == true)
			Multiplyer::Attachment.Suppressor = 0.75;
		if (bCSMG == true)
			Multiplyer::Attachment.Suppressor = 0.85;
		if (bSimple == true || bHolo == true)
			return 0.75;
		if (b8x == true && bSuppressor == true)
			return 1.46;
		else
			return Multiplyer::Attachment.Suppressor;

	}
	else
		return Multiplyer::Attachment.None;
}
double ScopeAttachment() {
	if (Input::WhilePressed(VK_LBUTTON) && Input::WhilePressed(VK_RBUTTON) && b8x == true && recoil == true) {

		if (bCSMG == true || bTHOMPSON == true) {
			if (b8x == true)
				return Multiplyer::Scope.x8 + 0.75;
		}
		return Multiplyer::Scope.x8;
	}
	else if (Input::WhilePressed(VK_LBUTTON) && Input::WhilePressed(VK_RBUTTON) && b16x == true && recoil == true) {
		if (bCSMG == true || bTHOMPSON == true) {
			if (b16x == true)
				return Multiplyer::Scope.x16 + 1.5;
		}
		return Multiplyer::Scope.x16;
	}
	else	if (Input::WhilePressed(VK_LBUTTON) && Input::WhilePressed(VK_RBUTTON) && bSimple == true && recoil == true) {
		if (bCSMG == true || bTHOMPSON == true) {
			if (bSimple == true)
				return Multiplyer::Scope.Simple + 0.1;
		}
		return Multiplyer::Scope.Simple;
	}
	else	if (Input::WhilePressed(VK_LBUTTON) && Input::WhilePressed(VK_RBUTTON) && bHolo == true && recoil == true) {
		if (bCSMG == true || bTHOMPSON == true) {
			if (bHolo == true)
				return Multiplyer::Scope.Holo + 0.3;
		}
		return Multiplyer::Scope.Holo;
	}




	else if (Input::WhilePressed(VK_LBUTTON) && Input::WhilePressed(VK_RBUTTON) && recoil == true)
	{
		return 1;
	}


	else if (recoil == false) {
		return Multiplyer::Scope.disabled;
	}


	else if (Input::WhilePressed(VK_LBUTTON) && recoil == true && bhýp == true)
	{
		return 0.6;
	}

}

void pQuerySleep(int ms)
{
	LONGLONG timerResolution;
	LONGLONG wantedTime;
	LONGLONG currentTime;

	QueryPerformanceFrequency((LARGE_INTEGER*)&timerResolution);
	timerResolution /= 1000;

	QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);
	wantedTime = currentTime / timerResolution + ms;
	currentTime = 0;
	while (currentTime < wantedTime)
	{
		QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);
		currentTime /= timerResolution;
	}
}

void Sound(bool type) {
	if (type == false) {
		switch (bSound) {
		case(false):
			Beep(200, 400);
		}
	}
	else {
		switch (bSound) {
		case(false):
			Beep(200, 400);
		}
	}
	Sleep(1);
}
