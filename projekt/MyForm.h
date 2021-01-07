#pragma once

#include <msclr\marshal_cppstd.h>

#include "API.h"
#include "Logowanie.h"
#include "Konto.h"

#include "MyForm4.h"
#include "MyForm1.h"
#include "MyForm.h"


namespace projekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

	protected:
		/// <summary>
		/// Wyczyść wszystkie używane zasoby.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ loginTextBox;
	protected:

	protected:


	private: System::Windows::Forms::TextBox^ hasloTextBox;
	private: System::Windows::Forms::Button^ zalogujBtn;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Button^ utworzKontoBtn;

	protected:

	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obsługi projektanta — nie należy modyfikować
		/// jej zawartości w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->loginTextBox = (gcnew System::Windows::Forms::TextBox());
			this->hasloTextBox = (gcnew System::Windows::Forms::TextBox());
			this->zalogujBtn = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->utworzKontoBtn = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// loginTextBox
			// 
			this->loginTextBox->Location = System::Drawing::Point(13, 19);
			this->loginTextBox->MaxLength = 6;
			this->loginTextBox->Name = L"loginTextBox";
			this->loginTextBox->Size = System::Drawing::Size(186, 20);
			this->loginTextBox->TabIndex = 0;
			// 
			// hasloTextBox
			// 
			this->hasloTextBox->BackColor = System::Drawing::SystemColors::Window;
			this->hasloTextBox->Location = System::Drawing::Point(13, 19);
			this->hasloTextBox->Name = L"hasloTextBox";
			this->hasloTextBox->PasswordChar = '*';
			this->hasloTextBox->Size = System::Drawing::Size(186, 20);
			this->hasloTextBox->TabIndex = 2;
			// 
			// zalogujBtn
			// 
			this->zalogujBtn->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->zalogujBtn->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->zalogujBtn->ForeColor = System::Drawing::SystemColors::ControlText;
			this->zalogujBtn->Location = System::Drawing::Point(123, 133);
			this->zalogujBtn->Name = L"zalogujBtn";
			this->zalogujBtn->Size = System::Drawing::Size(99, 31);
			this->zalogujBtn->TabIndex = 4;
			this->zalogujBtn->Text = L"Zaloguj";
			this->zalogujBtn->UseVisualStyleBackColor = false;
			this->zalogujBtn->Click += gcnew System::EventHandler(this, &MyForm::zalogujBtn_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->loginTextBox);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(210, 53);
			this->groupBox1->TabIndex = 5;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"ID Użytkownika";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->hasloTextBox);
			this->groupBox2->Location = System::Drawing::Point(12, 71);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(210, 56);
			this->groupBox2->TabIndex = 6;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Hasło";
			// 
			// utworzKontoBtn
			// 
			this->utworzKontoBtn->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->utworzKontoBtn->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->utworzKontoBtn->ForeColor = System::Drawing::SystemColors::ControlText;
			this->utworzKontoBtn->Location = System::Drawing::Point(12, 133);
			this->utworzKontoBtn->Name = L"utworzKontoBtn";
			this->utworzKontoBtn->Size = System::Drawing::Size(99, 31);
			this->utworzKontoBtn->TabIndex = 7;
			this->utworzKontoBtn->Text = L"Utwórz konto";
			this->utworzKontoBtn->UseVisualStyleBackColor = false;
			this->utworzKontoBtn->Click += gcnew System::EventHandler(this, &MyForm::utworzKontoBtn_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(237, 174);
			this->Controls->Add(this->utworzKontoBtn);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->zalogujBtn);
			this->Cursor = System::Windows::Forms::Cursors::Default;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"Logowanie";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void zalogujBtn_Click(System::Object^ sender, System::EventArgs^ e) {

		msclr::interop::marshal_context context;
		std::string uzytkownikId = context.marshal_as<std::string>(this->loginTextBox->Text);
		if (uzytkownikId.length() != 6) {
			::MessageBox(0, L"Niepoprawny identyfikator użytkownika", L"Uwaga", MB_ICONWARNING);
			return;
		}
		Logowanie* logowanie = new Logowanie(uzytkownikId, context.marshal_as<std::string>(this->hasloTextBox->Text));
		if (logowanie->Powodzenie() == 1) { //pomyślne logowanie
			this->Hide();
			MyForm1^ clientPanel = gcnew MyForm1(this);
			auto result = clientPanel->ShowDialog();
		} 
		else if (logowanie->Powodzenie() == 0) { //błędne hasło
			::MessageBox(0, L"Podano błędne hasło. Po 3 nieudanych próbach logowania, dostęp do konta zostanie czasowo zablokowany.", L"Uwaga", MB_ICONWARNING);
		}
		else if (logowanie->Powodzenie() == -1) { //brak użytkownika
			::MessageBox(0, L"Użytkownik o podanym ID nie istnieje", L"Uwaga", MB_ICONWARNING);
		}
		else if (logowanie->Powodzenie() == -2) { //zablokowanie logowania
			::MessageBox(0, L"Możliwość logowania do Twojego konta została zablokowana, z powodu 3-krotnego podania błędnego hasła. Kolejną próbę możesz podjąć po 24 godzinach od pierwszego nieduanego logowania", L"Błąd", MB_ICONERROR);
		}
		else {
			::MessageBox(0, L"Napotkano nieoczekiwany błąd. Spróbuj ponownie później", L"Błąd", MB_ICONERROR);
		}

	}

	private: System::Void utworzKontoBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		MyForm4^ newAccount = gcnew MyForm4(this);
		auto result = newAccount->ShowDialog();
	}
};
}
