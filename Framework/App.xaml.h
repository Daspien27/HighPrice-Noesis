#pragma once

#include "NsApp/Application.h"

namespace Blend {

    class App final :
        public NoesisApp::Application
    {
        NS_IMPLEMENT_INLINE_REFLECTION_(App, Application, "Blend.App")
    };

}

