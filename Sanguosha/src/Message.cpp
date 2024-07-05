// Copyright (C) 2018 - 2023 Tony's Studio. All rights reserved.
// Licensed under the MIT License.

#include <easyx.h>
#include "../inc/Message.h"
#include"../inc/Globals.h"

static MouseMessage mouse;

int userKey[256];

void PeekMouseMessage()
{
    ExMessage msg;

    mouse.isUp = false;
    mouse.isDown = false;
    for (int i = 0; i < 256; i++) userKey[i] = 0;
    while (peekmessage(&msg, EX_MOUSE| EX_KEY))
    {
        if (msg.message == WM_MOUSEMOVE)
        {
            mouse.x = msg.x;
            mouse.y = msg.y;
        }
        else if (msg.message == WM_LBUTTONUP)
        {
            mouse.isUp = true;
            mouse.isDown = false;
        }
        else if (msg.message == WM_LBUTTONDOWN)
        {
            mouse.isUp = false;
            mouse.isDown = true;
        }
        else if(msg.message == WM_KEYDOWN) {
            if (!msg.prevdown) {
                userKey[msg.vkcode] = 1;
            }
        }
    }
}

bool IsKeyDown(int key)
{
    return userKey[key];
//    int tmp = userKey[key];
//    return userKey[key]=0,tmp;
//    return (GetAsyncKeyState(key) & 0x8000);
}

std::wstring GetKey() {
    for (int i = 65; i <= 90; i++) {
        if (IsKeyDown(i)) {
            std::wstring s = L"";
            s += char(i);
            return s;
        }
    }
    for (int i = 48; i <= 57; i++) {
        if (IsKeyDown(i)) {
            std::wstring s = L"";
            s += char(i);
            return s;
        }
    }
    if (IsKeyDown(VK_RETURN)) return L"Enter";
    if (IsKeyDown(VK_SPACE)) return L"Space";
    if (IsKeyDown(VK_DELETE)) return L"Delete";
    if (IsKeyDown(VK_BACK)) return L"Backspace";
    if (IsKeyDown(VK_LSHIFT) || IsKeyDown(VK_RSHIFT)) return L"Shift";

    return L"None";
}

MouseMessage* GetMouseMessage()
{
    return &mouse;
}