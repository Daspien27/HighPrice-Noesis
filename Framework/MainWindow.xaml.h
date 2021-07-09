#pragma once

#include "NsApp/Window.h"

namespace Blend {
    class MainWindow final :
        public NoesisApp::Window
    {
    public:
        MainWindow();
    private:
        void InitializeComponents();
        void OnInitialized(BaseComponent*, const Noesis::EventArgs&);
    private:
        NS_IMPLEMENT_INLINE_REFLECTION_(MainWindow, Window, "Blend.MainWindow")
    };
}

