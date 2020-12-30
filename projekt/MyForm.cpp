#include "MyForm.h"
#include <iostream>
#include <mysql.h>
#include <string>
#include "Waluta.h"
#include "API.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]

void main(array<String^>^ args) {
	API::Get().InitDB("localhost", "root", "password", "projektcpp", 3307);
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	projekt::MyForm frm;
	Application::Run(% frm);
}