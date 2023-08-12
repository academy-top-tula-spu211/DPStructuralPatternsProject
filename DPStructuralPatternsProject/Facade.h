#pragma once
#include <iostream>

using namespace std;

// Systems, Services
class TextEditor
{
public:
	void CreateCode(string& code)
	{
		code = "code.cpp";
		cout << "editor create code\n";
	}

	string& SaveCode(string& code)
	{
		code = "prog.cpp";
		cout << "editor save code\n";
		return code;
	}
};

class Compiller
{
public:
	string Compile(string& code)
	{
		cout << "Compiller create exe file\n";
		return "prog.exe";
	}
};

class Debugger
{
public:
	void StepDebug(string& code)
	{
		cout << "Debugger execute one step of code\n";
	}

	string SaveDebug(string& code)
	{
		cout << "Debugger save debugging code\n";
		code = "prog_new.exe";
		return code;
	}
};

class Runtime
{
public:
	void Execute(string& code)
	{
		cout << "Runtime execute code\n";
	}

	int Finish(string& code)
	{
		cout << "Runtime finished code\n";
		return 0;
	}
};

// Facade
class VisualStudioFacade
{
	TextEditor* editor;
	Compiller* compiller;
	Debugger* debugger;
	Runtime* runtime;

	string code;
	string app;
public:
	VisualStudioFacade(TextEditor* editor,
						Compiller* compiller,
						Debugger* debugger,
						Runtime* runtime)
		: editor{ editor },
		compiller{ compiller },
		debugger{ debugger },
		runtime{ runtime } {}

	void Process()
	{
		editor->CreateCode(code);
		code = editor->SaveCode(code);

		app = compiller->Compile(code);
		runtime->Execute(app);
		runtime->Finish(app);

		debugger->StepDebug(code);
		code = debugger->SaveDebug(code);

		app = compiller->Compile(code);
		runtime->Execute(app);
		runtime->Finish(app);
	}
};
