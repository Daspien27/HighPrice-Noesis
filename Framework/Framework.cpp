// Framework.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>

#include "NsApp/ApplicationLauncher.h"
#include <NsApp/LocalXamlProvider.h>
#include <NsApp/LocalFontProvider.h>

#include "App.xaml.h"
#include "MainWindow.xaml.h"

using namespace Noesis;
using namespace NoesisApp;

class AppLauncher final : public NoesisApp::ApplicationLauncher
{
private:
    void RegisterComponents() const override
    {
        RegisterComponent<Blend::App>();
        RegisterComponent<Blend::MainWindow>();
    }

    Noesis::Ptr<XamlProvider> GetXamlProvider() const override
    {
        return *new LocalXamlProvider("../Blend/");
    }

    Noesis::Ptr<FontProvider> GetFontProvider() const override
    {
        return *new LocalFontProvider("../Blend");
    }
};


int main(int argc, char** argv)
{
    AppLauncher launcher;
    launcher.SetArguments(argc, argv);
    launcher.SetApplicationFile("App.xaml");
    return launcher.Run();
}