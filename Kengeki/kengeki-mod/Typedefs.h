#pragma once

typedef void(__cdecl* DebugConsoleOutputT)(std::string text, bool dev, std::string color);
DebugConsoleOutputT pDebugConsoleOutput = nullptr;

typedef void(__cdecl* DebugDrawRectangleT)(int x, int y, int w, int h, unsigned char* color, float alpha);
DebugDrawRectangleT pDebugDrawRectangle = nullptr;

typedef void(__cdecl* DebugDrawTextT)(std::string text, int x, int y, HFONT font, unsigned char* color, float alpha, std::string align);
DebugDrawTextT pDebugDrawText = nullptr;

