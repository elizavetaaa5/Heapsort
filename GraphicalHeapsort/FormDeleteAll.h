#pragma once  /* #pragma once — это директива препроцессора, которая указывает компилятору включить файл
заголовка только один раз при компиляции файла исходного кода */

// Подключаемые файлы проекта
#include "DatabaseQueries.h"

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

	/// <summary>
	/// Сводка для FormDeleteAll
	/// </summary>
	public ref class FormDeleteAll : public System::Windows::Forms::Form
	{
	public:
		FormDeleteAll(void)
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
		~FormDeleteAll()
		{
			if (components)
			{
				delete components;
			}
		}
		// Объявление элементов формы
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button_yes;



	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ button_no;

	protected:

	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>

/* #pragma region позволяет указать блок кода, который можно развернуть или свернуть при
использовании функции структурирования редактора Visual Studio */
#pragma region Windows Form Designer generated code
/// <summary>
/// Требуемый метод для поддержки конструктора — не изменяйте 
/// содержимое этого метода с помощью редактора кода.
/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FormDeleteAll::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button_yes = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button_no = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(152, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(617, 84);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Вы действительно хотите удалить все элементы массива\r\n\r\nбез возможности восстанов"
				L"ления\?\r\n";
			this->label1->Click += gcnew System::EventHandler(this, &FormDeleteAll::label1_Click);
			// 
			// button_yes
			// 
			this->button_yes->Location = System::Drawing::Point(606, 195);
			this->button_yes->Name = L"button_yes";
			this->button_yes->Size = System::Drawing::Size(105, 37);
			this->button_yes->TabIndex = 3;
			this->button_yes->Text = L"Да";
			this->button_yes->UseVisualStyleBackColor = true;
			this->button_yes->Click += gcnew System::EventHandler(this, &FormDeleteAll::button_yes_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(25, 21);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(109, 86);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			// 
			// button_no
			// 
			this->button_no->Location = System::Drawing::Point(731, 195);
			this->button_no->Name = L"button_no";
			this->button_no->Size = System::Drawing::Size(105, 37);
			this->button_no->TabIndex = 5;
			this->button_no->Text = L"Отмена";
			this->button_no->UseVisualStyleBackColor = true;
			this->button_no->Click += gcnew System::EventHandler(this, &FormDeleteAll::button_no_Click);
			// 
			// FormDeleteAll
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 22);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(848, 244);
			this->Controls->Add(this->button_no);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button_yes);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiBold", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ForeColor = System::Drawing::SystemColors::MenuText;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximumSize = System::Drawing::Size(866, 291);
			this->MinimumSize = System::Drawing::Size(866, 291);
			this->Name = L"FormDeleteAll";
			this->Text = L"Подтверждение удаления ";
			this->Load += gcnew System::EventHandler(this, &FormDeleteAll::FormDeleteAll_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		//Директива #pragma endregion помечает конец блока, определённого директивой #pragma region.
#pragma endregion 
	 /* Обработки событий, которые могут быть вызваны в процессе работы программы */
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void FormDeleteAll_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button_yes_Click(System::Object^ sender, System::EventArgs^ e) {

		if (DeleteAllFromBD()) MessageBox::Show("Данные удалены.", L"Успешно", MessageBoxButtons::OK, MessageBoxIcon::Information);
		else MessageBox::Show("Ошибка. Данные отсутствуют.", L"Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		
		this->Close();
	}
	private: System::Void button_no_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
};
}
