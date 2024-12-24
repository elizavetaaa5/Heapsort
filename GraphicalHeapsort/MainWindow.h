#pragma once /* #pragma once — это директива препроцессора, которая указывает компилятору включить файл
заголовка только один раз при компиляции файла исходного кода */

// Подключаемые библиотеки
#include <string>
#include <sstream>
#include <vector>

// Подключаемые файлы проекта
#include "ConnectionString.h"
#include "Heapsort.h"
#include "DatabaseQueries.h"

// Подключаемые формы
#include "FormDeleteAll.h"
#include "FormDeleteLine.h"

using namespace std; /* Using namespace std в C++ — это директива, которая позволяет использовать
все идентификаторы из пространства имён std без указания префикса std:: */


namespace GraphicalHeapsort {
	
	// Использованные пространства имен
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::OleDb;

	// <summary> Сводка для MainWindow - это описание класса MainWindow </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		MainWindow(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	// Объявление элементов формы
	private: System::Windows::Forms::TabControl^ TabControl;
	protected:
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::Label^ label1;
	public: System::Windows::Forms::TextBox^ textBox1;
	private:

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button_save;

	private: System::Windows::Forms::Button^ button_sort;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TabPage^ tabPage3;
	public: System::Windows::Forms::DataGridView^ dataGridView1;
	private:

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ UnsortedArray;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ SortedArray;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button_all;

	private: System::Windows::Forms::Button^ button_delete;

	private: System::Windows::Forms::Button^ button_update;


	private: System::Windows::Forms::GroupBox^ groupBox1;
	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;
/* #pragma region позволяет указать блок кода, который можно развернуть или свернуть при
использовании функции структурирования редактора Visual Studio */
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainWindow::typeid));
			this->TabControl = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button_save = (gcnew System::Windows::Forms::Button());
			this->button_sort = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button_all = (gcnew System::Windows::Forms::Button());
			this->button_delete = (gcnew System::Windows::Forms::Button());
			this->button_update = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->ID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->UnsortedArray = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->SortedArray = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->TabControl->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->tabPage3->SuspendLayout();
			this->SuspendLayout();
			// 
			// TabControl
			// 
			this->TabControl->Appearance = System::Windows::Forms::TabAppearance::FlatButtons;
			this->TabControl->Controls->Add(this->tabPage1);
			this->TabControl->Controls->Add(this->tabPage2);
			this->TabControl->Controls->Add(this->tabPage3);
			this->TabControl->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiLight", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->TabControl->Location = System::Drawing::Point(0, 0);
			this->TabControl->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->TabControl->Name = L"TabControl";
			this->TabControl->SelectedIndex = 0;
			this->TabControl->Size = System::Drawing::Size(1037, 537);
			this->TabControl->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->tabPage1->Controls->Add(this->label3);
			this->tabPage1->Controls->Add(this->button_save);
			this->tabPage1->Controls->Add(this->button_sort);
			this->tabPage1->Controls->Add(this->textBox2);
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Controls->Add(this->textBox1);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Location = System::Drawing::Point(4, 36);
			this->tabPage1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->tabPage1->Size = System::Drawing::Size(1029, 497);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Сортировка";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::SystemColors::Window;
			this->label3->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->label3->Font = (gcnew System::Drawing::Font(L"Bahnschrift Condensed", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->label3->Location = System::Drawing::Point(45, 160);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(270, 23);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Введите элементы массива через пробел\r\n";
			this->label3->Click += gcnew System::EventHandler(this, &MainWindow::label3_Click);
			// 
			// button_save
			// 
			this->button_save->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->button_save->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->button_save->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_save->ForeColor = System::Drawing::SystemColors::Highlight;
			this->button_save->Location = System::Drawing::Point(835, 351);
			this->button_save->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button_save->Name = L"button_save";
			this->button_save->Size = System::Drawing::Size(136, 36);
			this->button_save->TabIndex = 5;
			this->button_save->Text = L"Сохранить";
			this->button_save->UseVisualStyleBackColor = false;
			this->button_save->Visible = false;
			this->button_save->Click += gcnew System::EventHandler(this, &MainWindow::button_save_Click);
			// 
			// button_sort
			// 
			this->button_sort->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->button_sort->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->button_sort->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_sort->ForeColor = System::Drawing::SystemColors::Highlight;
			this->button_sort->Location = System::Drawing::Point(835, 160);
			this->button_sort->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button_sort->Name = L"button_sort";
			this->button_sort->Size = System::Drawing::Size(136, 34);
			this->button_sort->TabIndex = 4;
			this->button_sort->Text = L"Сортировать";
			this->button_sort->UseVisualStyleBackColor = false;
			this->button_sort->Click += gcnew System::EventHandler(this, &MainWindow::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::SystemColors::Window;
			this->textBox2->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Bahnschrift Condensed", 14.25F));
			this->textBox2->ForeColor = System::Drawing::SystemColors::MenuText;
			this->textBox2->Location = System::Drawing::Point(40, 351);
			this->textBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(751, 36);
			this->textBox2->TabIndex = 3;
			this->textBox2->Visible = false;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MainWindow::textBox2_TextChanged);
			this->textBox2->Enter += gcnew System::EventHandler(this, &MainWindow::textBox2_Enter);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->label2->Location = System::Drawing::Point(45, 295);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(375, 41);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Отсортированный массив:";
			this->label2->Visible = false;
			this->label2->Click += gcnew System::EventHandler(this, &MainWindow::label2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Bahnschrift Condensed", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->ForeColor = System::Drawing::SystemColors::MenuText;
			this->textBox1->Location = System::Drawing::Point(40, 160);
			this->textBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(751, 36);
			this->textBox1->TabIndex = 1;
			this->textBox1->Tag = L"";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MainWindow::textBox1_TextChanged);
			this->textBox1->Enter += gcnew System::EventHandler(this, &MainWindow::textBox1_Enter);
			this->textBox1->Leave += gcnew System::EventHandler(this, &MainWindow::textBox1_Leave);
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->label1->Location = System::Drawing::Point(40, 103);
			this->label1->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(749, 54);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Введите массив для сортировки:";
			this->label1->Click += gcnew System::EventHandler(this, &MainWindow::label1_Click);
			// 
			// tabPage2
			// 
			this->tabPage2->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->tabPage2->Controls->Add(this->groupBox1);
			this->tabPage2->Controls->Add(this->dataGridView1);
			this->tabPage2->Location = System::Drawing::Point(4, 36);
			this->tabPage2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->tabPage2->Size = System::Drawing::Size(1029, 497);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Список сохраненных массивов";
			this->tabPage2->Click += gcnew System::EventHandler(this, &MainWindow::tabPage2_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->groupBox1->Controls->Add(this->button_all);
			this->groupBox1->Controls->Add(this->button_delete);
			this->groupBox1->Controls->Add(this->button_update);
			this->groupBox1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->ForeColor = System::Drawing::Color::DimGray;
			this->groupBox1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->groupBox1->Location = System::Drawing::Point(797, 6);
			this->groupBox1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->groupBox1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->groupBox1->Size = System::Drawing::Size(213, 489);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Действия";
			// 
			// button_all
			// 
			this->button_all->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 14.25F, System::Drawing::FontStyle::Bold));
			this->button_all->ForeColor = System::Drawing::Color::DimGray;
			this->button_all->Location = System::Drawing::Point(5, 306);
			this->button_all->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button_all->Name = L"button_all";
			this->button_all->Size = System::Drawing::Size(200, 50);
			this->button_all->TabIndex = 2;
			this->button_all->Text = L"Удалить всё";
			this->button_all->UseVisualStyleBackColor = true;
			this->button_all->Click += gcnew System::EventHandler(this, &MainWindow::button5_Click);
			// 
			// button_delete
			// 
			this->button_delete->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 14.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button_delete->ForeColor = System::Drawing::Color::DimGray;
			this->button_delete->Location = System::Drawing::Point(5, 204);
			this->button_delete->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button_delete->Name = L"button_delete";
			this->button_delete->Size = System::Drawing::Size(200, 49);
			this->button_delete->TabIndex = 1;
			this->button_delete->Text = L"Удалить строку";
			this->button_delete->UseVisualStyleBackColor = true;
			this->button_delete->Click += gcnew System::EventHandler(this, &MainWindow::button4_Click);
			// 
			// button_update
			// 
			this->button_update->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button_update->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 14.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button_update->ForeColor = System::Drawing::Color::DimGray;
			this->button_update->Location = System::Drawing::Point(5, 111);
			this->button_update->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button_update->Name = L"button_update";
			this->button_update->Size = System::Drawing::Size(200, 49);
			this->button_update->TabIndex = 0;
			this->button_update->Text = L"Обновить";
			this->button_update->UseVisualStyleBackColor = false;
			this->button_update->Click += gcnew System::EventHandler(this, &MainWindow::button3_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->BackgroundColor = System::Drawing::Color::LightGray;
			this->dataGridView1->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->ID, this->UnsortedArray,
					this->SortedArray
			});
			this->dataGridView1->EnableHeadersVisualStyles = false;
			this->dataGridView1->GridColor = System::Drawing::Color::DimGray;
			this->dataGridView1->Location = System::Drawing::Point(0, 1);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dataGridView1->MaximumSize = System::Drawing::Size(776, 492);
			this->dataGridView1->MinimumSize = System::Drawing::Size(776, 492);
			this->dataGridView1->Name = L"dataGridView1";
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiLight", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::Color::WhiteSmoke;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->RowHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->RowHeadersWidth = 51;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle2->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle2->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::Color::White;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::Color::Black;
			this->dataGridView1->RowsDefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(776, 492);
			this->dataGridView1->TabIndex = 0;
			// 
			// ID
			// 
			this->ID->HeaderText = L"№";
			this->ID->MinimumWidth = 6;
			this->ID->Name = L"ID";
			this->ID->ReadOnly = true;
			this->ID->Width = 40;
			// 
			// UnsortedArray
			// 
			this->UnsortedArray->HeaderText = L"Неотсортированный массив";
			this->UnsortedArray->MinimumWidth = 6;
			this->UnsortedArray->Name = L"UnsortedArray";
			this->UnsortedArray->ReadOnly = true;
			this->UnsortedArray->Width = 250;
			// 
			// SortedArray
			// 
			this->SortedArray->HeaderText = L"Отсортированный массив";
			this->SortedArray->MinimumWidth = 6;
			this->SortedArray->Name = L"SortedArray";
			this->SortedArray->ReadOnly = true;
			this->SortedArray->Width = 250;
			// 
			// tabPage3
			// 
			this->tabPage3->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->tabPage3->Controls->Add(this->label4);
			this->tabPage3->Location = System::Drawing::Point(4, 36);
			this->tabPage3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->tabPage3->Size = System::Drawing::Size(1029, 497);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"О программе";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiLight SemiConde", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->ForeColor = System::Drawing::SystemColors::MenuText;
			this->label4->Location = System::Drawing::Point(5, 36);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(944, 432);
			this->label4->TabIndex = 0;
			this->label4->Text = resources->GetString(L"label4.Text");
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->ClientSize = System::Drawing::Size(1032, 540);
			this->Controls->Add(this->TabControl);
			this->ForeColor = System::Drawing::SystemColors::Control;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->MaximumSize = System::Drawing::Size(1050, 587);
			this->MinimumSize = System::Drawing::Size(1050, 587);
			this->Name = L"MainWindow";
			this->Text = L"Пирамидный Мастер";
			this->Load += gcnew System::EventHandler(this, &MainWindow::MainWindow_Load);
			this->TabControl->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			this->ResumeLayout(false);

		}
//Директива #pragma endregion помечает конец блока, определённого директивой #pragma region.
#pragma endregion

	/* Обработки событий, которые могут быть вызваны в процессе работы программы */
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void textBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text == "") {
			label3->Visible = false; // Скрыть Label, если TextBox пустой
		}
	}
	private: System::Void textBox1_Leave(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text == "") {
			label3->Visible = true; // Показать Label, если TextBox пустой
		}
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text != "") {
			label3->Visible = false; // Скрыть Label, если введён текст
		}
		else {
			label3->Visible = true; // Показать Label, если TextBox пустой
		}
	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
	private: System::Void tabPage2_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void textBox2_Enter(System::Object^ sender, System::EventArgs^ e) {
		this->ActiveControl = nullptr; // Убирает фокус с TextBox
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {

		dataGridView1->Rows->Clear();

		String^ ConnectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=C:\\Users\\lea05\\Desktop\\GraphicalHeapsort\\GraphicalHeapsort\\Database.mdb";
		OleDbConnection^ DBConnection = gcnew OleDbConnection(ConnectionString);

		String^ Query = "SELECT * FROM [Таблица массивов]";

		DBConnection->Open();

		OleDbCommand^ DBCommand = gcnew OleDbCommand(Query, DBConnection);

		OleDbDataReader^ DBReader = DBCommand->ExecuteReader();


		while (DBReader->Read()) {
			dataGridView1->Rows->Add(DBReader["ID"],
				DBReader["UnsortedArray"],
				DBReader["SortedArray"]);
		}

		DBReader->Close();
		DBConnection->Close();

		MessageBox::Show("Данные обновлены.", "Успешно", MessageBoxButtons::OK, MessageBoxIcon::Information);

	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		
		FormDeleteLine^ DeleteLineForm = gcnew FormDeleteLine();
		DeleteLineForm->Show();

	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {

		FormDeleteAll^ DeleteAllForm = gcnew FormDeleteAll();
		DeleteAllForm->Show();

	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		label2->Visible = false;
		textBox2->Visible = false;
		button_save->Visible = false;


		bool ErrorFlag = false;
		string TranslatedLine = "";
		String^ ReceivedLine = "";
		string TempLine = "";

		if (textBox1->Text->Length == 0) {
			ErrorFlag = true;
			MessageBox::Show(L"Ошибка. Проверьте корректность вводимых данных.", L"Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

		ReceivedLine = textBox1->Text;

		TranslatedLine = ToStdstring(ReceivedLine);

		vector<string> SeparatedList;

		stringstream LineStream(TranslatedLine);

		char del = ', ';

		while (getline(LineStream, TempLine, del)) SeparatedList.push_back(TempLine);

		for (int i = 0; i < TempLine.size(); i++) {
			if (TempLine[i] == ' ') {
				ErrorFlag = true;
				MessageBox::Show(L"Ошибка. Проверьте корректность вводимых данных.", L"Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				break;
			}
		}

		int size = static_cast<int>(SeparatedList.size());

		int* Array = new int[size];

		int number = 0;

		try {
			for (int i = 0; i < size; i++) {

				number = stoi(SeparatedList[i]);
				Array[i] = number;
			}


		}
		catch (...) {

			MessageBox::Show(L"Ошибка. Проверьте корректность вводимых данных.", L"Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			ErrorFlag = true;

		}

		if (ErrorFlag == false) {
			HeapSort(Array, size);

			String^ LineSortedArray = "";

			for (int i = 0; i < size - 1; i++) {

				LineSortedArray += Array[i].ToString();
				LineSortedArray += ", ";

			}
			LineSortedArray += Array[size - 1].ToString();

			textBox2->Text = LineSortedArray;

			label2->Visible = true;
			textBox2->Visible = true;
			button_save->Visible = true;
		}
	}
	private: System::Void button_save_Click(System::Object^ sender, System::EventArgs^ e) {

		String^ UnsortedLine = textBox1->Text;
		String^ SortedLine = textBox2->Text;

		string UnsortedString = ToStdstring(UnsortedLine);
		string SortedString = ToStdstring(SortedLine);

		SetArraysToDB(UnsortedString, SortedString);
		MessageBox::Show(L"Массив сохранен в таблицу", L"Успешно", MessageBoxButtons::OK, MessageBoxIcon::Information);

	}
	private: System::Void MainWindow_Load(System::Object^ sender, System::EventArgs^ e) {

		dataGridView1->AutoSize = false;

		dataGridView1->AutoSize = false;

		DataGridViewColumn^ FirstColumn = nullptr;
		FirstColumn = dataGridView1->Columns[0];
		FirstColumn->Width = 28;

		DataGridViewColumn^ SecondColumn = nullptr;
		SecondColumn = dataGridView1->Columns[1];
		SecondColumn->Width = 250;

		DataGridViewColumn^ ThirdColumn = nullptr;
		ThirdColumn = dataGridView1->Columns[2];
		ThirdColumn->Width = 250;

		string connStr = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=C:\\Users\\lea05\\Desktop\\GraphicalHeapsort\\GraphicalHeapsort\\Database.mdb";
		string query = "SELECT * From Database";



	}
	};
}