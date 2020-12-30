#pragma once

namespace projekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^ rachunkiComboBox;
	protected:
	private: System::Windows::Forms::Button^ wylogujBtn;
	private: System::Windows::Forms::Label^ userIdLabel;
	private: System::Windows::Forms::ListBox^ historiaPrzelewowListBox;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ kosztyMiesieczneLabel;
	private: System::Windows::Forms::Label^ oprocentowanieLabel;
	private: System::Windows::Forms::Label^ rodzajRachunkuLabel;
	private: System::Windows::Forms::Button^ zlecPrzelewBtn;
	private: System::Windows::Forms::Button^ limitMiesiecznyBtn;
	private: System::Windows::Forms::Button^ limitDziennyBtn;
	private: System::Windows::Forms::TextBox^ limitMiesiecznyTextBox;
	private: System::Windows::Forms::TextBox^ limitDziennyTextBox;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ saldoLabel;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;

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
			this->wylogujBtn = (gcnew System::Windows::Forms::Button());
			this->userIdLabel = (gcnew System::Windows::Forms::Label());
			this->historiaPrzelewowListBox = (gcnew System::Windows::Forms::ListBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->kosztyMiesieczneLabel = (gcnew System::Windows::Forms::Label());
			this->oprocentowanieLabel = (gcnew System::Windows::Forms::Label());
			this->rodzajRachunkuLabel = (gcnew System::Windows::Forms::Label());
			this->zlecPrzelewBtn = (gcnew System::Windows::Forms::Button());
			this->limitMiesiecznyBtn = (gcnew System::Windows::Forms::Button());
			this->limitDziennyBtn = (gcnew System::Windows::Forms::Button());
			this->limitMiesiecznyTextBox = (gcnew System::Windows::Forms::TextBox());
			this->limitDziennyTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->saldoLabel = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// rachunkiComboBox
			// 
			this->rachunkiComboBox->FormattingEnabled = true;
			this->rachunkiComboBox->Location = System::Drawing::Point(12, 12);
			this->rachunkiComboBox->Name = L"rachunkiComboBox";
			this->rachunkiComboBox->Size = System::Drawing::Size(413, 21);
			this->rachunkiComboBox->TabIndex = 0;
			this->rachunkiComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm1::comboBox1_SelectedIndexChanged);
			// 
			// wylogujBtn
			// 
			this->wylogujBtn->Location = System::Drawing::Point(567, 12);
			this->wylogujBtn->Name = L"wylogujBtn";
			this->wylogujBtn->Size = System::Drawing::Size(117, 21);
			this->wylogujBtn->TabIndex = 1;
			this->wylogujBtn->Text = L"Wyloguj";
			this->wylogujBtn->UseVisualStyleBackColor = true;
			// 
			// userIdLabel
			// 
			this->userIdLabel->AutoSize = true;
			this->userIdLabel->Location = System::Drawing::Point(526, 15);
			this->userIdLabel->Name = L"userIdLabel";
			this->userIdLabel->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->userIdLabel->Size = System::Drawing::Size(0, 13);
			this->userIdLabel->TabIndex = 2;
			this->userIdLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// historiaPrzelewowListBox
			// 
			this->historiaPrzelewowListBox->FormattingEnabled = true;
			this->historiaPrzelewowListBox->Location = System::Drawing::Point(413, 36);
			this->historiaPrzelewowListBox->Name = L"historiaPrzelewowListBox";
			this->historiaPrzelewowListBox->Size = System::Drawing::Size(244, 251);
			this->historiaPrzelewowListBox->TabIndex = 3;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->kosztyMiesieczneLabel);
			this->groupBox1->Controls->Add(this->oprocentowanieLabel);
			this->groupBox1->Controls->Add(this->rodzajRachunkuLabel);
			this->groupBox1->Controls->Add(this->zlecPrzelewBtn);
			this->groupBox1->Controls->Add(this->limitMiesiecznyBtn);
			this->groupBox1->Controls->Add(this->limitDziennyBtn);
			this->groupBox1->Controls->Add(this->limitMiesiecznyTextBox);
			this->groupBox1->Controls->Add(this->limitDziennyTextBox);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->saldoLabel);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->historiaPrzelewowListBox);
			this->groupBox1->Location = System::Drawing::Point(12, 39);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(672, 300);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			// 
			// kosztyMiesieczneLabel
			// 
			this->kosztyMiesieczneLabel->AutoSize = true;
			this->kosztyMiesieczneLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->kosztyMiesieczneLabel->Location = System::Drawing::Point(106, 141);
			this->kosztyMiesieczneLabel->Name = L"kosztyMiesieczneLabel";
			this->kosztyMiesieczneLabel->Size = System::Drawing::Size(0, 16);
			this->kosztyMiesieczneLabel->TabIndex = 19;
			// 
			// oprocentowanieLabel
			// 
			this->oprocentowanieLabel->AutoSize = true;
			this->oprocentowanieLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->oprocentowanieLabel->Location = System::Drawing::Point(106, 102);
			this->oprocentowanieLabel->Name = L"oprocentowanieLabel";
			this->oprocentowanieLabel->Size = System::Drawing::Size(0, 16);
			this->oprocentowanieLabel->TabIndex = 18;
			// 
			// rodzajRachunkuLabel
			// 
			this->rodzajRachunkuLabel->AutoSize = true;
			this->rodzajRachunkuLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->rodzajRachunkuLabel->Location = System::Drawing::Point(106, 63);
			this->rodzajRachunkuLabel->Name = L"rodzajRachunkuLabel";
			this->rodzajRachunkuLabel->Size = System::Drawing::Size(0, 16);
			this->rodzajRachunkuLabel->TabIndex = 17;
			// 
			// zlecPrzelewBtn
			// 
			this->zlecPrzelewBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->zlecPrzelewBtn->Location = System::Drawing::Point(13, 255);
			this->zlecPrzelewBtn->Name = L"zlecPrzelewBtn";
			this->zlecPrzelewBtn->Size = System::Drawing::Size(394, 32);
			this->zlecPrzelewBtn->TabIndex = 16;
			this->zlecPrzelewBtn->Text = L"Zleæ przelew";
			this->zlecPrzelewBtn->UseVisualStyleBackColor = true;
			// 
			// limitMiesiecznyBtn
			// 
			this->limitMiesiecznyBtn->Location = System::Drawing::Point(250, 213);
			this->limitMiesiecznyBtn->Name = L"limitMiesiecznyBtn";
			this->limitMiesiecznyBtn->Size = System::Drawing::Size(157, 22);
			this->limitMiesiecznyBtn->TabIndex = 15;
			this->limitMiesiecznyBtn->Text = L"Zmieñ";
			this->limitMiesiecznyBtn->UseVisualStyleBackColor = true;
			// 
			// limitDziennyBtn
			// 
			this->limitDziennyBtn->Location = System::Drawing::Point(250, 177);
			this->limitDziennyBtn->Name = L"limitDziennyBtn";
			this->limitDziennyBtn->Size = System::Drawing::Size(157, 22);
			this->limitDziennyBtn->TabIndex = 14;
			this->limitDziennyBtn->Text = L"Zmieñ";
			this->limitDziennyBtn->UseVisualStyleBackColor = true;
			// 
			// limitMiesiecznyTextBox
			// 
			this->limitMiesiecznyTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->limitMiesiecznyTextBox->Location = System::Drawing::Point(109, 213);
			this->limitMiesiecznyTextBox->Name = L"limitMiesiecznyTextBox";
			this->limitMiesiecznyTextBox->Size = System::Drawing::Size(135, 22);
			this->limitMiesiecznyTextBox->TabIndex = 13;
			// 
			// limitDziennyTextBox
			// 
			this->limitDziennyTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->limitDziennyTextBox->Location = System::Drawing::Point(109, 177);
			this->limitDziennyTextBox->Name = L"limitDziennyTextBox";
			this->limitDziennyTextBox->Size = System::Drawing::Size(135, 22);
			this->limitDziennyTextBox->TabIndex = 12;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(18, 218);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(85, 13);
			this->label7->TabIndex = 11;
			this->label7->Text = L"Limit miesiêczny:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(33, 182);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(70, 13);
			this->label6->TabIndex = 10;
			this->label6->Text = L"Limit dzienny:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(10, 143);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(96, 13);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Koszty miesiêczne:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(18, 104);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(88, 13);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Oprocentowanie:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(15, 65);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(91, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Rodzaj rachunku:";
			// 
			// saldoLabel
			// 
			this->saldoLabel->AutoSize = true;
			this->saldoLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->saldoLabel->Location = System::Drawing::Point(168, 16);
			this->saldoLabel->Name = L"saldoLabel";
			this->saldoLabel->Size = System::Drawing::Size(0, 31);
			this->saldoLabel->TabIndex = 6;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label2->Location = System::Drawing::Point(104, 22);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(73, 25);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Saldo:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(410, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(95, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Historia przelewów";
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(696, 344);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->userIdLabel);
			this->Controls->Add(this->wylogujBtn);
			this->Controls->Add(this->rachunkiComboBox);
			this->Name = L"MyForm1";
			this->Text = L"Panel klienta";
			this->Load += gcnew System::EventHandler(this, &MyForm1::MyForm1_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void MyForm1_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
