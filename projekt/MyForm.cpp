#include "MyForm.h"
#include <iostream>

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]

void main(array<String^>^ args) {
	Diagnostics::Debug::WriteLine(L"ASD AS DAS DAS D");
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	projekt::MyForm frm;
	Application::Run(% frm);
}