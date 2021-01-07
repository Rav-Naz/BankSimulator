#pragma once
#include <msclr\marshal_cppstd.h>
#include "API.h"

namespace projekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o MyForm4
	/// </summary>
	public ref class MyForm4 : public System::Windows::Forms::Form
	{
	public:
		System::Windows::Forms::Form^ loginForm;
		MyForm4(System::Windows::Forms::Form^ loginPanel)
		{
			loginForm = loginPanel;
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~MyForm4()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	protected:
	private: System::Windows::Forms::TextBox^ hasloTextBox;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::TextBox^ powtorzHasloTextBox;
	private: System::Windows::Forms::Button^ utworzBtn;
	private: System::Windows::Forms::Button^ wyjdzBtn;
	private: System::Windows::Forms::Label^ idLabel;

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm4::typeid));
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->hasloTextBox = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->powtorzHasloTextBox = (gcnew System::Windows::Forms::TextBox());
			this->utworzBtn = (gcnew System::Windows::Forms::Button());
			this->wyjdzBtn = (gcnew System::Windows::Forms::Button());
			this->idLabel = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->hasloTextBox);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(210, 53);
			this->groupBox1->TabIndex = 6;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Has³o";
			// 
			// hasloTextBox
			// 
			this->hasloTextBox->Location = System::Drawing::Point(13, 19);
			this->hasloTextBox->MaxLength = 25;
			this->hasloTextBox->Name = L"hasloTextBox";
			this->hasloTextBox->PasswordChar = '*';
			this->hasloTextBox->Size = System::Drawing::Size(186, 20);
			this->hasloTextBox->TabIndex = 0;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->powtorzHasloTextBox);
			this->groupBox2->Location = System::Drawing::Point(12, 71);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(210, 53);
			this->groupBox2->TabIndex = 7;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Powtórz has³o";
			// 
			// powtorzHasloTextBox
			// 
			this->powtorzHasloTextBox->Location = System::Drawing::Point(13, 19);
			this->powtorzHasloTextBox->MaxLength = 25;
			this->powtorzHasloTextBox->Name = L"powtorzHasloTextBox";
			this->powtorzHasloTextBox->PasswordChar = '*';
			this->powtorzHasloTextBox->Size = System::Drawing::Size(186, 20);
			this->powtorzHasloTextBox->TabIndex = 0;
			// 
			// utworzBtn
			// 
			this->utworzBtn->Location = System::Drawing::Point(123, 167);
			this->utworzBtn->Name = L"utworzBtn";
			this->utworzBtn->Size = System::Drawing::Size(100, 31);
			this->utworzBtn->TabIndex = 8;
			this->utworzBtn->Text = L"Utwórz";
			this->utworzBtn->UseVisualStyleBackColor = true;
			this->utworzBtn->Click += gcnew System::EventHandler(this, &MyForm4::utworzBtn_Click);
			// 
			// wyjdzBtn
			// 
			this->wyjdzBtn->Location = System::Drawing::Point(12, 167);
			this->wyjdzBtn->Name = L"wyjdzBtn";
			this->wyjdzBtn->Size = System::Drawing::Size(100, 31);
			this->wyjdzBtn->TabIndex = 9;
			this->wyjdzBtn->Text = L"WyjdŸ";
			this->wyjdzBtn->UseVisualStyleBackColor = true;
			this->wyjdzBtn->Click += gcnew System::EventHandler(this, &MyForm4::wyjdzBtn_Click);
			// 
			// idLabel
			// 
			this->idLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->idLabel->AutoSize = true;
			this->idLabel->Location = System::Drawing::Point(75, 127);
			this->idLabel->Name = L"idLabel";
			this->idLabel->Size = System::Drawing::Size(83, 13);
			this->idLabel->TabIndex = 10;
			this->idLabel->Text = L"Przydzielone ID:";
			this->idLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// MyForm4
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(235, 207);
			this->Controls->Add(this->idLabel);
			this->Controls->Add(this->wyjdzBtn);
			this->Controls->Add(this->utworzBtn);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm4";
			this->Text = L"Utwórz konto";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void wyjdzBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->loginForm->Show();
		this->Close();
	}
	private: System::Void utworzBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		msclr::interop::marshal_context context;
		std::string haslo = context.marshal_as<std::string>(this->hasloTextBox->Text);
		std::string powtorzoneHaslo = context.marshal_as<std::string>(this->powtorzHasloTextBox->Text);
		for (int i = 0; i < haslo.length(); i++) {
			if ((int)haslo[i] < 48 || ((int)haslo[i] > 57 && (int)haslo[i] < 65) || (int)haslo[i] > 122 ) {
				::MessageBox(0, L"U¿ywaj tylko liter alfabetu ³aciñskiego oraz liczb arabskich", L"Uwaga", MB_ICONWARNING);
				return;
				break;
			}
		}
		if (haslo != powtorzoneHaslo) {
			::MessageBox(0, L"Has³a siê ró¿ni¹", L"Uwaga", MB_ICONWARNING);
			return;
		}
		std::string result = API::Get().UtworzKonto(haslo);
		if (result == "Error") {
			::MessageBox(0, L"Napotkano nieoczekiwany b³¹d. Spróbuj ponownie póŸniej", L"B³¹d", MB_ICONERROR);
			return;
		}
		else
		{
			this->idLabel->Text = gcnew String(("Przydzielone ID: \n" + result).c_str());
			utworzBtn->Enabled = false;
		}
	}
};
}
