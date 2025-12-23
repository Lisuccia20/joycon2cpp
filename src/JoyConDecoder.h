#pragma once
#include <vector>
#include <utility>
#include <cstdint>
#include <Windows.h>
#include <ViGEm/Client.h>

enum class JoyConSide { Left, Right };
enum class JoyConOrientation { Upright, Sideways };
enum class GyroSource { Both, Left, Right };

struct StickData {
    int16_t x;
    int16_t y;
    BYTE rx;
    BYTE ry;
};

struct MotionData {
    SHORT gyroX, gyroY, gyroZ;
    SHORT accelX, accelY, accelZ;
};

// Funzioni per i dati degli analogici
StickData DecodeLeftJoyConStick(const std::vector<uint8_t>& buffer);
StickData DecodeRightJoyConStick(const std::vector<uint8_t>& buffer);
StickData DecodeProControllerLeftStick(const std::vector<uint8_t>& buffer);
StickData DecodeProControllerRightStick(const std::vector<uint8_t>& buffer);

// Converti coordinate Joy-Con a DS4
BYTE ConvertJoyConStickToDS4(int16_t joyconValue, bool invertY = false);

// Funzioni principali per generare report
DS4_REPORT_EX GenerateDS4Report(const std::vector<uint8_t>& buffer, JoyConSide side, JoyConOrientation orientation);
DS4_REPORT_EX GenerateDualJoyConDS4Report(const std::vector<uint8_t>& leftBuffer, const std::vector<uint8_t>& rightBuffer, GyroSource gyroSource);
DS4_REPORT_EX GenerateProControllerReport(const std::vector<uint8_t>& buffer);
DS4_REPORT_EX GenerateNSOGCReport(const std::vector<uint8_t>& buffer);

uint32_t ExtractButtonState(const std::vector<uint8_t>& buffer);
StickData DecodeJoystick(const std::vector<uint8_t>& buffer, JoyConSide side, JoyConOrientation orientation);
MotionData DecodeMotion(const std::vector<uint8_t>& buffer);