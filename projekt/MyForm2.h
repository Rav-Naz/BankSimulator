#pragma once
#include <list>

#include "API.h"
#include "Waluta.h"
#include "RodzajRachunku.h"
#include "MyForm1.h"

namespace projekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Podsumowanie informacji o MyForm2
	/// </summary>
	public ref class MyForm2 : public System::Windows::Forms::Form
	{
	public:
		MyForm2(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~MyForm2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^ rachunkiComboBox;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ oprocentowanieLabel;
	private: System::Windows::Forms::Label^ kosztyMiesieczneLabel;
	private: System::Windows::Forms::Button^ utworzBtn;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::ComboBox^ walutaComboBox;
	private: System::Windows::Forms::TextBox^ nazwaWlasnaTextBox;
	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::GroupBox^ groupBox5;
	private: System::Windows::Forms::Label^ oprocentowanieLbl;
	private: System::Windows::Forms::Label^ kosztyMiesieczneLbl;
	private: System::Windows::Forms::Button^ wyjdzBtn;


	protected:

	protected:

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
			this->rachunkiComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->oprocentowanieLabel = (gcnew System::Windows::Forms::Label());
			this->kosztyMiesieczneLabel = (gcnew System::Windows::Forms::Label());
			this->utworzBtn = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->nazwaWlasnaTextBox = (gcnew System::Windows::Forms::TextBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->walutaComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->oprocentowanieLbl = (gcnew System::Windows::Forms::Label());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->kosztyMiesieczneLbl = (gcnew System::Windows::Forms::Label());
			this->wyjdzBtn = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->SuspendLayout();
			// 
			// rachunkiComboBox
			// 
			this->rachunkiComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->rachunkiComboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->rachunkiComboBox->FormattingEnabled = true;
			this->rachunkiComboBox->Location = System::Drawing::Point(6, 19);
			this->rachunkiComboBox->Name = L"rachunkiComboBox";
			this->rachunkiComboBox->Size = System::Drawing::Size(353, 21);
			this->rachunkiComboBox->TabIndex = 0;
			this->rachunkiComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm2::rachunkiComboBox_SelectedIndexChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->rachunkiComboBox);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(365, 48);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Rodzaj rachunku";
			// 
			// oprocentowanieLabel
			// 
			this->oprocentowanieLabel->Location = System::Drawing::Point(0, 0);
			this->oprocentowanieLabel->Name = L"oprocentowanieLabel";
			this->oprocentowanieLabel->Size = System::Drawing::Size(100, 23);
			this->oprocentowanieLabel->TabIndex = 9;
			// 
			// kosztyMiesieczneLabel
			// 
			this->kosztyMiesieczneLabel->Location = System::Drawing::Point(0, 0);
			this->kosztyMiesieczneLabel->Name = L"kosztyMiesieczneLabel";
			this->kosztyMiesieczneLabel->Size = System::Drawing::Size(100, 23);
			this->kosztyMiesieczneLabel->TabIndex = 8;
			// 
			// utworzBtn
			// 
			this->utworzBtn->Location = System::Drawing::Point(202, 236);
			this->utworzBtn->Name = L"utworzBtn";
			this->utworzBtn->Size = System::Drawing::Size(115, 23);
			this->utworzBtn->TabIndex = 7;
			this->utworzBtn->Text = L"Utwórz";
			this->utworzBtn->UseVisualStyleBackColor = true;
			this->utworzBtn->Click += gcnew System::EventHandler(this, &MyForm2::utworzBtn_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->nazwaWlasnaTextBox);
			this->groupBox2->Location = System::Drawing::Point(12, 118);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(365, 48);
			this->groupBox2->TabIndex = 2;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Nazwa w³asna";
			// 
			// nazwaWlasnaTextBox
			// 
			this->nazwaWlasnaTextBox->Location = System::Drawing::Point(6, 19);
			this->nazwaWlasnaTextBox->Name = L"nazwaWlasnaTextBox";
			this->nazwaWlasnaTextBox->Size = System::Drawing::Size(353, 20);
			this->nazwaWlasnaTextBox->TabIndex = 0;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->walutaComboBox);
			this->groupBox3->Location = System::Drawing::Point(12, 172);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(365, 48);
			this->groupBox3->TabIndex = 2;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Waluta";
			// 
			// walutaComboBox
			// 
			this->walutaComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->walutaComboBox->Enabled = false;
			this->walutaComboBox->FormattingEnabled = true;
			this->walutaComboBox->Location = System::Drawing::Point(6, 19);
			this->walutaComboBox->Name = L"walutaComboBox";
			this->walutaComboBox->Size = System::Drawing::Size(353, 21);
			this->walutaComboBox->TabIndex = 0;
			this->walutaComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm2::walutaComboBox_SelectedIndexChanged);
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->oprocentowanieLbl);
			this->groupBox4->Location = System::Drawing::Point(12, 66);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(184, 48);
			this->groupBox4->TabIndex = 2;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Oprocentowanie";
			// 
			// oprocentowanieLbl
			// 
			this->oprocentowanieLbl->AutoSize = true;
			this->oprocentowanieLbl->Location = System::Drawing::Point(80, 20);
			this->oprocentowanieLbl->Name = L"oprocentowanieLbl";
			this->oprocentowanieLbl->Size = System::Drawing::Size(13, 13);
			this->oprocentowanieLbl->TabIndex = 0;
			this->oprocentowanieLbl->Text = L"--";
			this->oprocentowanieLbl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->kosztyMiesieczneLbl);
			this->groupBox5->Location = System::Drawing::Point(202, 66);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(175, 48);
			this->groupBox5->TabIndex = 3;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Koszty miesiêczne";
			// 
			// kosztyMiesieczneLbl
			// 
			this->kosztyMiesieczneLbl->AutoSize = true;
			this->kosztyMiesieczneLbl->Location = System::Drawing::Point(68, 20);
			this->kosztyMiesieczneLbl->Name = L"kosztyMiesieczneLbl";
			this->kosztyMiesieczneLbl->Size = System::Drawing::Size(13, 13);
			this->kosztyMiesieczneLbl->TabIndex = 0;
			this->kosztyMiesieczneLbl->Text = L"--";
			// 
			// wyjdzBtn
			// 
			this->wyjdzBtn->Location = System::Drawing::Point(81, 236);
			this->wyjdzBtn->Name = L"wyjdzBtn";
			this->wyjdzBtn->Size = System::Drawing::Size(115, 23);
			this->wyjdzBtn->TabIndex = 10;
			this->wyjdzBtn->Text = L"WyjdŸ";
			this->wyjdzBtn->UseVisualStyleBackColor = true;
			this->wyjdzBtn->Click += gcnew System::EventHandler(this, &MyForm2::wyjdzBtn_Click);
			// 
			// MyForm2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(389, 271);
			this->Controls->Add(this->wyjdzBtn);
			this->Controls->Add(this->groupBox5);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->utworzBtn);
			this->Controls->Add(this->kosztyMiesieczneLabel);
			this->Controls->Add(this->oprocentowanieLabel);
			this->Location = System::Drawing::Point(81, 236);
			this->Name = L"MyForm2";
			this->Text = L"Utwórz nowy rachunek";
			this->Load += gcnew System::EventHandler(this, &MyForm2::MyForm2_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void MyForm2_Load(System::Object^ sender, System::EventArgs^ e) {
		API::Get().PobierzWaluty();
		std::list<Waluta>::iterator it = API::Get().listaWalut.begin();
		for (it; it != API::Get().listaWalut.end(); ++it) {
			Waluta waluta = *it;
			auto managed = gcnew String(waluta.Nazwa().c_str());
			walutaComboBox->Items->Add(managed);
		}

		API::Get().PobierzRodzajeRachunku();
		std::list<RodzajRachunku>::iterator it2 = API::Get().listaRodzajiRachunkow.begin();
		RodzajRachunku rodzajRachunku;
		auto managed = gcnew String("");
		for (it2; it2 != API::Get().listaRodzajiRachunkow.end(); ++it2) {

			rodzajRachunku = *it2;
			managed = gcnew String(rodzajRachunku.Nazwa().c_str());
			rachunkiComboBox->Items->Add(managed);
		}
		rachunkiComboBox->SelectedIndex = 0;
		walutaComboBox->SelectedIndex = 0;
		
	}
	private: System::Void walutaComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		std::list<Waluta>::iterator iter = API::Get().listaWalut.begin();
		std::advance(iter, walutaComboBox->SelectedIndex);
		Waluta aktualnaWaluta = *iter;
		std::list<RodzajRachunku>::iterator iter2 = API::Get().listaRodzajiRachunkow.begin();
		std::advance(iter2, rachunkiComboBox->SelectedIndex);

		RodzajRachunku aktualnyRodzaj = *iter2;
		oprocentowanieLbl->Text = gcnew String(std::to_string(aktualnyRodzaj.Oprocentowanie()).substr(0, 4).c_str()) + " %" ;
		kosztyMiesieczneLbl->Text = gcnew String(std::to_string(aktualnyRodzaj.KosztyMiesieczne() * Waluta().PrzeliczNaWalute(aktualnaWaluta)).substr(0, 4).c_str()) + " " + walutaComboBox->Text;
	
	}
	private: System::Void rachunkiComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (rachunkiComboBox->Text->ToLower() == "rachunek walutowy") {
			walutaComboBox->Enabled = true;
		}
		else
		{
			walutaComboBox->Enabled = false;
		}

		std::list<RodzajRachunku>::iterator iter = API::Get().listaRodzajiRachunkow.begin();
		std::advance(iter, rachunkiComboBox->SelectedIndex);
		RodzajRachunku aktualny = *iter;
		auto managed = gcnew String(aktualny.Nazwa().c_str());
		walutaComboBox->SelectedIndex = 0;
		oprocentowanieLbl->Text = gcnew String(std::to_string(aktualny.Oprocentowanie()).substr(0, 4).c_str()) + " %";
		kosztyMiesieczneLbl->Text = gcnew String(std::to_string(aktualny.KosztyMiesieczne()).substr(0, 4).c_str()) + " " + walutaComboBox->Text;
		nazwaWlasnaTextBox->Text = managed;
	}
	private: System::Void wyjdzBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		/*this->Close();
		MyForm1 pulpitKlienta;
		pulpitKlienta.ShowDialog();*/
	}

	private: System::Void utworzBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		/*this->Close();*/
	}
};
}
