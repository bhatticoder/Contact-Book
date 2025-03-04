#include "Home.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
int main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	ContactsApp::Home form;
	Application::Run(% form);
	return 0;
}

