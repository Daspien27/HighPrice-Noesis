#include "pch.h"
#include "MainWindow.xaml.h"
#include "ViewModel.h"
namespace Blend
{
    MainWindow::MainWindow() {
        Initialized() += MakeDelegate(this, &MainWindow::OnInitialized);
        InitializeComponents();
    }

    void MainWindow::InitializeComponents() {
        Noesis::GUI::LoadComponent(this, "MainWindow.xaml");
    }

    void MainWindow::OnInitialized(BaseComponent*, const Noesis::EventArgs&)
    {
        SetDataContext(Noesis::MakePtr<ViewModel>());
    }
}