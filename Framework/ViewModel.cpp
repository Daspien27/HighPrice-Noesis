#include "pch.h"
#include "ViewModel.h"

#include <cmath>
#include <iostream>

#include "montecarlo.h"

namespace Blend
{
	const double time_step = 1.0 / 12.0;

	ViewModel::ViewModel()
	{

		interest_yearly = 0.05;
		interest_monthly = interest_yearly * time_step;

		volatility_yearly = 0.1;
		volatility_monthly = interest_yearly * std::sqrt(time_step);

		cap_rate = 0.05;

		term_length = 36;

		num_scenarios = 3000;

 		run_command.SetExecuteFunc(Noesis::MakeDelegate(this, &ViewModel::run));
	}

	void ViewModel::set_cap_rate(double value)
	{
		cap_rate = value / 100.0;
		OnPropertyChanged("cap_rate");
	}

	double ViewModel::get_cap_rate() const
	{
		return cap_rate * 100.0;
	}

	void ViewModel::set_interest_yearly(double value)
	{
		interest_yearly = value;
		interest_monthly = value * time_step;
		OnPropertyChanged("interest_yearly");
		OnPropertyChanged("interest_monthly");
	}

	double ViewModel::get_interest_yearly() const
	{
		return interest_yearly;
	}

	double ViewModel::get_interest_monthly() const
	{
		return interest_monthly;
	}

	void ViewModel::set_volatility_yearly(double value)
	{
		volatility_yearly = value;
		volatility_monthly = value * std::sqrt(time_step);
		OnPropertyChanged("volatility_yearly");
		OnPropertyChanged("volatility_monthly");
	}

	double ViewModel::get_volatility_yearly() const
	{
		return volatility_yearly;
	}


	double ViewModel::get_volatility_monthly() const
	{
		return volatility_monthly;
	}

	void ViewModel::set_term_length(int value)
	{
		term_length = value;
		OnPropertyChanged("term_length");
	}

	int ViewModel::get_term_length() const
	{
		return term_length;
	}

	void ViewModel::set_num_scenarios(int value)
	{
		num_scenarios = value;
		OnPropertyChanged("num_scenarios");
	}

	int ViewModel::get_num_scenarios() const
	{
		return num_scenarios;
	}

	const NoesisApp::DelegateCommand* ViewModel::get_run_command() const
	{
		return &run_command;
	}

	void ViewModel::run(Noesis::BaseComponent* param)
	{
		montecarlo::market_data m{ .annual_interest = interest_yearly, .annual_vol = interest_yearly,.time_step = time_step,.cap_rate = cap_rate };
		montecarlo::assumptions a{ .term_length_months = term_length };

		montecarlo::run_benchmark(100, num_scenarios, m, a);

		std::cout << "Work was done.\n";
		
	}

	NS_IMPLEMENT_REFLECTION(ViewModel)
	{
		NsProp("cap_rate", &ViewModel::get_cap_rate, &ViewModel::set_cap_rate);
		NsProp("interest_yearly", &ViewModel::get_interest_yearly, &ViewModel::set_interest_yearly);
		NsProp("interest_monthly", &ViewModel::get_interest_monthly);
		NsProp("volatility_yearly", &ViewModel::get_volatility_yearly, &ViewModel::set_volatility_yearly);
		NsProp("volatility_monthly", &ViewModel::get_volatility_monthly);
		NsProp("term_length", &ViewModel::get_term_length, &ViewModel::set_term_length);
		NsProp("num_scenarios", &ViewModel::get_num_scenarios, &ViewModel::set_num_scenarios);
		NsProp("run_command", &ViewModel::get_run_command);
	}
}