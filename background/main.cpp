#include <iostream>
#include <windows.h>
#include <chrono>
#include <thread>
#include <iomanip>
#include "memory.h"

using namespace std;

Memory memory;

void killProcess(const char* processName) {
    if (memory.FindProcess(processName)) {
        string command = "taskkill /F /IM ";
        command += processName;
        system(command.c_str());
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Неверное количество аргументов" << endl;
        return 1;
    }

    int timer = atoi(argv[1]);
    auto start = chrono::high_resolution_clock::now();

    while (true) {
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = end - start;
        if (elapsed.count() >= timer) {
            break;
        }

        killProcess("steam.exe");
        killProcess("EpicGamesLauncher.exe");
        killProcess("upc.exe");
        killProcess("Discord.exe");
        killProcess("FortniteClient-Win64-Shipping.exe");

        Sleep(1000);
    }

    return 0;
}
