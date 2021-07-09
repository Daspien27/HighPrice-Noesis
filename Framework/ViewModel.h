#pragma once

#include <NsApp/DelegateCommand.h>
#include "NsApp/NotifyPropertyChangedBase.h"

namespace Blend {
    class ViewModel :
        public NoesisApp::NotifyPropertyChangedBase
    {
    public:
        ViewModel();

    private:

        void set_cap_rate(double value);
        double get_cap_rate() const;
        void set_interest_yearly(double value);
		double get_interest_yearly() const;
		double get_interest_monthly() const;
		void set_volatility_yearly(double value);
		double get_volatility_yearly() const;
		double get_volatility_monthly() const;
		void set_term_length(int value);
		int get_term_length() const;
		void set_num_scenarios(int value);
		int get_num_scenarios() const;

        const NoesisApp::DelegateCommand* get_run_command() const;

        void run(Noesis::BaseComponent* param);

    private:

        double cap_rate;

        double interest_yearly;
        double interest_monthly;

        double volatility_yearly;
        double volatility_monthly;

        int term_length;

        int num_scenarios;

        NoesisApp::DelegateCommand run_command;

        NS_DECLARE_REFLECTION(ViewModel, NotifyPropertyChangedBase)
    };
}


