#include <string>
#include <mysql.h>
#include <iostream>
#include <cstdlib> 
#include <ctime> 

#include "MyForm.h"
#include "Waluta.h"
#include "API.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]

void main(array<String^>^ args) {
	//setlocale(LC_ALL, "pl-PL");
	srand((unsigned)time(0));
	API::Get().InitDB("localhost", "root", "password", "projektcpp", 3307);
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	projekt::MyForm frm;
	Application::Run(% frm);
}